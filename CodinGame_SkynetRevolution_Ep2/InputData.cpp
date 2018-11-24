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

std::string InputData::GetNodeString(const int virusPos) { 
    string nodeString = "";
    Node node = GetNodeToRemove(virusPos);
    
    nodeString += node.GetCurrentNode();
    nodeString += " ";
    nodeString += node.GetNextNode();
    
    return nodeString;
}

Node InputData::GetNodeToRemove(const int virusNode) {
    for(Node node : nodes)
        node.ClearData();
        
    Node nodeToRemove = nodes.back();
    
    for(int exit : exits) {
        Node nodeToCheck = AStar(virusNode, exit);
        
        if(nodeToRemove.GetSteps() > nodeToCheck.GetSteps()) {
            nodeToRemove = nodeToCheck;
        }
    }
    
    //Remove node from nodes.
    
    return nodeToRemove;
}

Node InputData::AStar(const int curVirNode, const int exitNode) {
    //stack<Node, vector<Node>> allNodes(nodes);
    queue<Node> allNodesToCheck;
    vector<Node> allLastNodes;
    
    for(Node & node : nodes){
        if(node.GetCurrentNode() == curVirNode){
            node.CheckNode();
            node.ChangeStepsToNode(1);
            //node.ChangeNodeWeight(1 / node.GetSteps());
            if(node.GetNextNode() == exitNode){
                allLastNodes.push_back(node);
            }
            allNodesToCheck.push(node);
        } else if(node.GetNextNode() == curVirNode){
            node.CheckNode();
            node.SwapNode();
            node.ChangeStepsToNode(1);
            //node.ChangeNodeWeight(1 / node.GetSteps());
            if(node.GetCurrentNode() == exitNode){
                allLastNodes.push_back(node);
            }
            allNodesToCheck.push(node);
        }
    }
    
    while(!allNodesToCheck.empty()){
        Node nodeToCheck = allNodesToCheck.front();
        for(Node & node : nodes){
            if(!node.IsChecked() && nodeToCheck.IsNextNode(node)){
                node.CheckNode();
                node.ChangeStepsToNode(nodeToCheck.GetSteps() + 1);
                //node.ChangeNodeWeight(nodeToCheck.GetWeight() + nodeToCheck.GetWeight()/node.GetSteps());
                if (node.GetNextNode() == exitNode) {
                    allLastNodes.push_back(node);
                } else {
                    allNodesToCheck.push(node);
                }
            }
        }
        allNodesToCheck.pop();
    }
    
    Node nodeToRemove = allLastNodes.back();
    for(Node node : allLastNodes){
        if(nodeToRemove.GetSteps() > node.GetSteps()) {
            nodeToRemove = node;
        }
    }
    
    return nodeToRemove;
}



