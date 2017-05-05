/*
*
* LongDateBCDHexaDecimal.cpp
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

#include "LongDateBCDHexaDecimal.h"

void LongDateBCDHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType LongDateBCDHexaDecimal::GetType()
{
    return myType;
}

void LongDateBCDHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int LongDateBCDHexaDecimal::GetSize()
{
    return mySize;
}

void LongDateBCDHexaDecimal::SetHexa(vector<HexaByte *> * arg)
{
    hexaValue = arg;
}

vector<HexaByte *> * LongDateBCDHexaDecimal::GetHexa()
{
    return hexaValue;
}

void LongDateBCDHexaDecimal::SetValue(int arg1yyyy, int arg2mm, int arg3dd, int arg4hh24, int arg5mi, int arg6ss)
{
    hexaValue = new vector<HexaByte *>();
    yyyy = arg1yyyy;
    mm = arg2mm;
    dd = arg3dd;
    hh24 = arg4hh24;
    mi = arg5mi;
    ss = arg6ss;
}

string LongDateBCDHexaDecimal::YYYYtoString()
{
    string ret;
    if (yyyy / 1000 >= 1) {
        ret.append(to_string(yyyy));
    }
    else if (yyyy / 100 >= 1) {
        ret.append("0").append(to_string(yyyy));
    }
    else if (yyyy / 10 >= 1) {
        ret.append("00").append(to_string(yyyy));
    }
    else {
        ret.append("000").append(to_string(yyyy));
    }
    return ret;
}

string LongDateBCDHexaDecimal::MMtoString()
{
    string ret;
    if (mm / 10 >= 1) {
        ret.append(to_string(mm));
    }
    else {
        ret.append("0").append(to_string(mm));
    }
    return ret;
}

string LongDateBCDHexaDecimal::DDtoString()
{
    string ret;
    if (dd / 10 >= 1) {
        ret.append(to_string(dd));
    }
    else {
        ret.append("0").append(to_string(dd));
    }
    return ret;
}

string LongDateBCDHexaDecimal::HH24toString()
{
    string ret;
    if (hh24 / 10 >= 1) {
        ret.append(to_string(hh24));
    }
    else {
        ret.append("0").append(to_string(hh24));
    }
    return ret;
}

string LongDateBCDHexaDecimal::MItoString()
{
    string ret;
    if (mi / 10 >= 1) {
        ret.append(to_string(mi));
    }
    else {
        ret.append("0").append(to_string(mi));
    }
    return ret;
}

string LongDateBCDHexaDecimal::SStoString()
{
    string ret;
    if (ss / 10 >= 1) {
        ret.append(to_string(ss));
    }
    else {
        ret.append("0").append(to_string(ss));
    }
    return ret;
}

string LongDateBCDHexaDecimal::GetBCDStr()
{
    string ret;
    for (size_t i = 0; i < hexaValue->size(); i++) {
        ret.append(hexaValue->at(i)->GetRawStr());
    }
    return ret;
}

int LongDateBCDHexaDecimal::GetNumericValue()
{
    return yyyy * 10000 * 1000000 + mm * 100 * 1000000 + dd * 1 * 1000000 + hh24 * 10000 + mi * 100 + ss;
}

string LongDateBCDHexaDecimal::GetRawValue()
{
    string retVal;
    retVal.assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        retVal.append(hexaValue->at(i)->GetBCDStr());
    }
    return retVal;
}

void LongDateBCDHexaDecimal::HexaToValue()
{
    size_t startAt = hexaValue->size() - 7;
    yyyy = stoi(hexaValue->at(startAt)->GetBCDStr().append(hexaValue->at(startAt + 1)->GetBCDStr()));
    mm = stoi(hexaValue->at(startAt + 2)->GetBCDStr());
    dd = stoi(hexaValue->at(startAt + 3)->GetBCDStr());
    hh24 = stoi(hexaValue->at(startAt + 4)->GetBCDStr());
    mi = stoi(hexaValue->at(startAt + 5)->GetBCDStr());
    ss = stoi(hexaValue->at(startAt + 6)->GetBCDStr());
}

void LongDateBCDHexaDecimal::ValueToHexa()
{
    DisposeHexaValue();

    string parseValue;
    parseValue.append(YYYYtoString());
    parseValue.append(MMtoString());
    parseValue.append(DDtoString());
    parseValue.append(HH24toString());
    parseValue.append(MItoString());
    parseValue.append(SStoString());
    if (mySize > 7) {
        for (int i = 0; i < mySize - 4; i++) {
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

LongDateBCDHexaDecimal::LongDateBCDHexaDecimal()
{
    hexaValue = nullptr;
}

void LongDateBCDHexaDecimal::DisposeHexaValue()
{
    if (hexaValue == nullptr) {
        return;
    }
    for (size_t i = 0; i < hexaValue->size(); i++) {
        delete hexaValue->at(i);
    }
    hexaValue->clear();
}

LongDateBCDHexaDecimal::~LongDateBCDHexaDecimal()
{
    DisposeHexaValue();
    delete hexaValue;
}