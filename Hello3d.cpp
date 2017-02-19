#include "TXLib.h"

const int Zmin = -100;
const int XWindowS = GetSystemMetrics (SM_CXSCREEN);
const int YWindowS = GetSystemMetrics (SM_CYSCREEN);
double ZoomX = 5000;
double ZoomY = 5000;
double ZoomZ = 25;
double Vx = 0;
double Vy = 0;
double Vz = 0;
double A = 0;
double B = 0;
double C = 0;

void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2);
void Rectangle3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2, COLORREF Color);
void Scale();
void StartAll();
void Movement();
void Rotation();

int main()
    {
    txCreateWindow(XWindowS, YWindowS);
    StartAll();
    }

void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2)
    {
    double X1_old = X1, Y1_old = Y1, Z1_old = Z1;
    double X2_old = X2, Y2_old = Y2, Z2_old = Z2;

    Y1 = Z1_old * sin (A) + Y1_old * cos (A);
    Y2 = Z2_old * sin (A) + Y2_old * cos (A);
    Z1 = Z1_old * cos (A) - Y1_old * sin (A);
    Z2 = Z2_old * cos (A) - Y2_old * sin (A);

    Y1_old = Y1;
    Y2_old = Y2;
    Z1_old = Z1;
    Z2_old = Z2;

    Y1 = X1_old * sin (B) + Y1_old * cos (B);
    Y2 = X2_old * sin (B) + Y2_old * cos (B);
    X1 = X1_old * cos (B) - Y1_old * sin (B);
    X2 = X2_old * cos (B) - Y2_old * sin (B);

    X1_old = X1;
    X2_old = X2;

    Z1 = X1_old * sin (C) + Z1_old * cos (C);
    Z2 = X2_old * sin (C) + Z2_old * cos (C);
    X1 = X1_old * cos (C) - Z1_old * sin (C);
    X2 = X2_old * cos (C) - Z2_old * sin (C);

    X1 *= ZoomX;
    Y1 *= ZoomY;
    Z1 *= ZoomZ;
    X2 *= ZoomX;
    Y2 *= ZoomY;
    Z2 *= ZoomZ;

    X1 += Vx;
    Y1 += Vy;
    Z1 += Vz;
    X2 += Vx;
    Y2 += Vy;
    Z2 += Vz;

    txLine(X1/(Z1 - Zmin) + XWindowS/2, -Y1/(Z1 - Zmin) + YWindowS/2, X2/(Z2 - Zmin) + XWindowS/2, -Y2/(Z2 - Zmin) + YWindowS/2);

    X1_old = X1;
    Y1_old = Y1;
    Z1_old = Z1;
    X2_old = X2;
    Y2_old = Y2;
    Z2_old = Z2;
    }

void Rectangle3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2, COLORREF Color)
    {
    txSetColor(Color, 5);
    Line3D(X1, Y1, Z1, X2, Y1, Z1); //������� �������� �����
    Line3D(X1, Y1, Z2, X2, Y1, Z2); //������� ������ �����
    Line3D(X1, Y1, Z1, X1, Y1, Z2); //������� ����� �����
    Line3D(X2, Y1, Z2, X2, Y1, Z1); //������� ������ �����
    Line3D(X1, Y1, Z2, X1, Y2, Z2); //������� ����� �����
    Line3D(X1, Y1, Z1, X1, Y2, Z1); //������� ����� �����
    Line3D(X1, Y2, Z1, X1, Y2, Z2); //������ ����� �����
    Line3D(X1, Y2, Z1, X2, Y2, Z1); //������ ������� �����
    Line3D(X1, Y2, Z2, X2, Y2, Z2); //������ ������� �����
    Line3D(X2, Y2, Z2, X2, Y2, Z1); //������ ������ �����
    Line3D(X2, Y2, Z2, X2, Y1, Z2); //������� ������ �����
    Line3D(X2, Y2, Z1, X2, Y1, Z1); //������� ������ �����
    }

void Scale()
    {
    if(GetAsyncKeyState('1'))
        {
        ZoomX+= 5;
        ZoomY+= 5;
        ZoomZ+= 0.05;
        }
    if(GetAsyncKeyState('2'))
        {
        ZoomX-= 5;
        ZoomY-= 5;
        ZoomZ-= 0.05;
        }
    }

void StartAll()
    {
    while(!GetAsyncKeyState(VK_ESCAPE))
        {
        txBegin();
        txClear();
        Rotation();
        Scale();
        Movement();
        Rectangle3D(-2, 2, 2, 2, -2, -2, RGB(55, 43, 210));
        txEnd();
        }
    }

void Movement()
    {
    if(GetAsyncKeyState('W')) Vy+= 50;
    if(GetAsyncKeyState('A')) Vx-= 50;
    if(GetAsyncKeyState('S')) Vy-= 50;
    if(GetAsyncKeyState('D')) Vx+= 50;
    if(GetAsyncKeyState('Z')) Vz+= 0.5;
    if(GetAsyncKeyState('X')) Vz-= 0.5;
    if(GetAsyncKeyState('C'))
        {
        Vx = 0;
        Vy = 0;
        Vz = 0;
        }
    }

void Rotation()
    {
    if (GetAsyncKeyState (VK_LEFT)) C -= 0.01;
    if (GetAsyncKeyState (VK_RIGHT)) C += 0.01;
    if (GetAsyncKeyState ('M')) B -= 0.01;
    if (GetAsyncKeyState ('N')) B += 0.01;
    if (GetAsyncKeyState (VK_UP)) A -= 0.01;
    if (GetAsyncKeyState (VK_DOWN)) A += 0.01;
    }



