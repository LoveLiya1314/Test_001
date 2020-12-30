package game.UI;/*
import	java.awt.BorderLayout;
import	java.io.File;
import	java.awt.image.BufferedImage;
 * Created by JFormDesigner on Mon Jun 22 18:07:23 CST 2020
 */

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.GroupLayout;
import javax.swing.border.*;

/**
 * @author Lambert
 */
public class FiveChess extends JFrame {



    public static Checkerboard drawPanel= new Checkerboard();
    private boolean GameStart=false;
    static boolean get1=true;


    public FiveChess() {
        initComponents();
    }


    private void menu12MouseClicked(MouseEvent e) {
        About jd= new About(this);
        jd.setVisible(true);
        // TODO add your code here
    }

    private void menu10MouseClicked(MouseEvent e) {

        About jd= new About(this);
        jd.setVisible(true);
        // TODO add your code here
    }

    private void menu11MouseClicked(MouseEvent e) {
        int result =1;
        result=JOptionPane.showConfirmDialog(this,"这就不玩了？","认输",JOptionPane.YES_NO_OPTION);
        if (result == 0){
            JOptionPane.showMessageDialog(this,"\t客官慢走，不送。\n\t下次再与老夫大战三百回合！！！");
            System.exit(0);
        }else if (result == 1) {
            ;
        }

        // TODO add your code here
    }

    private void menu13MouseClicked(MouseEvent e) {
        int result =1;
        result=JOptionPane.showConfirmDialog(this,"\t全体注意，游戏开始！\n\t这不是演习！！！\n\t这不是演习！！！\n\t这不是演习！！！","谁敢与我决一死战？",JOptionPane.YES_NO_OPTION);
        if (result == 0){
            JOptionPane.showMessageDialog(this,"\t来，让我们大战一场！");
            drawPanel.gamestart =true;
            drawPanel.restart();
        }else if (result == 1) {
            JOptionPane.showMessageDialog(this,"\t下次再战。");;
        }
        // TODO add your code here
    }

    private void menu14MouseClicked(MouseEvent e) {
        int result =1;
        result=JOptionPane.showConfirmDialog(this,"这就结束了？","就这？",JOptionPane.YES_NO_OPTION);
        if (result == 0){
            JOptionPane.showMessageDialog(this,"\t哎呀呀呀！\t\n真是不行啊，这么快就结束了");
            drawPanel.gamestart=false;
            drawPanel.repaint();
        }else if (result == 1) {
            ;
        }

        // TODO add your code here
    }

    private void menu15MouseClicked(MouseEvent e) {
        JOptionPane.showMessageDialog(this,"打不过人家就悔棋，下次不跟你玩了！！！");
        if (drawPanel.IsBlack) {
            drawPanel.goback();
        }else {
            drawPanel.goback();
        }
        // TODO add your code here
    }


    private void menu1MouseClicked(MouseEvent e) {
         int result =1;
        result=JOptionPane.showConfirmDialog(this,"确定认输？","认输",JOptionPane.YES_NO_OPTION);
        if (result == 0){
            JOptionPane.showMessageDialog(this,"\t哎呀呀呀！\t\n真是不行啊，这么快就结束了");
            GameStart=true;
            drawPanel.GameOver=true;
        }else if (result == 1) {
            ;
        }
        // TODO add your code here
    }
private void aaaa(){
        drawPanel=new Checkerboard();
        this.setLayout(new BorderLayout());
        this.add(drawPanel,BorderLayout.CENTER);

}

private void menu8MouseClicked(MouseEvent e) {
        get1=true;
        drawPanel.repaint();
    // TODO add your code here
}

private void menu9MouseClicked(MouseEvent e) {
    get1=false;
    drawPanel.repaint();
    // TODO add your code here
}


    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        ResourceBundle bundle = ResourceBundle.getBundle("form");
        menuBar1 = new JMenuBar();
        menu5 = new JMenu();
        menu13 = new JMenu();
        menu15 = new JMenu();
        menu1 = new JMenu();
        menu14 = new JMenu();
        menu2 = new JMenu();
        menu8 = new JMenu();
        menu9 = new JMenu();
        menu3 = new JMenu();
        menu10 = new JMenu();
        menu11 = new JMenu();
        separator1 = new JPopupMenu.Separator();
        menu12 = new JMenu();
        layeredPane3 = new JLayeredPane();

        //======== this ========
        setTitle("\u4e94\u5b50\u68cb");
        setIconImage(new ImageIcon(getClass().getResource("/image/001.jpg")).getImage());
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();

        //======== menuBar1 ========
        {

            //======== menu5 ========
            {
                menu5.setText(bundle.getString("FiveChess.menu5.text_2"));
                menu5.setBorder(new EtchedBorder());
                menu5.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

                //======== menu13 ========
                {
                    menu13.setText(bundle.getString("FiveChess.menu13.text"));
                    menu13.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));
                    menu13.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu13MouseClicked(e);
                        }
                    });
                }
                menu5.add(menu13);

                //======== menu15 ========
                {
                    menu15.setText(bundle.getString("FiveChess.menu15.text"));
                    menu15.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));
                    menu15.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu15MouseClicked(e);
                        }
                    });
                }
                menu5.add(menu15);

                //======== menu1 ========
                {
                    menu1.setText(bundle.getString("FiveChess.menu1.text_2"));
                    menu1.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));
                    menu1.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu1MouseClicked(e);
                        }
                    });
                }
                menu5.add(menu1);

                //======== menu14 ========
                {
                    menu14.setText(bundle.getString("FiveChess.menu14.text"));
                    menu14.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));
                    menu14.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu14MouseClicked(e);
                        }
                    });
                }
                menu5.add(menu14);
            }
            menuBar1.add(menu5);

            //======== menu2 ========
            {
                menu2.setText(bundle.getString("FiveChess.menu2.text_2"));
                menu2.setBorder(new EtchedBorder());
                menu2.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

                //======== menu8 ========
                {
                    menu8.setText(bundle.getString("FiveChess.menu8.text_2"));
                    menu8.setFont(new Font("\u6977\u4f53", Font.PLAIN, 14));
                    menu8.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu8MouseClicked(e);
                        }
                    });
                }
                menu2.add(menu8);

                //======== menu9 ========
                {
                    menu9.setText(bundle.getString("FiveChess.menu9.text"));
                    menu9.setFont(new Font("\u6977\u4f53", Font.PLAIN, 14));
                    menu9.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu9MouseClicked(e);
                        }
                    });
                }
                menu2.add(menu9);
            }
            menuBar1.add(menu2);

            //======== menu3 ========
            {
                menu3.setText(bundle.getString("FiveChess.menu3.text_2"));
                menu3.setBorder(new EtchedBorder());
                menu3.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

                //======== menu10 ========
                {
                    menu10.setText(bundle.getString("FiveChess.menu10.text"));
                    menu10.setFont(new Font("\u6977\u4f53", Font.PLAIN, 14));
                    menu10.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu10MouseClicked(e);
                        }
                    });
                }
                menu3.add(menu10);

                //======== menu11 ========
                {
                    menu11.setText(bundle.getString("FiveChess.menu11.text_2"));
                    menu11.setFont(new Font("\u6977\u4f53", Font.PLAIN, 14));
                    menu11.addMouseListener(new MouseAdapter() {
                        @Override
                        public void mouseClicked(MouseEvent e) {
                            menu11MouseClicked(e);
                        }
                    });
                }
                menu3.add(menu11);
            }
            menuBar1.add(menu3);
            menuBar1.add(separator1);

            //======== menu12 ========
            {
                menu12.setText(bundle.getString("FiveChess.menu12.text_2"));
                menu12.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));
                menu12.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        menu12MouseClicked(e);
                    }
                });
            }
            menuBar1.add(menu12);
        }
        setJMenuBar(menuBar1);

        GroupLayout contentPaneLayout = new GroupLayout(contentPane);
        contentPane.setLayout(contentPaneLayout);
        contentPaneLayout.setHorizontalGroup(
            contentPaneLayout.createParallelGroup()
                .addGroup(contentPaneLayout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(layeredPane3, GroupLayout.PREFERRED_SIZE, 593, GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        contentPaneLayout.setVerticalGroup(
            contentPaneLayout.createParallelGroup()
                .addGroup(GroupLayout.Alignment.TRAILING, contentPaneLayout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(layeredPane3, GroupLayout.PREFERRED_SIZE, 474, GroupLayout.PREFERRED_SIZE))
        );
        aaaa();
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents


    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JMenuBar menuBar1;
    private JMenu menu5;
    private JMenu menu13;
    private JMenu menu15;
    private JMenu menu1;
    private JMenu menu14;
    private JMenu menu2;
    private JMenu menu8;
    private JMenu menu9;
    private JMenu menu3;
    private JMenu menu10;
    private JMenu menu11;
    private JPopupMenu.Separator separator1;
    private JMenu menu12;
    private JLayeredPane layeredPane3;
    // JFormDesigner - End of variables declaration  //GEN-END:variables

}


/*
class BjPanel extends JPanel
{
    Image im;
    public BjPanel()
    {
        im= Toolkit.getDefaultToolkit().getImage("背景.jpg");
        //需要注意的是如果用相对路径载入图片,则图片文件必须放在类文件所在文件夹或项目的根文件夹中,否则必须用绝对路径。
    }
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        int imWidth=image.getWidth(this);
        Int imHeight=image.getHeight(this); //定义图片的宽度、高度
        int FWidth=getWidth();
        int FHeight=getHeight();//定义窗口的宽度、高度
        int x=(FWidth-imWidth)/2;
        int y=(FHeight-imHeight)/2;//计算图片的坐标,使图片显示在窗口正中间
        g.drawImage(image,x,y,null);//绘制图片
    }
}*/
