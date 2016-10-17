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

void DateBCDHexaDecimal::SetHexa(vector<HexaByte> * arg)
{
    hexaValue = arg;
}

vector<HexaByte>* DateBCDHexaDecimal::GetHexa()
{
    return hexaValue;
}

void DateBCDHexaDecimal::SetValue(int arg1yyyy, int arg2mm, int arg3dd)
{
    yyyy = arg1yyyy;
    mm = arg2mm;
    dd = arg3dd;
}

string DateBCDHexaDecimal::YYYYtoString()
{
    string ret;
    if (yyyy / 1000 >= 1) {
        ret.append(to_string(yyyy));
    }
    else if (yyyy / 100 >= 1) {
        ret.append("0").append(to_string(yyyy));
    }
    else if (yyyy / 10 >= 1) {
        ret.append("00").append(to_string(yyyy));
    }
    else {
        ret.append("000").append(to_string(yyyy));
    }
    return ret;
}

string DateBCDHexaDecimal::MMtoString()
{
    string ret;
    if (mm / 10 >= 1) {
        ret.append(to_string(mm));
    }
    else {
        ret.append("0").append(to_string(mm));
    }
    return ret;
}

string DateBCDHexaDecimal::DDtoString()
{
    string ret;
    if (dd / 10 >= 1) {
        ret.append(to_string(dd));
    }
    else {
        ret.append("0").append(to_string(dd));
    }
    return ret;
}

string DateBCDHexaDecimal::GetBCDStr()
{
    string ret;
    for (size_t i = 0; i < hexaValue->size(); i++) {
        ret.append(hexaValue->at(i).GetRawStr());
    }
    return ret;
}

void DateBCDHexaDecimal::HexaToValue()
{
    int startAt = hexaValue->size() - 4;
    yyyy = stoi(hexaValue->at(startAt).GetBCDStr().append(hexaValue->at(startAt + 1).GetBCDStr()));
    mm = stoi(hexaValue->at(startAt + 2).GetBCDStr());
    dd = stoi(hexaValue->at(startAt + 3).GetBCDStr());
}

void DateBCDHexaDecimal::ValueToHexa()
{
    hexaValue->clear();

    string parseValue;
    parseValue.append(YYYYtoString());
    parseValue.append(MMtoString());
    parseValue.append(DDtoString());
    if (mySize > 4) {
        for (int i = 0; i < mySize - 4; i++) {
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

DateBCDHexaDecimal::DateBCDHexaDecimal()
{
    hexaValue = new vector<HexaByte>();
}

DateBCDHexaDecimal::~DateBCDHexaDecimal()
{
    delete hexaValue;
}