#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Simbolo {
    
    vector <Simbolo> conexoes;                                          //Quais conexoes possui
    char nome;                                                          //Nome do simbolo

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

int main() {

    int numleituras, k = 0;
    vector <Simbolo> alfabeto;
    string simb, lixo, conexao;
    vector <Simbolo> :: iterator posicao;

    cin >> numleituras;

    for(int i = 0; i < numleituras; i++){
        
        cin >> simb >> lixo >> conexao;                                 //Le o simbolo, o lixo(->) e a conexao
        //cout << simb << " " << conexao << endl;

        if(simb[0] >= 65 && simb[0] <= 90) {                            //Verifica se eh letra maiuscula (obedece a chomsky)

        bool jaExiste = false;

            for(int j = 0; j < alfabeto.size(); j++) {

                if(simb[0] == alfabeto[j].getNome()) {

                    jaExiste = true;

                    // cout << "ja existe" << endl;

                    if(conexao[0] >= 65 && conexao[0] <= 90) {             //Caso a conexao nao seja terminal

                        alfabeto[j].setConexoes(conexao[0]);               //Seta mais conexoes a esse simbolo
                        alfabeto[j].setConexoes(conexao[1]);

                        // cout << "nao eh terminal" << endl;
                    }

                    else {                                                 //Caso seja terminal
                        alfabeto[j].setConexoes(conexao[0]);               //Seta mais uma conexao a esse simbolo

                        // cout << "eh terminal" << endl;
                    }
                    continue;
                }
            }

            if(jaExiste == false) {                                        //Se nao existia esse simbolo

                // cout << "nao existe" << endl;

                alfabeto.push_back(Simbolo(simb[0]));                      //Coloca no final do vector

                /*
                se esse cara de iterador funcionar, o trem todo funciona!
                */

                if(i == 0) {                                               //Inicializa o iterador em um ponto que existe
                    posicao = alfabeto.begin();
                    k++;
                }
                else {
                    posicao = alfabeto.begin() + k;
                    k++;
                }

                // cout << "colocou " << (*posicao).getNome() << endl;

                if(conexao[0] >= 65 && conexao[0] <= 90) {                //Caso a conexao nao seja terminal
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

    for(int j = 0; j < alfabeto.size(); j++){                             //Teste do alfabeto

        cout << '\n' << alfabeto[j].getNome() << " - ";

        for(int i = 0; i < alfabeto[j].getQntConexoes(); i++){

            cout << alfabeto[j].getConexoes(i).getNome();

        }

        cout << endl;
    }

}

/*
7
S -> AX
S -> AB
R -> AX
X -> RB
R -> AB
A -> a
B -> b
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
*/