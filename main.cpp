#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int L=9,W=11;
const int tgi=6,tgj=8;
int pli=1,plj=1;
int bxi=6,bxj=6;

char map[L][W]={
    "##########",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "##########"};

void show(void);
bool process(char ch);
bool movebox(int i,int j);
inline void init(void);

int main(void) {
    init();
    while (1) {
        show();
        if (process(getch())) break;
    }
    return 0;
}

inline void init (void) {
    map[pli][plj]='$';
    map[bxi][bxj]='*';
    map[tgi][tgj]='@';
}

void show (void) {
    system("cls");
    for (int i=0;i<8;i++)
        cout<<map[i]<<endl;
}

bool process(char ch) {
    map[pli][plj]=' ';
    int i=0,j=0;
    switch (ch) {
    case 'w':
        i--;break;
    case 's':
        i++;break;
    case 'a':
        j--;break;
    case 'd':
        j++;break;
    }
    switch (map[pli+i][plj+j]) {
    case '#':
        map[pli+i][plj+j]='$';
        show();
        cout<<"BOOM!"<<endl;
        system("pause");
        return true;
    case '*':
        if (movebox(i,j))
            return true;
    }
    /*
    if (map[pli+i][plj+j]=='#') {
        map[pli+i][plj+j]='$';
        show();
        cout<<"BOOM!"<<endl;
        system("pause");
        return true;
    } else if (map[pli+i][plj+j]=='*') {
        if (movebox(i,j)) return true;
    }
    */
    map[pli+=i][plj+=j]='$';
    return false;

}

bool movebox (int i,int j) {
    switch (map[pli+i+i][plj+j+j]) {
    case '#':
        map[pli+i][plj+j]='$';
        map[pli+i+i][plj+j+j]='*';
        show();
        cout<<"BOOM!"<<endl;
        system("pause");
        return true;
    case '@':
        map[pli+i][plj+j]='$';
        map[pli+i+i][plj+j+j]='*';
        show();
        cout<<"ON TARGET!"<<endl;
        system("pause");
        return true;
    }
    /*
    if (map[pli+i+i][plj+j+j]=='#') {
        map[pli+i][plj+j]='$';
        map[pli+i+i][plj+j+j]='*';
        show();
        cout<<"BOOM!"<<endl;
        system("pause");
        return true;
    } else if (map[pli+i+i][plj+j+j]=='@') {
        map[pli+i][plj+j]='$';
        map[pli+i+i][plj+j+j]='*';
        show();
        cout<<"ON TARGET!"<<endl;
        system("pause");
        return true;
    }
    */
    map[pli+i+i][plj+j+j]='*';
    return false;
}
