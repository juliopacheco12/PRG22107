#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSerialPort *serialPort;

public slots:
    void connectToSerial();
    void startReading();
    void enableWidgets(bool activate);
    void keyPressEvent(QKeyEvent *event);


signals:
    void startReading(bool ok);

private slots:
    void on_pushButton_frente_clicked();

    void on_pushButton_direita_clicked();

    void on_pushButton_esquerda_clicked();

    void on_pushButton_re_clicked();

    void on_pushButton_tremelique_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
