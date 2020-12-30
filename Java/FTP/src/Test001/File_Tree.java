package Test001;
import java.awt.*;
import javax.swing.*;
import javax.swing.tree.*;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

import java.awt.event.*;
import java.io.IOException;

//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////关于FTpClint的介绍网址，以及导入Jar包的下载位置=================利用
//http://commons.apache.org/proper/commons-net/apidocs/org/apache/commons/net/ftp/FTPClient.html
import javax.swing.event.*;

public class File_Tree extends JFrame{
    JPanel CosPlayer =new JPanel();
    public static FTPClient ftp = new FTPClient();
    static JTree jtree;
    public String A,B,C,D;
    public static String FileName ="", FilePath ="";
    DefaultMutableTreeNode root;


//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////FTP程序中最基本的一个方法，该方法得到端口，FTP地址，用户名，密码=========实现与服务区的链接=========以及服务器文件的遍历！！！！
    public File_Tree(String a, String b, String c, String d, int Hhhhhhh)
    {
        A=a;
        B=b;
        C=c;
        D=d;
        this.setSize(600,600);
        this.setLocation(450, 150);
        this.setTitle("try to use tree");
        CosPlayer =(JPanel)this.getContentPane();
        CosPlayer.setLayout(new BorderLayout());
        root=new DefaultMutableTreeNode("/");
        if (Hhhhhhh == -1) {
            Flush(root);
        }else {
            Load(root,Hhhhhhh);
        }
        jtree=new JTree(root);
        jtree.addTreeSelectionListener(new TreeSelectionListener() {
            @Override
            /*
            * 通过内敛函数的方式来重写这个触发器的功能来实现选择的文件
            * */
            public void valueChanged(TreeSelectionEvent e) {
                DefaultMutableTreeNode node = (DefaultMutableTreeNode) jtree.getLastSelectedPathComponent();
                if (node == null) {
                    return;
                }
                Object object = node.getUserObject();
                if (node.isLeaf()) {
                    FileName =object.toString();
                    String sss=jtree.getSelectionPath().toString();

                    String sss1=sss.replaceAll(", ", "/");
                    FilePath =sss1.replaceAll("//", "/");

                    FilePath = FilePath.replaceAll(object.toString(), "");
                    int i= FilePath.length();
                    FilePath = FilePath.substring(1,i-1);
                    System.out.println("选择文件为：" + FilePath +object.toString());
                }
            }
        });
    }



//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////
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



//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////FTP的整个登陆代码


    public  boolean Load(DefaultMutableTreeNode root,int res) {
        String  IP=A;
        String username=B;
        String password=C;
        int Port=Integer.parseInt(D);

        String path="/";
        boolean success = false;
        try {
            int Replay;
            ftp.setControlEncoding("gb2312");
            //  创建中文目录、上传中文文件名时，目录名及文件名中的中文显示乱码===================下面是关于乱码的一个大佬的自述=====
            //  网址为   https://blog.csdn.net/a772304419/article/details/79723249
/*
*        在网上Google了一些资料， FTP协议里面，规定文件名编码为iso-8859-1，所以目录名或文件名需要转码。
        所以网上很多人的解决方法为：
              将中文的目录或文件名转为iso-8859-1编码的字符。参考代码：
              String name="目录名或文件名";
              name=new String(name.getBytes("GBK"),"iso-8859-1");
       很多人改为上述操作后，发现上传后中文不再乱码了，就以为解决了问题
       还有人处理方法为：
             ftpClient.setControlEncoding("GBK");
             FTPClientConfig conf = new FTPClientConfig(FTPClientConfig.SYST_NT);
             conf.setServerLanguageCode("zh");
       上述的处理方法，我都试过，发现在我自己搭建的FTP服务器上，上传的文件中文是正常的，不是乱码，我当时以为中文问题就解决了，但是测试部的同事在将文件上传到他们搭建的FTP服务器上时，文件中文路径仍然是乱码，所以上述的解决方法是错误的。
      上面的方法之所以错误的原因是因为是没有考虑ftp服务器的编码格式。我搭建的Ftp服务器（windows2003 server）支持GBK编码方式，所以上述的解决方法可以，但是测试部的同事搭建的Ftp服务器（serv-u）是支持UTF-8格式的，所以此时在客户端的编码方式是GBK的，而搭设的ftp服务器中的设置就已经是utf-8的编码，所以肯定还是会出现乱码的问题。
     那么正确的解决方法时是什么呢，我们可以仿照FlashFXP、FileZilla等ftp 客户端连接工具。

* */


            ftp.setConnectTimeout(10*1000);                              //这里设置一下登陆超时的时间单位为ms
            try{
            ftp.setDefaultPort(Port);                                   //修改默认的ftp服务器的登陆端口
            ftp.connect(IP);                                           //连接FTP服务器
            ftp.login(username, password);                              //登录
            ftp.setFileType(FTPClient.BINARY_FILE_TYPE);
            Replay = ftp.getReplyCode();
            if (FTPReply.isPositiveCompletion(Replay)) {            //确定答复代码是否为肯定的完成答复
                Replay = ftp.getReplyCode();                             //此处是主目录，可以用JTree树将目录列表出来，而不必一级一级递归列出来
            }
            }catch(Exception eee) {
                JOptionPane.showMessageDialog(null,"登录超时！！！\n\t请检查网络状况或服务器地址后重新登录","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                return false;
            }
            list("/",root);
            success = true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        } finally {
            if (ftp.isConnected()) {
                int res1=res;
                if(res1 == 1){
                    JOptionPane.showMessageDialog(this, "登陆成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
                    System.out.println("ftp已连接！！！");
                }else if (res1==-1){
                    JOptionPane.showMessageDialog(this, "刷新完毕！！","Success",JOptionPane.INFORMATION_MESSAGE);
                    System.out.println("ftp已刷新！！！");
                }else if(res1==0){
                    System.out.println("ftp已自动刷新！！！");
                }

            }
        }
        return success;
    }
//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////FTP的整个刷新代码



    public  boolean Flush(DefaultMutableTreeNode root) {
        String  IP=A;
        String username=B;
        String password=C;
        int Port=Integer.parseInt(D);
        String path="/";
        boolean success = false;
        try {
            int reply;
            ftp.setControlEncoding("gb2312");
            ftp.setConnectTimeout(10*1000);                              //这里设置一下登陆超时的时间单位为ms
            try{
                ftp.setDefaultPort(Port);                                   //修改默认的ftp服务器的登陆端口
                ftp.connect(IP);                                           //连接FTP服务器
                ftp.login(username, password);                              //登录
                ftp.setFileType(FTPClient.BINARY_FILE_TYPE);
                reply = ftp.getReplyCode();
                if (FTPReply.isPositiveCompletion(reply)) {
                    reply = ftp.getReplyCode();                             //此处是主目录，可以用JTree树将目录列表出来，而不必一级一级递归列出来
                }
            }catch(Exception eee) {
                JOptionPane.showMessageDialog(null,"刷新超时！！！\n\t请检查网络链接超时，请重新登录","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                return false;
            }
            list("/",root);
            success = true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        } finally {
            if (ftp.isConnected()) {
                    JOptionPane.showMessageDialog(this, "刷新完毕！！","Success",JOptionPane.INFORMATION_MESSAGE);
                    System.out.println("已刷新！！！");
            }
        }
        return success;
    }

    @Override
    protected void processWindowEvent(WindowEvent e)
    {
        if(e.getID()==WindowEvent.WINDOW_CLOSING)
        {
            System.exit(0);
        }
    }
}
