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

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    InputData data = TestCases::TestCase(1);
    
    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        
        // Example: 3 4 are the indices of the nodes you wish to sever the link between
        cout << "3 4" << endl;
    }
}
