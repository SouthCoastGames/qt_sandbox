#include "openfiledialog.h"
#include "plotdataobject.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

OpenFileDialog::OpenFileDialog()
{

}

void OpenFileDialog::loadFromFile(QVector<PlotDataObject> *data)
{
    QFile inputFile;

    QString filename = QFileDialog::getOpenFileName(this,
                                                    QStringLiteral("Open Log File"),
                                                    QStringLiteral("Log File (*.log);;All Files (*)"));

    if (!filename.isEmpty())
    {
        QFile file(filename);
        QDataStream inputStream(&file);

        if (!file.open(QIODevice::ReadOnly))
        {
            // display a dialog box with the error.
            QMessageBox::information(this,
                                     QStringLiteral("Unable to open file"),
                                     file.errorString());
        }
        else
        {
            // file exists, so read in the data.
            while (!file.atEnd())
            {
                QString line;
                inputStream >> line;
//                process_line(line);
                QMessageBox::information(this, "Line of Text", line);
            }
        }
    }
}
