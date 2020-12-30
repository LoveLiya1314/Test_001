package Test001;

import ServerUDP.UDPFileClient;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.*;
//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
/*
* button_Load       ------  是登陆的按钮
* button_1          ------  是注销的按钮
* button_Flush      ------  是刷新的按钮
* button_Upload     ------  是上传的按钮
* button_Download   ------  是下载的按钮
* button_ChoseFile  ------  是选择文件的按钮
* button_Delete     ------  是删除文件的按钮
* */

public class File_UI {

    public static int DataChanged;              //


    public JFrame frame;                                //这个是主窗体
    public static JTextArea textArea_FileTree;          //这个是文件列表框;
    private JTextField textField_FTP_IP;                //IP地址动态文本框
    public static JScrollPane File_Screen;              //文件列表的滚动面板
    private JTextField textField_User;                  //用户
    private JTextField textField_Passwd;                //密码
    private JTextField textField_FilePath;              //上传文件时的本地文件路径
    private JTextField textField_Port;                  //端口号
    private JTextField textField_Port_UDP;
    protected boolean ConnectSucceed=false;


    public File_UI() {
        initialize();
    }

    private void initialize() {
        frame = new JFrame("文件传输");                                          //主窗体的标题以及出现的大小及其位置+相关设置
        frame.setBounds(600, 200, 441, 716);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);
        frame.setResizable(false);

        JLabel lblFtpPort = new JLabel("端口");                                    //FTP地址的那个静态文本框
        lblFtpPort.setBounds(43, 17, 72, 18);
        frame.getContentPane().add(lblFtpPort);

        JLabel lblFtp = new JLabel("地址");                                    //FTP地址的那个静态文本框
        lblFtp.setBounds(43, 50, 72, 18);
        frame.getContentPane().add(lblFtp);

        JLabel label = new JLabel("登陆用户名");                                   //用户名的哪个静态文本框
        label.setBounds(43, 87, 72, 18);
        frame.getContentPane().add(label);

        JLabel label_1 = new JLabel("密码");                                     //密码的那个静态文本框
        label_1.setBounds(43, 127, 72, 18);
        frame.getContentPane().add(label_1);

        textField_Port = new JTextField();
        textField_Port.setText("21");                                                           //填写FTP登陆端口的一个动态文本框，默认为21
        textField_Port.setBounds(109, 17, 28, 20);
        frame.getContentPane().add(textField_Port);
        textField_Port.setColumns(10);

        textField_Port_UDP = new JTextField();
        textField_Port_UDP.setText("23333");                                                           //填写UDP端口的一个动态文本框，默认为23333
        textField_Port_UDP.setBounds(144, 17, 40, 20);
        frame.getContentPane().add(textField_Port_UDP);
        textField_Port_UDP.setColumns(10);

        textField_FTP_IP = new JTextField();
        textField_FTP_IP.setText("192.168.159.130");                                           //填写FTP地址的一个动态文本框，默认为192.168.159.130
        textField_FTP_IP.setBounds(109, 47, 152, 24);
        frame.getContentPane().add(textField_FTP_IP);
        textField_FTP_IP.setColumns(10);

        textField_User = new JTextField();
        textField_User.setText("ftptest");                                                 //填写FTP登陆用户的一个动态文本框，默认为ftptest
        textField_User.setBounds(109, 84, 152, 24);
        frame.getContentPane().add(textField_User);
        textField_User.setColumns(10);

        textField_Passwd = new JPasswordField();
        textField_Passwd.setText("123456");                                                  //填写FTP登陆用户密码的一个动态密码文本框，默认为123456，并且隐藏密码
        textField_Passwd.setBounds(109, 124, 152, 24);
        frame.getContentPane().add(textField_Passwd);
        textField_Passwd.setColumns(10);

        JLabel label_2 = new JLabel("上传文件:");
        label_2.setBounds(24, 640, 91, 18);
        frame.getContentPane().add(label_2);

        textField_FilePath = new JTextField();
        textField_FilePath.setBounds(84, 640, 222, 24);
        frame.getContentPane().add(textField_FilePath);
        textField_FilePath.setColumns(10);

        //获取ftp服务器的端口，IP，用户名，密码++++++++++QAQ
        String Port=textField_Port.getText();
        String IP= textField_FTP_IP.getText();
        String username= textField_User.getText();
        String password=textField_Passwd.getText();
//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////登陆
        JButton button_Load = new JButton("登陆");
        button_Load.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {                                                                //实现登陆验证的功能函数
                                                                                                                        //如果验证正确就在列表里显示文件，如果验证错误就弹出对话框提示错误
                System.out.println(textField_FTP_IP.getText());
                DataChanged=1;
                if(textField_FTP_IP.getText().equals("")){
                    JOptionPane.showMessageDialog(frame, "信息填写错误！","错误",JOptionPane.ERROR_MESSAGE);
                }
                if(textField_FTP_IP.getText().equals("") || textField_User.getText().equals("")||textField_Passwd.getText().equals("") )
                {                                                                                                       //文本框为空
                    JOptionPane.showMessageDialog(frame, "信息填写错误！","错误",JOptionPane.ERROR_MESSAGE);
                }
                else{
                   try {
                       File_Tree jtree=new File_Tree(IP,username,password, Port,DataChanged);
                       File_Screen.setViewportView(jtree.jtree);
                       System.out.println("end");
                    }
                    catch (Exception e1){
                        JOptionPane.showMessageDialog(frame, "IP地址填写错误！","错误",JOptionPane.ERROR_MESSAGE);
                        JOptionPane.showMessageDialog(frame,"用户名或密码填写错误！","错误",JOptionPane.ERROR_MESSAGE);
                    }
                    ConnectSucceed=true;
                }
            }
        });
        button_Load.setBounds(301, 64, 90, 27);
        frame.getContentPane().add(button_Load);

//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////注销按钮的实现
        JButton button_1 = new JButton("注销");
        button_1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(ConnectSucceed){
                    try {
                        File_Tree.ftp.disconnect();
                        JOptionPane.showMessageDialog(frame, "注销成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
                    } catch (IOException e1) {
                        // TODO Auto-generated catch block
                        e1.printStackTrace();
                    }
                    ConnectSucceed=false;
                }else{
                    JOptionPane.showMessageDialog(frame, "请先登陆！！！","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }
//                File_Screen.updateUI();
//                File_Screen.invalidate();
//                File_Screen.validate();
//                File_Screen.repaint();
                //==========================刷新文本框，但似乎不起作用，打个注释吧==================QAQ
                }

        });
        button_1.setBounds(301, 104, 90, 27);
        frame.getContentPane().add(button_1);

        JLabel lblFtp_1 = new JLabel("文件列表：");                                               //FTP文件列表
        lblFtp_1.setBounds(29, 169, 119, 18);
        frame.getContentPane().add(lblFtp_1);

        textArea_FileTree = new JTextArea();                                                            //文件列表框

        File_Screen =new JScrollPane(textArea_FileTree);                                                //文件的遍历输出框
        File_Screen.setBounds(29, 203, 260, 433);
        frame.getContentPane().add(File_Screen);

//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////刷新按钮的相关实现
                                                                                                    //根据重新登陆来实现刷新
        JButton button_Flush = new JButton("刷新");
        button_Flush.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DataChanged=-1;
                if (ConnectSucceed){
                    File_Tree jtree=new File_Tree(IP,username,password,Port,DataChanged);
                    File_Screen.setViewportView(jtree.jtree);
                }else{
                    JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }

            }
        });
        button_Flush.setBounds(319, 243, 90, 27);
        frame.getContentPane().add(button_Flush);

//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////上传按钮的相关配置

        JButton button_Upload = new JButton("上传");
        button_Upload.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DataChanged=0;
                if(ConnectSucceed){
                    String LocalPath=null;
                    String Path= File_Tree.FilePath;
                    LocalPath= textField_FilePath.getText();                                            //从文件选择框中获取路径
                    if ( LocalPath.length()==0){
                        JOptionPane.showMessageDialog(null, "\t错误！！！\n\t未指定上传文件！！！","ERROR",JOptionPane.INFORMATION_MESSAGE);
                    }
                    String []sq=LocalPath.split("\\\\");                                         //根据\\来划分字符，Windows系统下资源管理器的文件路径中子文件和父文件是以\\来划分的
                    int u=sq.length;
                    String Name=sq[u-1];
                    boolean Res=false;
                    System.out.println(LocalPath+","+Name);
                    Res=Upload.upload(LocalPath, Name,Path);
                    if(Res)
                    {
                        JOptionPane.showMessageDialog(frame, "文件上传成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
                    }else{
                        JOptionPane.showMessageDialog(frame, "文件上传失败！！！\n请检查网络后再上传！！！","ERROR！！！",JOptionPane.INFORMATION_MESSAGE);
                    }
                    File_Tree jtree=new File_Tree(IP,username,password, Port,DataChanged);
                    File_Screen.setViewportView(jtree.jtree);
                }else{
                    JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }


            }
        });
        button_Upload.setBounds(319, 317, 90, 27);
        frame.getContentPane().add(button_Upload);

//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////下载窗口的有关设置
        JButton button_Download = new JButton("下载");
        button_Download.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (ConnectSucceed){
                    String localpath="D:/CODE/Java/FTP/src";//本地存放文件路径，设置为当前Java文件编写位置
                    String downloadFileName= File_Tree.FileName;//存放目标文件名

                        //参数文件在服务器上的路径
                        System.out.println(downloadFileName);
                        //解决路径问题
                        boolean r=Download.download(File_Tree.FilePath,localpath,downloadFileName);//调用下载函数

                        System.out.println(r);
                        if(r){

                            JOptionPane.showMessageDialog(frame, "文件下载成功！！！\n文件已下载到D:\\CODE\\Java\\FTP\\src","Success",JOptionPane.INFORMATION_MESSAGE);
                        }
                        else{
                            JOptionPane.showMessageDialog(frame, "ERROR!!!","False",JOptionPane.INFORMATION_MESSAGE);
                        }

                }else{
                    JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }

            }
        });
        button_Download.setBounds(319, 394, 90, 27);
        frame.getContentPane().add(button_Download);



//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////选择
        JButton button_ChoseFile = new JButton("选择");
        button_ChoseFile.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0) {
                if(ConnectSucceed){
                    //创建文件对话框，让用户选择保存的位置路径
                    JFileChooser chooser=new JFileChooser("D:\\");                  //创建对话框对象
                    chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
                    //chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);                   //设定选择为文件夹
                    int r=chooser.showOpenDialog(frame);
                    if(r==JFileChooser.APPROVE_OPTION){
                        textField_FilePath.setText(chooser.getSelectedFile().getAbsolutePath());     //得到选择的本地路径
                    }
                }else{
                    JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }

            }
        });
        button_ChoseFile.setBounds(317, 639, 90, 27);
        frame.getContentPane().add(button_ChoseFile);



//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////UDP
        JButton button_UDP = new JButton("UDP");
        button_UDP.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e1){
               String IP=textField_FTP_IP.getText();
               int port= Integer.parseInt(textField_Port_UDP.getText());
               DataChanged=0;
               if(ConnectSucceed){
                   String LocalPath=null;
                   LocalPath= textField_FilePath.getText();                                            //从文件选择框中获取路径
                   if ( LocalPath.length()==0){
                       JOptionPane.showMessageDialog(null, "\t错误！！！\n\t未指定上传文件！！！","ERROR",JOptionPane.INFORMATION_MESSAGE);
                   }
                   String []sq=LocalPath.split("\\\\");                                         //根据\\来划分字符，Windows系统下资源管理器的文件路径中子文件和父文件是以\\来划分的
                   int u=sq.length;
                   String Local_Path=LocalPath.replace(sq[u-1],"");
                   String Name=sq[u-1];
                   boolean Res=false;
                   System.out.println(Local_Path+Name);
                   Res= UDPFileClient.UDPFileClient(IP,port,LocalPath, Name);
                   if(Res)
                   {
                       JOptionPane.showMessageDialog(frame, "文件上传成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
                   }else{
                       JOptionPane.showMessageDialog(frame, "文件上传失败！！！\n请检查网络后再上传！！！","ERROR！！！",JOptionPane.INFORMATION_MESSAGE);
                   }
                   File_Tree jtree=new File_Tree(IP,username,password, Port,DataChanged);
                   File_Screen.setViewportView(jtree.jtree);
               }else{
                   JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
               }

           }
        });
        button_UDP.setBounds(319, 444, 90, 27);
        frame.getContentPane().add(button_UDP);



//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////删除
        JButton button_Delete =new JButton("删除");
        button_Delete.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                DataChanged=0;
                if (ConnectSucceed){
                    String DeleteFileName= File_Tree.FileName;                                          //目标文件路径
                    String DeleteFilePath= File_Tree.FilePath;                                           //目标文件名称
                    try {
                        //参数文件在服务器上的路径
                        System.out.println(DeleteFileName);
                                                                                                //解决路径问题
                        boolean res=Remove.Remove(DeleteFilePath,DeleteFileName, File_Tree.ftp);                 //调用下载函数
                        System.out.println(res);
                        if(res){
                            JOptionPane.showMessageDialog(frame, "文件删除成功！！！","Success",JOptionPane.INFORMATION_MESSAGE);
                        }
                        else{
                            JOptionPane.showMessageDialog(frame, "ERROR!!!","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                        }
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                    File_Tree jtree=new File_Tree(IP,username,password, Port,DataChanged);
                    File_Screen.setViewportView(jtree.jtree);
                }else{
                    JOptionPane.showMessageDialog(frame,"请先登陆","ERROR!!!",JOptionPane.INFORMATION_MESSAGE);
                }

            }
        });
        button_Delete.setBounds(319, 555, 90, 27);
        frame.getContentPane().add(button_Delete);
    }




//===================================================================================================================================
// ===================================================================================================================================
//===================================================================================================================================
////结束了啊！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

}
