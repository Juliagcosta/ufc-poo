#include <iostream>
#include <string>
using namespace std;

class Pessoa {
    public:string nome {""};
    public:string telefone;
    public:string conjunto;
    public:int cadeira;
    Pessoa(string nome, string telefone, int cadeira) {
        this->nome = nome;
        this->telefone = telefone;
        this->cadeira = cadeira;
        this->conjunto = nome + ':' + telefone;
    }
};

class Sala {
    Pessoa *pessoa;
    public:int espaco = 0;
    public:string salas[100];
    
    Sala(int espaco) {
        this->espaco = espaco;
    }
    
    void init() {
        for (int i = 1; i <= (2*espaco); i++) {
            if (i % 2 == 0) {
                salas[i] =  ' ';
            } else {
                salas[i] = '-';
            }
        }
    }
    
    void reservar(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        for (int i = 1; i <= (2*espaco); i++) {
            if (i == (pessoa->cadeira*2)-1) {
                if (salas[i] == "-") {
                    salas[i] = pessoa->conjunto;
                    cout << "A reserva de " << pessoa->nome << " foi confirmada.\n";
                } else {
                    cout << "Esta cadeira esta ocupada.\n";
                }
            }
        }
    }
    
    void cancelar(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        for (int i = 1; i <= (2*espaco); i++) {
            if (pessoa->conjunto == salas[i]) {
                salas[i] = '-';
                cout << "A reserva de " << pessoa->nome << " foi cancelada.\n";
            }
        }
    }
    
    void show() {
        cout << "[ ";
        for (int i = 1; i <= (2*espaco); i++) {
            cout << salas[i];
        }
        cout << "]\n";
    }
};

void Fluxo(int tamanho) {
    int x = 0, num, c;
    string n {""}, t {""};
    Sala sala {tamanho};
    
    sala.init();
    sala.show();
    
    cout << "Pressione 1 para reservar e 2 para cancelar uma reserva.";
    
    while (true) {
        cin >> num;
        
        if (num == 1) {
            cout << "Digite o nome: ";
            cin >> n;
            cout << "Digite telefone: ";
            cin >> t;
            cout << "Digite a cadeira: ";
            cin >> c;
            
            Pessoa pessoa {n, t, c};
            
            sala.reservar(&pessoa);
            sala.show();
        } if (num == 2) {
            cout << "Digite o nome: ";
            cin >> n;
            cout << "Digite telefone: ";
            cin >> t;
            cout << "Digite a cadeira: ";
            cin >> c;
            
            Pessoa pessoa {n, t, c};
            
            sala.cancelar(&pessoa);
            sala.show();
        }
    }
}

int main() {
    
    cout << "Vamos fazer uns testes: \n";
    
    cout << "[Inicialização] Insira o tamanho da sua sala de cinema:  ";
    
    int tamanho;
    cin >> tamanho;
    
    Fluxo(tamanho);
    
    return 1;
}
