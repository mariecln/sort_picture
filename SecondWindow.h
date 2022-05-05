#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QTimer>
#include <QMessageBox>


using namespace std;

class SecondWindow : public QWidget
{
    Q_OBJECT

    public:
    SecondWindow();
    void setMax(int max);
    void changement();

    private:
    QProgressBar *m_progress;
    int imageMax;

};

#endif // SECONDWINDOW_H
