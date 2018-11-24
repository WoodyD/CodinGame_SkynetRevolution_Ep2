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

#include "Node.hpp"

using namespace std;

class InputData{
public:
    InputData() = default;
    void AddNode(const int point1, const int point2);
    void AddExit(int exit);
    string GetNodeString(const int virusPos);
    
private:
    vector<Node> nodes = {};
    vector<int> exits = {};
    Node GetNodeToRemove(const int virusNode);
    Node AStar(const int curVirNode, const int exitNode);
    
};
