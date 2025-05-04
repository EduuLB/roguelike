#pragma once


struct Jogador
{
    int x = 5, y = 1;
    int vida = 10;
    int pontuacao = 0;
    int pocao = 0;
    int chave = 0;
    int dano = 2;
};

struct Inimigo
{
    int vida = 5;
    int x = 0, y = 0;
    int acao = 0;
    int dano = 2;
};
