#include "packui.h"
#include "ui_packui.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "product.h"
packUI::packUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::packUI)
{

    ui->setupUi(this);
    
       scene = new QGraphicsScene(this);
       pack_scene = new QGraphicsScene(this);
       info_scene=new QGraphicsScene(this);
       ui->graphicsView->setScene(scene);
       ui->graphicsView_2->setScene(pack_scene);
       ui->graphicsView_3->setScene(info_scene);
     


}

packUI::~packUI()
{
    delete ui;
}


void packUI::addProducts(product p,int count)//добавление изделий в список и их изображений  
{
    
    int last_width=0,x=0,y=0,shift=0;

    if(products.count()!=0)
    {

       
            last_width = products.last().getwidth();

        qDebug() << "ширина последнего: " << last_width;
        qDebug() << products.last().getwidth()<< endl;
        qDebug() << labels.last()->scenePos().x() << endl;
    
        shift = labels.last()->scenePos().x() -p.getwidth()- (products.last().getwidth()/2) -25;
        qDebug() << shift << endl;
        rectangle = new QGraphicsRectItem(shift, 0, p.getwidth(), p.getheight()); // Параметры: x, y, width, height
    }
    else
    {
        rectangle = new QGraphicsRectItem(0, 0, p.getwidth(), p.getheight()); 

    }

    scene->addItem(rectangle);

    for(int i=0;i<count;i++) products.append(p);
    addLabel(rectangle,count);

}
void packUI::addLabel(QGraphicsRectItem *rectangle,int count)//добавления подписи(размер,количество) для изображений изделий
{
    qreal width = rectangle->rect().width();
    qreal height = rectangle->rect().height();

    QGraphicsTextItem *textItem = scene->addText(QString::number(width)+"*"+QString::number(height)+" x"+QString::number(count));
        textItem->setPos(rectangle->sceneBoundingRect().center() - QPointF(textItem->boundingRect().width() / 2, textItem->boundingRect().height()+10));
    qDebug()<<textItem->pos().x();
    qDebug()<<textItem->scenePos();

    labels.append(textItem);


}
void packUI::on_ClearButton_clicked()//очистка изделий
{
    products.clear();
    labels.clear();
    scene->clear();
    qDebug() << "очищено" << endl;
}
void packUI::on_pushButton_clicked()//кнопка добавления изделий
{
    int width=180,height=30,count=1;
    width = ui->spinBox_4->text().toInt();
    height = ui->spinBox_5->text().toInt();
    count = ui->spinBox->text().toInt();
    product p{width,height};
    
    addProducts(p,count);
    scene->update();

}
int compare(product& obj1, product& obj2)//сравнение площадей изделий для сортировки
{
    return obj1.getsquare() > obj2.getsquare();
}

void packUI::CleanUp()//очистка сцен и обнуление упаковки введенных изделий
{
    pack_scene->clear();
    info_scene->clear();
    for (product& prod : products)prod.setPacked(false);
  
}
void packUI::on_PackButton_clicked()//кнопка упаковки
{
   int List_width=0,List_height=0;
   List_width=ui->spinBox_2->text().toInt();
   ui->comboBox->currentIndex()!=1 ? List_width :List_width=List_width*100;
   List_height=ui->spinBox_3->text().toInt();
   ui->comboBox_2->currentIndex()!=1 ? List_width : List_height=List_height*100;

   rectangle = new QGraphicsRectItem(0, 0, List_width, List_height);

   CleanUp();
   pack_scene->addItem(rectangle);
   

   std::sort(products.begin(), products.end(), compare);//сортировка по убыванию
   qDebug() << products.first().getsquare();

   if (products.last().getsquare() > (List_height * List_height)) 
   { QGraphicsTextItem* textItem = info_scene->addText("Ни одно изделие нельзя упаковать"); 
   } 
   else Packing(List_width,List_height);

}

void packUI::check_all(int pog_meter)//проверка, упакованы ли все изделия
{
    bool b=true;
    QGraphicsTextItem* textItem;
    int count = products.size();
    int x = 0;
    float pm = pog_meter / static_cast<float>(100);
    for (int j = 0; j < products.size(); j++)
    {
        qDebug() << products[j].check() << endl;
        if (products[j].check() == false)
        {
            
           if(b) QGraphicsTextItem* textItem = info_scene->addText("Не упаковано:");
           textItem= info_scene->addText(QString::number(j + 1));
           textItem->setPos(x, 25);
            x+=15;
            b = false;
            count--;
        }
    }
    b ? textItem = info_scene->addText("Все изделия упакованы") : textItem = info_scene->addText("Можно выполнить изделий: "
        + QString::number(count));
    textItem->setPos(1, 50);
    qDebug() << pm << " " << pog_meter << endl;
    textItem=info_scene->addText("\n Потребовалость " + QString::number(pm) + " погонного метра \nлистового металла (по горизонтали)");
    textItem->setPos(1, 75);
}
void packUI::Packing(int List_width, int List_height)//упаковка методом полос
{

    int list_square = List_width * List_height;
    bool placement = true;
    if (List_height >= List_width)
    {
   
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getwidth() > products[i].getheight()) products[i].flip();//изделия размещаются вертикально
        }
    }
    else
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getwidth() < products[i].getheight()) products[i].flip();//изделия размещаются горизонтально
        }
        placement = false;
    }

    int x = 0,y=0,xp=0,yp=0,pog_meter=0,first=0;
    int i = 0;
    bool first_check = true;
    for (product& prod : products)
    {
        
        i++;
        if (prod.getsquare() > list_square) continue;
        if (x + prod.getwidth() <= List_width && y + prod.getheight() <= List_height)
        {
           
            rectangle = new QGraphicsRectItem(x, y, prod.getwidth(), prod.getheight()); 
                     
            qDebug() << "x: " << x << " y:" << y << endl;
            placement?x += prod.getwidth():y+=prod.getheight();
            prod.setPacked(true);
            if (first_check) first = i;
            first_check = false;
        }
        
        else if((prod.getwidth() <= List_width && y+products[first].getheight()+ prod.getheight() <=List_height)&&placement)
        {
            qDebug() << "Переход" << endl;
           
                x = prod.getwidth(); 
                y += products[first].getheight(); 
           
            qDebug() << "x: " << x << " y:" << y << endl;

            rectangle = new QGraphicsRectItem(0, y, prod.getwidth(), prod.getheight()); 
            first_check = true;
            prod.setPacked(true);
            

        }
        else if (!placement && (x + products[first].getwidth() + prod.getwidth() <= List_width && prod.getheight()<=List_height))//в угоду читаемости это условие отдельно
        {
            qDebug() << "Переход" << endl;
            x += products[first].getwidth();
            y = prod.getheight();

            rectangle = new QGraphicsRectItem(x, 0, prod.getwidth(), prod.getheight());
            first_check = true;
            prod.setPacked(true);
        }
        
        if (x > pog_meter) pog_meter = x;//замер погонного метра по горизонтали

        rectangle->setPen(QColor(0, 0, 255));

        if (prod.check())//если изделие упаковано-отображается на сцене
        {
            prod.setcoords(x, y);
            QGraphicsTextItem* textItem = pack_scene->addText(QString::number(i));
            textItem->setPos(rectangle->sceneBoundingRect().center() - QPointF(textItem->boundingRect().width() / 2, textItem->boundingRect().height()));
        }
        pack_scene->addItem(rectangle);
       

    }
    check_all(pog_meter);
  
    
   
}


