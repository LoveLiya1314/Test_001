
#pragma warning(disable : 4996)

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
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/des.h"
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include <stdlib.h>
#include <Windows.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include<cstdio>
#pragma comment (lib, "libssl.lib")
#pragma comment (lib, "libcrypto.lib")


#include <io.h>
#include <stdio.h>
#include <vector>
using namespace std;
vector<string> vec_path;
vector<string> vec_path02;
bool TraverseDirectory(std::string path)
{
    __int64  Handle;
    struct __finddata64_t  FileInfo;
    string strFind = path + "\\*";

    if ((Handle = _findfirst64(strFind.c_str(), &FileInfo)) == -1L)
    {
        printf("没有找到匹配的项目\n");
        return false;
    }
    do
    {
        if (FileInfo.attrib & _A_SUBDIR)
        {
            if ((strcmp(FileInfo.name, ".") != 0) && (strcmp(FileInfo.name, "..") != 0))
            {
                string newPath = path + "\\" + FileInfo.name;
                TraverseDirectory(newPath);
            }
        }
        else	
        {
            string newPath = path + "\\" + FileInfo.name;
            vec_path.push_back(newPath);
        }
    } while (_findnext64(Handle, &FileInfo) == 0);

    _findclose(Handle);
    return true;
}
bool TraverseDirectory02(std::string path)
{
    __int64  Handle;
    struct __finddata64_t  FileInfo;
    string strFind = path + "\\*";

    if ((Handle = _findfirst64(strFind.c_str(), &FileInfo)) == -1L)
    {
        printf("没有找到匹配的项目\n");
        return false;
    }
    do
    {
        if (FileInfo.attrib & _A_SUBDIR)
        {
            if ((strcmp(FileInfo.name, ".") != 0) && (strcmp(FileInfo.name, "..") != 0))
            {
                string newPath = path + "\\" + FileInfo.name;
                TraverseDirectory02(newPath);
            }
        }
        else	
        {
            string newPath = path + "\\" + FileInfo.name;
            vec_path02.push_back(newPath);
        }
    } while (_findnext64(Handle, &FileInfo) == 0);

    _findclose(Handle);
    return true;
}


void encrypt_file(unsigned char* key, unsigned char* iv, FILE* fp, FILE* ofp);
bool decrypt_file(unsigned char* key, unsigned char* iv, FILE* ifp, FILE* ofp);
void handleErrors(void);

int main01()
{
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);
    unsigned char key[] = "1234567890123456";
    unsigned char iv[] = "1234567890123456";
    string input_path = "E:\\CODE\\GitHub\\ComputerTeconlogyExpermient\\C++\\1841302343";
    cin >> input_path;
    TraverseDirectory(input_path);
    for (int i = 0; i < vec_path.size(); i++)
    {
        cout << vec_path[i] << endl;
        cout << "\n";
        char* infile = (char*)vec_path[i].data();
        string buffer = vec_path[i];
        buffer = buffer + ".sm4";
        char* outfile = (char*)buffer.data();
        FILE* in = fopen(infile, "rb");
        FILE* out = fopen(outfile, "wb");

        if (in == NULL) {
            std::cout << "Unable to locate file." << endl;
            return 1;
        }

        encrypt_file(key, iv, in, out);

        fclose(in);
        fclose(out);
        if (remove(infile) == 0)
        {
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败" << endl;
        }
        cout << strerror(errno);


    }

    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();
}

int main03() {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);
    unsigned char key[] = "1234567890123456";
    unsigned char iv[] = "1234567890123456";
    string input_path = "E:\\CODE\\GitHub\\ComputerTeconlogyExpermient\\C++\\1841302343";
    cin >> input_path;
    TraverseDirectory02(input_path);
    for (int i = 0; i < vec_path02.size(); i++)
    {
        cout << vec_path02[i] << endl;
        cout << "\n";
        char* infile = (char*)vec_path02[i].data();
        string buffer = vec_path02[i];
        buffer.pop_back();
        buffer.pop_back();
        buffer.pop_back();
        buffer.pop_back();
        char* outfile = (char*)buffer.data();
        FILE* in = fopen(infile, "rb");
        FILE* out = fopen(outfile, "wb");

        if (in == NULL) {
            std::cout << "Unable to locate file.";
            return 1;
        }
        decrypt_file(key, iv, in, out);
        fclose(in);
        fclose(out);
        if (remove(infile) == 0)
        {
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败" << endl;
        }
        cout << strerror(errno);


    }
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();
    return 0;
}

void encrypt_file(unsigned char* key, unsigned char* iv, FILE* ifp, FILE* ofp)
{
    fseek(ifp, 0L, SEEK_END);
    int fsize = ftell(ifp);
    fseek(ifp, 0L, SEEK_SET);
    int outl = 0; int padl = 0;
    unsigned char* indata = (unsigned char*)malloc(fsize);
    unsigned char* outdata = (unsigned char*)malloc(fsize + 16);
    fread(indata, sizeof(char), fsize, ifp);
    EVP_CIPHER_CTX* ctx = NULL;
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();
    if (EVP_EncryptInit_ex(ctx, EVP_sm4_cbc(), NULL, key, iv) != 1)
        handleErrors();
    EVP_EncryptUpdate(ctx, outdata, &outl, indata, fsize);
    if (EVP_EncryptFinal_ex(ctx, outdata + outl, &padl) != 1)
        handleErrors();
    fwrite(outdata, sizeof(char), outl + padl, ofp);
    EVP_CIPHER_CTX_cleanup(ctx);
}

bool decrypt_file(unsigned char* key, unsigned char* iv, FILE* ifp, FILE* ofp)
{
    bool status = false;
    fseek(ifp, 0L, SEEK_END);
    int fsize = ftell(ifp);
    fseek(ifp, 0L, SEEK_SET);
    int outl = 0; int padl = 0;
    unsigned char* indata = (unsigned char*)malloc(fsize);
    unsigned char* outdata = (unsigned char*)malloc(fsize + 16);

    fread(indata, sizeof(char), fsize, ifp);

    EVP_CIPHER_CTX* ctx = NULL;


    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();


    if (EVP_DecryptInit_ex(ctx, EVP_sm4_cbc(), NULL, key, iv) != 1)
        handleErrors();

    EVP_DecryptUpdate(ctx, outdata, &outl, indata, fsize);

   
    if (EVP_DecryptFinal_ex(ctx, outdata + outl, &padl) > 0)
        status = true;

    fwrite(outdata, sizeof(char), outl + padl, ofp);

    EVP_CIPHER_CTX_cleanup(ctx);

    return status;
}

void handleErrors(void)
{
    unsigned long errCode;

    printf("An error occurred\n");
    while (errCode = ERR_get_error())
    {
        char* err = ERR_error_string(errCode, NULL);
        printf("%s\n", err);
    }
    abort();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
