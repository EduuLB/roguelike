#pragma once

void moverInimigo(Inimigo& inimigo){

    int direcao = rand() % 4;
    int posX = inimigo.x;
    int posY = inimigo.y;

    switch (direcao) {
    case 0: posY--; break; // cima
    case 1: posY++; break; // baixo
    case 2: posX--; break; // esquerda
    case 3: posX++; break; // direita
    }

    // Verifica se pode andar
    if (mapa[posX][posY] == 0) {
        inimigo.x = posX;
        inimigo.y = posY;
        return;
    } else {
        moverInimigo(inimigo);
    }
}

void moverInimigos(Inimigo inimigos[7]) {
    for (int i = 0; i <= 6; i++) {
        moverInimigo(inimigos[i]);
    }
}