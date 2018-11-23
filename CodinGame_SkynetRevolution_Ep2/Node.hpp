//
//  Node.hpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#pragma once

struct Node{
public:
    Node() = delete;
    Node(int curNode, int nextNode);
    
    void SwapCurNode();
    void ChangeStepsToNode(const int steps);
    void ChangeNodeWeight(const int nodeWeight);
    
    int GetCurrentNode() const;
    int GetNextNode() const;
    int GetSteps() const;
    int GetWeight() const;
    
private:
    int curNode = 0;
    int nextNode = 0;
    int stepsToNode = 0;
    int nodeWeight = 0;
};
