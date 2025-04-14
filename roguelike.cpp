#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int mapaEscuro[30][60] =  {0};

int mapa[30][60] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 8, 1, 0, 0, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0, 4, 4, 1, 0, 0, 0, 1, 0, 0, 0, 7, 1},
    {1, 7, 0, 0, 1, 1, 1, 1, 4, 4, 5, 5, 5, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 5, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 3, 5, 5, 5, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 1, 0, 1, 0, 0, 1, 0, 0, 6, 1},
    {1, 1, 0, 0, 1, 0, 0, 1, 4, 4, 4, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 6, 1, 0, 0, 0, 4, 5, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 4, 1, 7, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 5, 4, 0, 0, 0},
    {0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
    {0, 4, 4, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 5, 1, 1, 1, 0},
    {4, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1},
    {4, 5, 4, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 7, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
    {4, 5, 4, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 1, 0},
    {4, 5, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 5, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 4, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 4, 4, 5, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 0, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 4, 5, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 6, 0, 1, 0, 1, 6, 1, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 4, 5, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 4, 5, 4, 4, 1, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 4, 4, 1, 1, 1, 1, 1, 1, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 6, 1, 0, 0, 0, 1, 1, 4, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 5, 5, 5, 5, 5, 5, 5, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 4, 4, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 7, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};

int backupItens[30][60] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 8, 1, 0, 0, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0, 4, 4, 1, 0, 0, 0, 1, 0, 0, 0, 7, 1},
    {1, 7, 0, 0, 1, 1, 1, 1, 4, 4, 5, 5, 5, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 5, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 3, 5, 5, 5, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 1, 0, 1, 0, 0, 1, 0, 0, 6, 1},
    {1, 1, 0, 0, 1, 0, 0, 1, 4, 4, 4, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 6, 1, 0, 0, 0, 4, 5, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 4, 1, 7, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 5, 4, 0, 0, 0},
    {0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
    {0, 4, 4, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 5, 1, 1, 1, 0},
    {4, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1},
    {4, 5, 4, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 7, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
    {4, 5, 4, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 1, 0},
    {4, 5, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 5, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 4, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 4, 4, 5, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 0, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 4, 5, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 6, 0, 1, 0, 1, 6, 1, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 4, 5, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 4, 5, 4, 4, 1, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 4, 4, 1, 1, 1, 1, 1, 1, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 6, 1, 0, 0, 0, 1, 1, 4, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 5, 5, 5, 5, 5, 5, 5, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 4, 4, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 7, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};

struct Jogador
{
    int x = 5, y = 1;
    int vida = 10;
    int pontuacao = 0;
    int pocao = 0;
    int chave = 0;
    int dano = 2;
};

struct Inimigo
{
    int vida = 5;
    int x = 0, y = 0;
    int acao = 0;
    int dano = 2;
};

void corTexto(int cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void centralizarTexto(const string& text)
{
    // Pega o tamanho da tela do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calcula o deslocamento para centralizar o texto
    int padding = (consoleWidth - static_cast<int>(text.length())) / 2;
    if (padding < 0) padding = 0; // Evita valores negativos

    // Imprime os necess rios pra centralizar
    cout << string(padding, ' ') << text << endl;
}

int venceu(Jogador jogador)
{
    cout << "\n\n\n";
        cout << R"(
  ____   _    ____      _    ____  _____ _   _ ____    _  
 |  _ \ / \  |  _ \    / \  | __ )| ____| \ | / ___|  | | 
 | |_) / _ \ | |_) |  / _ \ |  _ \|  _| |  \| \___ \  | | 
 |  __/ ___ \|  _ <  / ___ \| |_) | |___| |\  |___) | |_| 
 |_| /_/   \_\_| \_\/_/   \_\____/|_____|_| \_|____/  (_) 
)" << endl;
    cout << "\n\n Voce derrotou o boss Univalison!! \n";
    cout << "\n A sua Pontuacao Final foi de: ";
    corTexto(4);
    cout << jogador.pontuacao << "!! \n\n\n";
    corTexto(7);
    exit (0);

}

void abrirPorta(int& chave, int x, int y)
{
    if (chave > 0)
    {
        if (mapa[x + 1][y] == 3) mapa[x + 1][y] = 0;
        if (mapa[x - 1][y] == 3) mapa[x - 1][y] = 0;
        if (mapa[x][y + 1] == 3) mapa[x][y + 1] = 0;
        if (mapa[x][y - 1] == 3) mapa[x][y - 1] = 0;
        cout << "\nPorta Aberta!\n";
        chave--;
        system("pause");
        system("cls");
    }
}

void moverInimigo(Inimigo inimigos[7])
{
    int direcao = rand() % 4; // 0: cima, 1: baixo, 2: esquerda, 3: direita
    for (int indexInimigo = 0; indexInimigo <= 6; indexInimigo++)
        switch (direcao)
        {
        case 0: // cima
            if (mapa[inimigos[indexInimigo].x - 1][inimigos[indexInimigo].y] == 0)
                inimigos[indexInimigo].x--;
            break;
        case 1: // baixo
            if (mapa[inimigos[indexInimigo].x + 1][inimigos[indexInimigo].y] == 0)
                inimigos[indexInimigo].x++;
            break;
        case 2: // esquerda
            if (mapa[inimigos[indexInimigo].x][inimigos[indexInimigo].y - 1] == 0)
                inimigos[indexInimigo].y--;
            break;
        case 3: // direita
            if (mapa[inimigos[indexInimigo].x][inimigos[indexInimigo].y + 1] == 0)
                inimigos[indexInimigo].y++;
            break;
        }

}

int batalha(Jogador& jogador, Inimigo inimigos[8], int indexInimigo)
{

    while (jogador.vida > 0)
    {
        system("cls");
        cout << "\n\nVidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave << " \n\nVida Do Inimigo: " << inimigos[indexInimigo].vida << " \n";
        cout << "\n\n";
        if (indexInimigo == 7) // index do boss
        {
            centralizarTexto("Voce encontrou O Chefe! Se prepare");
        }
        else
        {
            centralizarTexto("Voce encontrou um inimigo!");
        }

        cout << "\nEscolha uma acao:\n";
        cout << "1. Pedra\n";
        cout << "2. Papel\n";
        cout << "3. Tesoura\n";
        char escolha;
        cin >> escolha;

        inimigos[indexInimigo].acao = rand() % 3;
        if (escolha == '1')   // Pedra
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPedra X Pedra, nada aconteceu\n";

            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPedra X Papel, Voce tomou Dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPedra X Tesoura, Voce causou Dano""\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
        }
        else if (escolha == '2')   // Papel
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPapel X Pedra, Voce causou Dano\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPapel X Papel, nada aconteceu\n";
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPapel X Tesoura, Voce tomou dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }

        }
        else if (escolha == '3')   // Tesoura
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nTesoura X Pedra, voce tomou dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nTesoura X Papel, voce causou dano!\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nTesoura X Tesoura, nada aconteceu\n";
            }

        }
        else
        {
            cout << "\n escolha Invalida!";

        }
        system("pause");

        if (inimigos[indexInimigo].vida <= 0 && indexInimigo == 7)
        {

            jogador.pontuacao += (jogador.vida * 150);
            jogador.pontuacao += 1000;
            system("cls");
            venceu(jogador);
            break;

        }
        if (inimigos[indexInimigo].vida <= 0 && indexInimigo < 7)
        {

            cout << "\nInimigo Derrotado!\n\n\n\n\n\n\n";
            jogador.pontuacao += 200;
            system("pause");
            system("cls");
            return -1;
        }




    }


}

int jogo()
{
    srand(static_cast<unsigned int>(time(0))); // inicializar o gerador de n�meros aleat�rios
    Jogador jogador;
    Inimigo inimigos[8] =
    {
        { 4, 1, 1, 1, 2}, // inimigo[0]
        { 4, 2, 16, 1, 2}, // inimigo[1]
        { 5, 8, 39, 1, 2}, // inimigo[2]
        { 5, 15, 13, 1, 2}, // inimigo[3]
        { 6, 11, 10, 1, 2}, // inimigo[4]
        { 8, 20, 19, 1, 2}, // inimigo[5]
        { 6, 28, 28, 1, 2}, // inimigo[6]
        {25, 0, 0, 2, 3} // boss[7]


    };

    //ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
    //INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
    //ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    //Posicao inicial do inimigo no console

    long long tempoAnterior = GetTickCount(); // Tempo anterior do movimento do inimigo
    long long tempoAtual;
    //Variavel para tecla pressionada
    char tecla;


    while (true) // Loop principal do jogo, roda continuamente at� o jogador morrer ou escolher sair
    {
        //Posiciona o cursor no canto superior esquerdo do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 30; i++) // Loop pelas linhas do mapa (altura)
        {
            for (int j = 0; j < 60; j++) // Loop pelas colunas do mapa (largura)
            {
                // Se a posi��o atual for a mesma do jogador, imprime o personagem
                if (i == jogador.x && j == jogador.y)
                {
                    cout << char(190); // Personagem do jogador
                }

                // Se a posi��o atual for de um dos inimigos
                else if (
                    i == inimigos[0].x && j == inimigos[0].y ||
                    i == inimigos[1].x && j == inimigos[1].y ||
                    i == inimigos[2].x && j == inimigos[2].y ||
                    i == inimigos[3].x && j == inimigos[3].y ||
                    i == inimigos[4].x && j == inimigos[4].y ||
                    i == inimigos[5].x && j == inimigos[5].y ||
                    i == inimigos[6].x && j == inimigos[6].y
                )
                {
                    bool inimigoImpresso = false;

                    for (int idx = 0; idx < 7 && !inimigoImpresso; idx++) // Percorre todos os inimigos
                    {
                        if (i == inimigos[idx].x && j == inimigos[idx].y)
                        {
                            // Verifica se o jogador est� no raio de 3 unidades em rela��o ao inimigo
                            for (int di = -3; di <= 3 && !inimigoImpresso; di++)
                            {
                                for (int dj = -3; dj <= 3 && !inimigoImpresso; dj++)
                                {
                                    int posX = inimigos[idx].x + di;
                                    int posY = inimigos[idx].y + dj;

                                    // Verifica se a posi��o � v�lida dentro do mapa
                                    if (posX >= 0 && posY >= 0 && mapa[posX] != 0)
                                    {
                                        // C�lculo de dist�ncia de Manhattan entre jogador e inimigo
                                        int distanciaX = abs(jogador.x - posX);
                                        int distanciaY = abs(jogador.y - posY);

                                        if (distanciaX + distanciaY <= 3)
                                        {
                                            cout << char(38); // Imprime o inimigo vis�vel
                                            inimigoImpresso = true;
                                        }
                                    }
                                }
                            }

                            if (!inimigoImpresso)
                            {
                                cout << " "; // Inimigo est� fora do alcance de vis�o do jogador
                            }

                            break; // Sai do loop do inimigo atual
                        }
                    }
                }

                // Caso contr�rio, imprime o elemento do mapa
                else
                {
                    switch (mapaEscuro[i][j]) // mapaEscuro representa o que o jogador j� enxergou
                    {
                    case 0:
                        cout << " ";
                        break; // Caminho vazio
                    case 1:
                        cout << char(219);
                        break; // Parede
                    case 2:
                        cout << " ";
                        break;// Espa�o n�o especificado
                    case 3:
                        cout << char(178);
                        break;// Porta fechada
                    case 4:
                        cout << " ";
                        break;// Espa�o bloqueado
                    case 5:
                        cout << char(176);
                        break;// Corredor
                    case 6:
                        cout << char(117);
                        break;// Po��o de cura
                    case 7:
                        cout << char(88);
                        break;// Armadilha
                    case 8:
                        cout << char(170);
                        break;// Chave
                    case 9:
                        cout << char(184);
                        break;// Item de aumentar dano
                    case 10:
                        cout << char(241);
                        break;// Item que revela o mapa
                    case 11:
                        cout << char(157);
                        break;// Boss
                    }
                }
            }
            cout << "\n"; // Fim da linha do mapa
        }

        // Exibi��o das informa��es do jogador
        corTexto(3);
        cout << "\n Vidas: " << jogador.vida;
        cout << "  ||  Pontuacao: " << jogador.pontuacao;
        cout << "  || Usos da Pocao: " << jogador.pocao;
        cout << "  || Chave: " << jogador.chave;
        corTexto(7);
        // Verifica se o jogador est� sobre algum item especial
        if (mapa[jogador.x][jogador.y] == 6)   // Po��o
        {
            jogador.pocao += 1;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 7)   // Armadilha
        {
            jogador.vida -= 5;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 8)   // Chave
        {
            jogador.chave += 1;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }

        // Verifica se est� pr�ximo a uma porta para tentar abrir
        if (mapa[jogador.x + 1][jogador.y] == 3 || mapa[jogador.x - 1][jogador.y] == 3 ||
                mapa[jogador.x][jogador.y + 1] == 3 || mapa[jogador.x][jogador.y - 1] == 3)
        {
            abrirPorta(jogador.chave, jogador.x, jogador.y);
        }

        if (mapa[jogador.x][jogador.y] == 9) // Item para aumentar dano
        {
            jogador.dano += 3;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }

        if (mapa[jogador.x][jogador.y] == 10) // Item para revelar o mapa completo
        {
            for (int linha = 0; linha < 30; linha ++)
            {
                for (int coluna = 0; coluna < 60; coluna++)
                {
                    mapaEscuro[linha][coluna] = mapa[linha][coluna]; // Revela tudo
                }
            }
            mapa[jogador.x][jogador.y] = 0;
        }

        // Se estiver perto do boss, inicia batalha
        if (mapa[jogador.x + 1][jogador.y] == 11 || mapa[jogador.x - 1][jogador.y] == 11 ||
                mapa[jogador.x][jogador.y + 1] == 11 || mapa[jogador.x][jogador.y - 1] == 11)
        {
            batalha(jogador, inimigos, 7);
        }

        // Verifica se � hora de mover os inimigos
        tempoAtual = GetTickCount();
        if (tempoAtual - tempoAnterior >= 500) // A cada 500ms
        {
            moverInimigo(inimigos);
            tempoAnterior = tempoAtual;
        }

        // Verifica se o jogador colidiu com algum inimigo
        for (int controle = 0; controle < 7; controle++)
        {
            if (jogador.x == inimigos[controle].x && jogador.y == inimigos[controle].y)
            {
                // Chama batalha, inimigo pode ser derrotado ou mover
                inimigos[controle].x = batalha(jogador, inimigos, controle);
                inimigos[controle].y = inimigos[controle].x;
            }
        }

        ///Controle de movimento do jogador
        if (_kbhit()) // Se alguma tecla foi pressionada
        {
            mapaEscuro[jogador.x][jogador.y] = mapa[jogador.x][jogador.y]; // Atualiza mapa explorado

            // Atualiza �rea de vis�o do jogador em 3 unidades ao redor
            for (int i = -3; i < 3; i++)
            {
                if (mapa[jogador.x + i] != 0 && (jogador.x + i) >= 0)
                {
                    for (int j = -3; j < 3; j++)
                    {
                        if ((jogador.x + i) >= 0 && (jogador.y + j) >= 0)
                        {
                            int valor = mapa[jogador.x + i][jogador.y + j];
                            mapaEscuro[jogador.x + i][jogador.y + j] = (valor < 0) ? 0 : valor;
                        }
                    }
                }
            }

            tecla = _getch(); // Captura a tecla
            switch (tecla)
            {
            case 72:
            case 'w': // cima
                if (mapa[jogador.x - 1][jogador.y] == 0 || mapa[jogador.x - 1][jogador.y] > 4) jogador.x--;
                break;
            case 80:
            case 's': // baixo
                if (mapa[jogador.x + 1][jogador.y] == 0 || mapa[jogador.x + 1][jogador.y] > 4) jogador.x++;
                break;
            case 75:
            case 'a': // esquerda
                if (mapa[jogador.x][jogador.y - 1] == 0 || mapa[jogador.x][jogador.y - 1] > 4) jogador.y--;
                break;
            case 77:
            case 'd': // direita
                if (mapa[jogador.x][jogador.y + 1] == 0 || mapa[jogador.x][jogador.y + 1] > 4) jogador.y++;
                break;
            case 'e': // usar po��o
                if (jogador.pocao >= 1)
                {
                    jogador.vida += 3;
                    jogador.pocao--;
                }
                break;
            }
        }

        // Se o jogador morrer
        if (jogador.vida <= 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n";
            centralizarTexto("Voce Morreu! Deseja jogar novamente? (S para sim, N para nao)");
            cout << "\n\n\n\n\n\n\n";

            char escolha;
            cin >> escolha;

            if (escolha == 's' || escolha == 'S')
            {
                // Reinicia jogo do zero
                system("cls");
                for (int linha = 0; linha < 30; linha ++)
                {
                    for (int coluna = 0; coluna < 60; coluna++)
                    {
                        mapa[linha][coluna] = backupItens[linha][coluna];
                        mapaEscuro[linha][coluna] = 0;
                    }
                }
                return jogo(); // Reinicia
            }
            else
            {
                break; // Sai do loop principal, encerrando o jogo
            }
        }

    } // Fim do loop principal do jogo


    return 0;
}

int main()
{


    int opcao = 0;
    cout << "\n\n\n\n\n\n\n\n\n";
    corTexto(3);
    centralizarTexto("MENU\n");
    corTexto(1);
    centralizarTexto("1- Iniciar Jogo\n");
    centralizarTexto("2- Guia\n");
    centralizarTexto("3- Sair do Jogo\n");
    corTexto(7);
    cin >> opcao;
    system("cls"); // limpa o console ap s a op  o ser escolhida

    if (opcao == 1)   // Start Game
    {
        jogo();
    }
    else if (opcao == 2)   // Guia
    {
        char a = '0';
        corTexto(3);
        centralizarTexto("GUIA E MANUAL \n");
        centralizarTexto("Voce nasce em uma sala segura aqui voce deve se equipar e se preparar para explorar! \n");
        centralizarTexto("Voce deve explorar as demais salas, procurando por itens e derrotando os inimigos\n");
        centralizarTexto("porem cuidado, as salas so serao visiveis apos voce visita-las\n\n");
        cout << "Sistema de Pontuacao:                                                          "
             "Itens: \n";
        cout << "\n * Itens: 50 pontos.                                           "
             "* Chave: (" << char(170) << ") utilizada para abrir portas!\n";
        cout << "\n * Derrotar Inimigos: 200 pontos.                              "
             "* Pocao: (u) Aperte E para usar, Cure 3 de vida\n";
        cout << "\n * Derrotar O Chefe: 1000 pontos.                              "
			 "* Mapa: (" << char(241) << ") Revela o restante do mapa\n"; 
        cout << "\n * Ao terminar, cada vida sobrando te da 150 pontos.           "
    	     "* Arma: (�) Aumenta o Dano causado a inimigos \n\n\n\n\n"; 
        system("pause");

        system("cls");
        return main();
    }
    else   // Exit game
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        cout << "\n\n\n\n\n\n\nn\n\n\n";
        return 0;
    }
}