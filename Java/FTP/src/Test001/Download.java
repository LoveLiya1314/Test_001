package Test001;

import java.io.*;

import org.apache.commons.net.ftp.FTPFile;

//实现FTP的下载功能
public class Download {
                                                                                                //下载文件到本地位置上
    public static boolean download(String Path, String localPath,String filename)  {
        boolean res = false;
        //标记是否下载成功,在控制台能够看到是否下载成功
        System.out.println("查找文件"+Path);
//        try {
        try {
            File_Tree.ftp.changeWorkingDirectory(Path);                                              //转移到FTP服务器目录
        } catch (IOException e) {
            e.printStackTrace();
        }
        FTPFile[] fs= new FTPFile[0];
        try {
            fs = File_Tree.ftp.listFiles();
        } catch (IOException e) {
            e.printStackTrace();
        }
        for(FTPFile f:fs){
                if(f.getName().equals(filename)){                                                   //如果是所要下载的文件
                    File localFile=new File(localPath+"\\"+filename);
                    System.out.println("文件长度为：");
                    OutputStream is= null;
                    try {
                        is = new FileOutputStream(localFile);
                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                    }
                    try {
                        res= File_Tree.ftp.retrieveFile(f.getName(), is);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        is.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        is.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
/*
        }  catch (SocketException eee){
            JOptionPane.showMessageDialog(null,"网络链接丢失！","ERROR!!!",JOptionPane.ERROR_MESSAGE);
            res=false;

        }*/
        return res;
    }

}
