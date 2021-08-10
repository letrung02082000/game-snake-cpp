#include <iostream>
#include "mylib.h"
#define MAX 100

using namespace std;

int so_luong = 10;

void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();

void khoi_tao_ran(int toa_do_X[], int toa_do_Y[], int x, int y);
void ve_ran(int toa_do_X[], int toa_do_Y[]);
void xu_ly_ran(int toa_do_X[], int toa_do_Y[], int x, int y);
void xoa_ran(int toa_do_X[], int toa_do_Y[]);
void tao_qua(int& xqua, int& yqua);

bool kiem_tra_cham_duoi(int toa_do_X[], int toa_do_Y[]);
bool kiem_tra_cham_tuong(int toa_do_X[], int toa_do_Y[]);
bool kiem_tra(int toa_do_X[], int toa_do_Y[]);

void them(int a[], int idx, int x);
void xoa(int a[], int idx);

int main()
{
    srand(time(NULL));

    int xqua, yqua;
    int toadoX[MAX];
    int toadoY[MAX];
    int x = 50, y = 13;
    int check = 2;
    bool game_over = false;

    ve_tuong();
    khoi_tao_ran(toadoX, toadoY, x, y);
    ve_ran(toadoX, toadoY);
    tao_qua(xqua, yqua);

    while (game_over == false)
    {
        xoa_ran(toadoX, toadoY);

        //Dieu khien
        if (_kbhit())
        {
            char ki_tu = _getch();

            if (ki_tu == -32)
            {
                ki_tu = _getch();

                if (ki_tu == 72 && check != 0) //di len
                {
                    check = 1;
                }
                else if (ki_tu == 80 && check != 1) //di xuong
                {
                    check = 0;
                }
                else if (ki_tu == 77 && check != 3) //qua phai
                {
                    check = 2;
                }
                else if (ki_tu == 75 && check != 2) //qua trai
                {
                    check = 3;
                }
            }
        }

        //Xu ly huong
        if (check == 0)
        {
            y++;
        }
        else if (check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            x--;
        }

        xu_ly_ran(toadoX, toadoY, x, y);

        game_over = kiem_tra(toadoX, toadoY);
        
        Sleep(300);
    }

    _getch();
    return 0;
}

void xu_ly_ran(int toa_do_X[], int toa_do_Y[], int x, int y)
{
    //Them toa do vao dau mang
    them(toa_do_X, 0, x);
    them(toa_do_Y, 0, y);

    //Xoa toa do cuoi mang
    xoa(toa_do_X, so_luong - 1);
    xoa(toa_do_Y, so_luong - 1);

    //Ve ran
    ve_ran(toa_do_X, toa_do_Y);

}

void xoa_ran(int toa_do_X[], int toa_do_Y[])
{
    for (int i = 0; i < so_luong; i++)
    {
        gotoXY(toa_do_X[i], toa_do_Y[i]);
        cout << " ";
    }
}

bool kiem_tra(int toa_do_X[], int toa_do_Y[])
{
    bool kt1 = kiem_tra_cham_tuong(toa_do_X, toa_do_Y);
    bool kt2 = kiem_tra_cham_duoi(toa_do_X, toa_do_Y);

    if (kt1 == true || kt2 == true)
    {
        return true;
    }

    return false;
}

void tao_qua(int& xqua, int& yqua)
{
    xqua = rand() % (99 - 11 + 1) + 11;
    yqua = rand() % (25 - 2 + 1) + 2;
    gotoXY(xqua, yqua);
    cout << "$";
}

bool kiem_tra_cham_tuong(int toa_do_X[], int toa_do_Y[])
{
    //tường trên: y = 1, 10<=x<=100
    if (toa_do_Y[0] == 1 && toa_do_X[0] >= 10 && toa_do_X[0] <= 100)
    {
        return true;
    }

    //tường dưới: y = 26, 10<=x<=100
    if (toa_do_Y[0] == 26 && toa_do_X[0] >= 10 && toa_do_X[0] <= 100)
    {
        return true;
    }

    //tường bên phải: x = 100, 1<=y<=26
    if (toa_do_X[0] == 100 && toa_do_Y[0] >= 1 && toa_do_Y[0] <= 26)
    {
        return true;
    }

    //tường bên phải: x = 10, 1<=y<=26
    if (toa_do_X[0] == 10 && toa_do_Y[0] >= 1 && toa_do_Y[0] <= 26)
    {
        return true;
    }
}

bool kiem_tra_cham_duoi(int toa_do_X[], int toa_do_Y[])
{
    for (int i = 1; i < so_luong; i++)
    {
        if (toa_do_X[i] == toa_do_X[0] && toa_do_Y[i] == toa_do_Y[0])
        {
            return true;
        }
    }

    return false;
}

void them(int a[], int idx,  int x)
{
    for (int i = so_luong; i > idx; i--)
    {
        a[i] = a[i - 1];
    }

    a[idx] = x;
    so_luong++;
}

void xoa(int a[], int idx)
{
    for (int i = idx; i < so_luong; i++)
    {
        a[i] = a[i + 1];
    }

    so_luong--;
}

void khoi_tao_ran(int toa_do_X[], int toa_do_Y[], int x, int y)
{
    for (int i = 0; i < so_luong; i++)
    {
        toa_do_X[i] = x;
        toa_do_Y[i] = y;
        x--;
    }
}

void ve_ran(int toa_do_X[], int toa_do_Y[])
{
    for (int i = 0; i < so_luong; i++)
    {
        gotoXY(toa_do_X[i], toa_do_Y[i]);

        if (i == 0)
        {
            cout << "0";
        }
        else
        {
            cout << "o";
        }
    }
    
    gotoXY(0, 0);
}

void ve_tuong()
{
    ve_tuong_tren();
    ve_tuong_duoi();
    ve_tuong_phai();
    ve_tuong_trai();
}

void ve_tuong_tren()
{
    int x = 10, y = 1;

    while (x <= 100)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
    
}

void ve_tuong_duoi()
{
    int x = 10, y = 26;

    while (x <= 100)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }

}

void ve_tuong_trai()
{
    int x = 10, y = 1;

    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }

}

void ve_tuong_phai()
{
    int x = 100, y = 1;

    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }

}

/*
    int x = 10, y = 0;
    int xcu = x, ycu = y;
    int color = 1;

    // 0 di xuong, 1 di len, 2 sang trai, 3 sang phai
    int check = 0;

    while (true)
    {
        gotoXY(xcu, ycu);
        cout << "                     ";

        gotoXY(x, y);
        cout << "HOC LAP TRINH THAT DE";

        xcu = x;
        ycu = y;

        SetColor(color);
        color++;

        if (color > 15)
        {
            color = 1;
        }

        // dieu khien
        if (_kbhit())
        {
            char kitu = _getch();

            if (kitu == -32)
            {
                kitu = _getch();

                if(kitu == 72)
                {
                    check = 1;
                }
                else if (kitu == 80)
                {
                    check = 0;
                }
                else if (kitu == 75)
                {
                    check = 2;
                }
                else if (kitu == 77)
                {
                    check = 3;
                }
            }


        }

        //Kiem tra huong
        if (check == 0)
        {
            y++;
        }
        else if(check == 1)
        {
            y--;
        }
        else if (check == 2)
        {
            x--;
        }
        else if (check == 3)
        {
            x++;
        }

        //Kiem tra bien
        if (y == 28)
        {
            check = 1;
        }
        else if (y == 0)
        {
            check = 0;
        }
        else if (x == 0)
        {
            check = 3; //cham bien trai, di qua phai
        }
        else if (x == 100)
        {
            check = 2; //cham bien phai, di qua trai
        }

        Sleep(100);
    }
    */