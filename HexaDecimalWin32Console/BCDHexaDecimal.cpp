#include "stdafx.h"

#include "BCDHexaDecimal.h"

void BCDHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType BCDHexaDecimal::GetType()
{
    return myType;
}

void BCDHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int BCDHexaDecimal::GetSize()
{
    return mySize;
}

void BCDHexaDecimal::SetHexa(vector<HexaByte> * arg)
{
    hexaValue = arg;
}

vector<HexaByte> * BCDHexaDecimal::GetHexa()
{
    return hexaValue;
}

void BCDHexaDecimal::SetValue(int arg)
{
    myValue = arg;
}

int BCDHexaDecimal::GetValue()
{
    return myValue;
}

void BCDHexaDecimal::HexaToValue()
{
    string parseValue;
    for (size_t i = 0; i < hexaValue->size(); i++) {
        parseValue.append(hexaValue->at(i).GetBCDStr());
    }
    myValue = stoi(parseValue);
}

void BCDHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    string parseValue = to_string(myValue);
    if (parseValue.length() % 2 != 0) {
        parseValue.insert(0, "0");
    }
    if (((int)parseValue.length() / 2) < mySize) {
        for (int i = 0; i < mySize - (int)parseValue.length() / 2; i++) {
            char addChar[3] = { '0', '0', '\0' };
            HexaByte * h = new HexaByte(addChar);
            hexaValue->push_back(*h);
        }
    }
    for (size_t i = 0; i < parseValue.length() / 2; i++) {
        string oneChar = parseValue.substr(i * 2, i * 2 + 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(*h);
    }
}

BCDHexaDecimal::BCDHexaDecimal()
{
    hexaValue = new vector<HexaByte>();
}

BCDHexaDecimal::~BCDHexaDecimal()
{
    delete hexaValue;
}