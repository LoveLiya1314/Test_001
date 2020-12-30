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
//JTree的主要工作是将FTP服务器的目录遍历一遍
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
   //设置监听端口
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
               System.out.println("你选择了：" +t+object.toString());
           }
       }
   }); 
  }
  //获取一个目录的所有子目录
  public void list(String path1,DefaultMutableTreeNode node)throws IOException{
	  if(path1.startsWith("/") && path1.endsWith("/")){ 
		  //path1 = new String(path1.getBytes("GBK"),"iso-8859-1"); //关键是这行代码
		  
		  ftp.changeWorkingDirectory(path1);
		  //ftp.setControlEncoding("gb2312"); 
		  FTPFile[] fss=ftp.listFiles(path1);  
		  System.out.println(path1+"文件长度:"+ftp.listFiles().length);
		  if(fss.length==0){
			  DefaultMutableTreeNode child=new DefaultMutableTreeNode("空目录，不可选中");
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
	        
	        ftp.connect(url);//连接FTP服务器
	        ftp.login(username, password);//登录  
	        ftp.setFileType(FTPClient.BINARY_FILE_TYPE);  
	        reply = ftp.getReplyCode();  
	        if (!FTPReply.isPositiveCompletion(reply)) {  
	            ftp.disconnect();  
	            return success;  
	        } //此处是主目录，可以用JTree树将目录列表出来，而不必一级一级递归列出来     
            list("/",root);      
	        success = true; 
	    } catch (IOException e) {  
	        e.printStackTrace();  
	    } finally {  
	        if (ftp.isConnected()) {  
	            	JOptionPane.showMessageDialog(this, "登陆/刷新成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
	                System.out.println("ftp连接成功啦！！！");                
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