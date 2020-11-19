#pragma once

#include <QtWidgets/QWidget>

#pragma once

#include "nodedata.h"
#include "porttype.h"
#include <memory>

class NodeDataModel : public QObject {
  Q_OBJECT

public:
  NodeDataModel() {}
  virtual ~NodeDataModel() = default;
  virtual unsigned int nPorts(PortType portType) const = 0;
  virtual NodeDataType dataType(PortType portType,
                                PortIndex portIndex) const = 0;

public:
  /// Triggers the algorithm
  virtual void setInData(std::shared_ptr<NodeData> nodeData,
                         PortIndex port) = 0;
  virtual std::shared_ptr<NodeData> outData(PortIndex port) = 0;
  virtual QWidget *embeddedWidget() = 0;
  virtual bool resizable() const { return false; }
};

class DataModel : public NodeDataModel {
  Q_OBJECT
public:
  DataModel() : NodeDataModel() {}
  ~DataModel() override {}
  unsigned int nPorts(PortType) const { return 1; }
  NodeDataType dataType(PortType, PortIndex) const { return NodeDataType(); }
  void setInData(std::shared_ptr<NodeData>, PortIndex) {}
  std::shared_ptr<NodeData> outData(PortIndex) { return nullptr; }
  QWidget *embeddedWidget() { return nullptr; }
};
