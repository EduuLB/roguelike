#pragma once
using namespace std;
#include <string>
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
