#include "stdafx.h"

#include "DateBCDHexaDecimal.h"

void DateBCDHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType DateBCDHexaDecimal::GetType()
{
    return myType;
}

void DateBCDHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int DateBCDHexaDecimal::GetSize()
{
    return mySize;
}

void DateBCDHexaDecimal::SetHexa(std::vector<HexaByte>* arg)
{
    hexaValue = arg;
}

std::vector<HexaByte>* DateBCDHexaDecimal::GetHexa()
{
    return hexaValue;
}

void DateBCDHexaDecimal::SetValue(int arg1yyyy, int arg2mm, int arg3dd)
{
    yyyy = arg1yyyy;
    mm = arg2mm;
    dd = arg3dd;
}

std::string * DateBCDHexaDecimal::GetBCDStr()
{
    std::string * retVal = new std::string();
    for (size_t i = 0; i < hexaValue->size(); i++) {
        retVal->append(*hexaValue->at(i).GetBCDStr());
    }
    return retVal;
}

void DateBCDHexaDecimal::HexaToValue()
{
    int startAt = hexaValue->size() - 4;
    yyyy = std::stoi(hexaValue->at(startAt).GetBCDStr()->append(*hexaValue->at(startAt + 1).GetBCDStr()));
    mm = std::stoi(*hexaValue->at(startAt + 2).GetBCDStr());
    dd = std::stoi(*hexaValue->at(startAt + 3).GetBCDStr());
}

void DateBCDHexaDecimal::ValueToHexa()
{
    std::string * parseValue = new std::string();
    if (std::to_string(yyyy).length() % 2 == 0) {
        parseValue->append(std::to_string(yyyy));
    }
    else {
        parseValue->append("0");
        parseValue->append(std::to_string(yyyy));
    }
    if (std::to_string(mm).length() == 2) {
        parseValue->append(std::to_string(mm));
    }
    else {
        parseValue->append("0");
        parseValue->append(std::to_string(mm));
    }
    if (std::to_string(dd).length() == 2) {
        parseValue->append(std::to_string(dd));
    }
    else {
        parseValue->append("0");
        parseValue->append(std::to_string(dd));
    }
    for (size_t i = 0; i < parseValue->length() / 2; i++) {
        std::string oneChar = parseValue->substr(i * 2, i * 2 + 2);
        char addChar[3] = { oneChar[0], oneChar[1], '\0' };
        HexaByte * h = new HexaByte(addChar);
        hexaValue->push_back(*h);
    }
}

DateBCDHexaDecimal::DateBCDHexaDecimal()
{
    hexaValue = new std::vector<HexaByte>();
}

DateBCDHexaDecimal::~DateBCDHexaDecimal()
{
    delete hexaValue;
}