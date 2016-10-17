#pragma once

#include "stdafx.h"

#include "HexaByte.h"

class DateBCDHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte> * hexaValue;

    int yyyy;

    string YYYYtoString();

    int mm;

    string MMtoString();

    int dd;

    string DDtoString();

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte> * arg);

    vector<HexaByte> * GetHexa();

    void SetValue(int arg1yyyy, int arg2mm, int arg3dd);

    string GetBCDStr();

    void HexaToValue();

    void ValueToHexa();

    DateBCDHexaDecimal();

    ~DateBCDHexaDecimal();
};