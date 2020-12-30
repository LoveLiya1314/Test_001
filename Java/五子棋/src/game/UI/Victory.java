/*
 * Created by JFormDesigner on Mon Jun 22 20:27:41 CST 2020
 */

package game.UI;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.GroupLayout;
import javax.swing.border.*;

/**
 * @author Lambert
 */
public class Victory extends JDialog {
    public Victory() {
       // super();
        initComponents();
    }

    private void button1MouseClicked(MouseEvent e) {
        FiveChess.drawPanel.gamestart=false;
        FiveChess.drawPanel.repaint();
        setVisible(false);
        dispose();
        // TODO add your code here
    }

    private void button2MouseClicked(MouseEvent e) {
        FiveChess.drawPanel.restart();
        setVisible(false);
        dispose();
        // TODO add your code here
    }



    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        ResourceBundle bundle = ResourceBundle.getBundle("form");
        layeredPane1 = new JLayeredPane();
        label2 = new JLabel();
        button1 = new JButton();
        button2 = new JButton();

        //======== this ========
        if (FiveChess.drawPanel.IsBlack){
            setTitle("\u9ed1\u68cb\u80dc\u5229\u4e86\uff0c\u606d\u559c\u606d\u559c\uff01");
        }else {
            setTitle("\u767d\u68cb\u80dc\u5229\u4e86\uff0c\u606d\u559c\u606d\u559c\uff01");
        }
        setResizable(false);
        Container contentPane = getContentPane();

        //======== layeredPane1 ========
        {

            //---- label2 ----
            label2.setBorder(new EtchedBorder());
            label2.setIcon(new ImageIcon(getClass().getResource("/image/win2.jpg")));
            layeredPane1.add(label2, JLayeredPane.DEFAULT_LAYER);
            label2.setBounds(0, 0, 280, 260);

            //---- button1 ----
            button1.setText(bundle.getString("Victory.button1.text"));
            button1.setFont(new Font("\u6977\u4f53", Font.BOLD, 16));
            button1.setBorder(new EtchedBorder());
            button1.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    button1MouseClicked(e);
                }
            });
            layeredPane1.add(button1, JLayeredPane.DEFAULT_LAYER);
            button1.setBounds(0, 260, 135, 60);

            //---- button2 ----
            button2.setText(bundle.getString("Victory.button2.text"));
            button2.setFont(new Font("\u6977\u4f53", Font.BOLD, 16));
            button2.setBorder(new EtchedBorder());
            button2.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    button2MouseClicked(e);
                }
            });
            layeredPane1.add(button2, JLayeredPane.DEFAULT_LAYER);
            button2.setBounds(135, 260, 145, 60);
        }

        GroupLayout contentPaneLayout = new GroupLayout(contentPane);
        contentPane.setLayout(contentPaneLayout);
        contentPaneLayout.setHorizontalGroup(
            contentPaneLayout.createParallelGroup()
                .addComponent(layeredPane1, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 278, Short.MAX_VALUE)
        );
        contentPaneLayout.setVerticalGroup(
            contentPaneLayout.createParallelGroup()
                .addComponent(layeredPane1, GroupLayout.DEFAULT_SIZE, 318, Short.MAX_VALUE)
        );
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JLayeredPane layeredPane1;
    private JLabel label2;
    private JButton button1;
    private JButton button2;
    // JFormDesigner - End of variables declaration  //GEN-END:variables
}
