#pragma once



struct Jogador
{
    int x = 5, y = 1;
    int vida = 10;
    int vidaMaxima = 10;
    int pontuacao = 0;
    int pocao = 0;
    int pocaoGrande = 1;
    int chave = 0;
    int dano = 2;
    int exp = 0;
    int expNecessaria = 100;
    int nivel = 1;
    int critico = 20;
    int visual = 89;
    int cor = 7;
    int mapa = 0;
    int armadura = 0;
};

struct Inimigo
{
    int vida = 5;
    int x = 0, y = 0;
    int acao = 0;
    int dano = 2;
    int velocidade = 700;
    int visual = 35;
    int cor = 7;
    int exp = 10;
};

