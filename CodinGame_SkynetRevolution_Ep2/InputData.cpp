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
    nodes.push_back(node);
}

void InputData::AddExit(int exit) {
    exits.push_back(exit);
}

std::string InputData::GetNodeString(const int virusPos) const { 
    string nodeString = "";
    Node node = GetNodeToRemove(virusPos);
    
    nodeString += node.GetCurrentNode();
    nodeString += " ";
    nodeString += node.GetNextNode();
    
    return nodeString;
}

Node InputData::GetNodeToRemove(const int virusNode) const {
    for(Node node : nodes)
        node.ClearData();
        
    Node nodeToRemove = nodes.back();
    
    for(int exit : exits) {
        Node nodeToCheck = AStar(virusNode, exit);
        
        if(nodeToRemove.GetWeight() < nodeToCheck.GetWeight()) {
            nodeToRemove = nodeToCheck;
        }
    }
    
    return nodeToRemove;
}

Node InputData::AStar(const int curVirNode, const int exitNode) const {
    Node nodeToCheck = nodes.back();
    
    stack<Node> allNodesToCheck;
    vector<Node> allLastNodes;
    
    
    for(Node node : nodes){
        node.ChangeNodeWeight(1);
        node.ChangeStepsToNode(1);
        
        if(node.GetCurrentNode() == curVirNode){
            if(node.GetNextNode() == exitNode){
                return node;
            }
            allNodesToCheck.push(node);
        } else if(node.GetNextNode() == curVirNode){
            if(node.GetCurrentNode() == exitNode){
                return node;
            }
            node.SwapCurNode();
            allNodesToCheck.push(node);
        }
    }
    
    return nodeToCheck;
}



