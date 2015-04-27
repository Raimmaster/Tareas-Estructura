#include "T1Semaforo.h"
#include "ui_t1semaforo.h"
#include "calle.h"

//Colecciones y variables para estas
Calle** calles;
list<Calle*> grafo;
const int CANT_CALLES = 13;

//Prototyping
void initCalles();
void initAdyacentes();
void initGrafo();

//inits

void init(){
    calles = new Calle*[CANT_CALLES];
    initCalles();//inicializar las calles en el arreglo
    initAdyacentes();//inicializar las calles adyacentes a cada calle
    initGrafo();//insertar las calles con sus calles adyacentes en el grafo
}

void initCalles(){
    calles[0] = new Calle("AB");
    calles[1] = new Calle("AC");
    calles[2] = new Calle("AD");
    calles[3] = new Calle("BA");//SIEMPRE ABIERTA
    calles[4] = new Calle("BC");
    calles[5] = new Calle("BD");
    calles[6] = new Calle("DA");
    calles[7] = new Calle("DB");
    calles[8] = new Calle("DC");//SIEMPRE ABIERTA
    calles[9] = new Calle("EA");
    calles[10] = new Calle("EB");
    calles[11] = new Calle("EC");
    calles[12] = new Calle("ED");//SIEMPRE ABIERTA
}

void initAdyacentes(){
    //Calle AB
    calles[0]->agregarCalle(calles[4]);//BC
    calles[0]->agregarCalle(calles[5]);//BD
    calles[0]->agregarCalle(calles[6]);//DA
    calles[0]->agregarCalle(calles[9]);//EA

    //Calle AC
    calles[1]->agregarCalle(calles[5]);//BD
    calles[1]->agregarCalle(calles[6]);//DA
    calles[1]->agregarCalle(calles[7]);//DB
    calles[1]->agregarCalle(calles[9]);//EA
    calles[1]->agregarCalle(calles[10]);//EB

    //Calle AD
    calles[2]->agregarCalle(calles[9]);//EA
    calles[2]->agregarCalle(calles[10]);//EB
    calles[2]->agregarCalle(calles[11]);//EC

    //Calle BC
    calles[4]->agregarCalle(calles[0]);//AB
    calles[4]->agregarCalle(calles[7]);//DB
    calles[4]->agregarCalle(calles[10]);//EB

    //Calle BD
    calles[5]->agregarCalle(calles[0]);//AB
    calles[5]->agregarCalle(calles[1]);//AC
    calles[5]->agregarCalle(calles[6]);//DA

    //Calle DA
    calles[6]->agregarCalle(calles[0]);//AB
    calles[6]->agregarCalle(calles[1]);//AC
    calles[6]->agregarCalle(calles[5]);//BD
    calles[6]->agregarCalle(calles[10]);//EB
    calles[6]->agregarCalle(calles[11]);//EC

    //Calle DB
    calles[7]->agregarCalle(calles[1]);//AC
    calles[7]->agregarCalle(calles[4]);//BC
    calles[7]->agregarCalle(calles[11]);//EC

    //Calle EA
    calles[9]->agregarCalle(calles[0]);//AB
    calles[9]->agregarCalle(calles[1]);//AC
    calles[9]->agregarCalle(calles[2]);//AD

    //Calle EB
    calles[10]->agregarCalle(calles[1]);//AC
    calles[10]->agregarCalle(calles[2]);//AD
    calles[10]->agregarCalle(calles[4]);//BC
    calles[10]->agregarCalle(calles[5]);//BD
    calles[10]->agregarCalle(calles[6]);//DA

    //Calle EC
    calles[11]->agregarCalle(calles[2]);//AD
    calles[11]->agregarCalle(calles[5]);//BD
    calles[11]->agregarCalle(calles[6]);//DA
    calles[11]->agregarCalle(calles[7]);//DB
}

void initGrafo(){
    for(int i = 0; i < CANT_CALLES; i++){
        grafo.push_back(calles[i]);
    }
}

//fin inits

T1Semaforo::T1Semaforo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T1Semaforo)
{
    init();
    ui->setupUi(this);
}

T1Semaforo::~T1Semaforo()
{
    delete ui;
}

/**
 * @brief todasColoreadas
 * @return true si todas las calles están coloreadas
 */
bool todasColoreadas(){
    for(int i = 0; i < CANT_CALLES; i++){
        if(calles[i]->getGrupo() == WHITE)
            return false;
    }

    return true;
}

/**
 * @brief colorearCalles
    Colorea las calles
*/
void colorearCalles(){
    Color colorActual = BLUE;
    list<Calle*> temp;//lista de calles
    //que se están coloreando por el momento

    while(!todasColoreadas()){
        for(int i = 0; i < CANT_CALLES; i++){
            if(calles[i]->getGrupo() == WHITE){

            }
        }
        ++colorActual;
    }
}

void T1Semaforo::on_bCheck_clicked()
{

    for(int i = 0; i < CANT_CALLES; i++){
        cout<<"Calle: "<<calles[i]->getNombre()<<endl<<"ADJ: "<<endl;
        list<Calle*> temp = calles[i]->getAdyacentes();
        for(list<Calle*>::iterator i = temp.begin();
            i != temp.end(); i++){
            cout<<"\t"<<(*i)->getNombre()<<endl;
            cout<<(*i)->getGrupo()<<endl;
        }
    }
    cout<<"FIN"<<endl;
}
