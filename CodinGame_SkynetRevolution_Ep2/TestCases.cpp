//
//  TestCases.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include "TestCases.hpp"

using namespace std;

InputData TestCases::CreateTestCase0() {
    InputData data;
    
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    cerr << N << L << E << endl;
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        cerr << "N1 N2: " << N1 << N2 << endl;
        data.AddNode(N1, N2);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        cerr << "EI: " << EI << endl;
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

InputData TestCases::CreateTestCase2() {
    //In: 0 | Out: 1 4
    //In: 9 | Out: 2 6
    //In: 1 | Out: 1 3
    //In: 2 | Out: 2 5
    InputData data;
    
    data.AddNode(2, 6); data.AddNode(9, 7); data.AddNode(0, 7);
    data.AddNode(9, 8); data.AddNode(8, 2); data.AddNode(7, 1);
    data.AddNode(9, 2); data.AddNode(3, 1); data.AddNode(2, 5);
    data.AddNode(0, 8); data.AddNode(4, 1); data.AddNode(9, 1);
    data.AddNode(0, 9); data.AddNode(2, 1);
    
    data.AddExit(3);
    data.AddExit(4);
    data.AddExit(5);
    data.AddExit(6);
    
    return data;
}

InputData TestCases::CreateTestCase3() {
    //In: 8 | Out: 9 0
    //In: 9 | Out: 5 0
    //In: 5 | Out: 4 0
    //In: 4 | Out: 3 0
    //In: 3 | Out: 2 0
    //In: 2 | Out: 1 0
    //In: 1 | Out: 6 7
    //In: 6 | Out: 6 0
    
    InputData data;
    
    data.AddNode(0, 9); data.AddNode(6, 1); data.AddNode(0, 6);
    data.AddNode(0, 3); data.AddNode(0, 2); data.AddNode(11, 5);
    data.AddNode(10, 11); data.AddNode(11, 9); data.AddNode(10, 9);
    data.AddNode(8, 9); data.AddNode(5, 9); data.AddNode(4, 5);
    data.AddNode(0, 4); data.AddNode(0, 1); data.AddNode(3, 4);
    data.AddNode(8, 10); data.AddNode(0, 5); data.AddNode(1, 2);
    data.AddNode(6, 7); data.AddNode(2, 3);
    
    data.AddExit(0);
    data.AddExit(7);
    
    return data;
}

