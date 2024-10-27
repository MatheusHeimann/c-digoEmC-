#include <iostream>
#include <string>

using namespace std;

// Função para verificar se o valor do empréstimo excede 30% da renda
bool verificaRenda(double renda, double valorEmprestimo) {
    return valorEmprestimo <= (0.3 * renda);
}

// Função para verificar histórico de crédito (bom/mau)
bool verificaCredito(string historico) {
    return historico == "bom";
}

// Função para verificar estabilidade no emprego (sim/não)
bool verificaEstabilidade(string estabilidade) {
    return estabilidade == "sim";
}

int main() {
    double renda, valorEmprestimo, valorEntrada;
    string historicoCredito, estabilidadeEmprego;

    // Coleta de informações do usuário
    cout << "Informe a renda mensal: ";
    cin >> renda;

    cout << "Informe o valor do emprestimo desejado: ";
    cin >> valorEmprestimo;

    cout << "Informe o valor da entrada: ";
    cin >> valorEntrada;

    cout << "Informe o historico de credito (bom/mau): ";
    cin >> historicoCredito;

    cout << "Voce tem estabilidade no emprego? (sim/nao): ";
    cin >> estabilidadeEmprego;

    // Verificação dos critérios
    bool rendaValida = verificaRenda(renda, valorEmprestimo);
    bool creditoValido = verificaCredito(historicoCredito);
    bool estabilidadeValida = verificaEstabilidade(estabilidadeEmprego);

    // Condicional para aprovação
    if (rendaValida && creditoValido && estabilidadeValida) {
        cout << "Emprestimo aprovado!" << endl;
    } else {
        cout << "Emprestimo negado." << endl;
        // Explicação dos motivos da rejeição
        if (!rendaValida) cout << "Motivo: O valor do emprestimo excede 30% da sua renda mensal." << endl;
        if (!creditoValido) cout << "Motivo: Historico de credito ruim." << endl;
        if (!estabilidadeValida) cout << "Motivo: Falta de estabilidade no emprego." << endl;
    }

    return 0;
}
