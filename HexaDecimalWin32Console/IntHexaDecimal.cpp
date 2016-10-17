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

    int iLoopCount = (int)hexaValue->size();
    for (int i = iLoopCount; i > 0; i--) {
        int radix = 1;
        int jLoopCount = (int)hexaValue->size() - i;
        for (int j = 0; j < jLoopCount; j++) {
            radix *= 256;
        }
        myValue += hexaValue->at(i - 1).GetValue() * radix;
    }
}

void IntHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    uint8_t mod = 0;
    int parseValue = myValue;
    while (parseValue != 0) {
        mod = parseValue % 256;
        HexaByte * h = new HexaByte(mod);
        hexaValue->push_back(*h);

        parseValue = parseValue / 256;
    }

    int iLoopCount = mySize - (int)hexaValue->size();
    for (int i = 0; i < iLoopCount; i++) {
        char add[3] = { '0', '0', '\0' };
        HexaByte * h = new HexaByte(add);
        hexaValue->push_back(*h);
    }
    std::reverse(std::begin(*hexaValue), std::end(*hexaValue));
}

IntHexaDecimal::IntHexaDecimal()
{
    hexaValue = new std::vector<HexaByte>();
}

IntHexaDecimal::~IntHexaDecimal()
{
    delete hexaValue;
}