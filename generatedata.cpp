#include "generatedata.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>

#include "plotdataobject.h"

GenerateData::GenerateData()
{

}

void GenerateData::MakeData()
{
    filename = QFileDialog::getSaveFileName(nullptr,
                                            tr("Save Log File"),
                                            "",
                                            tr("All Files (*.*);;Log Files (*.log)"));

    if (filename.isEmpty())
    {
        // filename is empty, so there is nothing to do
        return;
    }

    QFile fileHandle(filename);

    fileHandle.open(QIODevice::WriteOnly);

    QDateTime startTime = QDateTime::currentDateTime();
    QDateTime currentTime;

    QDataStream outputStream(&fileHandle);

    QString line;
    float x, y, z;
    x = -1.0f;
    y = 1.2f;
    z = 1.5f;

    for (int i = 0; i <= 10; i++)
    {
        QString tempStr;
        QString body;

        // Add a second to the current time.
        currentTime = startTime.addSecs(i);

        line = tempStr.setNum(DATA_ID::DATA_ITEM1);
        line += ";";

        // now generate the body of the data...
        body = currentTime.toString(Qt::ISODate);
        body += ";";
        body += tempStr.setNum(x);
        body += ";";
        body += tempStr.setNum(y);
        body += ";";
        body += tempStr.setNum(z);
        body += '\n';

        // calculate the size of the data body.
        line += tempStr.setNum(body.size());
        // add the body size and body data to the message
        line = line + ";" + body;

        x += 0.1;

        outputStream << line;
    }
}
