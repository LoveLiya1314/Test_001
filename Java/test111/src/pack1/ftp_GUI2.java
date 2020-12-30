package pack1;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;


public class ftp_GUI2 {

	private JFrame frame;
	public static JTextArea textArea;//文件列表框;
	private JTextField textField;
	public static JScrollPane jsc;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable(){
			public void run(){
				try {
					ftp_GUI2 window = new ftp_GUI2();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}	
			}
		});
	}
	public ftp_GUI2() {
		initialize();
	}

	private void initialize() {
		frame = new JFrame("FTP文件服务");
		frame.setBounds(600, 200, 441, 616);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblFtp = new JLabel("FTP\u5730\u5740\uFF1A");//FTP地址
		lblFtp.setBounds(43, 50, 72, 18);
		frame.getContentPane().add(lblFtp);
		
		JLabel label = new JLabel("\u7528\u6237\u540D\uFF1A");//用户名
		label.setBounds(43, 87, 72, 18);
		frame.getContentPane().add(lxabel);
		
		JLabel label_1 = new JLabel("\u5BC6\u7801\uFF1A");//密码
		label_1.setBounds(43, 127, 72, 18);
		frame.getContentPane().add(label_1);
		
		textField = new JTextField();
		textField.setText("192.168.159.130");
		textField.setBounds(109, 47, 152, 24);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setText("ftptest");
		textField_1.setBounds(109, 84, 152, 24);
		frame.getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setText("123456");
		textField_2.setBounds(109, 124, 152, 24);
		frame.getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		JButton button = new JButton("\u767B\u5F55");//登陆按钮
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//实现登陆验证的功能函数
				//如果验证正确就在列表里显示文件，如果验证错误就弹出对话框提示错误
				System.out.println(textField.getText());
				if(textField.getText().equals("") ||textField_1.getText().equals("")||textField_2.getText().equals("") )
				{
					//文本框为空
					JOptionPane.showMessageDialog(frame, "信息填写错误！","错误",JOptionPane.ERROR_MESSAGE);
				}
				else{
				String IP=textField.getText();//获取ftp服务器的地址
				String username=textField_1.getText();
				String password=textField_2.getText();
				//分别获取用户名和密码，用于登陆验证
				//创建JTree，将参数传入构造函数
				//此处需判断是否满足条件
				try {
					
				}
				JTree2 jtree=new JTree2(IP,username,password);			
				//设置显示目录的窗口视图
				jsc.setViewportView(jtree.jtree);		
				System.out.println("end");
				}	
			}
		});
		button.setBounds(301, 64, 90, 27);
		frame.getContentPane().add(button);
		
		JButton button_1 = new JButton("\u6CE8\u9500");//注销
		button_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			
				try {
					JTree2.ftp.disconnect();
					JOptionPane.showMessageDialog(frame, "注销成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		button_1.setBounds(301, 104, 90, 27);
		frame.getContentPane().add(button_1);
		
		JLabel lblFtp_1 = new JLabel("FTP\u6587\u4EF6\u5217\u8868\uFF1A");//FTP文件列表
		lblFtp_1.setBounds(29, 169, 119, 18);
		frame.getContentPane().add(lblFtp_1);
		
	    textArea = new JTextArea();//文件列表框
		
		jsc=new JScrollPane(textArea);jsc.setBounds(29, 203, 258, 287);
		frame.getContentPane().add(jsc);
		
		JButton button_3 = new JButton("\u5237\u65B0");//刷新
		button_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				
				String IP=textField.getText();//获取ftp服务器的地址
				String username=textField_1.getText();
				String password=textField_2.getText();
				//分别获取用户名和密码，用于登陆验证
				//创建JTree，将参数传入构造函数
				//此处需判断是否满足条件
				JTree2 jtree=new JTree2(IP,username,password);			
				//设置显示目录的窗口视图
				jsc.setViewportView(jtree.jtree);
			}
		});
		button_3.setBounds(319, 243, 90, 27);
		frame.getContentPane().add(button_3);
		JButton button_4 = new JButton("上传");//上传
		button_4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String lpath=textField_3.getText();
				
				String []sq=lpath.split("\\\\");int u=sq.length;
				
				String fn=sq[u-1];boolean ee=false;
				System.out.println(lpath+","+fn);
				try {
					ee=Upload.upload(lpath, fn);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				if(ee)
				{
					JOptionPane.showMessageDialog(frame, "文件上传成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
				}		
				
			}
		});
		button_4.setBounds(319, 317, 90, 27);
		frame.getContentPane().add(button_4);
		
		JButton button_2 = new JButton("下载");//下载
		button_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String localpath="D:/FTP客户端下载文件";//本地存放文件路径
				String downloadFileName=JTree2.ob;//存放目标文件名
				try {
					//参数文件在服务器上的路径
					System.out.println(downloadFileName);
					//解决路径问题
					boolean r=Download.download(JTree2.t,localpath,downloadFileName);//调用下载函数

					System.out.println(r);
					if(r){
						
						JOptionPane.showMessageDialog(frame, "文件下载成功！！","Success",JOptionPane.INFORMATION_MESSAGE);
					}
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		button_2.setBounds(319, 394, 90, 27);	
		frame.getContentPane().add(button_2);	
		
		JLabel label_2 = new JLabel("上传文件:");
		label_2.setBounds(24, 522, 91, 18);
		frame.getContentPane().add(label_2);
		
		textField_3 = new JTextField();
		textField_3.setBounds(95, 519, 178, 24);
		frame.getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		JButton button_5 = new JButton("选择");//选择
		
		button_5.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0) {
				//创建文件对话框，让用户选择保存的位置路径
				JFileChooser chooser=new JFileChooser("D:\\");//创建对话框对象
				chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
				//chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);//设定选择为文件夹
				int r=chooser.showOpenDialog(frame);
				if(r==JFileChooser.APPROVE_OPTION){
					textField_3.setText(chooser.getSelectedFile().getAbsolutePath());//得到选择的本地路径
				}																
			}		
		});
		button_5.setBounds(287, 518, 90, 27);
		
		frame.getContentPane().add(button_5);
	}
}
