#pragma once

void mostrarOpcao(int opcaoEscolhida) {
	system("cls");
	cout << "Parabens! Voce subiu de nivel! \n";
	cout << "Voce pode escolher entre essas opcoes: \n";

	const char* itens[] = {
        "1- Forca",
        "2- Vida",
        "3- Chance de Critico"
    };

	for (int i = 0; i < 3; i++) {
		if (i == opcaoEscolhida) {
			corTexto(6);
			cout << "> " << itens[i] << "\n";
		} else {
			corTexto(7);
			cout << " " << itens[i] << "\n";
		}
		cout << "\n";
	}
	corTexto(7);

}

int subirNivel(Jogador& jogador) {
	int opcao = 0;
	int totalOpcoes = 3;
	jogador.exp = 0;
	jogador.nivel++;
	jogador.expNecessaria = jogador.nivel * 100;

	while (true) {
		mostrarOpcao(opcao);

		int tecla = _getch();

		 if (tecla == 224) { // identifica se o comando que vai vir é uma das setas
			 tecla = _getch();
			 if (tecla == 72) {            // seta para cima
			     opcao = (opcao - 1 + totalOpcoes) % totalOpcoes;
			 } 
				else if (tecla == 80) {       // seta para baixo
				    opcao = (opcao + 1) % totalOpcoes;
			 }
		 }
		 else if (tecla == 13) {          // Enter
			 switch (opcao)
			 {
			 case 0:
				jogador.dano++;
				return 0;
			 case 1:
				 jogador.vida += 5;
				 jogador.vidaMaxima += 5;
				 return 0;
			 case 2:
				jogador.critico += 5;
				return 0;
			 }
			
			 
		 }

		}
	}

