#include "stdafx.h"

#include "HexaByte.h"

int HexaByte::FindPositionInReplaceArray(char arg)
{
    int retVal = 0;
    for (int i = 0; i < 17; i++) {
        if (replaceArray[i] == arg) {
            retVal = i;
        }
    }
    return retVal;
}

void HexaByte::SetValue(uint8_t arg)
{
    myValue = arg;

    char upperValue = myValue / 16;
    char lowerValue = myValue % 16;

    char upper = replaceArray[upperValue];
    char lower = replaceArray[lowerValue];

    hexaValue[0] = upper;
    hexaValue[1] = lower;
    hexaValue[2] = char('\0');
}

uint8_t HexaByte::GetValue()
{
    return myValue;
}

void HexaByte::SetHexa(char arg[2])
{
    hexaValue[0] = arg[0];
    hexaValue[1] = arg[1];
    hexaValue[2] = char('\0');

    char upperValue = FindPositionInReplaceArray(arg[0]);
    char lowerValue = FindPositionInReplaceArray(arg[1]);

    myValue = upperValue * 16 + lowerValue;
}

char * HexaByte::GetHexa()
{
    return hexaValue;
}

string HexaByte::GetRawStr()
{
    string ret;
    for (int i = 0; i < 2; i++) {
        ret.push_back(hexaValue[i]);
    }
    return ret;
}

string HexaByte::GetBCDStr()
{
    string ret;
    ret.assign(to_string(myValue));
    if (ret.length() == 1) {
        ret.insert(0, "0");
    }
    return ret;
}

HexaByte::HexaByte()
{
}

HexaByte::HexaByte(uint8_t arg)
{
    myValue = arg;

    char upperValue = myValue / 16;
    char lowerValue = myValue % 16;

    char upper = replaceArray[upperValue];
    char lower = replaceArray[lowerValue];

    hexaValue[0] = upper;
    hexaValue[1] = lower;
    hexaValue[2] = char('\0');
}

HexaByte::HexaByte(char arg[2])
{
    hexaValue[0] = arg[0];
    hexaValue[1] = arg[1];
    hexaValue[2] = char('\0');

    char upperValue = FindPositionInReplaceArray(arg[0]);
    char lowerValue = FindPositionInReplaceArray(arg[1]);

    myValue = upperValue * 16 + lowerValue;
}

HexaByte::~HexaByte()
{
}