#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QString>

class GenerateData : public QObject
{
    Q_OBJECT

public:
    GenerateData();

    void MakeData();

private:
    QString filename;
};

#endif // GENERATEDATA_H
