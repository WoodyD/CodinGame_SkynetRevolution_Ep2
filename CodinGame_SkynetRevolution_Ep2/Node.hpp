//
//  Node.hpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#pragma once

#include <iostream>

struct Node{
public:
    Node(){};
    Node(int curNode, int nextNode);
//    Node(const Node& n) {
//        std::cout << "Node copy constructor" << std::endl;
//    };
    
    void SwapNode();
    void ChangeStepsToNode(const int steps);
    void ChangeNodeWeight(const int nodeWeight);
    void CheckNode();
    void UncheckNode();
    void ClearData();
    
    int GetCurrentNode() const;
    int GetNextNode() const;
    int GetSteps() const;
    int GetWeight() const;
    bool IsChecked() const;
    bool IsNextNode(Node & node);
    bool IsEqual(const Node & node) const;
    
private:
    int curNode = 0;
    int nextNode = 0;
    int stepsToNode = 0;
    int nodeWeight = 0;
    bool isChecked = false;
    bool isSwapedThisTurn = false;
};
