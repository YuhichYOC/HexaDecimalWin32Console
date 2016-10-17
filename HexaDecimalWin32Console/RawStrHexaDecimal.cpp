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

    int loopCount = (int)hexaValue->size();
    if (mySize > 0 && mySize < loopCount) {
        loopCount = mySize;
    }

    for (int i = 0; i < loopCount; i++) {
        if (i < loopCount) {
            myValue->push_back(hexaValue->at(i).GetRawStr()->at(0));
            myValue->push_back(hexaValue->at(i).GetRawStr()->at(1));
        }
        else {
            myValue->push_back('\0');
            myValue->push_back('\0');
        }
    }
}

void RawStrHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    std::string parseValue = *myValue;
    if (parseValue.substr(0, 2) == "0x") {
        parseValue.assign(parseValue.substr(2, parseValue.length() - 2));
    }
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }

    int iLoopCount = (int)parseValue.length() / 2;
    for (int i = 0; i < iLoopCount; i++) {
        std::string oneChar = parseValue.substr(i * 2, i * 2 + 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(*h);
    }
    int jLoopCount = mySize - (int)hexaValue->size();
    if (mySize > 0 && 0 < jLoopCount) {
        for (int j = 0; j < jLoopCount; j++) {
            char addChar[3] = { '0', '0', '\0' };
            HexaByte * h = new HexaByte(addChar);
            hexaValue->push_back(*h);
        }
    }
}

RawStrHexaDecimal::RawStrHexaDecimal()
{
    mySize = -1;
    hexaValue = new std::vector<HexaByte>();
    myValue = new std::string();
}

RawStrHexaDecimal::~RawStrHexaDecimal()
{
    delete hexaValue;
    delete myValue;
}