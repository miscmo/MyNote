#include "Node.h"

#include <QDebug>

namespace gnote {

Node::Node(const QString &dir)
    : m_sNodeDir(dir) {
}
Node::~Node() {
    qDebug() << "~Node" << endl;
}

void Node::addChild(QSharedPointer<Node> node) {
    m_pChilds.append(node);
}

}
