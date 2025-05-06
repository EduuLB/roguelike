#pragma once

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
    corTexto(4);
    cout << jogador.pontuacao << "!! \n\n\n";
    corTexto(7);
    exit(0);

}


int batalha(Jogador& jogador, Inimigo inimigos[8], int indexInimigo)
{

    while (jogador.vida > 0)
    {
        system("cls");
        cout << "\n\nVidas: " << jogador.vida << "  ||  Pontuacao: " << jogador.pontuacao << " || Usos da Pocao: " << jogador.pocao << " || Chave: " << jogador.chave << " \n\nVida Do Inimigo: " << inimigos[indexInimigo].vida << " \n";
        cout << "\n\n";
        if (indexInimigo == 7) // index do boss
        {
            centralizarTexto("Voce encontrou O Chefe! Se prepare");
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
        cin >> escolha;

        inimigos[indexInimigo].acao = rand() % 3;
        if (escolha == '1')   // Pedra
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPedra X Pedra, nada aconteceu\n";

            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPedra X Papel, Voce tomou Dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPedra X Tesoura, Voce causou Dano""\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
        }
        else if (escolha == '2')   // Papel
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nPapel X Pedra, Voce causou Dano\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nPapel X Papel, nada aconteceu\n";
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nPapel X Tesoura, Voce tomou dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }

        }
        else if (escolha == '3')   // Tesoura
        {
            if (inimigos[indexInimigo].acao == 0)
            {
                cout << "\nTesoura X Pedra, voce tomou dano!\n";
                jogador.vida -= inimigos[indexInimigo].dano;
            }
            else if (inimigos[indexInimigo].acao == 1)
            {
                cout << "\nTesoura X Papel, voce causou dano!\n";
                inimigos[indexInimigo].vida -= jogador.dano;
            }
            else if (inimigos[indexInimigo].acao == 2)
            {
                cout << "\nTesoura X Tesoura, nada aconteceu\n";
            }

        }
        else
        {
            cout << "\n escolha Invalida!";

        }
        system("pause");

        if (inimigos[indexInimigo].vida <= 0 && indexInimigo == 7)
        {

            jogador.pontuacao += (jogador.vida * 150);
            jogador.pontuacao += 1000;
            system("cls");
            venceu(jogador);
            break;

        }
        if (inimigos[indexInimigo].vida <= 0 && indexInimigo < 7)
        {

            cout << "\nInimigo Derrotado!\n\n\n\n\n\n\n";
            jogador.pontuacao += 200;
            jogador.exp += 10;
            system("pause");
            system("cls");
            return -1;
        }




    }


}