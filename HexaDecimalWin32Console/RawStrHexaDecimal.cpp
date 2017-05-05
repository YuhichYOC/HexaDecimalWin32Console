/*
*
* RawStrHexaDecimal.cpp
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

#include "RawStrHexaDecimal.h"

void RawStrHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType RawStrHexaDecimal::GetType()
{
    return myType;
}

void RawStrHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int RawStrHexaDecimal::GetSize()
{
    return mySize;
}

void RawStrHexaDecimal::SetHexa(vector<HexaByte *> * arg)
{
    hexaValue = arg;
}

vector<HexaByte *> * RawStrHexaDecimal::GetHexa()
{
    return hexaValue;
}

void RawStrHexaDecimal::SetValue(string arg)
{
    hexaValue = new vector<HexaByte *>();
    if (arg.substr(0, 2) == "0x") {
        myValue.assign(arg);
    }
    else {
        myValue.assign("0x");
        myValue.append(arg);
    }
}

string RawStrHexaDecimal::GetValue()
{
    myValue.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        myValue.append(hexaValue->at(i)->GetRawStr());
    }
    return myValue;
}

int RawStrHexaDecimal::GetNumericValue()
{
    int retVal = 0;
    int iLoopCount = (int)hexaValue->size();
    for (int i = iLoopCount; i > 0; i--) {
        int radix = 1;
        int jLoopCount = (int)hexaValue->size() - i;
        for (int j = 0; j < jLoopCount; j++) {
            radix *= 256;
        }
        retVal += hexaValue->at(i - 1)->GetValue() * radix;
    }
    return retVal;
}

string RawStrHexaDecimal::GetRawValue()
{
    myValue.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        myValue.append(hexaValue->at(i)->GetRawStr());
    }
    return myValue;
}

void RawStrHexaDecimal::HexaToValue()
{
    myValue.assign("0x");

    int loopCount = (int)hexaValue->size();
    if (mySize > 0 && mySize < loopCount) {
        loopCount = mySize;
    }

    for (int i = 0; i < loopCount; i++) {
        if (i < loopCount) {
            myValue.append(hexaValue->at(i)->GetRawStr());
        }
        else {
            myValue.append("00");
        }
    }
}

void RawStrHexaDecimal::ValueToHexa()
{
    DisposeHexaValue();

    string parseValue = myValue;
    if (parseValue.substr(0, 2) == "0x") {
        parseValue.assign(parseValue.substr(2, parseValue.length() - 2));
    }
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }

    int iLoopCount = (int)parseValue.length() / 2;
    for (int i = 0; i < iLoopCount; i++) {
        string oneChar = parseValue.substr(i * 2, 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(h);
    }
    int jLoopCount = mySize - (int)hexaValue->size();
    if (mySize > 0 && 0 < jLoopCount) {
        for (int j = 0; j < jLoopCount; j++) {
            char addChar[3] = { '0', '0', '\0' };
            HexaByte * h = new HexaByte(addChar);
            hexaValue->push_back(h);
        }
    }
}

RawStrHexaDecimal::RawStrHexaDecimal()
{
    mySize = -1;
    hexaValue = nullptr;
}

void RawStrHexaDecimal::DisposeHexaValue()
{
    if (hexaValue == nullptr) {
        return;
    }
    for (size_t i = 0; i < hexaValue->size(); i++) {
        delete hexaValue->at(i);
    }
    hexaValue->clear();
}

RawStrHexaDecimal::~RawStrHexaDecimal()
{
    DisposeHexaValue();
    delete hexaValue;
}