#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput);
       //setAttribute(Qt::WA_NoSystemBackground, true);
      // setAttribute(Qt::WA_TranslucentBackground, true);
       ui->setupUi(this);
       //ui->openGLWidget->setWindowFlags(Qt::WindowTransparentForInput);
       //ui->openGLWidget->setAttribute(Qt::WA_TranslucentBackground, true);
       //ui->openGLWidget->setAttribute(Qt::WA_NoSystemBackground, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

