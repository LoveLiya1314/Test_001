package pack1;

import java.awt.*;
import javax.swing.*;
import javax.swing.tree.*;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPClientConfig;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.event.*;
//JTree����Ҫ�����ǽ�FTP��������Ŀ¼����һ��
public class JTree2 extends JFrame
{
  JPanel cp=new JPanel();
  static FTPClient ftp = new FTPClient(); 
  JTree jtree;public String A,B,C;public static String ob="",t="";
  DefaultMutableTreeNode root;
  public JTree2(String a,String b,String c)
  {
	  A=a;B=b;C=c;
   this.setSize(600,600);
   this.setLocation(450, 150);
   this.setTitle("try to use tree");
   cp=(JPanel)this.getContentPane();
   cp.setLayout(new BorderLayout());
   
   root=new DefaultMutableTreeNode("/");
   Load(root);
   jtree=new JTree(root);
   //���ü����˿�
   jtree.addTreeSelectionListener(new TreeSelectionListener() {	   
       @Override
       public void valueChanged(TreeSelectionEvent e) {
           DefaultMutableTreeNode node = (DefaultMutableTreeNode) jtree
                   .getLastSelectedPathComponent();
           if (node == null)
               return;
           Object object = node.getUserObject();        
           if (node.isLeaf()) {          ob=object.toString();
           String sss=jtree.getSelectionPath().toString();
           
           String sss1=sss.replaceAll(", ", "/");
           t=sss1.replaceAll("//", "/");
        
               t=t.replaceAll(object.toString(), "");   int i=t.length();      
               t=t.substring(1,i-1);
               System.out.println("��ѡ���ˣ�" +t+object.toString());
           }
       }
   }); 
  }
  //��ȡһ��Ŀ¼��������Ŀ¼
  public void list(String path1,DefaultMutableTreeNode node)throws IOException{
	  if(path1.startsWith("/") && path1.endsWith("/")){ 
		  //path1 = new String(path1.getBytes("GBK"),"iso-8859-1"); //�ؼ������д���
		  
		  ftp.changeWorkingDirectory(path1);
		  //ftp.setControlEncoding("gb2312"); 
		  FTPFile[] fss=ftp.listFiles(path1);  
		  System.out.println(path1+"�ļ�����:"+ftp.listFiles().length);
		  if(fss.length==0){
			  DefaultMutableTreeNode child=new DefaultMutableTreeNode("��Ŀ¼������ѡ��");
			  node.add(child);
		  }
		  else{
		  for(FTPFile f:fss){
			  DefaultMutableTreeNode child=new DefaultMutableTreeNode(f.getName());
			  System.out.println(f.getName());
			  node.add(child);
			  if(f.isDirectory()){
				  list(path1+f.getName()+"/",child);
			  }
		  }
		  } 
	  }  
  }
  public  boolean Load(DefaultMutableTreeNode root) {  
	  String  url=A;String username=B;String password=C;String path="/";
	    boolean success = false;       
	    try {  
	        int reply; 
	        
	        ftp.setControlEncoding("gb2312");
	        
	        ftp.connect(url);//����FTP������
	        ftp.login(username, password);//��¼  
	        ftp.setFileType(FTPClient.BINARY_FILE_TYPE);  
	        reply = ftp.getReplyCode();  
	        if (!FTPReply.isPositiveCompletion(reply)) {  
	            ftp.disconnect();  
	            return success;  
	        } //�˴�����Ŀ¼��������JTree����Ŀ¼�б������������һ��һ���ݹ��г���     
            list("/",root);      
	        success = true; 
	    } catch (IOException e) {  
	        e.printStackTrace();  
	    } finally {  
	        if (ftp.isConnected()) {  
	            	JOptionPane.showMessageDialog(this, "��½/ˢ�³ɹ�����","Success",JOptionPane.INFORMATION_MESSAGE);
	                System.out.println("ftp���ӳɹ���������");                
	        }  
	    }  
	    return success;  
	}
  protected void processWindowEvent(WindowEvent e)
  {
   if(e.getID()==WindowEvent.WINDOW_CLOSING)
   {
    System.exit(0);
   }
  }
}