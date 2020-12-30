package game.UI;

import game.res.ChessPieces;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Checkerboard extends JPanel implements MouseListener {
    public static final int MARGIN=30;
    public static final int GRID_SPAN = 35;
    public static final int ROWS=15;
    public static final int COLS=15;

    private int X_index,Y_index;
    boolean IsBlack=true;
    boolean GameOver=false;
    ChessPieces[] ChessList=new ChessPieces[(ROWS+1)*(COLS+1)];
    int ChessCount=0;
    boolean gamestart = false;




    public Checkerboard(){
        super();
        this.setBackground(Color.BLACK);
        this.repaint();
        this.setVisible(true);
        this.setOpaque(false);
        this.addMouseListener(this);
    }
    @Override
    public void paintComponent(Graphics g) {
        if (FiveChess.get1){
            super.paintComponent(g);
            ImageIcon img = new ImageIcon("D:\\CODE\\Java\\五子棋\\src\\image\\background001.jpg");
            g.drawImage(img.getImage(),0,0,null);
        }else {
            super.paintComponent(g);
            ImageIcon img = new ImageIcon("D:\\CODE\\Java\\五子棋\\src\\image\\background002.jpg");
            g.drawImage(img.getImage(),0,0,null);
        }

    }
    @Override
    public void paint(Graphics g){
        if (this.gamestart){
            super.paint(g);
            for (int i = 0; i <=ROWS; ++i) {
                g.drawLine(MARGIN,MARGIN+i*GRID_SPAN,MARGIN+COLS*GRID_SPAN,MARGIN+i*GRID_SPAN);
            }
            for (int i = 0; i <=COLS; ++i) {
                g.drawLine(MARGIN+i*GRID_SPAN,MARGIN,MARGIN+i*GRID_SPAN,MARGIN+GRID_SPAN*ROWS);
            }
            //画棋子
            for (int i = 0; i < ChessCount; ++i) {
                int XPos = ChessList[i].getX()*GRID_SPAN+MARGIN;
                int YPos = ChessList[i].getY()*GRID_SPAN+MARGIN;
                g.setColor(ChessList[i].getChessColor());
                g.fillOval(XPos-ChessPieces.CHESSPIECESSIZE/2,YPos-ChessPieces.CHESSPIECESSIZE/2,ChessPieces.CHESSPIECESSIZE,ChessPieces.CHESSPIECESSIZE);
                if (i==ChessCount-1){
                    g.setColor(Color.RED);
                    g.drawRect(XPos-ChessPieces.CHESSPIECESSIZE/2,YPos-ChessPieces.CHESSPIECESSIZE/2,ChessPieces.CHESSPIECESSIZE,ChessPieces.CHESSPIECESSIZE);
                }
            }
        }else {
        }


    }

    @Override
    //重写FiveChess窗口大小以适应棋盘
    public Dimension getPreferredSize() {
        return new Dimension(MARGIN*2+GRID_SPAN*COLS,MARGIN*2+GRID_SPAN*ROWS);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        X_index=( e.getX()-MARGIN+GRID_SPAN/2)/GRID_SPAN;
        Y_index=(e.getY()-MARGIN+GRID_SPAN/2)/GRID_SPAN;
        //System.out.println("\t"+X_index+"\t"+Y_index);
        //几种不能落子的情况
        if (GameOver){
            return;
        }
        if (X_index<0||X_index>COLS||Y_index<0||Y_index> ROWS){
            return;
        }
        if(find(X_index,Y_index)){
            return;
        }
        //落子,无悔。
        ChessPieces chesspieces=new ChessPieces(X_index,Y_index,IsBlack?Color.BLACK:Color.WHITE );
        ChessList[ChessCount++]=chesspieces;
        if (IsWin()){

            File file = new File("D:\\CODE\\Java\\五子棋\\src\\game\\res\\defeat.mp3");
            FileInputStream fis = null;
            try {
                fis = new FileInputStream(file);
            } catch (FileNotFoundException fileNotFoundException) {
                fileNotFoundException.printStackTrace();
            }
            BufferedInputStream stream = new BufferedInputStream(fis);
            Player player = null;
            try {
                player = new Player(stream);
            } catch (JavaLayerException javaLayerException) {
                javaLayerException.printStackTrace();
            }
            try {
                player.play();
            } catch (JavaLayerException javaLayerException) {
                javaLayerException.printStackTrace();
            }
            if (FiveChess.drawPanel.IsBlack){
                JOptionPane.showMessageDialog(this,"白棋输了！");
            }else {
                JOptionPane.showMessageDialog(this,"黑棋输了！");
            }
            Victory win=new Victory();
            win.setVisible(true);
            GameOver=true;
            File file1 = new File("D:\\CODE\\Java\\五子棋\\src\\game\\res\\win.mp3");
            FileInputStream fis1 = null;
            try {
                fis1 = new FileInputStream(file1);
            } catch (FileNotFoundException fileNotFoundException) {
                fileNotFoundException.printStackTrace();
            }
            BufferedInputStream stream1 = new BufferedInputStream(fis1);
            Player player1 = null;
            try {
                player1 = new Player(stream1);
            } catch (JavaLayerException javaLayerException) {
                javaLayerException.printStackTrace();
            }
            try {
                player1.play();
            } catch (JavaLayerException javaLayerException) {
                javaLayerException.printStackTrace();
            }


        }
        this.repaint();
        IsBlack=!IsBlack;

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
    private boolean find(int x, int y) {
        for (ChessPieces c:ChessList ){
            if (c!=null&&c.getX()== x && c.getY() == y) {
                return true;
            }
        }
        return false;
    }
    //胜利
    private boolean IsWin() {
        return getwin();
    }
    private ChessPieces getChessPieces(int x,int y,Color color) {
        //得到棋子
        for (ChessPieces c:ChessList){
            if(c!=null && c.getX() == x&&c.getY() == y &&c.getChessColor()==color) {
                return c;
            }
        }
        return null;
    }
    private boolean getwin() {
        int ContinueCount = 1;
        //横
        for (int x=X_index-1,y = Y_index;x>=0;x--){//向左
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        for (int x=X_index+1,y = Y_index;x<=ROWS;x++){//向右
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        if (ContinueCount>=5){
            return true;
        }else {
            ContinueCount=1;
        }
        //纵
        for (int x=X_index,y = Y_index-1;y>=0;y--){//向上
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        for (int x=X_index,y = Y_index+1;y<=ROWS;y++){//向下
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        if (ContinueCount>=5){
            return true;
        }else {
            ContinueCount=1;
        }
        //右斜
        for (int x=X_index+1,y = Y_index-1;x<=COLS&&y>=0;x++,y--){//右上
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        for (int x=X_index-1,y = Y_index+1;x>=0&&y<=ROWS;x--,y++){//左下
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        if (ContinueCount>=5){
            return true;
        }else {
            ContinueCount=1;
        }
        //左斜
        for (int x=X_index-1,y = Y_index-1;x>=0&&y>=0;x--,y--){//左上
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        for (int x=X_index+1,y = Y_index+1;x<=COLS&&y<=ROWS;x++,y++){//右下
            Color c=IsBlack?Color.BLACK:Color.WHITE;
            if (getChessPieces(x,y,c)!=null){
                ContinueCount++;
            }else {
                break;
            }
        }
        if (ContinueCount>=5){
            return true;
        }else {
            ContinueCount=1;
        }

        return false;
    }
    //开始or重开
    public void restart() {
        for (int x = 0; x <ChessList.length;x++ ){
            ChessList[x]=null;
        }
        IsBlack=true;
        GameOver=false;
        ChessCount=0;
        this.repaint();
    }

    //悔棋
    public void goback(){
        if(ChessCount==0) {
            return ;
        }
        ChessList[ChessCount-1]=null;
        ChessCount--;
        if(ChessCount>0){
            X_index=ChessList[ChessCount-1].getX();
            Y_index=ChessList[ChessCount-1].getY();
        }
        IsBlack=!IsBlack;
        repaint();
    }


}
