/*
*
* IntHexaDecimal.cpp
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

#include "IntHexaDecimal.h"

void IntHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType IntHexaDecimal::GetType()
{
    return myType;
}

void IntHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int IntHexaDecimal::GetSize()
{
    return mySize;
}

void IntHexaDecimal::SetHexa(vector<HexaByte *> * arg)
{
    hexaValue = arg;
}

vector<HexaByte *> * IntHexaDecimal::GetHexa()
{
    return hexaValue;
}

void IntHexaDecimal::SetValue(int arg)
{
    hexaValue = new vector<HexaByte *>();
    myValue = arg;
}

int IntHexaDecimal::GetValue()
{
    return myValue;
}

int IntHexaDecimal::GetNumericValue()
{
    return myValue;
}

string IntHexaDecimal::GetRawValue()
{
    string retVal;
    retVal.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        retVal.append(hexaValue->at(i)->GetRawStr());
    }
    return retVal;
}

void IntHexaDecimal::HexaToValue()
{
    myValue = 0;

    int iLoopCount = (int)hexaValue->size();
    for (int i = iLoopCount; i > 0; i--) {
        int radix = 1;
        int jLoopCount = (int)hexaValue->size() - i;
        for (int j = 0; j < jLoopCount; j++) {
            radix *= 256;
        }
        myValue += hexaValue->at(i - 1)->GetValue() * radix;
    }
}

void IntHexaDecimal::ValueToHexa()
{
    DisposeHexaValue();

    uint8_t mod = 0;
    int parseValue = myValue;
    while (parseValue != 0) {
        mod = parseValue % 256;
        HexaByte * h = new HexaByte(mod);
        hexaValue->push_back(h);

        parseValue = parseValue / 256;
    }

    int iLoopCount = mySize - (int)hexaValue->size();
    for (int i = 0; i < iLoopCount; i++) {
        char add[3] = { '0', '0', '\0' };
        HexaByte * h = new HexaByte(add);
        hexaValue->push_back(h);
    }
    reverse(begin(*hexaValue), end(*hexaValue));
}

IntHexaDecimal::IntHexaDecimal()
{
    hexaValue = nullptr;
}

void IntHexaDecimal::DisposeHexaValue()
{
    if (hexaValue == nullptr) {
        return;
    }
    for (size_t i = 0; i < hexaValue->size(); i++) {
        delete hexaValue->at(i);
    }
    hexaValue->clear();
}

IntHexaDecimal::~IntHexaDecimal()
{
    DisposeHexaValue();
    delete hexaValue;
}