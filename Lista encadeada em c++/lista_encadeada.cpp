#include <iostream>

class no{
    public:
        int valor;
        no* prox;

        no(int umValor): valor(umValor), prox(nullptr) {}
};

class lista{

    public:
        lista(): inicio(nullptr), fim(nullptr) {}
        bool insere_inicio(int valor){
        no* aux = new no(valor);
        if (inicio == nullptr);
            inicio = aux;
            fim = aux;
            return true;
        }else{
            no*
        }


    private:
        no* inicio;
        no* fim;
};