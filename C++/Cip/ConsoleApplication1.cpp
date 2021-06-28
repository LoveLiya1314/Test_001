#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************
 * Copyright ©  11:55 2021 - 6 - 24  Lambert All rights reserved.             *
 *    Licensed under the Apache License, Version 2.0 (the "License");         *
 *    you may not use this file except in compliance with the License.        *
 *    You may obtain a copy of the License at                                 *
 *                                                                            *
 *      http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                            *
 *    Unless required by applicable law or agreed to in writing, software     *
 *    distributed under the License is distributed on an "AS IS" BASIS,       *
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
 *    See the License for the specific language governing permissions and     *
 *    limitations under the License.                                          *
 * Love Liya Forever!                                                         *
 ******************************************************************************/
#include <iostream>
#include <stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include <iterator>
#include <string>
#include <cassert>
#include <cstring>
#include <functional>
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/des.h"
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include <openssl/err.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
  
void md5(const std::string& srcStr, std::string& encodedStr, std::string& encodedHexStr) {
  
    unsigned char mdStr[33] = { 0 };
    MD5((const unsigned char*)srcStr.c_str(), srcStr.length(), mdStr);
    encodedStr = std::string((const char*)mdStr);   
    char buf[65] = { 0 };
    char tmp[3] = { 0 };
    for (int i = 0; i < 32; i++) {
        sprintf(tmp, "%02x", mdStr[i]);
        strcat(buf, tmp);
    }
    buf[32] = '\0'; 
    encodedHexStr = std::string(buf);
}
  
void sha256(const std::string& srcStr, std::string& encodedStr, std::string& encodedHexStr) {
 
    unsigned char mdStr[33] = { 0 };
    SHA256((const unsigned char*)srcStr.c_str(), srcStr.length(), mdStr);
    
    encodedStr = std::string((const char*)mdStr);
 
    char buf[65] = { 0 };
    char tmp[3] = { 0 };
    for (int i = 0; i < 32; i++) {
        sprintf(tmp, "%02x", mdStr[i]);
        strcat(buf, tmp);
    }
    buf[32] = '\0';   
    encodedHexStr = std::string(buf);
}
  
std::string des_encrypt(const std::string& clearText, const std::string& key) {
    std::string cipherText;     

    DES_cblock keyEncrypt;
    memset(keyEncrypt, 0, 8);

   
    if (key.length() <= 8)
        memcpy(keyEncrypt, key.c_str(), key.length());
    else
        memcpy(keyEncrypt, key.c_str(), 8);

   
    DES_key_schedule keySchedule;
    DES_set_key_unchecked(&keyEncrypt, &keySchedule);
   
    const_DES_cblock inputText;
    DES_cblock outputText;
    std::vector<unsigned char> vecCiphertext;
    unsigned char tmp[8];

    for (int i = 0; i < clearText.length() / 8; i++) {
        memcpy(inputText, clearText.c_str() + i * 8, 8);
        DES_ecb_encrypt(&inputText, &outputText, &keySchedule, DES_ENCRYPT);
        memcpy(tmp, outputText, 8);

        for (int j = 0; j < 8; j++)
            vecCiphertext.push_back(tmp[j]);
    }

    if (clearText.length() % 8 != 0) {
        int tmp1 = clearText.length() / 8 * 8;
        int tmp2 = clearText.length() - tmp1;
        memset(inputText, 0, 8);
        memcpy(inputText, clearText.c_str() + tmp1, tmp2);
  
        DES_ecb_encrypt(&inputText, &outputText, &keySchedule, DES_ENCRYPT);
        memcpy(tmp, outputText, 8);

        for (int j = 0; j < 8; j++)
            vecCiphertext.push_back(tmp[j]);
    }

    cipherText.clear();
    cipherText.assign(vecCiphertext.begin(), vecCiphertext.end());

    return cipherText;
}

  
std::string des_decrypt(const std::string& cipherText, const std::string& key) {
    std::string clearText;    

    DES_cblock keyEncrypt;
    memset(keyEncrypt, 0, 8);

    if (key.length() <= 8)
        memcpy(keyEncrypt, key.c_str(), key.length());
    else
        memcpy(keyEncrypt, key.c_str(), 8);

    DES_key_schedule keySchedule;
    DES_set_key_unchecked(&keyEncrypt, &keySchedule);

    const_DES_cblock inputText;
    DES_cblock outputText;
    std::vector<unsigned char> vecCleartext;
    unsigned char tmp[8];

    for (int i = 0; i < cipherText.length() / 8; i++) {
        memcpy(inputText, cipherText.c_str() + i * 8, 8);
        DES_ecb_encrypt(&inputText, &outputText, &keySchedule, DES_DECRYPT);
        memcpy(tmp, outputText, 8);

        for (int j = 0; j < 8; j++)
            vecCleartext.push_back(tmp[j]);
    }

    if (cipherText.length() % 8 != 0) {
        int tmp1 = cipherText.length() / 8 * 8;
        int tmp2 = cipherText.length() - tmp1;
        memset(inputText, 0, 8);
        memcpy(inputText, cipherText.c_str() + tmp1, tmp2);
  
        DES_ecb_encrypt(&inputText, &outputText, &keySchedule, DES_DECRYPT);
        memcpy(tmp, outputText, 8);

        for (int j = 0; j < 8; j++)
            vecCleartext.push_back(tmp[j]);
    }

    clearText.clear();
    clearText.assign(vecCleartext.begin(), vecCleartext.end());

    return clearText;
}


#define KEY_LENGTH  2048             
#define PUB_KEY_FILE "pubkey.pem"  
#define PRI_KEY_FILE "prikey.pem"   
 
void generateRSAKey(std::string strKey[2]) {
    // 公私密钥对    
    size_t pri_len;
    size_t pub_len;
    char* pri_key = NULL;
    char* pub_key = NULL;

    // 生成密钥对    
    RSA* keypair = RSA_generate_key(KEY_LENGTH, RSA_3, NULL, NULL);

    BIO* pri = BIO_new(BIO_s_mem());
    BIO* pub = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey(pub, keypair);

    // 获取长度    
    pri_len = BIO_pending(pri);
    pub_len = BIO_pending(pub);

    // 密钥对读取到字符串    
    pri_key = (char*)malloc(pri_len + 1);
    pub_key = (char*)malloc(pub_len + 1);

    BIO_read(pri, pri_key, pri_len);
    BIO_read(pub, pub_key, pub_len);

    pri_key[pri_len] = '\0';
    pub_key[pub_len] = '\0';

    // 存储密钥对    
    strKey[0] = pub_key;
    strKey[1] = pri_key;

    // 存储到磁盘（这种方式存储的是begin rsa public key/ begin rsa private key开头的）  
    FILE* pubFile = fopen(PUB_KEY_FILE, "w");
    if (pubFile == NULL) {
        assert(false);
        return;
    }
    fputs(pub_key, pubFile);
    fclose(pubFile);

    FILE* priFile = fopen(PRI_KEY_FILE, "w");
    if (priFile == NULL) {
        assert(false);
        return;
    }
    fputs(pri_key, priFile);
    fclose(priFile);

    // 内存释放  
    RSA_free(keypair);
    BIO_free_all(pub);
    BIO_free_all(pri);

    free(pri_key);
    free(pub_key);
}
std::string rsa_pub_encrypt(const std::string& clearText, const std::string& pubKey) {
    std::string strRet;
    RSA* rsa = NULL;
    BIO* keybio = BIO_new_mem_buf((unsigned char*)pubKey.c_str(), -1);
    RSA* pRSAPublicKey = RSA_new();
    rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);
    int len = RSA_size(rsa);
    char* encryptedText = (char*)malloc(len + 1);
    memset(encryptedText, 0, len + 1);
    int ret = RSA_public_encrypt(clearText.length(), (const unsigned char*)clearText.c_str(),
        (unsigned char*)encryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(encryptedText, ret);
    free(encryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);
    return strRet;
}
  
std::string rsa_pri_decrypt(const std::string& cipherText, const std::string& priKey) {
    std::string strRet;
    RSA* rsa = RSA_new();
    BIO* keybio;
    keybio = BIO_new_mem_buf((unsigned char*)priKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
    int len = RSA_size(rsa);
    char* decryptedText = (char*)malloc(len + 1);
    memset(decryptedText, 0, len + 1);
    int ret = RSA_private_decrypt(cipherText.length(), (const unsigned char*)cipherText.c_str(),
        (unsigned char*)decryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(decryptedText, ret);
    free(decryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}


std::vector<char> GenerateRsaSignByString(const std::string& message,
    const std::string& prikey) {
    OpenSSL_add_all_algorithms();
    BIO* in = BIO_new_mem_buf((void*)prikey.c_str(), -1);
    if (in == NULL) {
        std::cout << "BIO_new_mem_buf failed" << std::endl;
        return std::vector<char>();
    }

    RSA* rsa = PEM_read_bio_RSAPrivateKey(in, NULL, NULL, NULL);
    BIO_free(in);

    if (rsa == NULL) {
        std::cout << "PEM_read_bio_RSAPrivateKey failed" << std::endl;
        return std::vector<char>();
    }
    unsigned int size = RSA_size(rsa);
    std::vector<char> sign;
    sign.resize(size);

    int ret =
        RSA_sign(NID_md5, (const unsigned char*)message.c_str(),
            message.length(), (unsigned char*)sign.data(), &size, rsa);
    RSA_free(rsa);
    if (ret != 1) {
        std::cout << "RSA_sign failed" << std::endl;
        return std::vector<char>();
    }
    return sign;
}

bool VerifyRsaSignByString(char* sign, uint32_t sign_len,
    const std::string& pubkey,
    const std::string& verify_str) {
    BIO* in = BIO_new_mem_buf((void*)pubkey.c_str(), -1);
    if (in == NULL) {
        std::cout << "BIO_new_mem_buf failed" << std::endl;
        return false;
    }

    RSA* rsa = PEM_read_bio_RSA_PUBKEY(in, NULL, NULL, NULL);
    BIO_free(in);

    if (rsa == NULL) {
        std::cout << "PEM_read_bio_RSA_PUBKEY failed" << std::endl;
        return false;
    }

    int ret =
        RSA_verify(NID_md5, (const unsigned char*)verify_str.c_str(),
            verify_str.length(), (unsigned char*)sign, sign_len, rsa);
    RSA_free(rsa);
    if (ret != 1) {
        std::cout << "RSA_verify failed" << std::endl;
        return false;
    }
    return true;
}
int main02() {
  
    std::string srcText = "201931224014";
    
    std::string encryptText;
    std::string encryptHexText;
    std::string decryptText;
    cout << "1.对称密码算法加密=== des加解密" << endl;
    cout << "2.===非对称密码算法加密=== rsa加解密" << endl;
    cout << "3.===消息摘要===" << endl;
    int a = 4;
    cin >> a;
    while (a!=0) {
        cin >> srcText;
        std::cout << "=== 原始明文 ===" << std::endl;
        std::cout << srcText << std::endl;
        
        
        switch (a) {
        case 1: {
            // des    
            std::cout << "===对称密码算法加密=== des加解密 ===" << std::endl;
            std::string desKey = "123456";
            encryptText = des_encrypt(srcText, desKey);

            std::cout << "加密字符： " << std::endl;

            std::cout << encryptText << std::endl;


            decryptText = des_decrypt(encryptText, desKey);
            std::cout << "解密字符： " << std::endl;
            std::cout << decryptText << std::endl;

            break;
        }

        case 2: {
            // rsa    
            std::cout << "===非对称密码算法加密=== rsa加解密 ===" << std::endl;
            std::string key[2];
            generateRSAKey(key);
            std::cout << "公钥: " << std::endl;
            std::cout << key[0] << std::endl;
            std::cout << "私钥： " << std::endl;
            std::cout << key[1] << std::endl;
            encryptText = rsa_pub_encrypt(srcText, key[0]);
            std::cout << "加密字符： " << std::endl;
            std::cout << encryptText << std::endl;
            decryptText = rsa_pri_decrypt(encryptText, key[1]);
            std::cout << "解密字符： " << std::endl;
            std::cout << decryptText << std::endl;     
            break;
        }

        case 3: {
            std::cout << "===消息摘要=== md5哈希 ===" << std::endl;
            md5(srcText, encryptText, encryptHexText);
            std::cout << "摘要字符： " << encryptText << std::endl;
            std::cout << "摘要串： " << encryptHexText << std::endl;
            std::cout << "===消息摘要=== sha256哈希 ===" << std::endl;
            sha256(srcText, encryptText, encryptHexText);
            std::cout << "摘要字符： " << encryptText << std::endl;
            std::cout << "摘要串： " << encryptHexText << std::endl;
            break;
        }

        default:
            break;
        }
        cin >> a;
    }
    
    return 0;
}