#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Importation de la police d'ecriture
    QFontDatabase::addApplicationFont(":/Spyv3l.ttf"); //Spylord Laser

    //Création de la vue
    jeu=new Vue(geometry(),this);
    connect(jeu,SIGNAL(touchePressee(int)),this,SLOT(on_touchePressee(int)));
    connect(jeu,SIGNAL(sourisBougee(QPoint)),this,SLOT(on_sourisBougee(QPoint)));
    connect(jeu,SIGNAL(sourisCliquee()),this,SLOT(on_sourisCliquee()));

    //Création de la scène
    sceneJeu = new QGraphicsScene(0,0,640,640);
    sceneMenu = new QGraphicsScene(0,0,geometry().width()-10,geometry().height()-10);

    jeu->setScene(sceneMenu);
    jeu->setBackgroundBrush(QBrush(QPixmap(":/Images/bgMenu.jpg").scaledToHeight(geometry().height()-10)));

    //Initialisation du pinceau
    pen=new QPen(QBrush(Qt::white),10);

    //Création du menu
    boutonMenu[0]=new QGraphicsRectItem(QRect(0,0,650,150));
    boutonMenu[0]->setBrush(QBrush(QPixmap(":/Images/boutonJouer.png").scaledToHeight(boutonMenu[0]->rect().height())));
    boutonMenu[0]->setPos(310,150);
    sceneMenu->addItem(boutonMenu[0]);

    boutonMenu[1]=new QGraphicsRectItem(QRect(0,0,650,150));
    boutonMenu[1]->setBrush(QBrush(QPixmap(":/Images/boutonEditeur.png").scaledToHeight(boutonMenu[1]->rect().height())));
    boutonMenu[1]->setPos(310,450);
    sceneMenu->addItem(boutonMenu[1]);
    curseur=new QGraphicsRectItem(0,0,80,80);
    curseur->setBrush(QBrush(QPixmap(":/Images/curseurMenu.png").scaledToHeight(curseur->rect().height())));
    sceneMenu->addItem(curseur);
}

MainWindow::~MainWindow()
{
    sceneJeu->clear();
    delete sceneJeu;
    sceneMenu->clear();
    delete sceneMenu;
    delete pen;
    delete jeu;
    delete ui;
}

void MainWindow::creerMiroir(short sens, QGraphicsPolygonItem *poly)
{
    QVector<QPoint> tempVect;
    switch (sens) {
    case GH:
    {
        tempVect<<QPoint(40,0)<<QPoint(40,40)<<QPoint(0,40);
        QPolygon temp(tempVect);
        poly = new QGraphicsPolygonItem(temp);
        break;
    }
    case DH:
    {
        tempVect<<QPoint(0,0)<<QPoint(40,0)<<QPoint(40,40);
        QPolygon temp(tempVect);
        poly = new QGraphicsPolygonItem(temp);
        break;
    }
    case GB:
    {
        tempVect<<QPoint(0,0)<<QPoint(40,0)<<QPoint(40,40);
        QPolygon temp(tempVect);
        poly = new QGraphicsPolygonItem(temp);
        break;
    }
    case DB:
    {
        tempVect<<QPoint(0,40)<<QPoint(0,0)<<QPoint(40,0);
        QPolygon temp(tempVect);
        poly = new QGraphicsPolygonItem(temp);
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_touchePressee(int touche)
{

}

void MainWindow::on_sourisBougee(QPoint position)
{
    curseur->setPos(position);
}

void MainWindow::on_sourisCliquee()
{

}
