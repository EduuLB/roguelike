#include "include's.h";

using namespace std;

void mostrarMenu(int opcaoSelecionada) {
    system("cls");
    // Some linhas em branco para �centralizar� verticalmente
    for (int i = 0; i < 8; i++) cout << "\n";

    corTexto(3);
    centralizarTexto("MENU\n");
    corTexto(1);

    const char* itens[] = {
        "1- Iniciar Jogo",
        "2- Guia",
        "3- Sair do Jogo"
    };
    for (int i = 0; i < 3; i++) {
        if (i == opcaoSelecionada) {
            // muda a cor ou prefixa com '>' para real�ar
            corTexto(2);
            centralizarTexto((string("> ") + itens[i]).c_str());
        }
        else {
            corTexto(7);
            centralizarTexto((string("  ") + itens[i]).c_str());
        }
        cout << "\n";
    }
    corTexto(7);
}

int main() {
    int opcao = 0;                // �ndice da op��o destacada
    const int totalOpcoes = 3;

    while (true) {
        mostrarMenu(opcao);

        int tecla = _getch();
        // setas em Windows v�m em dois _getch(): primeiro 224, depois o c�digo real
        if (tecla == 224) {
            tecla = _getch();
            if (tecla == 72) {            // seta para cima
                opcao = (opcao - 1 + totalOpcoes) % totalOpcoes;
            }
            else if (tecla == 80) {       // seta para baixo
                opcao = (opcao + 1) % totalOpcoes;
            }
        }
        else if (tecla == 13) {          // Enter
            system("cls");
            switch (opcao) {
            case 0:  // Iniciar Jogo
                jogo();
                break;
            case 1:  // Guia
                corTexto(3);
                centralizarTexto("GUIA E MANUAL\n\n");
                corTexto(7);
                centralizarTexto("Voc� nasce em uma sala segura: equipe-se e explore!\n\n");
                // aqui copias o teu texto de dicas�
                cout << "\n";
                system("pause");
                break;
            case 2:  // Sair
                for (int i = 0; i < 8; i++) cout << "\n";
                centralizarTexto("Jogo Finalizado, At� a pr�xima!");
                cout << "\n\n";
                return 0;
            }
        }
        // sen�o: repete o loop, mostrando o menu com a nova `opcao`
    }

    return 0;
}
