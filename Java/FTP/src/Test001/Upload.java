package Test001;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

//实现FTP客户端的上传功能
public class Upload {
    public static boolean uploadFile(String filename,FileInputStream in,String path) {
        boolean flg=false;
        try {
            File_Tree.ftp.changeWorkingDirectory(path);//切换服务器目录
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            flg= File_Tree.ftp.storeFile(filename, in);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        try {
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return flg;
    }
    public static boolean upload(String localPath,String filename,String path) {
        boolean flag=false;
        try {
            FileInputStream in=new FileInputStream(new File(localPath));
            flag = uploadFile(filename,in,path);
            System.out.println(flag);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return flag;
    }
}
