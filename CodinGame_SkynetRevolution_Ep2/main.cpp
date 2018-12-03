//
//  main.cpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "InputData.hpp"
#include "TestCases.hpp"

using namespace std;

int main()
{
    TestCases test;
    InputData data = test.CreateTestCase2();
    
    // game loop
    while (1) {
        cerr << "Enter skynet's node: " << endl;
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        string nodeToRemove = data.GetNodeString(SI);
        
        cerr << "Remove: " << endl;
        cout << nodeToRemove << endl;

    }
}
