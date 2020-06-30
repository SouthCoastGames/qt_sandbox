#include "plotdataobject.h"

PlotDataObject::PlotDataObject()
{
    timestamp = QTime::currentTime();
    id = "";
    x_coord = y_coord = z_coord = 0.0;

    return;
}

PlotDataObject::PlotDataObject(QTime t, QString s, float x, float y, float z)
{
    timestamp = t;
    id = s;
    x_coord = x;
    y_coord = y;
    z_coord = z;

    return;
}

PlotDataObject::~PlotDataObject()
{
    return;
}

void PlotDataObject::addTimestamp(QTime t)
{
    timestamp = t;

    return;
}

void PlotDataObject::addID(QString s)
{
    id = s;

    return;
}

void PlotDataObject::addCoord(float x, float y, float z)
{
    x_coord = x;
    y_coord = y;
    z_coord = z;

    return;
}
