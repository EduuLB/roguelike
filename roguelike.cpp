#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Jogador {
    int x = 0, y = 0;
    int vida = 10;
    int pontuacao = 0;
    int pocao = 0;
    bool chave = false;
};

struct Inimigo {
    int vida = 10;
    int x = 0, y = 0;
    int pocao = 1;
    int acao = 1;
};

void centralizarTexto(const string& text) {
    // Pega o tamanho da tela do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calcula o deslocamento para centralizar o texto
    int padding = (consoleWidth - static_cast<int>(text.length())) / 2;
    if (padding < 0) padding = 0; // Evita valores negativos

    // Imprime os necessários pra centralizar
    cout << string(padding, ' ') << text << endl;
}
void abrirPorta(bool &chave, int x, int y, int mapa[7][20])
{
    if (chave == true)
    {
        if (mapa[x + 1][y] == 3) mapa[x + 1][y] = 0;
        if (mapa[x - 1][y] == 3) mapa[x - 1][y] = 0;
        if (mapa[x][y + 1] == 3) mapa[x][y + 1] = 0;
        if (mapa[x][y - 1] == 3) mapa[x][y - 1] = 0;
        cout << "\nPorta Aberta!\n";
        system("pause");
        system("cls");
    }
}

void moverInimigo(Inimigo& inimigo, int mapa[7][20]) {
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

    // Atualiza a posição do inimigo
    inimigo.x = novaX;
    inimigo.y = novaY;
}

void batalha(Jogador& jogador, Inimigo& inimigo, int mapa[7][20]) {
    while (jogador.vida > 0 && inimigo.vida > 0) {
        cout << "\nEscolha uma acao:\n";
        cout << "1. Atacar\n";
        cout << "2. Defender\n";
        cout << "3. Usar Pocao\n";
        char escolha;
        cin >> escolha;

      /*   system("cls"); 
         for (int i = 0; i < 7; i++) {  
            for (int j = 0; j < 20; j++) {
                if (i == jogador.x && j == jogador.y) {
                    cout << char(190); //personagem 
                }
                else if (i == inimigo.x && j == inimigo.y) {
                    cout << char(38); // inimigo
                }
                else {
                    switch (mapa[i][j]) {
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char(186); break; //parede
                    case 2: cout << char(205); break; //parede horizontal
                    case 3: cout << char(178); break; //Porta Fechada 
                    case 4: cout << char(); break; // Reservado para bloco que nao deixa passar
                    case 5: cout << char(95); break; // Caminho entre as salas
                    case 6: cout << char(117); break; // pocao
                    case 7: cout << char(88); break; // Armadilha
                    case 8: cout << char(170); break; // Chave
                    } //fim switch
                }
            }
            cout << endl;
        }
        */ // -------------------------------> For Reproduzindo Toda A matriz pra conseguir limpar a tela a cada ataque, mas mantendo o mapa aparecendo,
        // ----------------------------------> depois tentar de outro jeito por que assim o mapa aparece e volta dando um flick
        inimigo.acao = rand() % 3;
        if (escolha == '1') {
	            if (inimigo.acao == 0) {
		           cout << "\nOs Dois Atacaram\n";
	            }
        		else if (inimigo.acao == 1) {
		            cout << "\nJogador Atacou, inimigo defendeu\n";
	            } 
	            else if (inimigo.acao == 2){
	                cout << "\nJogador Atacou, inimigo usou uma pocao\n";
	            }
        } else if (escolha == '2') {
        		if (inimigo.acao == 0) {
		           cout << "\nJogador Defendeu, inimigo atacou\n";
	            }
        		else if (inimigo.acao == 1) {
		            cout << "\nJogador Defendeu, inimigo defendeu\n";
	            } 
	            else if (inimigo.acao == 2){
	                cout << "\nJogador Defendeu, inimigo usou pocao\n";
	            }

        } else if (escolha == '3') {
        		if (inimigo.acao == 0) {
		           cout << "\nJogador Usou pocao, inimigo atacou\n";
	            }
        		else if (inimigo.acao == 1) {
		            cout << "\nJogador Usou pocao, inimigo defendeu\n";
	            } 
	            else if (inimigo.acao == 2){
	                cout << "\nJogador Usou pocao, inimigo usou uma pocao\n";
	            }
	        
        } else {
	        cout << "\nescolha Invalida!";
             
        }
        
       
    }
}

int jogo() {
    srand(static_cast<unsigned int>(time(0)));
    Jogador jogador;
    Inimigo inimigo;

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

    int mapa[7][20] = {
        {2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,8,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,0,3,5,5,5,5,5,5,5,5,5,5},
        {1,2,0,0,1,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,6,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
    };

    //Posicao inicial do personagem no console
    jogador.x = 5, jogador.y = 1;
    inimigo.x = 1, inimigo.y = 1;

    long long tempoAnterior = GetTickCount64(); // Tempo anterior do movimento do inimigo
    long long tempoAtual;
    //Variavel para tecla pressionada
    char tecla;


    while (true) {
        ///Posiciona a escrita no inicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == jogador.x && j == jogador.y) {
                    cout << char(190); //personagem 
                }
                else if (i == inimigo.x && j == inimigo.y) {
                    cout << char(38); // inimigo
                }
                else {
                    switch (mapa[i][j]) {
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char(186); break; //parede
                    case 2: cout << char(205); break; //parede horizontal
                    case 3: cout << char(178); break; //Porta Fechada 
                    case 4: cout << char(); break; // Reservado para bloco que nao deixa passar
                    case 5: cout << char(95); break; // Caminho entre as salas
                    case 6: cout << char(117); break; // pocao
                    case 7: cout << char(88); break; // Armadilha
                    case 8: cout << char(170); break; // Chave
                    } //fim switch
                }
            }
            cout << "\n";
        } //fim for mapa
        cout << "Vidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao;

        if (mapa[jogador.x][jogador.y] == 6) {
            jogador.pocao += 3;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 7) {
            jogador.vida -= 5;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 8) {
            jogador.chave = true;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x+1][jogador.y] == 3 || mapa[jogador.x-1][jogador.y] == 3 || mapa[jogador.x][jogador.y+1] == 3 ||mapa[jogador.x][jogador.y-1] == 3)
        {
            abrirPorta(jogador.chave, jogador.x, jogador.y, mapa);
        }

        tempoAtual = GetTickCount64();

        // Se se passou 1 segundo (1000 milissegundos), move o inimigo
        if (tempoAtual - tempoAnterior >= 500) {
            moverInimigo(inimigo, mapa);
            tempoAnterior = tempoAtual; // Atualiza o tempo anterior para o tempo atual
        }

        if (jogador.x == inimigo.x && jogador.y == inimigo.y) {
            batalha(jogador, inimigo, mapa);
        }

        ///executa os movimentos
        if (_kbhit()) { // SE _kbhit == true significa que o usuario apertou ALGUM BOTAO, depois o getch pega essa tecla para jogar pro switch abaixo
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
            case 'g':
                if (jogador.pocao >= 1) {
                    jogador.vida += 2;
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
    } //fim do laço do jogo

    return 0;
}

int main() {
    int opcao = 0;
    cout << "\n\n\n\n\n\n\n\n\n";
    centralizarTexto("MENU\n");
    centralizarTexto("1- Iniciar Jogo\n");
    centralizarTexto("2- Guia\n");
    centralizarTexto("3- Sair do Jogo\n");
    cin >> opcao;
    system("cls"); // limpa o console após a opção ser escolhida

    if (opcao == 1) { // Start Game
        jogo();
    }
    else if (opcao == 2) { // Guia
        char a = '0';

        centralizarTexto("GUIA E MANUAL \n");
        centralizarTexto("Voce nasce em uma sala segura aqui voce deve se equipar e se preparar para explorar! \n");
        centralizarTexto("Voce deve explorar as demais salas, procurando por itens e derrotando os inimigos\n");
        centralizarTexto("porem cuidado, as salas so serao visiveis apos voce visita-las\n");
        cout << "Sistema de Pontuacao: \n";
        cout << "\n * Itens: 25 pontos\n";
        cout << "\n * Derrotar Inimigos: 200 pontos\n";
        cout << "\n * Abrir Portas Trancadas: 100 pontos\n";
        cout << "\n * Descobrir novas Salas: 50 pontos\n";
        cout << "\n * Derrotar O Chefe: 500 pontos\n";
        cin >> a;
        return jogo();
    }
    else { // Exit game
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        return 0;
    }
}
