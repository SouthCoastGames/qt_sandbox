#ifndef SCATTERDATAMODIFIER_H
#define SCATTERDATAMODIFIER_H
#include <QtDataVisualization>
#include <QVector>

using namespace QtDataVisualization;

class ScatterDataModifier : public QObject
{
    Q_OBJECT
public:
    ScatterDataModifier(Q3DScatter *m_graph);
    ~ScatterDataModifier();

    void addData();
    void addData(int series, float x, float y, float z);
    int  addDataSeries();
    void addAdditionalData();
    void resetData();

//    void changeStyle();
//    void changePresetCamera();
//    void changeLabelStyle();
//    void changeFont(const QFont &font);
//    void changeFontSize(int fontsize);
//    void setBackgroundEnabled(bool enabled);
//    void setGridEnabled(int enabled);
//    void setSmoothDots(int enabled);
//    void toggleItemCount();
    void loadFile();
//    void generateData();
    void sliderUpdate();
//    void start();

public Q_SLOTS:
//    void changeStyle(int style);
//    void changeTheme(int theme);
//    void changeShadowQuality(int quality);
    void shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality shadowQuality);

Q_SIGNALS:
//    void backgroundEnabledChanged(bool enabled);
//    void gridEnabledChanged(bool enabled);
    void shadowQualityChanged(int quality);
//    void fontChanged(QFont font);

private:
    QVector3D randVector();
    Q3DScatter *m_graph;
    int m_fontSize;
    QAbstract3DSeries::Mesh m_style;
    bool m_smooth;
    int m_itemCount;
    float m_curveDivider;
    int _num_series;
    QScatterDataProxy *proxy;
    QScatterDataArray *dataArray;
    QScatterDataItem  *ptrToDataArray;
};

#endif // SCATTERDATAMODIFIER_H
