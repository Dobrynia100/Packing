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
    ui->ClearButton->setText("Очистить список изделий (" + QString::number(products.count()) + ")");
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
int comparew(product& obj1, product& obj2)//сравнение широты изделий для сортировки
{
    return obj1.getwidth() > obj2.getwidth();
}
int compareh(product& obj1, product& obj2)//сравнение высоты изделий для сортировки
{
    return obj1.getheight() > obj2.getheight();
}

void packUI::CleanUp()//очистка сцен и обнуление упаковки введенных изделий
{
    qDebug() << "Очищение сцен" << endl;
    pack_scene->clear();
    info_scene->clear();
    for (product& prod : products) { prod.setPacked(false); prod.setcoords(0, 0); }
  
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
   
   if (products.count()==0)
   {
       QGraphicsTextItem* textItem = info_scene->addText("Добавьте хотя бы одно изделие");
   }
   else if (products.last().getsquare() > (List_height * List_height)) 
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
        qDebug() << products[j].check() <<"  ";
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
    textItem=info_scene->addText("\n Потребовалость " + QString::number(pm) + " погонного метра \nлистового металла");
    textItem->setPos(1, 75);
}
bool packUI::rotation(int List_width, int List_height,bool placement)
{
    if (ui->radioButton->isChecked())
    {
        if (List_height > List_width)
        {

            for (int i = 0; i < products.size(); i++)
            {
                if (products[i].getwidth() > products[i].getheight()) products[i].flip();//изделия размещаются вертикально

            }
            std::sort(products.begin(), products.end(), compareh);
        }
        else if (List_height < List_width)
        {
            for (int i = 0; i < products.size(); i++)
            {
                if (products[i].getwidth() < products[i].getheight()) products[i].flip();//изделия размещаются горизонтально
            }
            std::sort(products.begin(), products.end(), comparew);
            placement = false;
        }
        else std::sort(products.begin(), products.end(), compareh);
    }
    else if (ui->radioButton_2->isChecked())
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getwidth() < products[i].getheight()) products[i].flip();//изделия размещаются горизонтально
        }
        std::sort(products.begin(), products.end(), comparew);
        placement = false;
    }
    else if (ui->radioButton_3->isChecked())
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getwidth() > products[i].getheight()) products[i].flip();//изделия размещаются вертикально

        }
        std::sort(products.begin(), products.end(), compareh);
    }
    return placement;
}
void packUI::Packing(int List_width, int List_height)//упаковка методом полос с модификацией
{

    int list_square = List_width * List_height;
    bool placement = true;
    int x = 0, y = 0, xp = 0, yp = 0, pog_meter = 0, first = 0, stop_width = List_width, stop_height = List_height,ylim=0;
    int i = 0;
    bool first_check = true;

    rotation(List_width , List_height, placement);

    
    for (product& prod : products)
    {
        
        qDebug() << i+1 << ":";
        if (prod.getsquare() > list_square) continue;
        if (!first_check && products[i - 1].check())//если можно поместить текущий элемент над предыдущем в текущую строчку
        {
            qDebug() << "x: " << x << " y:" << y << endl;           
            if (products[i-1].gety() + products[i - 1].getheight() + prod.getheight() <= products[first].getheight() && x - products[i - 1].getwidth() + prod.getwidth() <= stop_width)
            {
                qDebug() << "1" << endl;
                rectangle = new QGraphicsRectItem(x - products[i - 1].getwidth(), products[i - 1].gety() + prod.getheight(), prod.getwidth(), prod.getheight());
                prod.setPacked(true);
                
                
            }
            else if (products[i - 1].getx() +products[i-1].getwidth() + prod.getwidth() <= products[first].getwidth() && y-products[i - 1].getheight() + prod.getheight() <= stop_height)
            {
                qDebug() << "2" << endl;
                rectangle = new QGraphicsRectItem(products[i - 1].getx() + prod.getwidth(), y - products[i - 1].getheight(), prod.getwidth(), prod.getheight());

                prod.setPacked(true);
                
            }
        }
        if (!prod.check()) {
            if (x + prod.getwidth() <= stop_width && y + prod.getheight() <= stop_height) //помещение элементов в строку
            {
                
                if (i > 0 && prod.getheight() > products[i - 1].getheight())//Если текущий элемент оказался выше предыдущего ставим лимит по ширине
                {
                    stop_width = x;
                    ylim = y + prod.getheight();
                }
                rectangle = new QGraphicsRectItem(x, y, prod.getwidth(), prod.getheight());
                
                qDebug() << "3" << endl;
                qDebug() << "x: " << x << " y:" << y << endl;
                placement ? x += prod.getwidth() : y += prod.getheight();
                prod.setPacked(true);
                
                if (first_check) first = i;
                first_check = false;
            }
            else if (y + prod.getwidth() <= stop_height && x + prod.getheight() <= products[first].getwidth())//поместится ли элемент в строчку если его повернуть?
            {
                qDebug() << "4" << endl;

                prod.flip();
                rectangle = new QGraphicsRectItem(x, y, prod.getwidth(), prod.getheight());
                
                x += prod.getheight();
                
                prod.setPacked(true);
            }
            else if (x + prod.getheight() <= stop_width && y + prod.getwidth() <= products[first].getheight())
            {
                qDebug() << "5" << endl;

                prod.flip();
                rectangle = new QGraphicsRectItem(x, y, prod.getwidth(), prod.getheight());
              
                y += prod.getwidth();
                
                prod.setPacked(true);
            }
            else if ((prod.getwidth() <= stop_width && y + products[first].getheight() + prod.getheight() <= stop_height) && placement)//переход на следующую строчку для вертикального расположения
            {
                qDebug() << "Переход" << endl;

                x = prod.getwidth();
                y += products[first].getheight();
                
                qDebug() << "x: " << x << " y:" << y << endl;
                qDebug() << "6" << endl;
                rectangle = new QGraphicsRectItem(0, y, prod.getwidth(), prod.getheight());
                
                first = i;
                prod.setPacked(true);


            }
            else if (!placement && (x + products[first].getwidth() + prod.getwidth() <= stop_width && prod.getheight() <= stop_height))//переход для горизонтального
            {
                qDebug() << "Переход" << endl;
                x += products[first].getwidth();
                y = prod.getheight();
                qDebug() << "7" << endl;
                rectangle = new QGraphicsRectItem(x, 0, prod.getwidth(), prod.getheight());
                
                first = i;
                prod.setPacked(true);
                
            }

        }
        pog_meter = (x > y) > pog_meter ? x : y;//замер погонного метра по горизонтали
        
        rectangle->setPen(QColor(0, 0, 255));
        
        if (y >= ylim)//снятие лимита по ширине
        {         
            stop_width = List_width;
            ylim = 0;
        }
        if (prod.check())//если изделие упаковано-отображается на сцене
        {
            
            QGraphicsTextItem* textItem = pack_scene->addText(QString::number(i+1));
            textItem->setPos(rectangle->sceneBoundingRect().center() - QPointF(textItem->boundingRect().width() / 2, textItem->boundingRect().height()/2));
            pack_scene->addItem(rectangle);
            qDebug() << rectangle->sceneBoundingRect().x() << " " << rectangle->sceneBoundingRect().y() << endl;
            prod.setcoords(rectangle->sceneBoundingRect().x(), rectangle->sceneBoundingRect().y());
        }
        
        if ((y == List_height && x + prod.getwidth() == List_width) || (y + prod.getheight() == List_height && x == List_width))break;
        i++;

    }
    check_all(pog_meter);
  
    
   
}


