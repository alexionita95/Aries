#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput);
       //setAttribute(Qt::WA_NoSystemBackground, true);
       //setAttribute(Qt::WA_TranslucentBackground, true);
       ui->setupUi(this);
       //ui->openGLWidget->setWindowFlags(Qt::WindowTransparentForInput);
       //ui->openGLWidget->setAttribute(Qt::WA_TranslucentBackground, true);
       //ui->openGLWidget->setAttribute(Qt::WA_NoSystemBackground, true);
       QSurfaceFormat format = ui->openGLWidget->format();
       format.setSamples(8);
       ui->openGLWidget->setFormat(format);
       connect(ui->openGLWidget,&QtRendererWidget::updateFPS,this, &MainWindow::on_updateFPS);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_released()
{
    ui->openGLWidget->generate();
}

void MainWindow::on_updateFPS(float fps)
{
    ui->label->setText("FPS: "+ QString::number(fps));
}


void MainWindow::on_pushButton_2_released()
{
    ui->openGLWidget->toggleDebug();
}

