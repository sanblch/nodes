#pragma once

#include "nodedatamodel.h"
#include <QObject>
#include <QUuid>
#include <memory>

class Node : public QObject {
  Q_OBJECT

  QUuid m_uid;

  // data
  std::unique_ptr<NodeDataModel> m_nodeDataModel;

public:
  /// NodeDataModel should be an rvalue and is moved into the Node
  Node(std::unique_ptr<NodeDataModel> &&dataModel)
      : m_uid(QUuid::createUuid()), m_nodeDataModel(std::move(dataModel)) {}

  virtual ~Node() = default;

public:
  QUuid id() const { return m_uid; }

  NodeDataModel *nodeDataModel() const { return m_nodeDataModel.get(); }
};
