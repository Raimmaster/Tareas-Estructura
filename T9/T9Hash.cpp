#include "T9Hash.h"
#include "ui_T9Hash.h"

T9Hash::T9Hash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T9Hash)
{
    ui->setupUi(this);
}

T9Hash::~T9Hash()
{
    delete ui;
}

int T9Hash::getHash(string s){
    return toupper(s[0] - 'A') % 26;
}
