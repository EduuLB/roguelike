#pragma once

inline void mostrarDificuldade(int opcaoEscolhida) {
	system("cls");
	cout << "Em que dificuldade voce gostaria de se Aventurar?\n\n";

	const char* itens[] = {
        "1- Facil",
        "2- Medio",
        "3- Dificil"
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

inline int dificuldade(int &dificuldadeEscolhida) {
	int opcao = 0;
	int totalOpcoes = 3;

	while (true) {
		mostrarDificuldade(opcao);

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
				dificuldadeEscolhida = 0; 
				return 0;
			 case 1:
				 dificuldadeEscolhida = 1; 
				 return 0;
			 case 2:
				dificuldadeEscolhida = 2; 
				return 0;
			 }
			
			 
		 }

		}
	}