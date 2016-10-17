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

    char hexaValue[2];

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