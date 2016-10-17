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

void RawStrHexaDecimal::SetHexa(vector<HexaByte> * arg)
{
    hexaValue = arg;
}

vector<HexaByte> * RawStrHexaDecimal::GetHexa()
{
    return hexaValue;
}

void RawStrHexaDecimal::SetValue(string arg)
{
    if (arg.substr(0, 2) == "0x") {
        myValue.assign(arg);
    }
    else {
        myValue.assign("0x");
        myValue.append(arg);
    }
}

string RawStrHexaDecimal::GetValue()
{
    return myValue;
}

void RawStrHexaDecimal::HexaToValue()
{
    myValue.assign("0x");

    int loopCount = (int)hexaValue->size();
    if (mySize > 0 && mySize < loopCount) {
        loopCount = mySize;
    }

    for (int i = 0; i < loopCount; i++) {
        if (i < loopCount) {
            myValue.append(hexaValue->at(i).GetRawStr());
        }
        else {
            myValue.append("\0\0");
        }
    }
}

void RawStrHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    string parseValue = myValue;
    if (parseValue.substr(0, 2) == "0x") {
        parseValue.assign(parseValue.substr(2, parseValue.length() - 2));
    }
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }

    int iLoopCount = (int)parseValue.length() / 2;
    for (int i = 0; i < iLoopCount; i++) {
        string oneChar = parseValue.substr(i * 2, i * 2 + 2);
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
    hexaValue = new vector<HexaByte>();
}

RawStrHexaDecimal::~RawStrHexaDecimal()
{
    delete hexaValue;
}