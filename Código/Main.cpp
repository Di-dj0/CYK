<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ehMaiusculo(char c);

class Simbolo {
    
    vector <Simbolo> conexoes;                                           //Quais conexoes possui
    char nome;                                                           //Nome do simbolo

public:

    Simbolo(char n) {
        
        nome = n;
    }

    void setConexoes(Simbolo c) {

        conexoes.push_back(c);
    }

    Simbolo getConexoes(int n) {

        return conexoes[n];
    }

    char getNome() {

        return nome;
    }

    int getQntConexoes(){
        
        return conexoes.size();
    }

};

// int Simbolo::maximo = 0;

int main() {

    int numleituras, k = 0, tamPalavra = 0, qtdConex = 0;
    vector <Simbolo> linguagem;
    string simb, lixo, conexao, entrada;
    vector <Simbolo> :: iterator posicao;

    cin >> numleituras;

    for(int i = 0; i < numleituras; i++){
        
        cin >> simb >> lixo >> conexao;                                     //Le o simbolo, o lixo(->) e a conexao
        //cout << simb << " " << conexao << endl;

        if(ehMaiusculo(simb[0])) {                                          //Verifica se eh letra maiuscula (obedece a chomsky)

        bool jaExiste = false;

            for(int j = 0; j < linguagem.size(); j++) {

                if(simb[0] == linguagem[j].getNome()) {

                    jaExiste = true;

                    // cout << "ja existe" << endl;

                    if(ehMaiusculo(conexao[0])) {                          //Caso a conexao nao seja terminal

                        linguagem[j].setConexoes(conexao[0]);               //Seta mais conexoes a esse simbolo
                        linguagem[j].setConexoes(conexao[1]);
                        

                        // cout << "nao eh terminal" << endl;
                    }

                    else {                                                 //Caso seja terminal
                        linguagem[j].setConexoes(conexao[0]);               //Seta mais uma conexao a esse simbolo

                        // cout << "eh terminal" << endl;
                    }
                    continue;
                }
            }

            if(jaExiste == false) {                                        //Se nao existia esse simbolo

                // cout << "nao existe" << endl;

                linguagem.push_back(Simbolo(simb[0]));                      //Coloca no final do vector

                /*
                se esse cara de iterador funcionar, o trem todo funciona!
                */

                if(i == 0) {                                               //Inicializa o iterador em um ponto que existe
                    posicao = linguagem.begin();
                    k++;
                }
                else {
                    posicao = linguagem.begin() + k;
                    k++;
                }

                // cout << "colocou " << (*posicao).getNome() << endl;

                if(ehMaiusculo(conexao[0])) {                             //Caso a conexao nao seja terminal
                    (*posicao).setConexoes(conexao[0]);                   //Seta mais conexoes a esse simbolo
                    (*posicao).setConexoes(conexao[1]);

                    // cout << "nao eh terminal" << endl;
                }

                else {                                                    //Caso seja terminal
                    (*posicao).setConexoes(conexao[0]);                   //Seta mais uma conexao a esse simbolo

                    // cout << "eh terminal" << endl;
                }
            }
        }

        // cout << "qnt em conexoes:" << (*posicao).getQntConexoes() << endl;

        // cout << "finaliza o loop" << endl;
    }

    /* for(int j = 0; j < linguagem.size(); j++){                             //Teste do linguagem

        cout << '\n' << linguagem[j].getNome() << " - ";

        for(int i = 0; i < linguagem[j].getQntConexoes(); i++){

            cout << linguagem[j].getConexoes(i).getNome();

        }

        cout << endl;
    } */

    
    /* Checa o maximo de conexoes possivel */
    for(int i = 0;i < linguagem.size();i++) {
        qtdConex += linguagem[i].getQntConexoes();
    }



    while(1) {
        
        cin >> entrada;

        tamPalavra = entrada.length();

        if(tamPalavra == 0 || entrada == "*"){
            break;
        }

        /*Inicio da logica*/

        char table[tamPalavra][tamPalavra][qtdConex] = {};

        for(int i = 0; i < tamPalavra; i++) {

            int aux = 0;
            for(int j = 0; j < linguagem.size(); j++){

                for(int k = 0; k < linguagem[j].getQntConexoes(); k++){

                    if(entrada[i] == linguagem[j].getConexoes(k).getNome()){

                        table[i][i][aux] = linguagem[j].getNome();
                        
                        cout << table[i][i][aux] << endl;
                        aux++;
                    }
                }
            }
        }
        

    }

    return 0;

}

bool ehMaiusculo(char c) {
    if(c >= 65 && c <= 90) 
        return true;
    else 
        return false;
}

//Testing

/*
7
S -> AX
S -> AB
R -> AX
X -> RB
R -> AB
A -> a
B -> b
aabb
*/

/*
41
S -> AX
S -> RY
S -> RZ
S -> RW
S -> RP
S -> 0
S -> 1
S -> 2
S -> 3
S -> 4
S -> 5
S -> 6
S -> 7
S -> 8
S -> 9
R -> AX
R -> RY
R -> RZ
R -> RW
R -> RP
R -> 0
R -> 1
R -> 2
R -> 3
R -> 4
R -> 5
R -> 6
R -> 7
R -> 8
R -> 9
X -> RF
Y -> MR
Z -> BR
W -> VR
P -> DR
A -> (
F -> )
M -> +
B -> -
V -> *
D -> /
=======
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ehMaiusculo(char c);

class Simbolo {
    
    vector <Simbolo> conexoes;                                           //Quais conexoes possui
    char nome;                                                           //Nome do simbolo

public:

    Simbolo(char n) {
        
        nome = n;
    }

    void setConexoes(Simbolo c) {

        conexoes.push_back(c);
    }

    Simbolo getConexoes(int n) {

        return conexoes[n];
    }

    char getNome() {

        return nome;
    }

    int getQntConexoes(){
        
        return conexoes.size();
    }

};

// int Simbolo::maximo = 0;

int main() {

    int numleituras, k = 0, tamPalavra = 0, qtdConex = 0;
    vector <Simbolo> linguagem;
    string simb, lixo, conexao, entrada;
    vector <Simbolo> :: iterator posicao;

    cin >> numleituras;

    for(int i = 0; i < numleituras; i++){
        
        cin >> simb >> lixo >> conexao;                                     //Le o simbolo, o lixo(->) e a conexao
        //cout << simb << " " << conexao << endl;

        if(ehMaiusculo(simb[0])) {                                          //Verifica se eh letra maiuscula (obedece a chomsky)

        bool jaExiste = false;

            for(int j = 0; j < linguagem.size(); j++) {

                if(simb[0] == linguagem[j].getNome()) {

                    jaExiste = true;

                    // cout << "ja existe" << endl;

                    if(ehMaiusculo(conexao[0])) {                          //Caso a conexao nao seja terminal

                        linguagem[j].setConexoes(conexao[0]);               //Seta mais conexoes a esse simbolo
                        linguagem[j].setConexoes(conexao[1]);
                        

                        // cout << "nao eh terminal" << endl;
                    }

                    else {                                                 //Caso seja terminal
                        linguagem[j].setConexoes(conexao[0]);               //Seta mais uma conexao a esse simbolo

                        // cout << "eh terminal" << endl;
                    }
                    continue;
                }
            }

            if(jaExiste == false) {                                        //Se nao existia esse simbolo

                // cout << "nao existe" << endl;

                linguagem.push_back(Simbolo(simb[0]));                      //Coloca no final do vector

                /*
                se esse cara de iterador funcionar, o trem todo funciona!
                */

                if(i == 0) {                                               //Inicializa o iterador em um ponto que existe
                    posicao = linguagem.begin();
                    k++;
                }
                else {
                    posicao = linguagem.begin() + k;
                    k++;
                }

                // cout << "colocou " << (*posicao).getNome() << endl;

                if(ehMaiusculo(conexao[0])) {                             //Caso a conexao nao seja terminal
                    (*posicao).setConexoes(conexao[0]);                   //Seta mais conexoes a esse simbolo
                    (*posicao).setConexoes(conexao[1]);

                    // cout << "nao eh terminal" << endl;
                }

                else {                                                    //Caso seja terminal
                    (*posicao).setConexoes(conexao[0]);                   //Seta mais uma conexao a esse simbolo

                    // cout << "eh terminal" << endl;
                }
            }
        }

        // cout << "qnt em conexoes:" << (*posicao).getQntConexoes() << endl;

        // cout << "finaliza o loop" << endl;
    }

    /* for(int j = 0; j < linguagem.size(); j++){                             //Teste do linguagem

        cout << '\n' << linguagem[j].getNome() << " - ";

        for(int i = 0; i < linguagem[j].getQntConexoes(); i++){

            cout << linguagem[j].getConexoes(i).getNome();

        }

        cout << endl;
    } */

    
    /* Checa o maximo de conexoes possivel */
    for(int i = 0;i < linguagem.size();i++) {
        qtdConex += linguagem[i].getQntConexoes();
    }



    while(1) {
        
        cin >> entrada;

        tamPalavra = entrada.length();

        if(tamPalavra == 0 || entrada == "*"){
            break;
        }

        /*Inicio da logica*/

        char table[tamPalavra][tamPalavra][qtdConex] = {};

        for(int i = 0; i < tamPalavra; i++) {

            int aux = 0;
            for(int j = 0; j < linguagem.size(); j++){

                for(int k = 0; k < linguagem[j].getQntConexoes(); k++){

                    if(entrada[i] == linguagem[j].getConexoes(k).getNome()){

                        table[i][i][aux] = linguagem[j].getNome();
                        
                        cout << table[i][i][aux] << endl;
                        aux++;
                    }
                }
            }
        }
        

    }

    return 0;

}

bool ehMaiusculo(char c) {
    if(c >= 65 && c <= 90) 
        return true;
    else 
        return false;
}

//Testing

/*
7
S -> AX
S -> AB
R -> AX
X -> RB
R -> AB
A -> a
B -> b
aabb
*/

/*
41
S -> AX
S -> RY
S -> RZ
S -> RW
S -> RP
S -> 0
S -> 1
S -> 2
S -> 3
S -> 4
S -> 5
S -> 6
S -> 7
S -> 8
S -> 9
R -> AX
R -> RY
R -> RZ
R -> RW
R -> RP
R -> 0
R -> 1
R -> 2
R -> 3
R -> 4
R -> 5
R -> 6
R -> 7
R -> 8
R -> 9
X -> RF
Y -> MR
Z -> BR
W -> VR
P -> DR
A -> (
F -> )
M -> +
B -> -
V -> *
D -> /
>>>>>>> f714cbee72a6e1ed23bf3f61e21c7263ab1f1025
*/