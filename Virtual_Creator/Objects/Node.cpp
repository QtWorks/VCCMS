/** *********************************************************************** **/
/** *********************************************************************** **/
/**     Created by:     Ruan (Baggins) Luies 23511354                       **/
/**     email:          23511354@nwu.ac.za                                  **/
/**     Project name:   Virtual Concierge Creator And Management System     **/
/**     File Name:      Node.cpp                                            **/
/**     From Date:      2015/02/24                                          **/
/**     To Date:        2015/10/01                                          **/
/** **********************************************************************  **/
/** *********************************************************************** **/

#include "Objects/Node.h"
#include <QVector2D>
#include <QVector3D>
#include <QString>

Node::Node()
{
    m_position = new QVector3D(0,0,0);
    m_color = new QVector3D(0,0,0);
    m_name = new QString();
    m_connected.clear();
    m_connectedindex.clear();
    m_shortest.clear();
    m_links = false;
    m_walk = false;
    m_bike = false;
    m_vehicle = false;
    m_wheelchair = false;
    m_nshortest = 0;
    m_g = 10000000.0;
    m_lastindex = 0;
}

Node::Node(QVector3D * Position)
{
    m_position = Position;
    m_color = new QVector3D(0,0,0);
    m_name = new QString();
    m_connected.clear();
    m_connectedindex.clear();
    m_shortest.clear();
    m_links = false;
    m_nshortest = 0;
    m_g = 10000000.0;
}

QVector3D Node::getColor()
{
    return *m_color;
}

void Node::setColor(QVector3D *color)
{
    m_color = color;
}

Node::Node(QVector3D *Position, QString *Name)
{
    m_position = Position;
    m_name = Name;
    m_color = new QVector3D(0,0,0);
    m_connected.clear();
    m_connectedindex.clear();
    m_shortest.clear();
    m_links = false;
    m_nshortest = 0;
    m_g = 10000000.0;
}

void Node::setSourceNode()
{
    m_color->setX(0.0f);
    m_color->setY(0.0f);
    m_color->setZ(1.0f);
}

void Node::setDestinationNode()
{
    m_color->setX(1.0f);
    m_color->setY(0.0f);
    m_color->setZ(0.0f);
}

void Node::AddLink(QString *Name, int index)
{
    m_connected.push_back(Name);
    m_connectedindex.push_back(index);
    m_links = true;
}

void Node::RemoveLinkedFromIndex(int index)
{
    m_connected.removeAt(index);
    m_connectedindex.removeAt(index);
    if(m_connected.count()<1)
        m_links = false;
}
void Node::MoveLinkedIndexBack(int index)
{
    // replace the specific index
    if(m_connectedindex.value(index)>0)
    m_connectedindex.replace(index,m_connectedindex.value(index)-1);
}

QVector3D Node::Position()
{
    return *m_position;
}

int Node::countConnected()
{
    return m_connected.size();
}

QString Node::getLinkedName(int index)
{
    return *m_connected.value(index);
}

int Node::getConnectedIndex(int index)
{
    return m_connectedindex.value(index);
}

QString Node::getName()
{
    return *m_name;
}

void Node::clearPath()
{
    m_shortest.clear();
}

void Node::addShortest(int index)
{
    m_shortest.push_back(index);
}

void Node::setG(double g)
{
    m_g = g;
}

double Node::getG()
{
    return m_g;
}

void Node::setShortest(int index)
{
    m_nshortest = index;
}

int Node::getShortestIndex()
{
    return m_nshortest;
}

void Node::setWalk(bool value)
{
    m_walk = value;
}

void Node::setWheelChair(bool value)
{
    m_wheelchair = value;
}

void Node::setVehicle(bool value)
{
    m_vehicle = value;
}

void Node::setBike(bool value)
{
    m_bike = value;
}

bool Node::getWalk()
{
    return m_walk;
}

bool Node::getWheelChair()
{
    return m_wheelchair;
}

bool Node::getVehicle()
{
    return m_vehicle;
}

bool Node::getBike()
{
    return m_bike;
}
