package pack1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import org.apache.commons.net.ftp.FTPFile;

//实现FTP的下载功能
public class Download {
	//下载文件到本地位置上
	public static boolean download(String Path, String localPath,String filename)  
            throws IOException {  
        boolean res = false;  //标记是否下载成功
        System.out.println("查找文件"+Path);
        //JTree2.ftp.setFileType(JTree2.ftp.BINARY_FILE_TYPE);
        //JTree2.ftp.enterLocalPassiveMode();
        JTree2.ftp.changeWorkingDirectory(Path);//转移到FTP服务器目录
        FTPFile[] fs=JTree2.ftp.listFiles();
        for(FTPFile f:fs){
        	if(f.getName().equals(filename)){//如果是所要下载的文件
        		File localFile=new File(localPath+"\\"+filename);
        		System.out.println("文件长度为：");
        		OutputStream is=new FileOutputStream(localFile);
        		res=JTree2.ftp.retrieveFile(f.getName(), is);
    			is.flush();  
                is.close();         		
        	}   	
        } 
        return res;  
    }  
}
