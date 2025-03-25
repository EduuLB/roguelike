#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

void centralizarTexto(const string& text) {
    // Pega o tamanho da tela do console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calcula o deslocamento para centralizar o texto
    int padding = (consoleWidth - text.length()) / 2;
    if (padding < 0) padding = 0; // Evita valores negativos

    // Imprime os necessários pra centralizar
    cout << string(padding, ' ') << text << endl;

}

int movimento()
{
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
    {4,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,4,2,7,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,0,0,0,1,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9},
    {8,2,0,0,1,0,4,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {5,2,2,2,2,2,6,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };


    //Posicao inicial do personagem no console
    int x = 5, y = 1;
    //Variavel para tecla precionada
    char tecla;

    while (true) {
        ///Posiciona a escrita no inicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == x && j == y) {
                    cout << char(190); //personagem 
                }                                               // nessa parte, se o usuario esta em uma das pósicoes do mapa, esse pedaço do mapa é 
                else {                                          // subtituida pelo boneco, SENAO, No caso, as outras posicoes sao exibidascomo o mapa
                    switch (mapa[i][j]) {
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char(186); break; //parede
                    case 2: cout << char(205); break; //parede horizontal
                    case 3: cout << char(187); break;
                    case 4: cout << char(201); break;
                    case 5: cout << char(200); break;
                    case 6: cout << char(188); break;
                    case 7: cout << char(202); break;
                    case 8: cout << char(204); break;
                    case 9: cout << char(95); break;
                        //default: cout<<"-"; //erro
                    } //fim switch
                }
            }
            cout << "\n";
        } //fim for mapa

        ///executa os movimentos
        if (_kbhit()) { // SE _kbhit == true signifia se o usuario apertou ALGUM BOTAO, depois o getch pega essa botao pra jogar pro switch
            tecla = _getch(); // pega o que o usuario esta escrevendo e baseado nesse valor executa o switch abaixo
            switch (tecla)
            {
            case 72: case 'w': ///cima
                if(mapa[x - 1][y] == 0 || mapa[x - 1][y] == 9) x--;
                break;
            case 80: case 's': ///baixo
                if (mapa[x + 1][y] == 0 || mapa[x + 1][y] == 9) x++;
                break;
            case 75:case 'a': ///esquerda
                if (mapa[x][y - 1] == 0 || mapa[x][y - 1] == 9) y--;
                break;
            case 77: case 'd': ///direita
                if (mapa[x][y + 1] == 0 || mapa[x][y + 1] == 9) y++;
                break;
            }
        }


    } //fim do laco do jogo

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
    system("cls"); // limpa o console apos a opção ser escolhida
    if (opcao == 1) { // Start Game
        movimento();
    }
    else if (opcao == 2) { // Guia
        char a = '0';

        centralizarTexto("GUIA E MANUAL");
        cout << " ";
        cin >> a;
        return main();
    }
    else { // Exit game
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        return 0;
    }
}