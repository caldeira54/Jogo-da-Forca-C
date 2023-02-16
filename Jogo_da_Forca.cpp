#include <iostream>;
#include <string>;
#include <time.h>

using namespace std;

void limpaTela(){
    system("cls");
}

void exibeStatus(string palavraComMascara,int tamanhoDaPalavra,int tentivasRestantes,string letrasArriscadas,string mensagem){
    cout << mensagem << endl;
    cout << "Palavra : " << palavraComMascara << "(Tamanho : " << tamanhoDaPalavra << ")" << endl;
    cout << "Vidas restantes : " << tentivasRestantes << endl;
    cout << "Letras ja arriscadas : ";
    for(int i = 0;i < letrasArriscadas.size();i++){
        cout << letrasArriscadas[i] << ", ";
    }
    cout << endl;
}

string retornaPalavraAleatoria(){
    string palavras[10] = {"carro","abacaxi","macaco","caminhar","desenvolver","telefone","morango","otorrinolaringologista","paralelepipedo","paralelogramo"};
    int aleatorio = rand() % 10;
    return palavras[aleatorio];
}

int jogarNovamente(){
    int opcao;
    cout << "Deseja jogar novamente : " << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cin >> opcao;
    limpaTela();
    return opcao;
}

int jogar(int jogadores){

    string palavra;

    if(jogadores == 1){
        palavra = retornaPalavraAleatoria();
    } else {
        cout << "Digite uma palavra : ";
        cin >> palavra;
        limpaTela();
    }

    /// Variaveis Principais
    int opcao,vidas = 6;
    char letra;
    int i = 0;
    bool letrasDigitadas = false,acertouLetra = false;
    string chute;
    string mensagem = "Bem vindo ao jogo!";
    string palavraComMascara;
    string letrasArriscadas;

    int tamanhoDaPalavra = palavra.size();


    while(i < tamanhoDaPalavra){
        palavraComMascara += "_";
        i++;
    }

    while(vidas > 0 && palavra != palavraComMascara){
        limpaTela();
        exibeStatus(palavraComMascara,tamanhoDaPalavra,vidas,letrasArriscadas,mensagem);
        cout << "Digite uma letra : ";
        cin >> letra;

        for(int cont = 0;cont < vidas;cont ++){
            if(letrasArriscadas[cont] == letra){
                mensagem = "Essa letra ja foi digitada!";
                letrasDigitadas = true;
            }
        }

        if(letrasDigitadas == false){
            letrasArriscadas += tolower(letra);

            for(int j = 0;j < tamanhoDaPalavra;j++){
                if(palavra[j] == tolower(letra)){
                    palavraComMascara[j] = palavra[j];
                    acertouLetra = true;
                }
            }
             if(acertouLetra == false){
                mensagem = "Voce errou uma letra!";
                vidas--;
            } else {
                mensagem = "Voce acertou uma letra!";
            }
        }
        letrasDigitadas = false;
        acertouLetra = false;
        limpaTela();
    }

    if(palavra == palavraComMascara){
        cout << "Parabens, voce venceu!" << endl;
        cout << "A palavra era : " << palavra << endl;
        return jogarNovamente();
    } else {
        cout << "Voce perdeu!" << endl;
        cout << "A palavra era : " << palavra << endl;
        return jogarNovamente();
    }
}

void menuInicial(){
    int opcao;

    do{
        cout << "Bem vindo ao jogo! Escolha uma opcao : " << endl;
        cout << "1 - Jogar solo" << endl;
        cout << "2 - Jogar multiplayer" << endl;
        cout << "3 - Sobre" << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;
        limpaTela();

        switch(opcao){
            case 1:
                cout << "Jogo iniciado solo." << endl;
                if(jogar(1) == 1){
                    menuInicial();
                }
                cout << "Obrigado por jogar, ate a proxima." << endl;
                return;
                break;

            case 2:
                cout << "Jogo iniciado multiplayer." << endl;
                if(jogar(2) == 1){
                    menuInicial();
                }
                cout << "Obrigado por jogar, ate a proxima." << endl;
                return;
                break;

            case 3:
                cout << "Jogo desenvolvido por Arthur Alves Caldeira com auxilio do professor Joao Victor da Udemy." << endl;
                cout << "05/04/2021 : comeco do projeto." << endl;
                cout << "06/04/2021 : teste e acabamento do projeto." << endl;
                cout << "07/04/2021 : testes finais e termino do projeto." << endl;
                break;

            case 4:
                cout << "Obrigado por jogar, ate a proxima." << endl;
                break;

            default:
                cout << "Opcao invalida, tente novamente." << endl;
                break;
        }

    }while(opcao != 4);
}

int main(){

    srand((unsigned)time(NULL));
    menuInicial();

    return 0;
}
