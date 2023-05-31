#ifndef TELAINICIO_H
#define TELAINICIO_H
#include "telaprojeto.h"
#include "telaprincipal.h"
#include <QDialog>

namespace Ui {
class TelaInicio;
}

class TelaInicio : public QDialog
{
    Q_OBJECT

public:
    explicit TelaInicio(QWidget *parent = nullptr);
    ~TelaInicio();

private:
    Ui::TelaInicio *ui;
};

#endif // TELAINICIO_H
