package game.res;

import java.awt.*;

public class ChessPieces {
    private int x;
    private int y;
    private Color ChessColor;
    public static final int CHESSPIECESSIZE=30;

    public ChessPieces(int x, int y, Color chessColor) {
        this.x = x;
        this.y = y;
        this.ChessColor = chessColor;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Color getChessColor() {
        return ChessColor;
    }

    public void setChessColor(Color chessColor) {
        ChessColor = chessColor;
    }
}
