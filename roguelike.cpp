#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

int mapaEscuro[30][60] =  {0};
int mapa[30][60] = {
{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
{1, 0, 0, 0, 0, 0, 8, 1, 0, 0, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0, 4, 4, 1, 0, 0, 0, 1, 0, 0, 0, 7, 1},
{1, 7, 0, 0, 1, 1, 1, 1, 4, 4, 5, 5, 5, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 5, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 1, 1, 0, 0, 3, 5, 5, 5, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 1, 0, 1, 0, 0, 1, 0, 0, 6, 1},
{1, 1, 0, 0, 1, 0, 0, 1, 4, 4, 4, 4, 5, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
{1, 0, 0, 0, 0, 0, 6, 1, 0, 0, 0, 4, 5, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 4, 1, 7, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 5, 4, 0, 0, 0},
{0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 0, 0, 0},
{0, 4, 4, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 5, 1, 1, 1, 0},
{4, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1},
{4, 5, 4, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 7, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
{4, 5, 4, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 1, 0},
{4, 5, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{4, 5, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 4, 5, 4, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 5, 5, 5, 5, 5, 5, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 4, 4, 5, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 4, 5, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 5, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 6, 0, 1, 0, 1, 0, 1, 4, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 1, 4, 5, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 5, 5, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 4, 5, 4, 4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 5, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 6, 1, 0, 0, 0, 1, 1, 4, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 5, 5, 5, 5, 5, 5, 5, 4, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 4, 4, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};
struct Jogador {
    int x = 5, y = 1;
    int vida = 10;
    int pontuacao = 0;
    int pocao = 0;
    int chave = 5;
    int dano = 2;
};

struct Inimigo {
    int vida = 0;
    int x = 0, y = 0;
    int acao = 0;
    int dano = 2;
};


void corTexto(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void centralizarTexto(const string& text) {
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

int venceu(Jogador jogador){
    cout << "\n\n\n";
     cout << R"(
					    __   _    __      _    __  __ _   _ ___
					   |  _ \ / \  |  _ \    / \  | _ )| __| \ | / __|
					   | |) / _ \ | |) |  / _ \ |  _ \|  | |  \| \__ \
					   |  _/ __ \|  _ <  / _ \| |) | |_| |\  |__) |
					   || //   \\| \\//   \\_/|__|| \|_/
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

void moverInimigo(Inimigo& inimigo) {
    int direcao = rand() % 4; // 0: cima, 1: baixo, 2: esquerda, 3: direita
    int novaX = inimigo.x, novaY = inimigo.y;

    switch (direcao) {
    case 0: // cima
        if (mapa[inimigo.x - 1][inimigo.y] == 0)
            novaX--;
        break;
    case 1: // baixo
        if (mapa[inimigo.x + 1][inimigo.y] == 0)
            novaX++;
        break;
    case 2: // esquerda
        if (mapa[inimigo.x][inimigo.y - 1] == 0)
            novaY--;
        break;
    case 3: // direita
        if (mapa[inimigo.x][inimigo.y + 1] == 0)
            novaY++;
        break;
    }

    // Atualiza a posi  o do inimigo
    inimigo.x = novaX;
    inimigo.y = novaY;
}

void batalha(Jogador& jogador, Inimigo& inimigo) {
    while (jogador.vida > 0) {
        system("cls");
        cout << "\n\nVidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave << "\n";
        cout << "\n\n";
        centralizarTexto("Voce encontrou um inimigo! ");
        cout << "\nEscolha uma acao:\n";
        cout << "1. Pedra\n";
        cout << "2. Papel\n";
        cout << "3. Tesoura\n";
        char escolha;
        cin >> escolha;


        // -------------------------------> For Reproduzindo Toda A matriz pra conseguir limpar a tela a cada ataque, mas mantendo o mapa aparecendo,
       // ----------------------------------> depois tentar de outro jeito por que assim o mapa aparece e volta dando um flick
        inimigo.acao = rand() % 3;
        if (escolha == '1') { // Pedra
            if (inimigo.acao == 0) {
                cout << "\nPedra X Pedra, nada aconteceu\n";

            }
            else if (inimigo.acao == 1) {
                cout << "\nPedra X Papel, Voce tomou Dano!\n";
                jogador.vida -= inimigo.dano;
            }
            else if (inimigo.acao == 2) {
                cout << "\nPedra X Tesoura, Voce causou Dano""\n";
                inimigo.vida -= jogador.dano;
            }
        }
        else if (escolha == '2') { // Papel
            if (inimigo.acao == 0) {
                cout << "\nPapel X Pedra, Voce causou Dano\n";
                inimigo.vida -= jogador.dano;
            }
            else if (inimigo.acao == 1) {
                cout << "\nPapel X Papel, nada aconteceu\n";
            }
            else if (inimigo.acao == 2) {
                cout << "\nPapel X Tesoura, Voce tomou dano!\n";
                jogador.vida -= inimigo.dano;
            }

        }
        else if (escolha == '3') { // Tesoura
            if (inimigo.acao == 0) {
                cout << "\nTesoura X Pedra, voce tomou dano!\n";
                jogador.vida -= inimigo.dano;
            }
            else if (inimigo.acao == 1) {
                cout << "\nTesoura X Papel, voce causou dano!\n";
                inimigo.vida -= jogador.dano;
            }
            else if (inimigo.acao == 2) {
                cout << "\nTesoura X Tesoura, nada aconteceu\n";
            }

        }
        else {
            cout << "\n escolha Invalida!";

        }
        system("pause");
        char usarPocao = 'n';


        if (inimigo.vida <= 0)
        {
            inimigo.x = -1, inimigo.y = -1;
            cout << "\nInimigo Derrotado!";
            jogador.pontuacao += 200;
            system("cls");

            break;

        }



    }
}

void batalhaBoss(Jogador& jogador, Inimigo& boss) {
    while (jogador.vida > 0) {
        system("cls");
        cout << "\n\nVidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave << "\n";
        cout << "\n\n";
        centralizarTexto("Voce encontrou O Chefe! Se prepare, (e reze!) ");
        cout << "\nEscolha uma acao:\n";
        cout << "1. Pedra\n";
        cout << "2. Papel\n";
        cout << "3. Tesoura\n";
        char escolha;
        cin >> escolha;


        // -------------------------------> For Reproduzindo Toda A matriz pra conseguir limpar a tela a cada ataque, mas mantendo o mapa aparecendo,
       // ----------------------------------> depois tentar de outro jeito por que assim o mapa aparece e volta dando um flick
        boss.acao = rand() % 3;
        if (escolha == '1') { // Pedra
            if (boss.acao == 0) {
                cout << "\nPedra X Pedra, nada aconteceu\n";

            }
            else if (boss.acao == 1) {
                cout << "\nPedra X Papel, Voce tomou Dano!\n";
                jogador.vida -= boss.dano;
            }
            else if (boss.acao == 2) {
                cout << "\nPedra X Tesoura, Voce causou Dano""\n";
                boss.vida -= jogador.dano;
            }
        }
        else if (escolha == '2') { // Papel
            if (boss.acao == 0) {
                cout << "\nPapel X Pedra, Voce causou Dano\n";
                boss.vida -= jogador.dano;
            }
            else if (boss.acao == 1) {
                cout << "\nPapel X Papel, nada aconteceu\n";
            }
            else if (boss.acao == 2) {
                cout << "\nPapel X Tesoura, Voce tomou dano!\n";
                jogador.vida -= boss.dano;
            }

        }
        else if (escolha == '3') { // Tesoura
            if (boss.acao == 0) {
                cout << "\nTesoura X Pedra, voce tomou dano!\n";
                jogador.vida -= boss.dano;
            }
            else if (boss.acao == 1) {
                cout << "\nTesoura X Papel, voce causou dano!\n";
                boss.vida -= jogador.dano;
            }
            else if (boss.acao == 2) {
                cout << "\nTesoura X Tesoura, nada aconteceu\n";
            }

        }
        else {
            cout << "\n escolha Invalida!";

        }
        system("pause");



        if (boss.vida <= 0)
        {
            jogador.pontuacao += 1000;
            system("cls");

            // jogador.pontuacao += jogador.vida * 50;
            venceu(jogador);
            break;
        }



    }
}

int jogo() {
    srand(static_cast<unsigned int>(time(0)));
    Jogador jogador;
    Inimigo inimigo = { 5, 1, 1, 1, 2};
    Inimigo inimigo2 = { 5, 4, 3, 1, 2};
    Inimigo boss = {2, 0, 0, 1, 1};

    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
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
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    //Posicao inicial do inimigo no console

    long long tempoAnterior = GetTickCount(); // Tempo anterior do movimento do inimigo
    long long tempoAtual;
    //Variavel para tecla pressionada
    char tecla;


    while (true) {
        ///Posiciona a escrita no inicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                if (i == jogador.x && j == jogador.y) {
                    cout << char(190); // personagem
                } else if (
                    i == inimigo.x &&
                    j == inimigo.y ||
                    i == inimigo2.x &&
                    j == inimigo2.y
                ) {
                    bool inimigoImpresso = false; // Variável de controle

                    for (int di = -3; di <= 3 && !inimigoImpresso; di++) {
                        for (int dj = -3; dj <= 3; dj++) {
                            int posX = inimigo.x + di;
                            int posY = inimigo.y + dj;

                            // Verifica se as coordenadas estão dentro do mapa
                            if (posX >= 0 && posY >= 0 && mapa[posX] != 0) {
                                // Calcula a distância e verifica raio
                                int distanciaX = (jogador.x - posX >= 0) ? jogador.x - posX : -(jogador.x - posX);
                                int distanciaY = (jogador.y - posY >= 0) ? jogador.y - posY : -(jogador.y - posY);

                                if (distanciaX + distanciaY <= 3) { // Condição de raio
                                    cout << char(38); // Imprime o inimigo
                                    inimigoImpresso = true; // Atualiza a variável de controle
                                    break; // Interrompe o loop interno
                                }
                            }
                        }

                        if (inimigoImpresso) break; // Interrompe o loop externo
                    }

                    if (!inimigoImpresso) {
                        cout << " "; // Imprime espaço vazio caso o inimigo não esteja no raio
                    }
                } else {
                    // Garantir que sempre seja impresso algo no mapa
                    switch (mapaEscuro[i][j]) {
                    case 0: cout << " "; break; // caminho
                    case 1: cout << char(219); break; // parede
                    case 2: cout << " "; break; //
                    case 3: cout << char(178); break; // Porta Fechada
                    case 4: cout << " "; break; // Espaço Bloqueado
                    case 5: cout << char(176); break; // Caminho entre as salas
                    case 6: cout << char(117); break; // poção
                    case 7: cout << char(88); break; // Armadilha
                    case 8: cout << char(170); break; // Chave
                    case 9: cout << char(184); break; // aumentar dano
                    case 10: cout << char(241); break; // mapa
                    case 11: cout << char(157); break; // BOSS
                    }
                }

            }
            cout << "\n";
        } //fim for mapa
        cout << "\n Vidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave;

        if (mapa[jogador.x][jogador.y] == 6) { // jogador pegar pocao
            jogador.pocao += 3;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 7) { // jogador chegar em uma armadilha
            jogador.vida -= 5;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 8) { // jogador pegar uma chave
            jogador.chave = true;
            mapa[jogador.x][jogador.y] = 0;
            jogador.pontuacao += 50;
        }
        if (mapa[jogador.x + 1][jogador.y] == 3 || mapa[jogador.x - 1][jogador.y] == 3 || mapa[jogador.x][jogador.y + 1] == 3 || mapa[jogador.x][jogador.y - 1] == 3)
        { // jogador chegar perto de uma porta
            abrirPorta(jogador.chave, jogador.x, jogador.y);
        }
        if (mapa[jogador.x][jogador.y] == 9)
        {
	        jogador.dano += 3;
            mapa[jogador.x][jogador.y] = 0;
            jogador.pontuacao += 50;
        }
        if (mapa[jogador.x][jogador.y] == 10)
        {

            for (int linha = 0; linha < 30; linha ++) {
	            for (int coluna = 0; coluna < 60; coluna++) {
		            mapaEscuro[linha][coluna] = mapa[linha][coluna];
	            }
            }
        	mapa[jogador.x][jogador.y] = 0;

        }
        if (mapa[jogador.x + 1][jogador.y] == 11 || mapa[jogador.x - 1][jogador.y] == 11 || mapa[jogador.x][jogador.y + 1] == 11 || mapa[jogador.x][jogador.y - 1] == 11)
        {
	        batalhaBoss(jogador, boss);
        }


        tempoAtual = GetTickCount();

        // Se passou meio segundo ou millissegundos), move o inimigo
        if (tempoAtual - tempoAnterior >= 500) {
            moverInimigo(inimigo);
            tempoAnterior = tempoAtual; // Atualiza o tempo anterior para o tempo atual
        }

        if (jogador.x == inimigo.x && jogador.y == inimigo.y) { // jogador encontra um inimigo
            batalha(jogador, inimigo);
        }

        ///executa os movimentos
        if (_kbhit()) { // SE _kbhit == true significa que o usuario apertou ALGUM BOTAO, depois o getch pega essa tecla para jogar pro switch abaixo
            mapaEscuro[jogador.x][jogador.y] = mapa[jogador.x][jogador.y];
            for (int i = -3; i < 3; i++) {
                if (mapa[jogador.x + i] != 0 && (jogador.x + i) >= 0) {
                    for (int j = -3; j < 3; j++) {
                        if ((jogador.x + i) >= 0 && (jogador.y + j) >= 0) {
                            int valor = mapa[jogador.x + i][jogador.y + j];
                            mapaEscuro[jogador.x + i][jogador.y + j] = (valor < 0) ? 0 : valor; // Evita valores negativos
                        }
                    }
                }
            }
            tecla = _getch(); // pega o que o usuario esta escrevendo e baseado nesse valor executa o switch abaixo
            switch (tecla) {
            case 72: case 'w': ///cima
                if (mapa[jogador.x - 1][jogador.y] == 0 || mapa[jogador.x - 1][jogador.y] > 4) jogador.x--;
                break;
            case 80: case 's': ///baixo
                if (mapa[jogador.x + 1][jogador.y] == 0 || mapa[jogador.x + 1][jogador.y] > 4) jogador.x++;
                break;
            case 75: case 'a': ///esquerda
                if (mapa[jogador.x][jogador.y - 1] == 0 || mapa[jogador.x][jogador.y - 1] > 4) jogador.y--;
                break;
            case 77: case 'd': ///direita
                if (mapa[jogador.x][jogador.y + 1] == 0 || mapa[jogador.x][jogador.y + 1] > 4) jogador.y++;
                break;
            case 'e':
                if (jogador.pocao >= 1) {
                    jogador.vida += 3;
                    jogador.pocao--;
                }
                break;
            }
        }

        if (jogador.vida <= 0) {
            system("cls");
            cout << "\n\n\n\n\n\n\n";
            centralizarTexto("Voce Morreu! Deseja jogar novamente? (S para sim, N para nao)");
            cout << "\n\n\n\n\n\n\n";
            char escolha;
            cin >> escolha;
            if (escolha == 's' || escolha == 'S') {
                system("cls");
                return jogo();
            }
            else {
                break;
            }
        }

    } //fim do la o do jogo

    return 0;
}

int main() {
    //HWND hwnd = GetConsoleWindow();
    //ShowWindow(hwnd, SW_MAXIMIZE);
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

    if (opcao == 1) { // Start Game
        jogo();
    }
    else if (opcao == 2) { // Guia
        char a = '0';

        centralizarTexto("GUIA E MANUAL \n");
        centralizarTexto("Voce nasce em uma sala segura aqui voce deve se equipar e se preparar para explorar! \n");
        centralizarTexto("Voce deve explorar as demais salas, procurando por itens e derrotando os inimigos\n");
        centralizarTexto("porem cuidado, as salas so serao visiveis apos voce visita-las\n\n");
        cout << "Sistema de Pontuacao:                                                          "
            "Itens: \n";
        cout << "\n * Itens: 50 pontos.                                           "
            "* Chave: e utilizada para abrir portas!\n";
        cout << "\n * Derrotar Inimigos: 200 pontos.                              "
            "* Pocao: Aperte E para usar, Cure 3 de vida\n";
        cout << "\n * Derrotar O Chefe: 1000 pontos.\n";
        cout << "\n * Ao terminar, cada vida sobrando te da 150 pontos.\n\n\n\n";
        system("pause");

        system("cls");
        return main();
    }
    else { // Exit game
        cout << "\n\n\n\n\n\n\n\n\n\n";
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        cout << "\n\n\n\n\n\n\nn\n\n\n";
        return 0;
    }
}