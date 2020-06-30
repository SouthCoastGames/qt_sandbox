#ifndef SCATTERPLOTWINDOW_H
#define SCATTERPLOTWINDOW_H

#include "plotdataobject.h"

#include <QtDataVisualization>
#include <QWindow>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QVector>

class scatterplotWindow : public QWidget
{
public:
    scatterplotWindow(QWidget *parent = nullptr);
    ~scatterplotWindow();
    void addDatagroup();
    QVector<PlotDataObject> *plotData;

    QGroupBox *dataSelectionGroupBox;
};

#endif // SCATTERPLOTWINDOW_H
