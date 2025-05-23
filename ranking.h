#pragma once
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
bool comparaDecrescente(const T& a, const T& b) {
    return a > b;
}

void salvaRanking(string nome = "Jogador", int pontuacao = 0, string tempo = "00:00") {
	ofstream arquivo("ranking.txt", ios::app); //  ios::app = abrir em modo de ADICAO, para nao substituir oque ja tem

	if (arquivo.is_open()) {
		arquivo << nome << "\t|\t" << pontuacao << "\t|\t" << tempo << "\n";
		arquivo.close();
	} else {
		cerr << "Erro ao abrir o arquivo ranking.txt para salvar." << endl;
	}
}

void leRanking() {
	// Abre o arquivo "ranking.txt" para leitura
	ifstream arquivo("ranking.txt");

	if (arquivo.is_open()) {  // Verifica se o arquivo foi aberto com sucesso
		string linha;    // VARIAVEL para armazenar cada linha lida do arquivo
		vector<Jogador> registro;  // Vetor para armazenar todos os jogadores

		// Pular o cabecalho (primeira linha do arquivo)
		getline(arquivo, linha);

		// LC* o arquivo linha por linha ate o final
		while (getline(arquivo, linha)) {
			// Encontra a posicao do primeiro separador '|'
			size_t pos1 = linha.find('|');
			// Encontra a posicao do segundo separador '|'
			size_t pos2 = linha.find('|', pos1 + 1);

			Jogador j;  // Cria um novo struct Jogador para armazenar os dados

			// Extrai o nome (tudo antes do primeiro '|')
			j.nome = linha.substr(0, pos1);
			// Remove espacos em branco do final do nome
			j.nome.erase(j.nome.find_last_not_of(" \t") + 1);

			// Extrai a string do score (entre os dois '|')
			string scoreStr = linha.substr(pos1 + 1, pos2 - pos1 - 1);
			// Remove espacos em branco do inicio e fim da string do score
			scoreStr.erase(0, scoreStr.find_first_not_of(" \t"));
			// Converte a string do score para inteiro
			j.pontuacao = stoi(scoreStr);

			// Extrai o tempo (tudo depois do segundo '|')
			j.tempo = linha.substr(pos2 + 1);
			// Remove espacos em branco do inicio do tempo
			j.tempo.erase(0, j.tempo.find_first_not_of(" \t"));

			// Adiciona o jogador ao vetor de registro
			registro.push_back(j);
		}
		arquivo.close();  // Fecha o arquivo apC3s a leitura

		// Ordena o vetor de jogadores por score em ordem decrescente
        sort(registro.begin(), registro.end(), [](const Jogador& a, const Jogador& b) {
            return comparaDecrescente(a.pontuacao, b.pontuacao);
        });

		// Imprime o cabecalho do ranking
		cout << "Nome\t|\tScore\t|\tTempo" << "\n";
        // Percorre todos os jogadores do vetor registro usando C-ndice
		for (size_t i = 0; i < registro.size(); i++) {  // i vai de 0 ate tamanho-1
			// Imprime nome com e separador |
			cout << registro[i].nome << "\t|\t";

			// Imprime score com  e separador |
			cout << registro[i].pontuacao << "\t|\t";

			// Imprime tempo e quebra de linha
			cout << registro[i].tempo << "\n";
		}
	} else {
		// Mensagem de erro se nao conseguir abrir o arquivo
		cerr << "Erro ao abrir o arquivo ranking.txt para leitura." << endl;
	}
}

/* int main() {
	salvaRanking();
	salvaRanking("Ismael", 989, "10:05");
	salvaRanking("Eduardo", 250, "25:41");
	leRanking();
	return 0;
} */