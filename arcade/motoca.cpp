#include <iostream>

struct Pessoa {
    std::string nome {""};
    int idade = 0;
    Pessoa(std::string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
    }
};

struct Moto {
    Pessoa *pessoa;
    int potencia {1};
    int minutos {0};
    int dirige {0};
    bool alguem = false;

    Moto(int potencia, int dirige) {
        this->potencia = potencia;
        this->dirige = dirige;
    }
    
    void comprar_t(int minutos) {
        this->minutos++;
    }
    
    void subir(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        if(pessoa->idade <= 10) {
            std::cout << "\n" <<pessoa->nome << " sobe.\n";
            this->pessoa = pessoa;
            this->alguem = true;
        }    
    }
    
    void descer(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        if (alguem) {
            this->alguem = false;
            std::cout << "\n" <<pessoa->nome << " desce.\n";
        }
    }
    
    bool dirigir(int minutos, Pessoa *pessoa, int dirige) {
        this->pessoa = pessoa;
        
        if (alguem) {
            if (pessoa->idade <= 10) {
                int quanto = 0;
                
                while (minutos > 0 && dirige > 0) {
                    quanto++;
                    minutos--;
                    dirige--;
                }
                if (minutos == 0) {
                    std::cout << "O tempo acabou. " << pessoa->nome << " andou " << quanto << " minutos.";
                } else if (dirige == 0) {
                    std::cout << pessoa->nome << " andou " << quanto << " minutos.";
                }
            } 
        } else {
            std::cout << pessoa->nome << " não pôde andar na motoca.";
            return false;
        }
        return true;
    }
    
    void buzinar(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        if (alguem) {
            std::cout << pessoa->nome << " buzinou: ";
            
            std::cout << "P";

            for (int i = 0; i < potencia; i++) {
                std::cout << "E";
            }
            
            std::cout << "M!!!";
        } else {
            std::cout << pessoa->nome << " não estava na motoca.";
        }
    }
    
    int show(Pessoa *pessoa, int tempo, int dirige, bool alguem) {
        this->pessoa = pessoa;
        
        for (int i = 0; i < tempo; i++) {
            comprar_t(0);
        }
        
        if (!alguem) {
            minutos = tempo;
        } else if (tempo > dirige){
            minutos = tempo - dirige;
        } else {
            minutos = 0;
        }
        
        std::cout << "potencia: " << potencia << ", minutos: " << minutos << ", pessoa: [" << pessoa->nome << "," << pessoa->idade << "].";
        
        return minutos;
    }
};

int solver(Pessoa *pessoa, int np, int dirige, int tempo) {
    Moto moto {np, dirige};
    
    moto.subir(pessoa);
    std::cout << "[Dirigir] ";
    bool alguem = moto.dirigir(tempo, pessoa, dirige);
    std::cout << "\n[Buzinar] ";
    moto.buzinar(pessoa);
    std::cout << "\n[Show] ";
    int restantes = moto.show(pessoa, tempo, dirige, alguem);
    moto.descer(pessoa);
    
    return restantes;
}

int main() {
    
    std::cout << "Selecione a potência da motoca:\n";
    
    int np;
    std::cin >> np;
    
    if (np == 0) {
        std::cout << "Digite uma potência maior que zero.\n";
        std::cin >> np;
    }
    
    std::cout << "Nossa motoca tem a potência " << np << ".\n ----------------------------------\n";
    
    std::cout << "Selecione uma pessoa para testar:\n 1 - Marta, 12 anos\n 2 - Caio, 7 anos\n 3 - Júnior, 10 anos\n 4 - Para testar 2 pessoas em sequência.\n";
    
    Pessoa marta {"Marta", 12};
    Pessoa caio {"Caio", 7};
    Pessoa junior {"Júnior", 10};
    
    int n, n1, n2;
    std::cin >> n;
    
    if (n == 4) {
        std::cin >> n1 >> n2;
    }
    
    if (n == 4) {
        std::cout << "Quanto o primeiro quer dirigir?\n";
    } else {
        std::cout << "Quanto tempo você quer dirigir?\n";
    }
    
    int dirige;
    std::cin >> dirige;
    
    Moto moto {np, dirige};
    
    std::cout << "Quanto tempo você quer comprar?\n";
    
    int tempo;
    std::cin >> tempo;
    
    for (int i = 0; i < tempo; i++) {
        moto.comprar_t(0);
    }
    
    std::cout << "\n----------------------------------\n";
    
    int restantes;
    
    if (n == 1 || n1 == 1) {
        std::cout << "|-----MARTHA-----|\n";
        restantes = solver(&marta, np, dirige, tempo);
    } if (n == 2 || n1 == 2) {
        std::cout << "|-----CAIO-----|\n";
        restantes = solver(&caio, np, dirige, tempo);
    } if (n == 3 || n1 == 3) {
        std::cout << "|-----JÚNIOR-----|\n";
        restantes = solver(&junior, np, dirige, tempo);
    }
    
    std::cout << "\n";
    
    //N2
    
    if (n == 4) {
        std::cout << "\nQuanto o segundo quer dirigir?\n";
    }
    
    int dirige2;
    std::cin >> dirige2;
    
    if (n2 == 1) {
        std::cout << "\n|-----MARTHA-----|\n";
        solver(&marta, np, dirige2, restantes);
    } if (n2 == 2) {
        std::cout << "\n|-----CAIO-----|\n";
        solver(&caio, np, dirige2, restantes);
    } if (n2 == 3) {
        std::cout << "\n|-----JÚNIOR-----|\n";
        solver(&junior, np, dirige2, restantes);
    } 
    
    return 1;
}
