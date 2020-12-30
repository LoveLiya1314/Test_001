/*
 * Created by JFormDesigner on Mon Jun 22 18:51:21 CST 2020
 */

package game.UI;

import java.awt.*;
import java.util.*;
import javax.swing.*;
import javax.swing.GroupLayout;
import javax.swing.border.*;

/**
 * @author Lambert
 */
public class About extends JDialog {
    public About(Window owner) {
        super(owner);
        initComponents();
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        ResourceBundle bundle = ResourceBundle.getBundle("form");
        panel1 = new JPanel();
        label1 = new JLabel();
        label2 = new JLabel();
        label3 = new JLabel();
        label4 = new JLabel();
        label5 = new JLabel();
        label6 = new JLabel();

        //======== this ========
        setTitle("\u5173\u4e8e");
        setModal(true);
        setResizable(false);
        Container contentPane = getContentPane();

        //======== panel1 ========
        {
            panel1.setBorder(new EtchedBorder());

            //---- label1 ----
            label1.setIcon(new ImageIcon(getClass().getResource("/image/000.jpg")));

            //---- label2 ----
            label2.setText(bundle.getString("About.label2.text"));
            label2.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

            //---- label3 ----
            label3.setText(bundle.getString("About.label3.text"));
            label3.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

            //---- label4 ----
            label4.setText(bundle.getString("About.label4.text"));
            label4.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

            //---- label5 ----
            label5.setText(bundle.getString("About.label5.text"));
            label5.setFont(new Font("\u6977\u4f53", Font.PLAIN, 16));

            //---- label6 ----
            label6.setText(bundle.getString("About.label6.text"));

            GroupLayout panel1Layout = new GroupLayout(panel1);
            panel1.setLayout(panel1Layout);
            panel1Layout.setHorizontalGroup(
                panel1Layout.createParallelGroup()
                    .addGroup(panel1Layout.createSequentialGroup()
                        .addComponent(label1)
                        .addGap(46, 46, 46)
                        .addGroup(panel1Layout.createParallelGroup()
                            .addComponent(label2, GroupLayout.DEFAULT_SIZE, 163, Short.MAX_VALUE)
                            .addComponent(label3, GroupLayout.DEFAULT_SIZE, 163, Short.MAX_VALUE)
                            .addComponent(label4, GroupLayout.DEFAULT_SIZE, 163, Short.MAX_VALUE)
                            .addComponent(label5, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 163, Short.MAX_VALUE)
                            .addComponent(label6, GroupLayout.DEFAULT_SIZE, 163, Short.MAX_VALUE)))
            );
            panel1Layout.setVerticalGroup(
                panel1Layout.createParallelGroup()
                    .addGroup(panel1Layout.createSequentialGroup()
                        .addGroup(panel1Layout.createParallelGroup(GroupLayout.Alignment.TRAILING)
                            .addGroup(panel1Layout.createSequentialGroup()
                                .addContainerGap(GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(label2, GroupLayout.PREFERRED_SIZE, 25, GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(label3, GroupLayout.PREFERRED_SIZE, 29, GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(label4, GroupLayout.PREFERRED_SIZE, 26, GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(label5, GroupLayout.PREFERRED_SIZE, 25, GroupLayout.PREFERRED_SIZE)
                                .addGap(24, 24, 24)
                                .addComponent(label6, GroupLayout.PREFERRED_SIZE, 23, GroupLayout.PREFERRED_SIZE))
                            .addComponent(label1))
                        .addGap(0, 0, Short.MAX_VALUE))
            );
        }

        GroupLayout contentPaneLayout = new GroupLayout(contentPane);
        contentPane.setLayout(contentPaneLayout);
        contentPaneLayout.setHorizontalGroup(
            contentPaneLayout.createParallelGroup()
                .addComponent(panel1, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        contentPaneLayout.setVerticalGroup(
            contentPaneLayout.createParallelGroup()
                .addGroup(GroupLayout.Alignment.TRAILING, contentPaneLayout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(panel1, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
        );
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JPanel panel1;
    private JLabel label1;
    private JLabel label2;
    private JLabel label3;
    private JLabel label4;
    private JLabel label5;
    private JLabel label6;
    // JFormDesigner - End of variables declaration  //GEN-END:variables
}
