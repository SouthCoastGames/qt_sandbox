#ifndef OPENFILEDIALOG_H
#define OPENFILEDIALOG_H
#include "plotdataobject.h"
#include <QWidget>
#include <QVector>

class OpenFileDialog : public QWidget
{
public:
    OpenFileDialog();
    void loadFromFile(QVector<PlotDataObject> *data);
};

#endif // OPENFILEDIALOG_H
