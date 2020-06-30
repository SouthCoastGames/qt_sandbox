#include "mainwindow.h"
#include "scatterdatamodifier.h"
#include "surface_tutorial.h"
#include "scatterplotwindow.h"
#include "treemodel.h"

#include <sys/stat.h>

#include <QFile>
#include <QTreeView>
#include <QFileDialog>

struct stat results;

#include <QtWidgets/QApplication>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //  MainWindow is a demo window to test out text boxes.
    //  We're not going to be using it right now.
    // MainWindow w;
    // w.show();

    // Scatter Plot Menu
    //scatterplotWindow scatter_window;

    // surface plot sample
    //surface_tutorial surface;

    //scatter_window.show();

    QString filename = QFileDialog::getOpenFileName(nullptr,
                                                    QStringLiteral("Open Log File"),
                                                    QStringLiteral("Log File (*.log);;All Files (*)"));

    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    TreeModel model(file.readAll());
    file.close();

    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));
    view.show();

    return a.exec();
}
