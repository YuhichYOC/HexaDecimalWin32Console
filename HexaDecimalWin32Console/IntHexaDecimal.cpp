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
    for (size_t i = 0; i < hexaValue->size(); i++)
    {
        int radix = 1;
        for (uint16_t j = 0; j < hexaValue->size() - (i + 1); j++)
        {
            radix *= 256;
        }
        myValue += hexaValue->at(i).GetValue() * radix;
    }
}

void IntHexaDecimal::ValueToHexa()
{
    uint8_t mod = 0;
    int parseValue = myValue;
    while (parseValue != 0)
    {
        mod = parseValue % 256;
        parseValue = (parseValue - mod) / 256;

        HexaByte * h = new HexaByte(mod);
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