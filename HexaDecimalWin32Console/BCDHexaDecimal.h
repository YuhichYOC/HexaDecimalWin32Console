#pragma once

#include "stdafx.h"

#include "HexaByte.h"

class BCDHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte> * hexaValue;

    int myValue;

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte> * arg);

    vector<HexaByte> * GetHexa();

    void SetValue(int arg);

    int GetValue();

    void HexaToValue();

    void ValueToHexa();

    BCDHexaDecimal();

    ~BCDHexaDecimal();
};