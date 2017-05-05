/*
*
* LongDateBCDHexaDecimal.h
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

#pragma once

#include "stdafx.h"

#include "IHexaDecimal.h"

class LongDateBCDHexaDecimal : public IHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte *> * hexaValue;

    int yyyy;

    string YYYYtoString();

    int mm;

    string MMtoString();

    int dd;

    string DDtoString();

    int hh24;

    string HH24toString();

    int mi;

    string MItoString();

    int ss;

    string SStoString();

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte *> * arg);

    vector<HexaByte *> * GetHexa();

    void SetValue(int arg1yyyy, int arg2mm, int arg3dd, int hh24, int mi, int ss);

    string GetBCDStr();

    int GetNumericValue();

    string GetRawValue();

    void HexaToValue();

    void ValueToHexa();

    LongDateBCDHexaDecimal();

    void DisposeHexaValue();

    ~LongDateBCDHexaDecimal();
};
