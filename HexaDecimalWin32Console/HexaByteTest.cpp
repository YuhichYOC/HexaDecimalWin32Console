/*
*
* HexaByteTest.cpp
*
* Copyright 2016 Yuichi Yoshii
*     ‹gˆä—Yˆê @ ‹gˆäŽY‹Æ  you.65535.kir@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#include "stdafx.h"

#include "HexaByteTest.h"

bool HexaByteTest::GetTestSuccess()
{
    return testSuccess;
}

void HexaByteTest::HexaByteTest01()
{
    testSuccess = false;

    char testValue = 123;
    HexaByte * h = new HexaByte();
    h->SetValue(testValue);

    string test("7B");

    /*
    if ((h->GetRawStr() == test) == 0) {
        testSuccess = true;
    }
    */
    if (h->GetRawStr() == test) {
        testSuccess = true;
    }

    delete h;
}

void HexaByteTest::HexaByteTest02()
{
    testSuccess = false;

    char testValue[3] = "7B";
    HexaByte * h = new HexaByte();
    h->SetHexa(testValue);

    char test = 123;

    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
}

void HexaByteTest::HexaByteTest03()
{
    testSuccess = false;

    char testValue = 20;
    HexaByte * h = new HexaByte();
    h->SetValue(testValue);

    string test("20");

    /*
    if ((h->GetBCDStr() == test) == 0) {
        testSuccess = true;
    }
    */
    if (h->GetBCDStr() == test) {
        testSuccess = true;
    }

    delete h;
}

HexaByteTest::HexaByteTest()
{
}

HexaByteTest::~HexaByteTest()
{
}