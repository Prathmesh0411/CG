#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;

// Class for DDA Line Drawing
class Line {
public:
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        float Xinc = dx / (float)steps;
        float Yinc = dy / (float)steps;

        float X = x1;
        float Y = y1;

        for (int i = 0; i <= steps; i++) {
            putpixel(round(X), round(Y), WHITE);
            X += Xinc;
            Y += Yinc;
        }
    }
};

// Class for Bresenham’s Circle Drawing
class Circle {
public:
    void drawCircle(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;
        drawCirclePoints(xc, yc, x, y);
        while (y >= x) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else
                d = d + 4 * x + 6;
            drawCirclePoints(xc, yc, x, y);
        }
    }

private:
    void drawCirclePoints(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
};

// Main class that integrates the shapes
class Pattern {
    Line line;
    Circle circle;

public:
    void drawPattern() {
        // Draw Rectangle using DDA Line algorithm
        line.drawLine(200, 150, 400, 150);
        line.drawLine(400, 150, 400, 300);
        line.drawLine(400, 300, 200, 300);
        line.drawLine(200, 300, 200, 150);

        // Draw Circle using Bresenham's Circle algorithm
        circle.drawCircle(300, 225, 60);

        // Draw Diagonal lines for the diamond shape
        line.drawLine(200, 225, 300, 150);  // Top-left diagonal
        line.drawLine(300, 150, 400, 225);  // Top-right diagonal
        line.drawLine(400, 225, 300, 300);  // Bottom-right diagonal
        line.drawLine(300, 300, 200, 225);  // Bottom-left diagonal
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    Pattern pattern;
    pattern.drawPattern();

    getch();
    closegraph();
    return 0;
}
