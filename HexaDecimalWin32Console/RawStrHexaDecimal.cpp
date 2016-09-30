#include "stdafx.h"

#include "RawStrHexaDecimal.h"

void RawStrHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType RawStrHexaDecimal::GetType()
{
    return myType;
}

void RawStrHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int RawStrHexaDecimal::GetSize()
{
    return mySize;
}

void RawStrHexaDecimal::SetHexa(std::vector<HexaByte> * arg)
{
    hexaValue = arg;
}

std::vector<HexaByte> * RawStrHexaDecimal::GetHexa()
{
    return hexaValue;
}

void RawStrHexaDecimal::SetValue(std::string * arg)
{
    myValue = arg;
}

std::string * RawStrHexaDecimal::GetValue()
{
    return myValue;
}

void RawStrHexaDecimal::HexaToValue()
{
    myValue->assign("0x");
    for (size_t i = 0; i < hexaValue->size(); i++) {
        myValue->push_back(hexaValue->at(i).GetRawStr()->at(0));
        myValue->push_back(hexaValue->at(i).GetRawStr()->at(1));
    }
}

void RawStrHexaDecimal::ValueToHexa()
{
    std::string parseValue = *myValue;
    if (parseValue.substr(0, 2) == "0x") {
        parseValue.assign(parseValue.substr(2, parseValue.length() - 2));
    }
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }
    for (size_t i = 0; i < parseValue.length() / 2; i++) {
        std::string oneChar = parseValue.substr(i * 2, i * 2 + 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(*h);
    }
}

RawStrHexaDecimal::RawStrHexaDecimal()
{
    hexaValue = new std::vector<HexaByte>();
    myValue = new std::string();
}

RawStrHexaDecimal::~RawStrHexaDecimal()
{
    delete hexaValue;
    delete myValue;
}