#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressBar>
#include <QDateTime>
#include <QFormLayout>
#include <QSignalMapper>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QLabel>
#include "qt_windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QFileDialog>
#include <QDebug>

using namespace std;

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void trimage();
    void choixRep1();
    void choixRep2();

    private:
    QPushButton *m_boutonDialogue;
    QLabel *m_rep1;
    QLabel *m_rep2;
    QString main_repertoire;
    QString sort_repertoire;
    int nbProgressBar;

};

#endif // MAFENETRE_H
