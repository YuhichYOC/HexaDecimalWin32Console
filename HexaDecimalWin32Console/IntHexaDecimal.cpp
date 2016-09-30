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

void IntHexaDecimal::SetHexa(std::vector<HexaByte> * arg)
{
    hexaValue = arg;
}

std::vector<HexaByte>* IntHexaDecimal::GetHexa()
{
    return hexaValue;
}

void IntHexaDecimal::SetValue(int arg)
{
    myValue = arg;
}

int IntHexaDecimal::GetValue()
{
    return myValue;
}

void IntHexaDecimal::HexaToValue()
{
    myValue = 0;
    int loopCount = (int)hexaValue->size();
    for (int i = 0; i < loopCount; i++) {
        int radix = 1;
        for (int j = 0; j < i; j++) {
            radix *= 256;
        }
        myValue += hexaValue->at(loopCount - (i + 1)).GetValue() * radix;
    }
}

void IntHexaDecimal::ValueToHexa()
{
    int mod = 0;
    int parseValue = myValue;
    while (parseValue != 0) {
        mod = parseValue % 256;
        parseValue = (parseValue - mod) / 256;
        HexaByte * h = new HexaByte(mod);
        hexaValue->push_back(*h);
    }
    if (mySize > 0 && (size_t)mySize > hexaValue->size()) {
        int loopCount = mySize - (int)hexaValue->size();
        for (int i = 0; i < loopCount; i++) {
            HexaByte * h = new HexaByte((uint8_t)0);
            hexaValue->push_back(*h);
        }
    }
    std::reverse(std::begin(*hexaValue), std::end(*hexaValue));
}

IntHexaDecimal::IntHexaDecimal()
{
    mySize = -1;
    hexaValue = new std::vector<HexaByte>();
}

IntHexaDecimal::~IntHexaDecimal()
{
    delete hexaValue;
}