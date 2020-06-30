#ifndef PLOTDATAOBJECT_H
#define PLOTDATAOBJECT_H

#include <QTime>
#include <QString>

typedef enum _data_id
{
    DATA_ITEM1 = 0,
    DATA_ITEM2 = 1,
    DATA_ITEM3 = 2,
    DATA_ITEM4 = 3
} DATA_ID;

class PlotDataObject
{
public:
    //Methods
    PlotDataObject();
    PlotDataObject(QTime t, QString s, float x, float y, float z);
    ~PlotDataObject();

    void addTimestamp(QTime t);
    void addID(QString s);
    void addCoord(float x, float y, float z);

    // Members

private:
    // Methods
    QTime   timestamp;
    QString id;
    float   x_coord;
    float   y_coord;
    float   z_coord;

    // Members
};

#endif // PLOTDATAOBJECT_H
