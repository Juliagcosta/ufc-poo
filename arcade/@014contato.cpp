#include <iostream>
#include <string>
using namespace std;

class Telefone {
    public:string label;
    public:string telefone;
    public:string conjunto;
    public:bool valido = true;
    Telefone(string label, string telefone) {
        this->label = label;
        this->telefone = telefone;
        this->conjunto = ':' + label + ':' + telefone;
        
        int i = 0;
        while (telefone[i] != '\0') {
            if (!((telefone[i] <= '9' && telefone[i] >= '0') || telefone[i] == ')' || telefone[i] == '(')) {
                cout << "Esse número é inválido\n";
                this->valido = false;
                break;
            }
            i++;
        }
    }
};

class Contato {
    Telefone *telefone;
    public:string nome {""};
    public:string ordem[100];
    public:int skip[100];
    public:int in = 0;
    public:bool val = true;
    
    Contato(string nome) {
        this->nome = nome;
    }
    
    void inserir(Telefone *telefone) {
        this->telefone = telefone;
        
        this->ordem[in] = telefone->conjunto;
        this->skip[in] = 0;
        this->val = telefone->valido;
        if (!val) {
            skip[in] = 1;
        }
        this->in++;
    }
    
    void remover(int indice) {
        this->skip[indice] = 1;
    }
    
    void show() {
        int num = 0;
        
        cout << " " << nome << " ";
        for (int i = 0; i < in; i++) {
            if (skip[i] != 1) {
                cout << "[";
                cout << num;
                cout << ordem[i];
                cout << "]";
                num++;
            }
        }   
        cout << "\n";
    }
};

int main() {
    
    cout << "Vamos fazer uns testes: \n";
    
    cout << "Insira o nome do contato: ";
    
    string contato {""};
    cin >> contato;
    
    Contato c {contato};
    
    cout << "Pressione 1 para salvar um novo número e 2 para apagar um número existente.";
    int num;
    
    while (true) {
        cin >> num;
        
        if (num == 1) {
            string l {""};
            string n {""};
            
            cout << "\n Digite a label do número: ";
            cin >> l;
            cout << "\nDigite o número: ";
            cin >> n;
            
            Telefone t {l, n};
            c.inserir(&t);
            c.show();
        } if (num == 2) {
            cout << "\n Qual número remover? ";
            
            int r;
            cin >> r;
            
            c.remover(r);
            c.show();
        }
    }
    
    return 1;
}
