#ifndef T9HASH_H
#define T9HASH_H

#include <QDialog>
#include <iostream>
using namespace std;

namespace Ui {
class T9Hash;
}

class T9Hash : public QDialog
{
    Q_OBJECT

public:
    int getHash(string s);
    explicit T9Hash(QWidget *parent = 0);
    ~T9Hash();

private:
    Ui::T9Hash *ui;
};

#endif // T9HASH_H
