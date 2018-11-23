//
//  InputData.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "InputData.hpp"

void InputData::AddNode(const int point1, const int point2) { 
    Node node(point1, point2);
    InputData::nodes.push_back(node);
}

void InputData::AddExit(int exit) {
    InputData::exits.push_back(exit);
}

std::string InputData::GetNodeString(const int virusPos) const { 
    string nodeString = "";
    Node node = GetNodeToRemove(virusPos);
    
    nodeString += node.GetCurrentNode();
    nodeString += " ";
    nodeString += node.GetNextNode();
    
    return nodeString;
}

Node InputData::GetNodeToRemove(const int virusNode) const{
    Node nodeToRemove = nodes.back();
    for(int exit : exits) {
        Node nodeToCheck = AStar(virusNode, exit);
        if(nodeToRemove.GetWeight() < nodeToCheck.GetWeight())
            nodeToRemove = nodeToCheck;
    }
    return nodeToRemove;
}

Node InputData::AStar(const int curVirNode, const int exitNode) const {
    Node nodeToCheck = nodes.back();
    for(Node node : nodes){
        
    }
    return nodeToCheck;
}



