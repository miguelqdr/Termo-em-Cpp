#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

string gera_palavra(const vector<string>& pal);
int main()
{
    
    int pc = 0, pe = 0, chances = 6;
    string palavra, pal_ocl = "#####", pal_sec;
    char let_cet[26] = " ", let_err[26] = " ", qlqr;
    vector<string> lista_pal = {"ARROZ", "CARTA", "BANHO", "FRACO", "FILHO", "MANHA", "JUSTO", "LEGAL", "SANTO", "CORTE", "SONHO", "VETOR", "TURMA", "TROCA", "TEMPO", "OUTRO", "PALCO", "PADRE", "PIADA", "PRATO", "HEROI", "LIVRO", "IRMAO", "MAIOR", "IDADE", "MESES", "PISTA", "PRAZO", "RESTO", "REGRA", "QUASE"};
    pal_sec = gera_palavra(lista_pal);
    cout << "Bem vindo ao Termo!!!" << endl;

    cout << "Nesse jogo o objetivo é acertar a palavra secreta com 5 letras antes de suas 6 chances acabarem" << endl;
    cout << "Sempre que você acertar a letra, ela será revelada junto a sua posição, boa sorte!\n\n";
    cout << "\nPressione qualquer tecla para continuar" << endl;
    cin >> qlqr;

    while(true){
        system("clear");

        cout << "Voce tem mais " << chances << " chances" << endl;
        cout << "Letras certas: "; 
        for(int i=0; i<pc; i++) 
        {
            if(i != pc-1) cout << let_cet[i] << ", ";
            else cout << let_cet[i];
        }
        cout << endl;
        cout << "Letras erradas: ";
        for(int i=0; i<pe; i++)
        {
            if(i != pe-1) cout << let_err[i] << ", ";
            else cout << let_err[i];
        }    
        cout << "\n\n";
        cout << "Palavra secreta: " << pal_ocl << endl;

        cout << "\n\nDigite a palavra secreta: ";
        cin >> palavra;
        for(int i = 0; i<palavra.length(); i++) palavra[i] = toupper(palavra[i]);
        if(palavra.length() != 5) 
        {
            cout << "Palavra inválida!\nLembre-se ela precisa ter 5 letras, tente novamente." << endl;
            cout << "Pressione qualquer tecla para tentar novamente" << endl;
            cin >> qlqr;
            continue;
        }

        for(int i=0; i<5; i++)
        {
            if(pal_sec[i] == palavra[i]) pal_ocl[i] = pal_sec[i];
            bool pertence = false;
            for(int k = 0; k<5; k++)
            {
                if (pal_sec[k] == palavra[i]) pertence = true;
            }
                if(pertence)
                {
                    bool existe = false;
                    for(int j=0; j<pc; j++)
                    {
                        if(let_cet[j] == palavra[i]) existe = true;
                    }
                    if (!existe) 
                    {
                        let_cet[pc] = palavra[i];
                        pc++;
                    }
                }  
                else
                {
                    bool existe = false;
                    for(int j=0; j<pe; j++)
                    {
                        if(let_err[j] == palavra[i]) existe = true;
                    }
                    if(!existe)
                    {
                        let_err[pe] = palavra[i];
                        pe++;
                    }
                }
        }

        if(pal_ocl == pal_sec)
        {
            system("clear");
            cout << "Parabéns, voce acertou a palavra secreta!!!" << endl;
            cout << "A palavra secreta eh: " << pal_sec << "!\n" << endl;
            break;
        }
    chances--;
    if(chances == 0)
    {
        system("clear");
        cout << "Voce perdeu ;-;. Mais sorte na proxima vez" << endl;
        break;
    }
}
    return 0;
}

string gera_palavra(const vector<string>& pal)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<size_t> distrib(0, pal.size()-1);

    return pal[distrib(gen)];
}
