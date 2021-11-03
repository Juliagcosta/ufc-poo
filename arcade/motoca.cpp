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
    bool alguem = false;

    Moto(int potencia) {
        this->potencia = potencia;
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
    
    void dirigir(int minutos, Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        if (alguem) {
            if (pessoa->idade <= 10) {
                int quanto = 0;
                
                while (minutos > 0) {
                    quanto++;
                    minutos--;
                }
                if (minutos == 0) {
                    std::cout << "O tempo acabou. " << pessoa->nome << " andou " << quanto << " minutos.";
                }
            } 
        } else {
            std::cout << pessoa->nome << " não pôde andar na motoca.";
        }
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
    
    void show(Pessoa *pessoa) {
        this->pessoa = pessoa;
        
        std::cout << "potencia: " << potencia << ", minutos: " << minutos << ", pessoa: [" << pessoa->nome << "," << pessoa->idade << "].";
    }
};

int main() {
    
    std::cout << "Selecione a potência da motoca:\n";
    
    int np;
    std::cin >> np;
    
    if (np == 0) {
        std::cout << "Digite uma potência maior que zero.\n";
        std::cin >> np;
    }
    
    Moto moto {np};
    
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
    
    std::cout << "Quanto tempo você quer comprar?\n";
    
    int tempo;
    std::cin >> tempo;
    
    for (int i = 0; i < tempo; i++) {
        moto.comprar_t(0);
    }
    
    std::cout << "\n----------------------------------\n";
    
    if (n == 1 || n1 == 1) {
        std::cout << "|-----MARTHA-----|\n";
        moto.subir(&marta);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &marta);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&marta);
        std::cout << "\n[Show] ";
        moto.show(&marta);
        moto.descer(&marta);
    } if (n == 2 || n1 == 2) {
        std::cout << "|-----CAIO-----|\n";
        moto.subir(&caio);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &caio);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&caio);
        std::cout << "\n[Show] ";
        moto.show(&caio);
        moto.descer(&caio);
    } if (n == 3 || n1 == 3) {
        std::cout << "|-----JÚNIOR-----|\n";
        moto.subir(&junior);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &junior);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&junior);
        std::cout << "\n[Show] ";
        moto.show(&junior);
        moto.descer(&junior);
    }
    
    std::cout << "\n";
    
    //N2
    
    if (n2 == 1) {
        std::cout << "\n|-----MARTHA-----|\n";
        moto.subir(&marta);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &marta);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&marta);
        std::cout << "\n[Show] ";
        moto.show(&marta);
    } if (n2 == 2) {
        std::cout << "\n|-----CAIO-----|\n";
        moto.subir(&caio);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &caio);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&caio);
        std::cout << "\n[Show] ";
        moto.show(&caio);
    } if (n2 == 3) {
        std::cout << "\n|-----JÚNIOR-----|\n";
        moto.subir(&junior);
        std::cout << "[Dirigir] ";
        moto.dirigir(tempo, &junior);
        std::cout << "\n[Buzinar] ";
        moto.buzinar(&junior);
        std::cout << "\n[Show] ";
        moto.show(&junior);
    } 
    
    
    return 1;
}
