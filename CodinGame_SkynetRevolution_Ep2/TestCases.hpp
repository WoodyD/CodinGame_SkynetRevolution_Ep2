//
//  TestCases.hpp
//  CodinGame_SkynetRevolution_Ep2
//
//  Created by Woody on 23/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#pragma once

#include <iostream>

#include "InputData.hpp"

class TestCases{
public:
    TestCases();
    static InputData TestCase(int caseNumber);
private:
    static InputData Case0;
    static InputData Case1;
    
    InputData CreateTestCase0();
    InputData CreateTestCase1();
};
