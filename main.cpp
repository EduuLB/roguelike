#include "Includes.h"

using namespace std;

int main()
{
    int dificuldadeEscolhida = 1;
    int opcao = 0;
    cout << "\n\n\n\n\n\n\n\n\n";
    corTexto(3);
    centralizarTexto("MENU\n");
    corTexto(1);
    centralizarTexto("1- Iniciar Jogo\n");
    centralizarTexto("2- Guia\n");
    centralizarTexto("3- Ranking\n");
    centralizarTexto("4- Sair do Jogo\n");
    corTexto(7);
    cin >> opcao;
    system("cls"); // limpa o console ap s a op  o ser escolhida

    if (opcao == 1)   // Start Game
    {
        
        dificuldade(dificuldadeEscolhida);
        jogo(dificuldadeEscolhida);
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
    	     "* Arma: (©) Aumenta o Dano causado a inimigos \n";
    	cout << "\n * Ao terminar, cada vida sobrando te da 150 pontos.           "
    	     "* Armadura: (@) Resiste ao dano causado por inimigos \n";
    	cout << "\n * Ao terminar, cada vida sobrando te da 150 pontos.           "
    	     "* Oculos: ("<< char(145) << ") Aumenta A chance de crítico \n";
    	cout << "\n * Ao terminar, cada vida sobrando te da 150 pontos.           "
    	     "* Pocao Grande: (U) Aumenta a vida Maxima \n\n\n\n\n";



        system("pause");

        system("cls");
        return main();
    } else if (opcao == 3) {
		leRanking();
    }
    else   // Exit game
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        centralizarTexto("Jogo Finalizado, Ate a proxima!");
        cout << "\n\n\n\n\n\n\nn\n\n\n";
        return 0;
    }
}