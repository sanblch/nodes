#pragma once

#include "node.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class FlowScene : public QGraphicsScene {
  Q_OBJECT
  std::map<QUuid, std::unique_ptr<Node>> m_nodes;

public:
  FlowScene(QObject *parent = Q_NULLPTR) : QGraphicsScene(parent) {
    setItemIndexMethod(QGraphicsScene::NoIndex);
  }

  Node &createNode(std::unique_ptr<NodeDataModel> &&dataModel) {
    auto node = std::make_unique<Node>(std::move(dataModel));
    m_nodes[node->id()] = std::move(node);
    return *node.get();
  }
};

class FlowView : public QGraphicsView {
  Q_OBJECT

public:
  FlowView(QWidget *parent = Q_NULLPTR) : QGraphicsView(parent) {
    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHint(QPainter::Antialiasing);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setCacheMode(QGraphicsView::CacheBackground);
  }

  FlowView(FlowScene *scene, QWidget *parent = Q_NULLPTR) : FlowView(parent) {
    QGraphicsView::setScene(scene);
  }

  FlowView(const FlowView &) = delete;
  FlowView operator=(const FlowView &) = delete;

};
