#pragma once
#include "Combate.h"
#include "Mapas.h"
#include "SubirNivel.h"
int jogo(int dificuldadeEscolhida)
{
   
    // dificuldade Media adotada como padrao

    srand(static_cast<unsigned int>(time(0))); // inicializar o gerador de números aleatórios
    Jogador jogador;
    Inimigo inimigos[8];
    if (dificuldadeEscolhida == 0) {
        inimigos[0] =  { 3, 1, 1, 1, 2, 700, 38, 7, 50}; // inimigo[0]
    	inimigos[1] =  { 3, 2, 16, 1, 2, 700, 38, 7, 50}; // inimigo[1]
    	inimigos[2] =  { 4, 8, 39, 1, 2, 700, 36, 7, 50}; // inimigo[2]
        inimigos[3] =  { 4, 15, 13, 1, 2, 700, 36, 7, 50}; // inimigo[3]
        inimigos[4] =  { 5, 11, 10, 1, 2, 700, 36, 7, 50}; // inimigo[4]
        inimigos[5] =  { 5, 28, 28, 1, 2, 700, 36, 7, 50}; // inimigo[6]
    	inimigos[6] =  {20, 0, 0, 2, 3, 700, 38, 7, 50};// boss[7]};

    } else if (dificuldadeEscolhida == 1) {
        inimigos[0] =  { 3, 1, 1, 1, 2, 500, 38, 7, 50}; // inimigo[0]
    	inimigos[1] =  { 3, 2, 16, 1, 2, 500, 36, 7, 50}; // inimigo[1]
    	inimigos[2] =  { 4, 8, 39, 1, 2, 500, 36, 7, 50}; // inimigo[2]
        inimigos[3] =  { 4, 15, 13, 1, 2, 500, 36, 7, 50}; // inimigo[3]
        inimigos[4] =  { 5, 11, 10, 1, 2, 500, 36, 7, 50}; // inimigo[4]
        inimigos[5] =  { 5, 28, 28, 1, 2, 500, 36, 7, 50}; // inimigo[6]
    	inimigos[6] =  {20, 0, 0, 2, 3, 500, 38, 7, 50};// boss[7]};
    } else if (dificuldadeEscolhida == 2) {
        inimigos[0] =  { 3, 1, 1, 1, 2, 250, 38, 7, 50}; // inimigo[0]
    	inimigos[1] =  { 3, 2, 16, 1, 2, 250, 38, 7, 50}; // inimigo[1]
    	inimigos[2] =  { 4, 8, 39, 1, 2, 250, 36, 7, 50}; // inimigo[2]
        inimigos[3] =  { 4, 15, 13, 1, 2, 250, 36, 7, 50}; // inimigo[3]
        inimigos[4] =  { 5, 11, 10, 1, 2, 250, 36, 7, 50}; // inimigo[4]
        inimigos[5] =  { 5, 28, 28, 1, 2, 250, 36, 7, 50}; // inimigo[6]
    	inimigos[6] =  {20, 0, 0, 2, 3, 250, 38, 7, 50};// boss[7]};
    };


	cout << "Primeiro, Qual é Seu Nome?";
	cin >> jogador.nome;

    //ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
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
    //ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    //Posicao inicial do inimigo no console

    long long tempoAnterior = GetTickCount64(); // Tempo anterior do movimento do inimigo
    long long tempoAtual;
    auto ultimoSegundo = std::chrono::steady_clock::now();

    //Variavel para tecla pressionada
    char tecla;

    if (dificuldadeEscolhida == 0)
	{
		jogador = {5, 1 , 15, 15};
	} if (dificuldadeEscolhida == 2)
	{
		jogador = {5, 1 , 5, 10};
	}
	int minutos = 0;
	int segundos = 0;
    while (true) // Loop principal do jogo, roda continuamente até o jogador morrer ou escolher sair
    {

        //Posiciona o cursor no canto superior esquerdo do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        //Imprime o jogo: mapa e personagem.
        for (int i = 0; i < 30; i++) // Loop pelas linhas do mapa (altura)
        {
            for (int j = 0; j < 60; j++) // Loop pelas colunas do mapa (largura)
            {
                // Se a posição atual for a mesma do jogador, imprime o personagem
                if (i == jogador.x && j == jogador.y)
                {
                    corTexto(jogador.cor);
                    cout << char(jogador.visual); // Personagem do jogador
                    corTexto(7);
                    
                }

                // Se a posição atual for de um dos inimigos
                else if (
                    i == inimigos[0].x && j == inimigos[0].y ||
                    i == inimigos[1].x && j == inimigos[1].y ||
                    i == inimigos[2].x && j == inimigos[2].y ||
                    i == inimigos[3].x && j == inimigos[3].y ||
                    i == inimigos[4].x && j == inimigos[4].y ||
                    i == inimigos[5].x && j == inimigos[5].y ||
                    i == inimigos[6].x && j == inimigos[6].y
                )
                {
                    bool inimigoImpresso = false;

                    for (int idx = 0; idx < 7 && !inimigoImpresso; idx++) // Percorre todos os inimigos
                    {
                        if (i == inimigos[idx].x && j == inimigos[idx].y)
                        {
                            // Verifica se o jogador está no raio de 3 unidades em relação ao inimigo
                            for (int di = -3; di <= 3 && !inimigoImpresso; di++)
                            {
                                for (int dj = -3; dj <= 3 && !inimigoImpresso; dj++)
                                {
                                    int posX = inimigos[idx].x + di;
                                    int posY = inimigos[idx].y + dj;

                                    // Verifica se a posição é válida dentro do mapa
                                    if (posX >= 0 && posY >= 0 && mapa[posX] != 0)
                                    {
                                        // Cálculo de distância de Manhattan entre jogador e inimigo
                                        int distanciaX = abs(jogador.x - posX);
                                        int distanciaY = abs(jogador.y - posY);

                                        if (distanciaX + distanciaY <= 3)
                                        {

                                            cout << char(inimigos[idx].visual); // Imprime o inimigo visível
                                            inimigoImpresso = true;
                                        }
                                    }
                                }
                            }

                            if (!inimigoImpresso)
                            {
                                cout << " "; // Inimigo está fora do alcance de visão do jogador
                            }

                            break; // Sai do loop do inimigo atual
                        }
                    }
                }

                // Caso contrário, imprime o elemento do mapa
                else
                {
                    switch (mapaEscuro[i][j]) // mapaEscuro representa o que o jogador já enxergou
                    {
                    case 0:
                        cout << " ";
                        break; // Caminho vazio
                    case 1:
                        cout << char(219);
                        break; // Parede
                    case 2:
                        cout << " ";
                        break;// Espaço não especificado
                    case 3:
                        cout << char(178);
                        break;// Porta fechada
                    case 4:
                        cout << " ";
                        break;// Espaço bloqueado
                    case 5:
                        cout << char(176);
                        break;// Corredor
                    case 6:
                        cout << char(117);
                        break;// Poção de cura
                    case 7:
                        cout << char(88);
                        break;// Armadilha
                    case 8:
                        cout << char(170);
                        break;// Chave
                    case 9:
                        cout << char(184);
                        break;// Item de aumentar dano
                    case 10:
                        cout << char(241);
                        break;// Item que revela o mapa
                    case 11:
                        cout << char(157);
                        break;// Boss
                    case 12:
                        cout << char(72);
						break;// Escada
                    case 13:
                        cout << char(64);
                    	break;
                    case 14:
                        cout << char(145);
                        break;
                    case 15:
                        cout << char(85);
                    	break;
                    }
                }
            }
            cout << "\n"; // Fim da linha do mapa
        }

        // Exibição das informações do jogador
        corTexto(3);

        auto agora = std::chrono::steady_clock::now();
		auto diferenca = std::chrono::duration_cast<std::chrono::seconds>(agora - ultimoSegundo);



        cout << "\n Vida: " << jogador.vida << " / " << jogador.vidaMaxima;
        cout << "  || Pontuacao: " << jogador.pontuacao;
        cout << "  || pocoes: " << jogador.pocao;
        cout << "  || Pocao Grande: " << jogador.pocaoGrande;
        cout << "  || Chaves: " << jogador.chave;
    	cout << "  || Nivel: " << jogador.nivel;
        cout << "  || Exp: " << jogador.exp << " / " << jogador.expNecessaria << "\n\n";

		relogio(minutos, segundos);
    	std::this_thread::sleep_for(std::chrono::milliseconds(10));
		int segundoAtual = segundos; 
        // cout << "Nivel: " << 2 << " ||   Level:";
        corTexto(7);
        // Verifica se o jogador está sobre algum item especial
        if (mapa[jogador.x][jogador.y] == 6) {  // Poção 
            jogador.pocao += 1;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
            jogador.exp += 5;
        }
        if (mapa[jogador.x][jogador.y] == 7)   // Armadilha
        {
            jogador.vida -= 5;
            mapa[jogador.x][jogador.y] = 0;
        }
        if (mapa[jogador.x][jogador.y] == 8)   // Chave
        {
            jogador.chave += 1;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
        }

        // Verifica se está próximo a uma porta para tentar abrir
        if (mapa[jogador.x + 1][jogador.y] == 3 || mapa[jogador.x - 1][jogador.y] == 3 ||
                mapa[jogador.x][jogador.y + 1] == 3 || mapa[jogador.x][jogador.y - 1] == 3)
        {
            abrirPorta(jogador.chave, jogador.x, jogador.y, jogador.exp);
        }

        if (mapa[jogador.x][jogador.y] == 9) // Item para aumentar dano
        {
            jogador.dano += 3;
            jogador.pontuacao += 50;
            mapa[jogador.x][jogador.y] = 0;
            jogador.visual = 190;
            jogador.exp += 5;
        }

        if (mapa[jogador.x][jogador.y] == 10) // Item para revelar o mapa completo
        {
            for (int linha = 0; linha < 30; linha ++)
            {
                for (int coluna = 0; coluna < 60; coluna++)
                {
                    mapaEscuro[linha][coluna] = mapa[linha][coluna]; // Revela tudo
                }
            }
            mapa[jogador.x][jogador.y] = 0;
            jogador.exp += 5;
        }

        // Se estiver perto do boss, inicia batalha
        if (mapa[jogador.x + 1][jogador.y] == 11 || mapa[jogador.x - 1][jogador.y] == 11 ||
			mapa[jogador.x][jogador.y + 1] == 11 || mapa[jogador.x][jogador.y - 1] == 11) {
            batalha(jogador, inimigos, 7);
        }

        // Subir a Escada
        if (mapa[jogador.x][jogador.y] == 12) {

        	mapa[jogador.x][jogador.y] = 0;
        	jogador.exp += 5;

            if (jogador.mapa == 0) {
				jogador.x = 27;
	            jogador.y = 58;
            	inimigos[0] =  { 3, 28, 55, 1, 2, 500, 38, 7, 50}; // inimigo[0]
    			inimigos[1] =  { 3, 2, 16, 1, 2, 500, 36, 7, 50}; // inimigo[1]
    			inimigos[2] =  { 4, 8, 39, 1, 2, 500, 36, 7, 50}; // inimigo[2]
		        inimigos[3] =  { 4, 15, 13, 1, 2, 500, 36, 7, 50}; // inimigo[3]
		        inimigos[4] =  { 5, 11, 10, 1, 2, 500, 36, 7, 50}; // inimigo[4]
		        inimigos[5] =  { 5, 28, 28, 1, 2, 500, 36, 7, 50}; // inimigo[6]
    			inimigos[6] =  {20, 0, 0, 2, 3, 500, 38, 7, 50};// boss[7]};

            	for (int linha = 0; linha < 30; linha++) {
        			for (int coluna = 0; coluna < 60; coluna++) {
        				mapaEscuro[linha][coluna] = 0;
        				mapa[linha][coluna] = mapa2[linha][coluna];
        			}
        		}

            } else if (jogador.mapa == 1) {
                jogador.x = jogador.x;
	            jogador.y = jogador.y;
                inimigos[0] =  { 3, 28, 55, 1, 2, 500, 38, 7, 50}; // inimigo[0]
    			inimigos[1] =  { 3, 2, 16, 1, 2, 500, 36, 7, 50}; // inimigo[1]
    			inimigos[2] =  { 4, 8, 39, 1, 2, 500, 36, 7, 50}; // inimigo[2]
		        inimigos[3] =  { 4, 15, 13, 1, 2, 500, 36, 7, 50}; // inimigo[3]
		        inimigos[4] =  { 5, 11, 10, 1, 2, 500, 36, 7, 50}; // inimigo[4]
		        inimigos[5] =  { 5, 28, 28, 1, 2, 500, 36, 7, 50}; // inimigo[6]
    			inimigos[6] =  {20, 0, 0, 2, 3, 500, 38, 7, 50};// boss[7]};

            	for (int linha = 0; linha < 30; linha++) {
            		for (int coluna = 0; coluna < 60; coluna++) {
	                    mapaEscuro[linha][coluna] = 0;
	                    mapa[linha][coluna] = mapa3[linha][coluna];
					}
            	}
            }
        	jogador.mapa++;
        }
		jogador.minutos = minutos;
        jogador.segundos = segundos;
        if (mapa[jogador.x][jogador.y] == 13) { // Armadura
            mapa[jogador.x][jogador.y] = 0;
			jogador.cor = 8;
            jogador.exp += 5;
        }

    	if (mapa[jogador.x][jogador.y] == 14) { // Oculos de Critico
            mapa[jogador.x][jogador.y] = 0;
			jogador.critico += 5;
            jogador.exp += 5;
            
        }

    	if (mapa[jogador.x][jogador.y] == 15) { // Pocao Grande
            mapa[jogador.x][jogador.y] = 0;
            jogador.pocaoGrande += 1;
            jogador.exp += 5;
        }

    	tempoAtual = GetTickCount64();
        // Verifica se é hora de mover os inimigos
        
        if (tempoAtual - tempoAnterior >= inimigos[0].velocidade) // A cada 500ms
        {
            moverInimigos(inimigos);
            tempoAnterior = tempoAtual;
        }
        // Verifica se o jogador subir de nivel
        if (jogador.exp >= jogador.expNecessaria) {
			subirNivel(jogador);
        }

        // Verifica se o jogador colidiu com algum inimigo
        for (int controle = 0; controle < 7; controle++)
        {
            if (jogador.x == inimigos[controle].x && jogador.y == inimigos[controle].y)
            {
                // Chama batalha, inimigo pode ser derrotado ou mover
                inimigos[controle].x = batalha(jogador, inimigos, controle);
                inimigos[controle].y = inimigos[controle].x;
            }
        }
        
        ///Controle de movimento do jogador
        if (_kbhit()) // Se alguma tecla foi pressionada
        {
            mapaEscuro[jogador.x][jogador.y] = mapa[jogador.x][jogador.y]; // Atualiza mapa explorado

            // Atualiza área de visão do jogador em 3 unidades ao redor
            for (int i = -3; i < 3; i++)
            {
                if (mapa[jogador.x + i] != 0 && (jogador.x + i) >= 0)
                {
                    for (int j = -3; j < 3; j++)
                    {
                        if ((jogador.x + i) >= 0 && (jogador.y + j) >= 0)
                        {
                            int valor = mapa[jogador.x + i][jogador.y + j];
                            mapaEscuro[jogador.x + i][jogador.y + j] = (valor < 0) ? 0 : valor;
                        }
                    }
                }
            }

            tecla = _getch(); // Captura a tecla
            switch (tecla)
            {
            case 72:
            case 'w': // cima
                if (mapa[jogador.x - 1][jogador.y] == 0 || mapa[jogador.x - 1][jogador.y] > 4) jogador.x--;
                break;
            case 80:
            case 's': // baixo
                if (mapa[jogador.x + 1][jogador.y] == 0 || mapa[jogador.x + 1][jogador.y] > 4) jogador.x++;
                break;
            case 75:
            case 'a': // esquerda
                if (mapa[jogador.x][jogador.y - 1] == 0 || mapa[jogador.x][jogador.y - 1] > 4) jogador.y--;
                break;
            case 77:
            case 'd': // direita
                if (mapa[jogador.x][jogador.y + 1] == 0 || mapa[jogador.x][jogador.y + 1] > 4) jogador.y++;
                break;
            case 'e': // usar poção
                if (jogador.pocao > 0 && jogador.vida < jogador.vidaMaxima) {
                    jogador.vida += 2;
                    jogador.pocao--;
                    if (jogador.vida > jogador.vidaMaxima) jogador.vida = jogador.vidaMaxima;
                    break;
                }
        	case 'f': // usar poção
                if (jogador.pocaoGrande > 0) {
                    jogador.vida += 3;
                    jogador.vidaMaxima += 3;
                    jogador.pocaoGrande--;
                    break;
                }
            }
        }
                        
        // Se o jogador morrer
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
                // Reinicia jogo do zero
                system("cls");
                for (int linha = 0; linha < 30; linha ++)
                {
                    for (int coluna = 0; coluna < 60; coluna++)
                    {
						if (jogador.mapa == 0) mapa[linha][coluna] = backupItens[linha][coluna];
                    	if (jogador.mapa == 1) mapa[linha][coluna] = backupItens2[linha][coluna];
                    	if (jogador.mapa == 2) mapa[linha][coluna] = backupItens3[linha][coluna];
                        mapaEscuro[linha][coluna] = 0;
                    }
                }
                return jogo(dificuldadeEscolhida); // Reinicia
            }
            else
            {
                break; // Sai do loop principal, encerrando o jogo
            }
        }

    } // Fim do loop principal do jogo


    return 0;
}