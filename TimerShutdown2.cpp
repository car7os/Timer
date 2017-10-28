#include <iostream>
#include <ctime>
#include <cstdlib>

//==================================================================================
//    Classe Horario de Funcionamento
//==================================================================================

typedef class tipo_horario{

private:

    int horaLocal;
    int minutosLocal;
    int local;

    int horaFuncionamento;
    int minutosFuncionamento;
    int funcionamento;

    int diaAtual;
    int diaDesligamento;


public:
    void setHorario (int, int, int);
    void desligar();
    void DesligaAgora ();

    void loopComando ();

} tipo_horario;

tipo_horario *HoraDesligamento;

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

 HoraDesligamento->loopComando();


}

//----------------------------------------------------------------------------------


//==================================================================================
//    Função setHorario
//==================================================================================

void tipo_horario::setHorario(int hora, int minutos, int dia){

    this->horaFuncionamento = hora;
    this->minutosFuncionamento = minutos;

    this->funcionamento = ((this->horaFuncionamento*60)+this->minutosFuncionamento); // Transforma os horarios em minutos
    this->diaDesligamento = dia;
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

        this->diaAtual = HoraAtual->tm_mday;

        this->local = (this->horaLocal*60)+this->minutosLocal; // Transforma todo o horario em minutos

        cout << endl << "Hora Corrente: " << this->horaLocal << ":" << this->minutosLocal << " // Dia Corrente: " << this->diaAtual << endl;

        if ( (this->diaDesligamento == this->diaAtual) && (this->local >= this->funcionamento) ) {

            cout << endl << "O Computador sera desligado ..." << endl;

            DesligaAgora();


        }else{

            cout << endl << "Esperando Horario de Desligamento ..." << endl;

        }
}

//----------------------------------------------------------------------------------


//==================================================================================
//    Função setHorario
//==================================================================================

void tipo_horario::DesligaAgora (){

    system("shutdown -s -f -m \\DESKTOP-M0FPFRK");

    //system("shutdown -s -f");
}


void tipo_horario::loopComando(){
  while(true){

        system("cls");

        HoraDesligamento = NULL;

        HoraDesligamento = new tipo_horario();

        HoraDesligamento->setHorario(16,05,28);

       HoraDesligamento->desligar();

       HoraDesligamento = NULL;

       free(HoraDesligamento);

    }

}
