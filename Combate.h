#pragma once
#include "ranking.h"
#include <sstream>

int escolherNumeroAleatorio() {
    const char numeros[] = { '1', '2', '3' };
    int indice = rand() % 3;  // Gera um número entre 0 e 2
    return numeros[indice];
}

int venceu(Jogador jogador)
{

    cout << "\n\n\n";
        cout << R"(
  ____   _    ____      _    ____  _____ _   _ ____    _  
 |  _ \ / \  |  _ \    / \  | __ )| ____| \ | / ___|  | | 
 | |_) / _ \ | |_) |  / _ \ |  _ \|  _| |  \| \___ \  | | 
 |  __/ ___ \|  _ <  / ___ \| |_) | |___| |\  |___) | |_| 
 |_| /_/   \_\_| \_\/_/   \_\____/|_____|_| \_|____/  (_) 
)" << endl;
    cout << "\n\n Voce derrotou o boss Univalison!! \n";
    cout << "\n A sua Pontuacao Final foi de: ";
    jogador.pontuacao -= jogador.minutos * 5;
    corTexto(4);
    cout << jogador.pontuacao << "!! \n\n\n";
    corTexto(7);

		ostringstream oss;
	    oss << setfill('0') << setw(2) << jogador.minutos
	        << ":" << setfill('0') << setw(2) << jogador.segundos;

	    jogador.tempo = oss.str();

    
    salvaRanking(jogador.nome, jogador.pontuacao, jogador.tempo);
    leRanking();
    exit (0);

}

int batalha(Jogador& jogador, Inimigo inimigos[8], int indexInimigo, bool jogarSozinho = false)
{

    while (jogador.vida > 0)
    {
        system("cls");
        cout << "\n\nVidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave << " \n\nVida Do Inimigo: " << inimigos[indexInimigo].vida << " \n";
        cout << "\n\n";
        if (indexInimigo == 7) // index do boss
        {
            centralizarTexto("Voce encontrou Um Chefe! Se prepare");
        }
        else
        {
            centralizarTexto("Voce encontrou um inimigo!");
        }

        cout << "\nEscolha uma acao:\n";
        cout << "1. Pedra\n";
        cout << "2. Papel\n";
        cout << "3. Tesoura\n";
        char escolha;
        bool isCritico = false;
        int numAleatorio = rand() % 100;
        if (numAleatorio <= jogador.critico) isCritico = true;
        if (!jogarSozinho) {
            cin >> escolha;
        }else {
            escolha = escolherNumeroAleatorio();
            cout << escolha;
        }

        inimigos[indexInimigo].acao = rand() % 3;
        
        if (escolha == '1')   // Pedra
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPedra X Pedra, Empate, voces se causaram dano\n";
                jogador.vida -= inimigos[indexInimigo].dano / 2;
                inimigos[indexInimigo].vida -= jogador.dano / 2;

            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPedra X Papel, Voce tomou Dano!\n";
                jogador.vida -= (inimigos[indexInimigo].dano - jogador.armadura);
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPedra X Tesoura, Voce causou Dano";
                if (isCritico) {
                    inimigos[indexInimigo].vida -= jogador.dano / 2;
                    cout << ", Critico!\n";
                } else cout << "\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
        }
        else if (escolha == '2')   // Papel
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPapel X Pedra, Voce causou Dano\n";
                  if (isCritico) {
                    inimigos[indexInimigo].vida -= jogador.dano / 2;
                    cout << ", Critico!";
                }
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPapel X Papel, Empate, voces se causaram dano\n";
                 jogador.vida -= inimigos[indexInimigo].dano / 2;
                 inimigos[indexInimigo].vida -= jogador.dano / 2;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPapel X Tesoura, Voce tomou dano!\n";
                jogador.vida -= (inimigos[indexInimigo].dano - jogador.armadura);
            }

        }
        else if (escolha == '3')   // Tesoura
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nTesoura X Pedra, voce tomou dano!\n";
                jogador.vida -= (inimigos[indexInimigo].dano - jogador.armadura);
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nTesoura X Papel, voce causou dano!\n";
                  if (isCritico) {
                    inimigos[indexInimigo].vida -= jogador.dano / 2;
                    cout << ", Critico!";
                }
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nTesoura X Tesoura, Empate, voces se causaram dano\n";
                 jogador.vida -= inimigos[indexInimigo].dano / 2;
                 inimigos[indexInimigo].vida -= jogador.dano / 2;
            }

        }
        else
        {
            cout << "\n escolha Invalida!";

        }
        if (!jogarSozinho) {
            system("pause");
        }
        if (inimigos[indexInimigo].vida <= 0 && inimigos[indexInimigo].cor == 5)
        {

            jogador.pontuacao += (jogador.vida * 150);
            jogador.pontuacao += 1000;
            system("cls");
            venceu(jogador);
            break;

        }
        if (inimigos[indexInimigo].vida <= 0 && inimigos[indexInimigo].velocidade == 0) {
        	cout << "\nInimigo Derrotado!\n\n\n\n\n\n\n";
            jogador.pontuacao += 200;
            jogador.exp += inimigos[indexInimigo].exp;
            mapa[jogador.x][jogador.y] = 0;
            if (!jogarSozinho) {
                system("pause");
            }
            system("cls");
            return -1;
        }
        if (inimigos[indexInimigo].vida <= 0 && inimigos[indexInimigo].cor != 5)
        {

            cout << "\nInimigo Derrotado!\n\n\n\n\n\n\n";
            jogador.pontuacao += 200;
            jogador.exp += inimigos[indexInimigo].exp;
            if (!jogarSozinho) {
                system("pause");
            }
            system("cls");
            return -1;
        }

    }


}