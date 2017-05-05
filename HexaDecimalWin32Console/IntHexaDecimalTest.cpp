/*
*
* IntHexaDecimalTest.cpp
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

#include "IntHexaDecimalTest.h"

bool IntHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void IntHexaDecimalTest::IntHexaDecimalTest01()
{
    testSuccess = false;

    int testValue = 65535;
    IntHexaDecimal * h = new IntHexaDecimal();
    h->SetValue(testValue);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0xFF;
    uint8_t test02 = (uint8_t)0xFF;

    testSuccess = true;
    if (h->GetHexa()->at(0)->GetValue() != test01) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(1)->GetValue() != test02) {
        testSuccess = false;
    }

    delete h;
}

void IntHexaDecimalTest::IntHexaDecimalTest02()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(255);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(255);
    vector<HexaByte *> * testValue = new vector<HexaByte *>();
    testValue->push_back(h1);
    testValue->push_back(h2);
    IntHexaDecimal * h = new IntHexaDecimal();
    h->SetHexa(testValue);
    h->HexaToValue();

    int test = 65535;
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
}

void IntHexaDecimalTest::IntHexaDecimalTest03()
{
    testSuccess = false;

    int testValue = 65535;
    int testSize = 4;
    IntHexaDecimal * h = new IntHexaDecimal();
    h->SetValue(testValue);
    h->SetSize(testSize);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x00;
    uint8_t test02 = (uint8_t)0x00;
    uint8_t test03 = (uint8_t)0xFF;
    uint8_t test04 = (uint8_t)0xFF;

    testSuccess = true;
    if (h->GetHexa()->at(0)->GetValue() != test01) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(1)->GetValue() != test02) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(2)->GetValue() != test03) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(3)->GetValue() != test04) {
        testSuccess = false;
    }

    delete h;
}

void IntHexaDecimalTest::IntHexaDecimalTest04()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(255);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(255);
    vector<HexaByte *> * testValue = new vector<HexaByte *>();
    testValue->push_back(h1);
    testValue->push_back(h2);
    int testSize = 4;
    IntHexaDecimal * h = new IntHexaDecimal();
    h->SetHexa(testValue);
    h->SetSize(testSize);
    h->HexaToValue();

    int test = 65535;
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
}

IntHexaDecimalTest::IntHexaDecimalTest()
{
}

IntHexaDecimalTest::~IntHexaDecimalTest()
{
}