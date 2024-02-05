#ifndef PACKUI_H
#define PACKUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLineEdit>
#include <QGraphicsTextItem>
#include <QComboBox>
#include "product.h"
QT_BEGIN_NAMESPACE
namespace Ui { class packUI; }
QT_END_NAMESPACE

class packUI : public QMainWindow
{
    Q_OBJECT

public:
    packUI(QWidget *parent = nullptr);
    ~packUI();

private slots:
    void on_PackButton_clicked();
    void on_ClearButton_clicked();
    void on_pushButton_clicked();
    void addProducts(product p,int count);//(int width,int height,int count);
    void addLabel(QGraphicsRectItem *rectangle,int count);
private:
    Ui::packUI *ui;
    QPainter *painter;
    QGraphicsScene *scene;
    QGraphicsScene *pack_scene;
    QGraphicsScene *info_scene;
    QGraphicsRectItem *rectangle;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    //QList<QGraphicsRectItem*> products;
    QList <product> products;
    QList<QGraphicsTextItem*> labels;
    void Packing(int List_width, int List_height);
    void check_all(int pog_meter);
    void CleanUp();
};
#endif // PACKUI_H
