package game;

import java.io.*;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;



public class Voice {
    static Player player = null;
    public void PlayWin() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    File file = new File("D:\\CODE\\Java\\五子棋\\src\\game\\res\\win.mp3");
                    FileInputStream fis = new FileInputStream(file);
                    BufferedInputStream stream = new BufferedInputStream(fis);
                    player = new Player(stream);
                    player.play();
                } catch (Exception e) {

                    // TODO: handle exception
                }
            }
        }).start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        player.close();
    }
    public void PlayDefault() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    File file = new File("D:\\CODE\\Java\\五子棋\\src\\game\\res\\defeat.mp3");
                    FileInputStream fis = new FileInputStream(file);
                    BufferedInputStream stream = new BufferedInputStream(fis);
                    player = new Player(stream);
                    player.play();
                } catch (Exception e) {

                    // TODO: handle exception
                }
            }
        }).start();
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        player.close();
    }
}

