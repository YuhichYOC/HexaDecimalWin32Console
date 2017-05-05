/*
*
* StrHexaDecimal.cpp
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

#include "StrHexaDecimal.h"

void StrHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType StrHexaDecimal::GetType()
{
    return myType;
}

void StrHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int StrHexaDecimal::GetSize()
{
    return mySize;
}

void StrHexaDecimal::SetHexa(vector<HexaByte *> * arg)
{
    hexaValue = arg;
}

vector<HexaByte *> * StrHexaDecimal::GetHexa()
{
    return hexaValue;
}

void StrHexaDecimal::SetValue(string arg)
{
    hexaValue = new vector<HexaByte *>();
    myValue = arg;
}

string StrHexaDecimal::GetValue()
{
    return myValue;
}

int StrHexaDecimal::GetNumericValue()
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

string StrHexaDecimal::GetRawValue()
{
    string ret;
    ret.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        ret.append(hexaValue->at(i)->GetRawStr());
    }
    return ret;
}

void StrHexaDecimal::HexaToValue()
{
    DisposeHexaValue();

    int loopCount = (int)hexaValue->size();
    if (mySize > 0 && mySize < loopCount) {
        loopCount = mySize;
    }

    for (int i = 0; i < loopCount; i++) {
        if (i < loopCount) {
            myValue.append(hexaValue->at(i)->GetHexa());
        }
    }
}

void StrHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    const char * parseValue = myValue.c_str() + char('\0');
    int loopCount = 0;
    while (parseValue[loopCount] != char('\0') && parseValue[loopCount + 1] != char('\0')) {
        char addChar[3] = { parseValue[loopCount], parseValue[loopCount + 1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(h);
        loopCount += 2;
    }
}

StrHexaDecimal::StrHexaDecimal()
{
    mySize = -1;
    hexaValue = nullptr;
}

void StrHexaDecimal::DisposeHexaValue()
{
    if (hexaValue == nullptr) {
        return;
    }
    for (size_t i = 0; i < hexaValue->size(); i++) {
        delete hexaValue->at(i);
    }
    hexaValue->clear();
}

StrHexaDecimal::~StrHexaDecimal()
{
    DisposeHexaValue();
    delete hexaValue;
}