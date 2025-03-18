#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char* [height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' '; 
        }
    }
}



void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int dx = 0, dy = ray;
    int d = 3 - 2 * ray;
    while (dx <= dy) {
        SetPoint(x + dx, y + dy, ch);
        SetPoint(x - dx, y + dy, ch);
        SetPoint(x + dx, y - dy, ch);
        SetPoint(x - dx, y - dy, ch);
        SetPoint(x + dy, y + dx, ch);
        SetPoint(x - dy, y + dx, ch);
        SetPoint(x + dy, y - dx, ch);
        SetPoint(x - dy, y - dx, ch);
        if (d < 0) {
            d += 4 * dx + 6;
        }
        else {
            d += 4 * (dx - dy) + 10;
            dy--;
        }
        dx++;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = -ray; i <= ray; i++) {
        for (int j = -ray; j <= ray; j++) {
            if (i * i + j * j <= ray * ray) {
                SetPoint(x + i, y + j, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; i++) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx, sy;

    if (x1 < x2) 
        sx = 1;
    else
        sx = -1;

    if (y1 < y2) 
        sy = 1;
    else 
        sy = -1;

    int err = dx - dy, e2;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) 
        { 
            err -= dy; 
            x1 += sx; 
        }

        if (e2 < dx) 
        { 
            err += dx; 
            y1 += sy; 
        
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}
