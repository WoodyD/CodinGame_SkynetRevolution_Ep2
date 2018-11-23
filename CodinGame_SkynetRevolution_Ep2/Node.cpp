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

void Node::SwapCurNode() {
    int prevCurNode = curNode;
    curNode = nextNode;
    nextNode = prevCurNode;
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

int Node::GetWeight() const { 
    return nodeWeight;
}


