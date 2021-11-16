#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Crianca {
    string nome {""};
    int idade;
    int dinheiro;
    Crianca(string nome, int idade, int dinheiro) {
        this->nome = nome;
        this->idade = idade;
        this->dinheiro = dinheiro;
    }
};

struct PulaPula {
    Crianca *crianca;
    string fila[200];
    int posicao = 1;
    int inicio = 1;
    int final = 1;
    int quantos = 0;
    int custo = 0;
    int caixa = 0;
    int i = 0;
    
    PulaPula(float custo) {
        this->custo = custo;
    }
    
    void inserir(Crianca *crianca) {
        this->crianca = crianca;
        
        if (crianca->idade <= 10) {
            
                this->fila[posicao] = crianca->nome;
                this->fila[posicao+1] = ':';
                this->fila[posicao+2] = to_string(crianca->idade);
                this->fila[posicao+3] = ' ';
                
                this->posicao += 4;
                
                cout << crianca->nome << " entrou na fila!\n";
        } else {
            cout << "Esta criança é muito grande para entrar no pula-pula.\n";
        }
    }
    
    void entra(Crianca *crianca) {
        this->crianca = crianca;
        this->quantos++;
        
        if (quantos < 4 && crianca->dinheiro >= custo) {
            this->final += 4;
            this->caixa += custo;
            crianca->dinheiro -= custo;
            cout << "Hora da diversao. " << crianca->nome << " entrou no pula-pula. Aproveite!\n";
        } else if (quantos >= 4){
            cout << "Tem muitas crianças no Pula-Pula, espere uma sair.\n";
        } else {
            this->final += 4;
            remover();
        }
    }
    
    void remover() {
        this->quantos--;
        this->inicio = final;
        cout << "Vemos você na próxima!\n";
    }
    
    void remover_voltar() {
        int num = (final - inicio)/4;
        this->quantos -= num;
        
        for (i = inicio; i < final; i++) {
            this->fila[posicao] = fila[i];
            posicao++;
        }
        
        cout << "Tchau! Vamos de novo?\n";
        
        this->inicio = final;
    }
    
    void show() {
        cout << "vvv-------------------vvv\n";
        cout << "[ ";
        for (i = inicio; i < final; i++) {
            cout << fila[i];
        }
        cout << "] <= ";
        for (i = final; i < posicao; i++) {
            cout << fila[i];
        }
        cout << "<=.\n";
        cout << "Caixa: " << this->caixa << endl;
        cout << "^^^-------------------^^^\n";
    }
};

int main() {
    
    cout << "Vamos fazer uns testes: \n";
    
    PulaPula p {2};
    Crianca yasmin {"Yasmin", 4, 6};
    Crianca mirian {"Mírian", 10, 2};
    Crianca jose {"José", 12, 4};
    Crianca alice {"Alice", 8, 10};
    Crianca lucas {"Lucas", 5, 8};
    Crianca amanda {"Amanda", 6, 8};
    
    p.inserir(&yasmin);
    p.show();
    p.inserir(&mirian);
    p.show();
    p.entra(&yasmin);
    p.entra(&mirian);
    p.show();
    p.inserir(&jose);
    p.inserir(&alice);
    p.show();
    p.remover_voltar();
    p.show();
    p.entra(&alice);
    p.show();
    p.inserir(&lucas);
    p.show();
    p.entra(&yasmin);
    p.show();
    p.inserir(&amanda);
    p.remover_voltar();
    p.entra(&mirian);
    p.show();
    p.entra(&lucas);
    p.entra(&amanda);
    p.entra(&alice);
    p.entra(&yasmin);
    
    return 1;
}
