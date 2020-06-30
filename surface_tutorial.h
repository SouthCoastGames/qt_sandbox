#ifndef SURFACE_TUTORIAL_H
#define SURFACE_TUTORIAL_H

#include <QWidget>
#include <Q3DSurface>
#include <QTouch3DInputHandler>

using namespace QtDataVisualization;

class surface_tutorial : public QWidget, QAbstract3DInputHandler
{
public:
    surface_tutorial();
    void fillSqrtSinProxy();

    // members
    Q3DSurface *m_graph;
    Q3DCamera *camera;
    QTouch3DInputHandler *inputHandler;
    QSurfaceDataProxy *m_sqrtSinProxy;
    QSurface3DSeries *m_sqrtSinSeries;

};

#endif // SURFACE_TUTORIAL_H
