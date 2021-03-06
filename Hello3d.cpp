#include "TXLib.h"

const int XWindowS = GetSystemMetrics (SM_CXSCREEN);
const int YWindowS = GetSystemMetrics (SM_CYSCREEN);
double ZoomX = 50000, ZoomY = 50000, ZoomZ = 500;
double Vx = 0, Vy = 0, Vz = 45000;
double A = 0, B = 0, C = 0;

//void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2);
void Line3D (double x1, double y1, double z1, double x2, double y2, double z2);
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

/*void Line3D(int X1, int Y1, int Z1, int X2, int Y2, int Z2)
    {
    double X1_old = X1, Y1_old = Y1, Z1_old = Z1;
    double X2_old = X2, Y2_old = Y2, Z2_old = Z2;

    Y1 = Z1_old * sin (A) + Y1_old * cos (A);
   Y2 = Z2_old * sin (A) + Y2_old * cos (A);
    Z1 = Z1_old * cos (A) - Y1_old * sin (A);
    Z2 = Z2_old * cos (A) - Y2_old * sin (A);

    X1_old = X1;
    X2_old = X2;
    Y1_old = Y1;
    Y2_old = Y2;
    Z1_old = Z1;
    Z2_old = Z2;

   X1 = X1_old * cos (B) - Y1_old * sin (B);
    X2 = X2_old * cos (B) - Y2_old * sin (B);
    Y1 = X1_old * sin (B) + Y1_old * cos (B);
   Y2 = X2_old * sin (B) + Y2_old * cos (B);

    X1_old = X1;
    X2_old = X2;
    Y1_old = Y1;
    Y2_old = Y2;
    Z1_old = Z1;
    Z2_old = Z2;

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

    const int Zmin = -100;
    txLine(X1/(Z1 - Zmin) + XWindowS/2, -Y1/(Z1 - Zmin) + YWindowS/2, X2/(Z2 - Zmin) + XWindowS/2, -Y2/(Z2 - Zmin) + YWindowS/2);

    X1_old = X1;
    Y1_old = Y1;
    Z1_old = Z1;
    X2_old = X2;
    Y2_old = Y2;
    Z2_old = Z2;
    }   */

void Line3D (double x1, double y1, double z1, double x2, double y2, double z2)
{
double x1_old = x1, y1_old = y1, z1_old = z1;
double x2_old = x2, y2_old = y2, z2_old = z2;

y1 = z1_old * sin (A) + y1_old * cos (A);
y2 = z2_old * sin (A) + y2_old * cos (A);
z1 = z1_old * cos (A) - y1_old * sin (A);
z2 = z2_old * cos (A) - y2_old * sin (A);

y1_old = y1;
y2_old = y2;
z1_old = z1;
z2_old = z2;

y1 = x1_old * sin (B) + y1_old * cos (B);
y2 = x2_old * sin (B) + y2_old * cos (B);
x1 = x1_old * cos (B) - y1_old * sin (B);
x2 = x2_old * cos (B) - y2_old * sin (B);

x1_old = x1;
x2_old = x2;

z1 = x1_old * sin (C) + z1_old * cos (C);
z2 = x2_old * sin (C) + z2_old * cos (C);
x1 = x1_old * cos (C) - z1_old * sin (C);
x2 = x2_old * cos (C) - z2_old * sin (C);

x1 *= ZoomX;
y1 *= ZoomY;
z1 *= ZoomZ;

x2 *= ZoomX;
y2 *= ZoomY;
z2 *= ZoomZ;

x1 += Vx;
y1 += Vy;
z1 += Vz;

x2 += Vx;
y2 += Vy;
z2 += Vz;
double zmin = -100;
txLine ((x1)/(z1 - zmin) + XWindowS / 2, YWindowS / 2 - (y1)/(z1 - zmin), XWindowS / 2 + (x2)/(z2 - zmin), YWindowS / 2 - (y2)/(z2 - zmin));

x1_old = x1;
y1_old = y1;
z1_old = z1;
x2_old = x2;
y2_old = y2;
z2_old = z2;
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
        Rectangle3D(20, 20, 20, -20, -20, -20, RGB(55, 43, 210));
        txEnd();
        }
    }

void Movement()
    {
    if(GetAsyncKeyState('W')) Vy+= 10000;
    if(GetAsyncKeyState('A')) Vx-= 10000;
    if(GetAsyncKeyState('S')) Vy-= 10000;
    if(GetAsyncKeyState('D')) Vx+= 10000;
    if(GetAsyncKeyState('Z')) Vz+= 5;
    if(GetAsyncKeyState('X')) Vz-= 5;
    if(GetAsyncKeyState('C'))
        {
        Vx = 0;
        Vy = 0;
        Vz = 0;
        }
    }

void Rotation()
    {
    if (GetAsyncKeyState (VK_LEFT)) C -= 0.02;
    if (GetAsyncKeyState (VK_RIGHT)) C += 0.02;
    if (GetAsyncKeyState ('M')) B -= 0.02;
    if (GetAsyncKeyState ('N')) B += 0.02;
    if (GetAsyncKeyState (VK_UP)) A -= 0.02;
    if (GetAsyncKeyState (VK_DOWN)) A += 0.02;
    }



