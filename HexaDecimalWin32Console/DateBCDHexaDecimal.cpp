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

std::string * DateBCDHexaDecimal::YYYYtoString()
{
    std::string * retVal = new std::string();
    if (yyyy / 1000 >= 1) {
        retVal->append(std::to_string(yyyy));
    }
    else if (yyyy / 100 >= 1) {
        retVal->append("0").append(std::to_string(yyyy));
    }
    else if (yyyy / 10 >= 1) {
        retVal->append("00").append(std::to_string(yyyy));
    }
    else {
        retVal->append("000").append(std::to_string(yyyy));
    }
    return retVal;
}

std::string * DateBCDHexaDecimal::MMtoString()
{
    std::string * retVal = new std::string();
    if (mm / 10 >= 1) {
        retVal->append(std::to_string(mm));
    }
    else {
        retVal->append("0").append(std::to_string(mm));
    }
    return retVal;
}

std::string * DateBCDHexaDecimal::DDtoString()
{
    std::string * retVal = new std::string();
    if (dd / 10 >= 1) {
        retVal->append(std::to_string(dd));
    }
    else {
        retVal->append("0").append(std::to_string(dd));
    }
    return retVal;
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
    parseValue->append(*YYYYtoString());
    parseValue->append(*MMtoString());
    parseValue->append(*DDtoString());
    if (mySize > 4) {
        for (int i = 0; i < mySize - 4; i++) {
            char addChar[3] = { '0', '0', '\0' };
            HexaByte * h = new HexaByte(addChar);
            hexaValue->push_back(*h);
        }
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