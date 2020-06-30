#include "surface_tutorial.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtCore/qmath.h>

using namespace QtDataVisualization;

const float sampleMin = -8.0f;
const float sampleMax = 8.0f;
const int sampleCountX = 50;
const int sampleCountZ = 50;

surface_tutorial::surface_tutorial()
{
    m_graph = new Q3DSurface();

    QWidget *container = QWidget::createWindowContainer(m_graph);
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();

    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    vLayout->setAlignment(Qt::AlignTop);

    m_sqrtSinProxy = new QSurfaceDataProxy();
    QSurface3DSeries *m_sqrtSinSeries = new QSurface3DSeries(m_sqrtSinProxy);

    // create a new camera object
    camera = new Q3DCamera();
    // set up the camera to look down from the "top"
    camera->setCameraPreset(Q3DCamera::CameraPresetDirectlyAbove);
    // assign the camera to the graph
    m_graph->scene()->setActiveCamera(camera);

    // Create a new touch input handler
    inputHandler = new QTouch3DInputHandler();
    // disable the rotation handler
    inputHandler->setRotationEnabled(false);
    inputHandler->setZoomEnabled(false);
    // assign the input handler to the graph
    m_graph->setActiveInputHandler(inputHandler);

    m_graph->setOrthoProjection(true);

    fillSqrtSinProxy();

    m_sqrtSinSeries->setDrawMode(QSurface3DSeries::DrawSurface);
    m_sqrtSinSeries->setFlatShadingEnabled(true);

    m_graph->axisX()->setLabelFormat("%.2f");
    m_graph->axisZ()->setLabelFormat("%.2f");
    m_graph->axisX()->setRange(sampleMin, sampleMax);
    m_graph->axisY()->setRange(0.0f, 2.0f);
    m_graph->axisZ()->setRange(sampleMin, sampleMax);
    m_graph->axisX()->setLabelAutoRotation(30);
    m_graph->axisY()->setLabelAutoRotation(90);
    m_graph->axisZ()->setLabelAutoRotation(30);

    m_graph->addSeries(m_sqrtSinSeries);

    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

    widget->show();
}

void surface_tutorial::fillSqrtSinProxy()
{
    float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(sampleCountZ);
    for (int i = 0; i < sampleCountZ; i++)
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
        // Keep values within range bounds, since just adding step can cause minor drift due
        // to the rounding errors.
        float z = qMin(sampleMax, (i * stepZ + sampleMin));
        int index = 0;
        for (int j = 0; j < sampleCountX; j++)
        {
            float x = qMin(sampleMax, (j * stepX + sampleMin));
            float R = qSqrt(z * z + x * x) + 0.01f;
            float y = (qSin(R) / R + 0.24f) * 1.61f;
            (*newRow)[index++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    m_sqrtSinProxy->resetArray(dataArray);
}
