#include "SecondWindow.h"

SecondWindow::SecondWindow() : QWidget()
{
    setFixedSize(500, 120);
    setWindowTitle("Chargement");

    QHBoxLayout *layout = new QHBoxLayout();

    m_progress = new QProgressBar();
    m_progress->setGeometry(10, 60, 150, 20);
    m_progress->setMinimum(0);
    m_progress->setValue(0);

    layout->addWidget(m_progress);
    setLayout(layout);

}

void SecondWindow::setMax(int max)

{
    if(max == 0)
    {
        QMessageBox msgWarning;
        msgWarning.setText("Votre repertoire ne contient aucune photo");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Warning");
        msgWarning.exec();
        if (msgWarning.clickedButton()) {
            this->close();
        }
    }
    m_progress->setMaximum(max);
}

void SecondWindow::changement()

{
    m_progress->setValue(m_progress->value()+1);
}


