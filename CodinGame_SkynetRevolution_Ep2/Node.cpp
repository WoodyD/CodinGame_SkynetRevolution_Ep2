//
//  Node.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "Node.hpp"

Node::Node(int curNode, int nextNode) { 
    Node::curNode = curNode;
    Node::nextNode = nextNode;
}

void Node::SwapNode() {
    int prevCurNode = curNode;
    curNode = nextNode;
    nextNode = prevCurNode;
}

void Node::ClearData() {
    stepsToNode = 10000;
    isChecked = false;
    //nodeWeight = 0;
}

int Node::GetCurrentNode() const {
    return Node::curNode;
}

int Node::GetNextNode() const {
    return Node::nextNode;
}

void Node::ChangeStepsToNode(const int steps) { 
    Node::stepsToNode = steps;
}

void Node::ChangeNodeWeight(const int nodeWeight) { 
    Node::nodeWeight = nodeWeight;
}

int Node::GetSteps() const {
    return stepsToNode;
}

float Node::GetWeight() const {
    return nodeWeight;
}

bool Node::IsChecked() const { 
    return isChecked;
}

void Node::CheckNode() { 
    isChecked = true;
}

void Node::UncheckNode() { 
    isChecked = false;
}

bool Node::IsNextNode(Node & node) {
    if (nextNode == node.nextNode && curNode != node.curNode){
        node.SwapNode();
        return true;
    } else if (nextNode == node.curNode && curNode != node.nextNode) {
        return true;
    } else {
        return false;
    }
}

bool Node::IsEqual(const Node &node) const{
    if((curNode == node.curNode && nextNode == node.nextNode)
       || (curNode == node.nextNode && nextNode == node.curNode)){
        return true;
    } else {
        return false;
    }
}







