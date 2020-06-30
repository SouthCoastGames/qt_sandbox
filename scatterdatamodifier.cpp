#include "scatterdatamodifier.h"
#include "openfiledialog.h"
#include <stdio.h>
#include <time.h>

#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtWidgets/QComboBox>
#include <QMessageBox>

using namespace QtDataVisualization;

const int lowerNumberOfItems = 900;
const float lowerCurveDivider = 0.75f;


ScatterDataModifier::ScatterDataModifier(Q3DScatter *scatter)
    : m_graph(scatter),
      m_fontSize(40.0f),
      m_style(QAbstract3DSeries::MeshSphere),
      m_smooth(true),
      m_itemCount(lowerNumberOfItems),
      m_curveDivider(lowerCurveDivider)
{
    m_graph->activeTheme()->setType(Q3DTheme::ThemeEbony);
    QFont font = m_graph->activeTheme()->font();
    font.setPointSize(10);
    m_graph->activeTheme()->setFont(font);
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftLow);
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);

    proxy = new QScatterDataProxy;
//    QScatter3DSeries *series = new QScatter3DSeries(proxy);

//    addData();
}

ScatterDataModifier::~ScatterDataModifier()
{
}

int ScatterDataModifier::addDataSeries()
{
    QScatter3DSeries *newSeries = new QScatter3DSeries(proxy);

    newSeries->setItemLabelFormat(QStringLiteral("@xTitle: #xLabel @xTitle: @yLabel @zTitle: @zLabel"));
    newSeries->setMeshSmooth(1);
    m_graph->addSeries(newSeries);
    _num_series++;

    dataArray = new QScatterDataArray;
    dataArray->resize(5);
    ptrToDataArray = &dataArray->first();

    return _num_series;
}

void ScatterDataModifier::resetData()
{
    dataArray->clear();
}

void ScatterDataModifier::addData(int series, float x, float y, float z)
{
    QScatterDataItem *newItem = new QScatterDataItem;

    newItem->setPosition(QVector3D(x, y, z));

    dataArray->append(*newItem);
}

void ScatterDataModifier::addData()
{
    m_graph->axisX()->setTitle("X");
    m_graph->axisY()->setTitle("Y");
    m_graph->axisZ()->setTitle("Z");

    ptrToDataArray->setPosition(QVector3D(1.0, 0.5, 0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(1.2, 0.6, -.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(1.4, 0.7, -1.0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(1.2, 0.8, -1.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(1.0, 0.9, -2.0));
    ptrToDataArray++;

//    float limit = qSqrt(m_itemCount) / 2.0f;
//    for (float i = -limit; i < limit; i++)
//    {
//        for (float j = -limit; j < limit; j++)
//        {
//            ptrToDataArray->setPosition(QVector3D(i + 0.5f, qCos(qDegreesToRadians((i * j) / m_curveDivider)), j + 0.5f));
//            ptrToDataArray++;
//        }
//    }

    m_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);
}

void ScatterDataModifier::addAdditionalData()
{
    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(10);
    QScatterDataItem *ptrToDataArray = &dataArray->first();

    ptrToDataArray->setPosition(QVector3D(2.0, 0.5, 0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(2.2, 1.6, -.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(2.4, 2.7, -1.0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(3.2, 3.8, -1.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(3.0, 4.9, -2.0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(4.0, 0.5, 0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(4.2, 1.6, -.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(5.4, 2.7, -1.0));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(6.2, 3.8, -1.5));
    ptrToDataArray++;
    ptrToDataArray->setPosition(QVector3D(7.0, 4.9, -2.0));
    ptrToDataArray++;

//    float limit = qSqrt(m_itemCount) / 2.0f;
//    for (float i = -limit; i < limit; i++)
//    {
//        for (float j = -limit; j < limit; j++)
//        {
//            ptrToDataArray->setPosition(QVector3D(i + 0.5f, qCos(qDegreesToRadians((i * j) / m_curveDivider)), j + 0.5f));
//            ptrToDataArray++;
//        }
//    }

    m_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);
}

void ScatterDataModifier::sliderUpdate()
{
    return;
}

void ScatterDataModifier::shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality sq)
{
    int quality = int(sq);
    emit shadowQualityChanged(quality);   // connected to a checkbox in main.cpp
}

void ScatterDataModifier::loadFile()
{
    OpenFileDialog openfile;

//    openfile.loadFromFile(plotData);
}
