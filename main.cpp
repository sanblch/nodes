#include "graphics.h"
#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <memory>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  FlowScene scene;
  FlowView view(&scene);

  QMainWindow mainWindow;
  auto toolBar = mainWindow.addToolBar("data");
  auto action = toolBar->addAction("Create node");
  QObject::connect(action, &QAction::triggered, [&scene]() {
    std::unique_ptr<NodeDataModel> model = std::make_unique<DataModel>();
    scene.createNode(std::move(model));
  });

  mainWindow.setCentralWidget(&view);
  mainWindow.setWindowTitle("Example");
  mainWindow.resize(800, 600);
  mainWindow.show();

  return app.exec();
}
