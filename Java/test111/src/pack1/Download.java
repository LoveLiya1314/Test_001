package pack1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import org.apache.commons.net.ftp.FTPFile;

//ʵ��FTP�����ع���
public class Download {
	//�����ļ�������λ����
	public static boolean download(String Path, String localPath,String filename)  
            throws IOException {  
        boolean res = false;  //����Ƿ����سɹ�
        System.out.println("�����ļ�"+Path);
        //JTree2.ftp.setFileType(JTree2.ftp.BINARY_FILE_TYPE);
        //JTree2.ftp.enterLocalPassiveMode();
        JTree2.ftp.changeWorkingDirectory(Path);//ת�Ƶ�FTP������Ŀ¼
        FTPFile[] fs=JTree2.ftp.listFiles();
        for(FTPFile f:fs){
        	if(f.getName().equals(filename)){//�������Ҫ���ص��ļ�
        		File localFile=new File(localPath+"\\"+filename);
        		System.out.println("�ļ�����Ϊ��");
        		OutputStream is=new FileOutputStream(localFile);
        		res=JTree2.ftp.retrieveFile(f.getName(), is);
    			is.flush();  
                is.close();         		
        	}   	
        } 
        return res;  
    }  
}
