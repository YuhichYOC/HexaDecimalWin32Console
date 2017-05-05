/*
*
* BCDHexaDecimal.cpp
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

#include "BCDHexaDecimal.h"

void BCDHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType BCDHexaDecimal::GetType()
{
    return myType;
}

void BCDHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int BCDHexaDecimal::GetSize()
{
    return mySize;
}

void BCDHexaDecimal::SetHexa(vector<HexaByte *> * arg)
{
    hexaValue = arg;
}

vector<HexaByte *> * BCDHexaDecimal::GetHexa()
{
    return hexaValue;
}

void BCDHexaDecimal::SetValue(int arg)
{
    hexaValue = new vector<HexaByte *>();
    myValue = arg;
}

int BCDHexaDecimal::GetValue()
{
    return myValue;
}

int BCDHexaDecimal::GetNumericValue()
{
    return myValue;
}

string BCDHexaDecimal::GetRawValue()
{
    string retVal;
    retVal.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        retVal.append(hexaValue->at(i)->GetBCDStr());
    }
    return retVal;
}

void BCDHexaDecimal::HexaToValue()
{
    string parseValue;
    for (size_t i = 0; i < hexaValue->size(); i++) {
        parseValue.append(hexaValue->at(i)->GetBCDStr());
    }
    myValue = stoi(parseValue);
}

void BCDHexaDecimal::ValueToHexa()
{
    DisposeHexaValue();

    string parseValue = to_string(myValue);
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }
    if (((int)parseValue.length() / 2) < mySize) {
        for (int i = 0; i < mySize - (int)parseValue.length() / 2; i++) {
            char addChar[3] = { '0', '0', '\0' };
            HexaByte * h = new HexaByte(addChar);
            hexaValue->push_back(h);
        }
    }
    for (size_t i = 0; i < parseValue.length() / 2; i++) {
        string oneChar = parseValue.substr(i * 2, i * 2 + 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(h);
    }
}

BCDHexaDecimal::BCDHexaDecimal()
{
    hexaValue = nullptr;
}

void BCDHexaDecimal::DisposeHexaValue()
{
    if (hexaValue == nullptr) {
        return;
    }
    for (size_t i = 0; i < hexaValue->size(); i++) {
        delete hexaValue->at(i);
    }
    hexaValue->clear();
}

BCDHexaDecimal::~BCDHexaDecimal()
{
    DisposeHexaValue();
    delete hexaValue;
}