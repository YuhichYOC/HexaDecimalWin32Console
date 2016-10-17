#pragma once

#include "stdafx.h"

#include "HexaByte.h"

class RawStrHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte> * hexaValue;

    string myValue;

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte> * arg);

    vector<HexaByte> * GetHexa();

    void SetValue(string arg);

    string GetValue();

    void HexaToValue();

    void ValueToHexa();

    RawStrHexaDecimal();

    ~RawStrHexaDecimal();
};