#include "MaFenetre.h"
#include "SecondWindow.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(700, 120);
    setWindowTitle("Tri d'image");

    // Création du layout de formulaire et de ses widgets

    m_rep1 = new QLabel("Choix du repertoire : ",this);
    m_rep2 = new QLabel("Choix du repertoire : ",this);
    QPushButton *boutonRep1 = new QPushButton("Choix", this);
    QPushButton *boutonRep2 = new QPushButton("Choix", this);
    QPushButton *boutonValider = new QPushButton("Valider", this);

    // Création du layout principal
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_rep1, 0, 0, 1, 2);
    layout->addWidget(boutonRep1, 0, 2, 1, 1);
    layout->addWidget(m_rep2, 1, 0, 1, 2);
    layout->addWidget(boutonRep2, 1, 2, 1, 1);
    layout->addWidget(m_rep1, 1, 0, 1, 2);
    layout->addWidget(boutonValider, 2, 0, 1, 3);

    setLayout(layout);

    connect(boutonValider, SIGNAL(clicked()), this, SLOT(trimage()));
    connect(boutonRep1, SIGNAL(clicked()), this, SLOT(choixRep1()));
    connect(boutonRep2, SIGNAL(clicked()), this, SLOT(choixRep2()));

}


void MaFenetre::trimage()
{
    SecondWindow *fenetre = new SecondWindow;
    fenetre->show();

    //on se place dans le répertoire voulu
    QDir const source(main_repertoire);
        if (!source.exists())
            return;
    QFileInfoList list = source.entryInfoList(QDir::NoDotAndDotDot|QDir::Files);
    QString sortrep;
    int max = 0;
    for(int i=0;i<list.size();++i) {
        const QFileInfo finfo = list.at(i);
        QString ext = finfo.suffix();
        if(ext=="jpg" || ext=="png" || ext=="jpeg")
        {
            max++;
        }
    }
    fenetre->setMax(max);
    for(int i=0;i<list.size();++i) {
        const QFileInfo finfo = list.at(i);
        QString ext = finfo.suffix();
        if(ext=="jpg" || ext=="png" || ext=="jpeg")
        {
            QDateTime mtime = finfo.lastModified();
            QString day = mtime.toString("dd");
            QString month = mtime.toString("MMMM");
            QString year = mtime.toString("yyyy");
            sortrep = sort_repertoire;
            source.setCurrent(sortrep);
            QDir().mkdir(year);
            source.setCurrent(sortrep+"/"+year);
            QDir().mkdir(month);
            source.setCurrent(sortrep+"/"+year+"/"+month);
            QDir().mkdir(day);
            QString namefile = list[i].fileName();
            QFile::copy(main_repertoire+"/"+namefile, sortrep+"/"+year+"/"+month+"/"+day+"/"+namefile);
            fenetre->changement();
            if(QDir::setCurrent(main_repertoire))
            {
                QFile::remove(namefile);
            }
        }
    }
}

void MaFenetre::choixRep1()
{
    main_repertoire = QFileDialog::getExistingDirectory(this);
    m_rep1->setText(main_repertoire);
}

void MaFenetre::choixRep2()
{
    sort_repertoire = QFileDialog::getExistingDirectory(this);
    m_rep2->setText(sort_repertoire);
}




