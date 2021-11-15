#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Grafite {
    int dureza;
    int tamanho;
    float calibre;
    Grafite(float calibre, int dureza, int tamanho) {
        this->calibre = calibre;
        this->dureza = dureza;
        this->tamanho = tamanho;
    }
};

struct Lapiseira {
    Grafite *grafite;
    string tambor[100];
    int pos_tambor = 1;
    float calibrel = 0;
    int puxai = 1;
    int puxaf = 1;
    int i = 0;
    bool presente = false;
    
    Lapiseira(float calibrel) {
        this->calibrel = calibrel;
    }
    
    void inserir(Grafite *grafite) {
        this->grafite = grafite;
        
        if (grafite->calibre != 0 && grafite->tamanho != 0 && grafite->dureza == 1 || 2 || 4 || 6) {
                
                this->tambor[pos_tambor] = '[';
                this->tambor[pos_tambor+1] = to_string(grafite->calibre);
                this->tambor[pos_tambor+2] = ':';
                if (grafite->dureza == 1) {
                    this->tambor[pos_tambor+3] = 'H';
                } else {
                    this->tambor[pos_tambor+3] = to_string(grafite->dureza);
                }
                this->tambor[pos_tambor+4] = 'B';
                this->tambor[pos_tambor+5] = ':';
                this->tambor[pos_tambor+6] = to_string(grafite->tamanho);
                this->tambor[pos_tambor+7] = ']';
            
                this->pos_tambor += 8;
            }
    }
    
    void puxar() {
        if (presente) {
            cout << "Há um grafite no bico. Retire-o primeiro.\n";
        } else {
            this->puxaf += 8;
            this->presente = true;
            cout << "Você colocou um grafite no bico da lapiseira.\n";
        }
    }
    
    void remover() {
        this->presente = false;
        
        this->puxai = puxaf;
        
        cout << "Um grafite foi removido da lapiseira.\n";
    }
    
    void escrever(Grafite *grafite) {
        this->grafite = grafite;
        
        if (!presente || grafite->calibre != calibrel) {
            cout << "Não foi possível escrever.\n";
        } else if (grafite->dureza == 1 && grafite->tamanho >= 11) {
            grafite->tamanho -= 1;
            this->tambor[puxaf-2] = to_string(grafite->tamanho);
            cout << "Uma folha foi escrita!\n";
        } else if (grafite->dureza == 2 && grafite->tamanho >= 12) {
            grafite->tamanho -= 2;
            this->tambor[puxaf-2] = to_string(grafite->tamanho);
            cout << "Uma folha foi escrita!\n";
        } else if (grafite->dureza == 4 && grafite->tamanho >= 14) {
            grafite->tamanho -= 4;
            this->tambor[puxaf-2] = to_string(grafite->tamanho);
            cout << "Uma folha foi escrita!\n";
        } else if (grafite->dureza == 6 && grafite->tamanho >= 16) {
            grafite->tamanho -= 6;
            this->tambor[puxaf-2] = grafite->tamanho;
            cout << "Uma folha foi escrita!\n";
        } else {
            cout << "Grafite acabou! A folha ficou incompleta.\n";
        }
    }
    
    void show() {
        cout << setprecision(1) << fixed;
        
        cout << "calibre: " <<  calibrel << ", bico: {";
        for (i = puxai; i < puxaf; i++) {
            cout << tambor[i];
        }
        cout << "}, tambor: {";
        for (i = puxaf; i < pos_tambor; i++) {
            cout << tambor[i];
        }
        cout << "}.\n";
    }
};

int main() {
    
    cout << "Vamos fazer uns testes: \n";
    
    Lapiseira lap {0.5};
    Grafite g1 {0.5, 2, 20};
    Grafite g2 {0.7, 2, 10};
    Grafite g3 {0.5, 1, 12};
    Grafite g4 {0.5, 4, 17};
    Grafite g5 {0.5, 6, 18};
    Grafite g6 {0.5, 4, 2};
    
    cout << "\n#### GRAFITE 1 É INSERIDO ####\n";
    lap.inserir(&g1);
    lap.show();
    
    cout << "\n#### GRAFITE 2 É INSERIDO ####\n";
    lap.inserir(&g2);
    lap.show();
    
    cout << "\n#### PUXA GRAFITE E ESCREVE ####\n";
    lap.puxar();
    lap.show();
    lap.escrever(&g1);
    lap.show();
    lap.escrever(&g1);
    lap.show();
    lap.escrever(&g1);
    lap.show();
    lap.escrever(&g1);
    lap.show();
    lap.escrever(&g1);
    lap.escrever(&g1);
    
    cout << "\n#### REMOVE, PUXA E INSERE GRAFITES ####\n";
    lap.remover();
    lap.show();
    lap.inserir(&g3);
    lap.inserir(&g4);
    lap.inserir(&g5);
    lap.show();
    lap.puxar();
    lap.escrever(&g2);
    lap.remover();
    lap.puxar();
    lap.show();
    lap.remover();
    lap.puxar();
    lap.remover();
    lap.puxar();
    lap.show();
    lap.escrever(&g5);
    lap.remover();
    lap.show();
    
    return 1;
}
