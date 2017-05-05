/*
*
* HexaByte.h
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

enum ValueType
{
    HEX, NUM_INT, NUM_LONG, NUM_DECIMAL, BCD, BCD_LONG, BCD_DATE, BCD_DATE_LONG, RAW_STR, STR
};

class HexaByte
{
private:

    uint8_t myValue;

    char hexaValue[3];

    char replaceArray[17] = "0123456789ABCDEF";

    int FindPositionInReplaceArray(char arg);

public:

    void SetValue(uint8_t arg);

    uint8_t GetValue();

    void SetHexa(char arg[2]);

    char * GetHexa();

    string GetRawStr();

    string GetBCDStr();

    HexaByte();

    HexaByte(uint8_t arg);

    HexaByte(char arg[2]);

    ~HexaByte();
};