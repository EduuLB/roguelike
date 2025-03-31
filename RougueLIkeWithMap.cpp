#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

using namespace std;

struct Jogador
{
    int x = 0, y = 0;  // Posição do jogador no mapa
    int vida = 20;     // Vida do jogador
    int pontuacao = 0; // Pontuação do jogador
    int pocao = 2;     // Quantidade de poções que o jogador tem
};

struct Inimigo
{
    int vida = 10;    // Vida do inimigo
    int x = 0, y = 0; // Posição do inimigo no mapa
};

void centralizarTexto(const string &text)
{
    // Pega o tamanho da tela do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calcula o deslocamento para centralizar o texto
    int padding = (consoleWidth - static_cast<int>(text.length())) / 2;
    if (padding < 0)
        padding = 0; // Evita valores negativos

    // Imprime os necessários pra centralizar
    cout << string(padding, ' ') << text << endl;
}

void moverInimigo(Inimigo &inimigo, int mapa[15][30])
{
    int direcao = rand() % 4; // 0: cima, 1: baixo, 2: esquerda, 3: direita
    int novaX = inimigo.x, novaY = inimigo.y;

    switch (direcao)
    {
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

    // Atualiza a posição do inimigo
    inimigo.x = novaX;
    inimigo.y = novaY;
}

void revelarSala(int mapa[15][30], int x, int y)
{
    // Revela a sala ao redor da posição (x, y)
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < 15 && j >= 0 && j < 30)
            {
                if (mapa[i][j] == 0)
                {                   // Se for caminho
                    mapa[i][j] = 6; // Revela como espaço visível
                }
            }
        }
    }
}

void batalha(Jogador &jogador, Inimigo &inimigo)
{
    while (jogador.vida > 0 && inimigo.vida > 0)
    {
        cout << "\nEscolha uma ação:\n";
        cout << "1. Atacar\n";
        cout << "2. Usar poção\n";
        char escolha;
        cin >> escolha;

        if (escolha == '1')
        {
            // Jogador ataca
            inimigo.vida -= 2; // O jogador causa 2 de dano
            cout << "Você atacou o inimigo! Vida do inimigo: " << inimigo.vida << endl;
            if (inimigo.vida <= 0)
            {
                jogador.pontuacao += 100; // O jogador ganha 100 pontos
                cout << "Inimigo derrotado! Pontuação: " << jogador.pontuacao << endl;
                return; // Inimigo derrotado
            }
        }
        else if (escolha == '2')
        {
            // Usar poção
            if (jogador.pocao > 0)
            {
                jogador.vida += 2; // O jogador recupera 2 de vida
                jogador.pocao--;
                cout << "Você usou uma poção! Vida do jogador: " << jogador.vida << endl;
            }
            else
            {
                cout << "Você não tem poções!\n";
            }
        }
        else
        {
            cout << "Escolha inválida!\n";
            continue; // Volta para o início do loop
        }

        // Inimigo ataca
        jogador.vida -= 2; // O inimigo causa 2 de dano
        cout << "O inimigo atacou! Vida do jogador: " << jogador.vida << endl;
        if(inimigo.vida <= 0 ){
            inimigo.x = -5;
        }
    }
}

int jogo()
{
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios
    Jogador jogador;
    Inimigo inimigo;

    // INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    // FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA

    // Mapa maior com salas ocultas
    int mapa[15][30] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},
        {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    };

    // Posição inicial do personagem no console
    jogador.x = 1, jogador.y = 1; // Posição inicial do jogador
    inimigo.x = 5, inimigo.y = 5; // Posição inicial do inimigo
    char tecla;

    int contadorInimigo = 0;         // Contador para controlar a movimentação do inimigo
    const int intervaloInimigo = 10; // Intervalo para movimentação do inimigo

    // Revela a sala inicial
    revelarSala(mapa, jogador.x, jogador.y);

    while (true)
    {
        // Posiciona a escrita no inicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

        // Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (i == jogador.x && j == jogador.y)
                {
                    cout << char(190); // personagem
                }
                else if (i == inimigo.x && j == inimigo.y)
                {
                    cout << char(38); // inimigo
                }
                else
                {
                    switch (mapa[i][j])
                    {
                    case 0:
                        cout << " ";
                        break; // caminho
                    case 1:
                        cout << char(186);
                        break; // parede
                    case 2:
                        cout << char(205);
                        break; // parede horizontal
                    case 3:
                        cout << char(95);
                        break;
                    case 4:
                        cout << char(117);
                        break;
                    case 5:
                        cout << char(88);
                        break;
                    case 6:
                        cout << " ";
                        break; // espaço revelado
                    }
                }
            }
            cout << "\n";
        }

        cout << "Vidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao;

        // Verifica se o jogador entrou em uma sala
        if (mapa[jogador.x][jogador.y] == 0)
        {
            revelarSala(mapa, jogador.x, jogador.y);
        }

        // Mover inimigo a cada 'intervaloInimigo' iterações
        if (contadorInimigo >= intervaloInimigo)
        {
            moverInimigo(inimigo, mapa);
            contadorInimigo = 0; // Reinicia o contador
        }
        contadorInimigo++; // Incrementa o contador

        // Verificar colisão com inimigo
        if (jogador.x == inimigo.x && jogador.y == inimigo.y)
        {
            batalha(jogador, inimigo);
        }

        // Executa os movimentos
        if (_kbhit())
        {
            tecla = _getch();
            switch (tecla)
            {
            case 72:
            case 'w': // cima
                if (mapa[jogador.x - 1][jogador.y] == 0 || mapa[jogador.x - 1][jogador.y] > 2)
                    jogador.x--;
                break;
            case 80:
            case 's': // baixo
                if (mapa[jogador.x + 1][jogador.y] == 0 || mapa[jogador.x + 1][jogador.y] > 2)
                    jogador.x++;
                break;
            case 75:
            case 'a': // esquerda
                if (mapa[jogador.x][jogador.y - 1] == 0 || mapa[jogador.x][jogador.y - 1] > 2)
                    jogador.y--;
                break;
            case 77:
            case 'd': // direita
                if (mapa[jogador.x][jogador.y + 1] == 0 || mapa[jogador.x][jogador.y + 1] > 2)
                    jogador.y++;
                break;
            case 'g':
                if (jogador.pocao >= 1)
                {
                    jogador.vida += 2; // O jogador usa uma poção
                    jogador.pocao--;
                }
                break;
            }
        }

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
                system("cls");
                return jogo(); // Reinicia o jogo
            }
            else
            {
                break; // Sai do jogo
            }
        }
    } // fim do laço do jogo

    return 0;
}

int menu()
{
    int opcao = 0;
    cout << "\n\n\n\n\n\n\n\n\n";
    centralizarTexto("MENU\n");
    centralizarTexto("1- Iniciar Jogo\n");
    centralizarTexto("2- Guia\n");
    centralizarTexto("3- Sair do Jogo\n");
    cin >> opcao;
    system("cls"); // limpa o console após a opção ser escolhida
    if (opcao == 1)
    { // Start Game
        jogo();
    }
    else if (opcao == 2)
    { // Guia
        char a = '0';
        centralizarTexto("GUIA E MANUAL");
        cout << " ";
        cin >> a;
        return menu();
    }
    else
    { // Exit game
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        return 0;
    }
}

int main()
{
    menu(); // Inicia o menu do jogo
}