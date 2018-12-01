//
//  InputData.hpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//


#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <queue> 
#include <iostream>

#include "Node.hpp"

// !! DONT USE NAMESPACE GLOBALY IN HEADER FILE
//using namespace std;

class InputData{
public:
    InputData()
    {
        std::cout << "InputData constructor" << std::endl;
    }
    
    InputData(const InputData& x)
    {
        std::cout << "InputData copy constructor" << std::endl;
    }
    
//    ˜InputData()
//    {
//        std::cout << "InputData destructor" << std::endl;
//    }

    void AddNode(const int point1, const int point2);
    void AddExit(int exit);
    std::string GetNodeString(const int virusPos);
    
private:
    std::vector<Node> nodes = {};
    std::vector<int> exits = {};
    Node GetNodeToRemove(const int virusPos);
    Node* AStar(const int curVirNode, const int exitNode);
    
    void RemoveFromNodes(Node &node);
    void SkipNodesWeight();
    void UncheckNodes();
};

