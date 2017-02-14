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


void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2);
void Rectangle3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2, COLORREF Color);
void Scale();
void StartAll();
void Movement();

int main()
    {
    txCreateWindow(XWindowS, YWindowS);
    StartAll();
    }

void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2)
    {
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
    }

void Rectangle3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2, COLORREF Color)
    {
    txSetColor(Color, 5);
    Line3D(X1, Y1, Z1, X2, Y1, Z1); //верхнее переднее ребро
    Line3D(X1, Y1, Z2, X2, Y1, Z2); //верхнее заднее ребро
    Line3D(X1, Y1, Z1, X1, Y1, Z2); //верхнее левое ребро
    Line3D(X2, Y1, Z2, X2, Y1, Z1); //верхнее правое ребро
    Line3D(X1, Y1, Z2, X1, Y2, Z2); //дальнее левое ребро
    Line3D(X1, Y1, Z1, X1, Y2, Z1); //ближнее левое ребро
    Line3D(X1, Y2, Z1, X1, Y2, Z2); //нижнее левое ребро
    Line3D(X1, Y2, Z1, X2, Y2, Z1); //нижнее ближнее ребро
    Line3D(X1, Y2, Z2, X2, Y2, Z2); //нижнее дальнее ребро
    Line3D(X2, Y2, Z2, X2, Y2, Z1); //нижнее правое ребро
    Line3D(X2, Y2, Z2, X2, Y1, Z2); //дальнее правое ребро
    Line3D(X2, Y2, Z1, X2, Y1, Z1); //ближнее правое ребро
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


