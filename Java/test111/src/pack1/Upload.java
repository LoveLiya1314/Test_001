package pack1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

//实现FTP客户端的上传功能
public class Upload {
	public static boolean uploadFile(String filename,FileInputStream in) throws IOException{
		boolean flg=false;
		JTree2.ftp.changeWorkingDirectory("/");//切换服务器目录
		try {
			flg=JTree2.ftp.storeFile(filename, in);	
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}           
        in.close();  
		return flg;	
	}
	public static boolean upload(String localPath,String filename) throws IOException{
	boolean flag=false;
		try {  
        FileInputStream in=new FileInputStream(new File(localPath));  
        flag = uploadFile(filename,in);  
        System.out.println(flag);  
    } catch (FileNotFoundException e) {  
        e.printStackTrace();  
    }  
	return flag;
	}	
}
