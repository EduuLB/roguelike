#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

struct Jogador {
    int x = 0, y = 0;
    int vida = 10;
    int pontuacao = 0;
    int pocao = 0;
};
struct Inimigo {
    int vida = 10;
    int x = 0, y = 0;
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
void enemy() {

}

int jogo()
{
    Jogador jogador;
    Inimigo inimigo;
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
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
    {1,0,5,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,5,5,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3},
    {1,2,0,0,1,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},


    };


    //Posicao inicial do personagem no console
    jogador.x = 5, jogador.y = 1;
    inimigo.x = 1, inimigo.y = 1;
    //Variavel para tecla precionada
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
               // if (i == inimigo.x && j == inimigo.y) {
                 //   cout << char(38);
                //}
                else {                                         
                    switch (mapa[i][j]) {
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char(186); break; //parede
                    case 2: cout << char(205); break; //parede horizontal
                    case 3: cout << char(95); break;
                    case 4: cout << char(117); break;
                    case 5: cout << char(88); break;
                    case 6: cout << char(38); break;
                        //default: cout<<"-"; //erro
                    } //fim switch
                }

            }
            cout << "\n";
        } //fim for mapa
        cout << "Vidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao;
        if (mapa[jogador.x][jogador.y] == 4) {
            jogador.pocao += 3;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 5) {
           jogador.vida -= 5;
          mapa[jogador.x][jogador.y] = 0;
        }

        ///executa os movimentos
        if (_kbhit()) { // SE _kbhit == true signifia se o usuario apertou ALGUM BOTAO, depois o getch pega essa botao pra jogar pro switch
            tecla = _getch(); // pega o que o usuario esta escrevendo e baseado nesse valor executa o switch abaixo
            switch (tecla)
            {
                
            case 72: case 'w': ///cima
                if(mapa[jogador.x - 1][jogador.y] == 0 || mapa[jogador.x - 1][jogador.y] > 2) jogador.x--;
                break;
            case 80: case 's': ///baixo
                if (mapa[jogador.x + 1][jogador.y] == 0 || mapa[jogador.x + 1][jogador.y] > 2) jogador.x++;
                break;
            case 75:case 'a': ///esquerda
                if (mapa[jogador.x][jogador.y - 1] == 0 || mapa[jogador.x][jogador.y - 1] > 2) jogador.y--;
                break;
            case 77: case 'd': ///direita
                if (mapa[jogador.x][jogador.y + 1] == 0 || mapa[jogador.x][jogador.y + 1] > 2) jogador.y++;
                break;
            case 'g':
                if (jogador.pocao >= 1) {
                    jogador.vida += 2;
                    jogador.pocao--;
                }
                break;
            }

        }

        if (jogador.vida <= 0){
            system("cls");
            cout << "\n\n\n\n\n\n\n";
            centralizarTexto("Voce Morreu! Deseja jogar novamente? (S para sim, N para nao)");
            cout << "\n\n\n\n\n\n\n";
            char escolha;
            cin >> escolha;
            if (escolha == 's' || escolha == 'S') {
                system("cls");
                return jogo();
            } else {
                break;
            }
        }
    } //fim do laco do jogo

    return 0;
}
int menu() {
    int opcao = 0;
    cout << "\n\n\n\n\n\n\n\n\n";
    centralizarTexto("MENU\n");
    centralizarTexto("1- Iniciar Jogo\n");
    centralizarTexto("2- Guia\n");
    centralizarTexto("3- Sair do Jogo\n");
    cin >> opcao;
    system("cls"); // limpa o console apos a opção ser escolhida
    if (opcao == 1) { // Start Game
        jogo();

    }
    else if (opcao == 2) { // Guia
        char a = '0';

        centralizarTexto("GUIA E MANUALl");
        cout << " ";
        cin >> a;
        return menu();
    }
    else { // Exit game
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        return 0;
    }
}
int main() {
    menu();
}