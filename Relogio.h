#pragma once
using namespace std;

int minutos = 0;
int segundos = 0;

void relogio() {
    // Mantém o tempo entre chamadas
    static auto ultimo_update = chrono::steady_clock::now();

    auto agora = chrono::steady_clock::now();
    auto duracao = chrono::duration_cast<chrono::seconds>(agora - ultimo_update);

    if (duracao.count() >= 1) {
        ultimo_update = agora;  // Atualiza o tempo de referência

        // Atualiza tempo
        segundos++;
        if (segundos == 60) {
            segundos = 0;
            minutos++;
        }

        // Exibe o tempo
        cout << "\r Tempo: "
             << setfill('0') << setw(2) << minutos << ":"
             << setfill('0') << setw(2) << segundos
             << flush;
    }
}