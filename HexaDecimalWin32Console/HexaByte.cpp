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
}

uint8_t HexaByte::GetValue()
{
    return myValue;
}

void HexaByte::SetHexa(char arg[2])
{
    hexaValue[0] = arg[0];
    hexaValue[1] = arg[1];
}

char * HexaByte::GetHexa()
{
    return hexaValue;
}

std::string * HexaByte::GetRawStr()
{
    std::string * retVal = new std::string();
    for (int i = 0; i < 2; i++) {
        retVal->push_back(hexaValue[i]);
    }
    return retVal;
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
}

HexaByte::HexaByte(char arg[2])
{
    hexaValue[0] = arg[0];
    hexaValue[1] = arg[1];

    char upperValue = FindPositionInReplaceArray(arg[0]);
    char lowerValue = FindPositionInReplaceArray(arg[1]);

    myValue = upperValue * 16 + lowerValue;
}

HexaByte::~HexaByte()
{
}