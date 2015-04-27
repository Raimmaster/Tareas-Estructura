#include "T1Semaforo.h"
#include "ui_t1semaforo.h"
#include "calle.h"

//Colecciones y variables para estas
Calle** calles;
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
}

/**
 * @brief initCalles - Inicializar cada calle
 */
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
 * @brief adyColored - Compara si la calle ya tiene adyacentes con este color
 * @param calle - Calle a comparar
 * @param actual - Color actual a asignar
 * @return true si tiene adyacentes con el color actual
 */
bool adyColored(Calle* calle, Color actual){
    list<Calle*> temp = calle->getAdyacentes();
    for(list<Calle*>::iterator i = temp.begin();
        i != temp.end(); i++){
        if((*i)->getGrupo() == actual)
            return true;
    }

    return false;
}

/**
 * @brief moveColor - Cambia al siguiente color para asignar
 * @param color - Color actual que se debe cambiar
 * @return El nuevo Color a asignar
 */
Color moveColor(Color color){
    switch(color){
        case BLUE:
            return RED;
        case RED:
            return GREEN;
        case GREEN:
            return YELLOW;
        case YELLOW:
            return color;
    }
}

/**
 * @brief colorearCalles
    Colorea las calles
*/
void colorearCalles(){
    Color colorActual = BLUE;

    while(!todasColoreadas()){
        for(int i = 0; i < CANT_CALLES; i++){
            if(calles[i]->getGrupo() == WHITE){
                if(!adyColored(calles[i], colorActual)){//compara si tiene adyacentes de este color
                    calles[i]->setGrupo(colorActual);
                }
            }
        }
        colorActual = moveColor(colorActual);
    }
}

/**
 * @brief setQLabelColors - Colorea los labels según su grupo
 */
void T1Semaforo::setQLabelColors(){
    QPalette color_palette;
    QLabel** qLabels = new QLabel*[13];

    qLabels[0] = T1Semaforo::ui->lAB;
    qLabels[1] = T1Semaforo::ui->lAC;
    qLabels[2] = T1Semaforo::ui->lAD;
    qLabels[3] = T1Semaforo::ui->lBA;
    qLabels[4] = T1Semaforo::ui->lBC;
    qLabels[5] = T1Semaforo::ui->lBD;
    qLabels[6] = T1Semaforo::ui->lDA;
    qLabels[7] = T1Semaforo::ui->lDB;
    qLabels[8] = T1Semaforo::ui->lDC;
    qLabels[9] = T1Semaforo::ui->lEA;
    qLabels[10] = T1Semaforo::ui->lEB;
    qLabels[11] = T1Semaforo::ui->lEC;
    qLabels[12] = T1Semaforo::ui->lED;

    for(int i = 0; i < CANT_CALLES; i++){
        color_palette.setColor(QPalette::Window, Qt::white);
        switch(calles[i]->getGrupo()){
            case BLUE:
                color_palette.setColor(QPalette::WindowText, Qt::blue);
                break;
            case RED:
                color_palette.setColor(QPalette::WindowText, Qt::red);
                break;
            case GREEN:
                color_palette.setColor(QPalette::WindowText, Qt::green);
                break;
            case YELLOW:
                color_palette.setColor(QPalette::WindowText, Qt::yellow);
                break;
            default:
                color_palette.setColor(QPalette::WindowText, Qt::white);
        }

        qLabels[i]->setAutoFillBackground(true);
        qLabels[i]->setPalette(color_palette);
    }

}

void T1Semaforo::on_bCheck_clicked()
{
    colorearCalles();
    setQLabelColors();

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
