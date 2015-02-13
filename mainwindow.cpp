#include <QGraphicsView>
#include <QTimer>
#include <QLayout>
#include <QPushButton>
#include <QDesktopWidget>
#include "constants.h"
#include "gamecontroller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    game(new GameController(*scene, this)),ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    //titre de ma fenetre
    setWindowTitle(trUtf8("Jeux Zelda"));
    // centrer ma fenetre a l ouverture
    QRect frect = frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(frect.topLeft());
    //boutton close
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    //lien entre le bouton et la toucher echape
    ui->pushButton->setShortcut(QKeySequence(Qt::Key_Escape));
    //on met la scene dans la fenetre
    ui->graphicsView->setScene(scene);
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::adjustViewSize()
{
    //view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initSceneBackground()
{
    scene->setSceneRect(0, 0, 900,600);//taille de la scene
    view->setRenderHint(QPainter::Antialiasing);
   //accelerer le temps total du rendu pour les zone lents a rebdre
    view->setCacheMode(QGraphicsView::CacheBackground);
    //mise en sauvgarde du font
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //change le curseur en main quand on click sur l ecrant possibliter de deplacer l ecrant
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setOptimizationFlags(QGraphicsView::DontClipPainter
                              | QGraphicsView::DontSavePainterState
                              | QGraphicsView::DontAdjustForAntialiasing);

     view->viewport()->setFocusProxy( this );
}
