#include <iostream>
#include <ctime>
#include <cstdlib>

//==================================================================================
//    Classe Horario de Funcionamento
//==================================================================================

class tipo_horario{

private:

    int horaLocal;
    int minutosLocal;
    int local;

    int horaFuncionamento;
    int minutosFuncionamento;
    int funcionamento;


public:
    void setHorario (int, int);
    void desligar();

}HoraDesligamento;





//----------------------------------------------------------------------------------


//==================================================================================
// NAMESPACE
//==================================================================================

using namespace std;

//----------------------------------------------------------------------------------


//==================================================================================
//    Função Principal
//==================================================================================

main(){


    while(1){

        system("cls");

        HoraDesligamento.setHorario(15,50);

       HoraDesligamento.desligar();

    }


}

//----------------------------------------------------------------------------------


//==================================================================================
//    Função setHorario
//==================================================================================

void tipo_horario::setHorario(int hora, int minutos){

    this->horaFuncionamento = hora;
    this->minutosFuncionamento = minutos;

    this->funcionamento = ((this->horaFuncionamento*60)+this->minutosFuncionamento); // Transforma os horarios em minutos
}

//----------------------------------------------------------------------------------



//==================================================================================
//    Função Deligar
//==================================================================================

void tipo_horario::desligar(){

        struct tm *HoraAtual;
        time_t horario;
        time(&horario);
        HoraAtual = localtime(&horario);

        this->horaLocal = HoraAtual->tm_hour;
        this->minutosLocal = HoraAtual->tm_min;

        this->local = (this->horaLocal*60)+this->minutosLocal; // Transforma todo o horario em minutos

        if (this->local>=this->funcionamento){

            cout << endl << "O Computador sera desligado ..." << endl;

        }else{

            cout << endl << "Esperando Horario de Desligamento ..." << endl;

        }




}

//----------------------------------------------------------------------------------

