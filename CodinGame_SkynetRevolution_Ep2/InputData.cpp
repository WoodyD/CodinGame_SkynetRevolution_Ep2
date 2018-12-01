//
//  InputData.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "InputData.hpp"
#include <optional>

// The way to not show private methods in header file
namespace
{
    //optional parameters "old way"
    void Blah(InputData* x)
    {
        if (x)
        {
            x->GetNodeString(0);
        }
    }

    //optional parameters "new way"
    void Blah(std::optional<InputData> x)
    {
        if (x)
        {
            x->GetNodeString(0);
        }
    }
}

void InputData::AddNode(const int point1, const int point2) {
    Node node(point1, point2);
    nodes.push_back(node);
}

void InputData::AddExit(int exit) {
    exits.push_back(exit);
}

std::string InputData::GetNodeString(const int virusNode) {
    std::string nodeString = "";
    Node node = GetNodeToRemove(virusNode);
    
    nodeString += std::to_string(node.GetCurrentNode());
    nodeString += " ";
    nodeString += std::to_string(node.GetNextNode());
    
    return nodeString;
}

Node InputData::GetNodeToRemove(const int virusPos) {
    Node* nodeToRemove = nullptr;
    
    for(int exit : exits) {
        Node nodeToCheck = AStar(virusPos, exit);
//        if(!nodeToCheck)
//            continue;
        if(!nodeToRemove){
            nodeToRemove = &nodeToCheck;
            continue;
        }
        if(nodeToCheck.GetCurrentNode() == nodeToRemove->GetCurrentNode()){
            nodeToCheck.ChangeNodeWeight(nodeToCheck.GetWeight() + 1);
            nodeToRemove->ChangeNodeWeight(nodeToRemove->GetWeight() + 1);
        }
        
        if(nodeToRemove->GetSteps() > nodeToCheck.GetSteps()) {
            nodeToRemove = &nodeToCheck;
        } else if(nodeToRemove->GetSteps() == nodeToCheck.GetSteps()){
            if(nodeToRemove->GetWeight() < nodeToCheck.GetWeight())
                nodeToRemove = &nodeToCheck;
        }
    }
    
    Node removedNode;
    if(nodeToRemove)
        removedNode = *nodeToRemove;
    else{
        for(auto& exit : exits){
            for(auto& node : nodes)
                if(node.GetCurrentNode() == exit || node.GetNextNode() == exit)
                    removedNode = node;
        }
    }
    
    RemoveFromNodes(removedNode);
    
    SkipNodesWeight();
    
    return removedNode;
}

Node InputData::AStar (const int curVirNode, const int exitNode) {
    //Node nodeToRemove = nodes.back();
    std::queue<Node*> allNodesToCheck;
    //Node* lastNode = nullptr;
    Node lastNode(-1, -1);
    lastNode.ChangeStepsToNode(100);
    //std::vector<Node> allLastNodes;
    
    for(Node & node : nodes)
        node.ClearData();
    
    for(Node & node : nodes){
        if(node.GetCurrentNode() == curVirNode){
            node.CheckNode();
            node.ChangeStepsToNode(1);
            if(node.GetNextNode() == exitNode){
                return node;
                //return lastNode;
                //allLastNodes.push_back(node);
            }
            allNodesToCheck.push(&node);
        } else if(node.GetNextNode() == curVirNode){
            node.CheckNode();
            node.ChangeStepsToNode(1);
            node.SwapNode();
            if(node.GetCurrentNode() == exitNode){
                return node;
                //return lastNode;
                //allLastNodes.push_back(node);
            }
            allNodesToCheck.push(&node);
        }
    }
    
    while(!allNodesToCheck.empty()){
        Node* nodeToCheck = allNodesToCheck.front();
        nodeToCheck->CheckNode();
        for(Node & node : nodes){
            if(nodeToCheck->IsNextNode(node)){
                if (node.GetNextNode() == exitNode){
                    node.ChangeStepsToNode(nodeToCheck->GetSteps() + 1);

                    if(lastNode.GetSteps() > node.GetSteps()){
                        lastNode = node;
                    }
                    
                } else if(!node.IsChecked()){
                    node.ChangeStepsToNode(nodeToCheck->GetSteps() + 1);
                    allNodesToCheck.push(&node);
                }
            }
        }
        
        allNodesToCheck.pop();
    }
    
    return lastNode;
}

void InputData::RemoveFromNodes(Node &nodeToRemove) {
    int nodeIndex = -1;
    for(Node & node : nodes){
        nodeIndex++;
        if(node.IsEqual(nodeToRemove))
            break;
    }
    
    std::vector<Node>::iterator it = nodes.begin();
    advance(it, nodeIndex);
    nodes.erase(it);
}

void InputData::SkipNodesWeight() { 
    for(Node & node : nodes)
        node.ChangeNodeWeight(0);
}

void InputData::UncheckNodes(){
    for(Node & node : nodes)
        node.UncheckNode();
}






