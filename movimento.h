#pragma once

void moverInimigo(Inimigo inimigos[7])
{
    int direcao = rand() % 4; // 0: cima, 1: baixo, 2: esquerda, 3: direita
    for (int indexInimigo = 0; indexInimigo <= 6; indexInimigo++)
        switch (direcao)
        {
        case 0: // cima
            if (mapa[inimigos[indexInimigo].x - 1][inimigos[indexInimigo].y] == 0)
                inimigos[indexInimigo].x--;
            break;
        case 1: // baixo
            if (mapa[inimigos[indexInimigo].x + 1][inimigos[indexInimigo].y] == 0)
                inimigos[indexInimigo].x++;
            break;
        case 2: // esquerda
            if (mapa[inimigos[indexInimigo].x][inimigos[indexInimigo].y - 1] == 0)
                inimigos[indexInimigo].y--;
            break;
        case 3: // direita
            if (mapa[inimigos[indexInimigo].x][inimigos[indexInimigo].y + 1] == 0)
                inimigos[indexInimigo].y++;
            break;
        }

}