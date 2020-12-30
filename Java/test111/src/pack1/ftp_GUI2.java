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
	public static JTextArea textArea;//�ļ��б��;
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
		frame = new JFrame("FTP�ļ�����");
		frame.setBounds(600, 200, 441, 616);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblFtp = new JLabel("FTP\u5730\u5740\uFF1A");//FTP��ַ
		lblFtp.setBounds(43, 50, 72, 18);
		frame.getContentPane().add(lblFtp);
		
		JLabel label = new JLabel("\u7528\u6237\u540D\uFF1A");//�û���
		label.setBounds(43, 87, 72, 18);
		frame.getContentPane().add(lxabel);
		
		JLabel label_1 = new JLabel("\u5BC6\u7801\uFF1A");//����
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
		
		JButton button = new JButton("\u767B\u5F55");//��½��ť
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//ʵ�ֵ�½��֤�Ĺ��ܺ���
				//�����֤��ȷ�����б�����ʾ�ļ��������֤����͵����Ի�����ʾ����
				System.out.println(textField.getText());
				if(textField.getText().equals("") ||textField_1.getText().equals("")||textField_2.getText().equals("") )
				{
					//�ı���Ϊ��
					JOptionPane.showMessageDialog(frame, "��Ϣ��д����","����",JOptionPane.ERROR_MESSAGE);
				}
				else{
				String IP=textField.getText();//��ȡftp�������ĵ�ַ
				String username=textField_1.getText();
				String password=textField_2.getText();
				//�ֱ��ȡ�û��������룬���ڵ�½��֤
				//����JTree�����������빹�캯��
				//�˴����ж��Ƿ���������
				try {
					
				}
				JTree2 jtree=new JTree2(IP,username,password);			
				//������ʾĿ¼�Ĵ�����ͼ
				jsc.setViewportView(jtree.jtree);		
				System.out.println("end");
				}	
			}
		});
		button.setBounds(301, 64, 90, 27);
		frame.getContentPane().add(button);
		
		JButton button_1 = new JButton("\u6CE8\u9500");//ע��
		button_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			
				try {
					JTree2.ftp.disconnect();
					JOptionPane.showMessageDialog(frame, "ע���ɹ�����","Success",JOptionPane.INFORMATION_MESSAGE);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		button_1.setBounds(301, 104, 90, 27);
		frame.getContentPane().add(button_1);
		
		JLabel lblFtp_1 = new JLabel("FTP\u6587\u4EF6\u5217\u8868\uFF1A");//FTP�ļ��б�
		lblFtp_1.setBounds(29, 169, 119, 18);
		frame.getContentPane().add(lblFtp_1);
		
	    textArea = new JTextArea();//�ļ��б��
		
		jsc=new JScrollPane(textArea);jsc.setBounds(29, 203, 258, 287);
		frame.getContentPane().add(jsc);
		
		JButton button_3 = new JButton("\u5237\u65B0");//ˢ��
		button_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				
				String IP=textField.getText();//��ȡftp�������ĵ�ַ
				String username=textField_1.getText();
				String password=textField_2.getText();
				//�ֱ��ȡ�û��������룬���ڵ�½��֤
				//����JTree�����������빹�캯��
				//�˴����ж��Ƿ���������
				JTree2 jtree=new JTree2(IP,username,password);			
				//������ʾĿ¼�Ĵ�����ͼ
				jsc.setViewportView(jtree.jtree);
			}
		});
		button_3.setBounds(319, 243, 90, 27);
		frame.getContentPane().add(button_3);
		JButton button_4 = new JButton("�ϴ�");//�ϴ�
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
					JOptionPane.showMessageDialog(frame, "�ļ��ϴ��ɹ�����","Success",JOptionPane.INFORMATION_MESSAGE);
				}		
				
			}
		});
		button_4.setBounds(319, 317, 90, 27);
		frame.getContentPane().add(button_4);
		
		JButton button_2 = new JButton("����");//����
		button_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String localpath="D:/FTP�ͻ��������ļ�";//���ش���ļ�·��
				String downloadFileName=JTree2.ob;//���Ŀ���ļ���
				try {
					//�����ļ��ڷ������ϵ�·��
					System.out.println(downloadFileName);
					//���·������
					boolean r=Download.download(JTree2.t,localpath,downloadFileName);//�������غ���

					System.out.println(r);
					if(r){
						
						JOptionPane.showMessageDialog(frame, "�ļ����سɹ�����","Success",JOptionPane.INFORMATION_MESSAGE);
					}
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		button_2.setBounds(319, 394, 90, 27);	
		frame.getContentPane().add(button_2);	
		
		JLabel label_2 = new JLabel("�ϴ��ļ�:");
		label_2.setBounds(24, 522, 91, 18);
		frame.getContentPane().add(label_2);
		
		textField_3 = new JTextField();
		textField_3.setBounds(95, 519, 178, 24);
		frame.getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		JButton button_5 = new JButton("ѡ��");//ѡ��
		
		button_5.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0) {
				//�����ļ��Ի������û�ѡ�񱣴��λ��·��
				JFileChooser chooser=new JFileChooser("D:\\");//�����Ի������
				chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
				//chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);//�趨ѡ��Ϊ�ļ���
				int r=chooser.showOpenDialog(frame);
				if(r==JFileChooser.APPROVE_OPTION){
					textField_3.setText(chooser.getSelectedFile().getAbsolutePath());//�õ�ѡ��ı���·��
				}																
			}		
		});
		button_5.setBounds(287, 518, 90, 27);
		
		frame.getContentPane().add(button_5);
	}
}
