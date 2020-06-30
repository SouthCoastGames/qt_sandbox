#include "scatterplotwindow.h"
#include "scatterdatamodifier.h"
#include "ui_mainwindow.h"
#include "plotdataobject.h"
#include "generatedata.h"

#include <QWindow>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QScrollBar>

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>

using namespace QtDataVisualization;

scatterplotWindow::~scatterplotWindow()
{

}

scatterplotWindow::scatterplotWindow(QWidget *parent)
    : QWidget(parent)
{
    // This is a test of a 3D Scatter plot...
    Q3DScatter *graph = new Q3DScatter();

    QWidget *container = QWidget::createWindowContainer(graph);

    QDesktopWidget dw;

    container->setFixedSize((dw.width()*0.75), (dw.height()*0.75));
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *leftvLayout = new QVBoxLayout();
    QVBoxLayout *rightvLayout = new QVBoxLayout();

    QScrollBar *playbackSlider = new QScrollBar();

    // Setup the Playback slider
    playbackSlider = new QScrollBar();
    playbackSlider->setFocusPolicy(Qt::StrongFocus);
    playbackSlider->setSingleStep(1);

//    hLayout->addWidget(container, 1);
    hLayout->addLayout(leftvLayout);
    hLayout->addLayout(rightvLayout);

    leftvLayout->addWidget(container, 1);
    leftvLayout->addWidget(playbackSlider, 2);

    QPushButton *generateTestData = new QPushButton(widget);
    generateTestData->setText(QStringLiteral("Create Test Data"));
    generateTestData->setToolTip(QStringLiteral("Generate test data in test_data.log file"));
    rightvLayout->addWidget(generateTestData, 0, Qt::AlignTop);

    QPushButton *loadButton = new QPushButton(widget);
    loadButton->setText(QStringLiteral("Load"));
    loadButton->setToolTip(QStringLiteral("Select Data File To Load"));
    rightvLayout->addWidget(loadButton, 1, Qt::AlignTop);

    dataSelectionGroupBox = new QGroupBox();
    rightvLayout->addWidget(dataSelectionGroupBox, 2, Qt::AlignTop);

    ScatterDataModifier *modifier = new ScatterDataModifier(graph);
    GenerateData *dataGenearator = new GenerateData();

    QPushButton *addDataButton = new QPushButton(widget);
    addDataButton->setText(QStringLiteral("Update Data"));
    rightvLayout->addWidget(addDataButton, 1, Qt::AlignTop);

    QObject::connect(playbackSlider, &QScrollBar::valueChanged, modifier, &ScatterDataModifier::sliderUpdate);
    QObject::connect(loadButton, &QPushButton::clicked, modifier, &ScatterDataModifier::loadFile);
    QObject::connect(generateTestData, &QPushButton::clicked, dataGenearator, &GenerateData::MakeData);
    QObject::connect(graph, &Q3DScatter::shadowQualityChanged, modifier, &ScatterDataModifier::shadowQualityUpdatedByVisual);
    QObject::connect(addDataButton, &QPushButton::clicked, modifier, &ScatterDataModifier::addAdditionalData);

    widget->show();
}

void scatterplotWindow::addDatagroup()
{
    return;
}
