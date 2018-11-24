//
//  TestCases.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "TestCases.hpp"

InputData TestCases::CreateTestCase0() {
    InputData data;
    
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        data.AddNode(N1, N2);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        data.AddExit(EI);
    }
    
    return data;
}

InputData TestCases::CreateTestCase1() {
    //In: 0 | Out: 3 4
    //In: 3 | Out: 3 5
    //In: 6 | Out: 6 5
    //In: 3 | Out: 7 4
    InputData data;
    
    data.AddNode(6, 2); data.AddNode(7, 3); data.AddNode(6, 3);
    data.AddNode(5, 3); data.AddNode(3, 4); data.AddNode(7, 1);
    data.AddNode(2, 0); data.AddNode(0, 1); data.AddNode(0, 3);
    data.AddNode(1, 3); data.AddNode(2, 3); data.AddNode(7, 4);
    data.AddNode(6, 5);
    
    data.AddExit(4);
    data.AddExit(5);
    
    return data;
}




