#pragma once

#include "stdafx.h"

#include "IHexaDecimal.h"

class RawStrHexaDecimal : public IHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte *> * hexaValue;

    string myValue;

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte *> * arg);

    vector<HexaByte *> * GetHexa();

    void SetValue(string arg);

    string GetValue();

    int GetNumericValue();

    string GetRawValue();

    void HexaToValue();

    void ValueToHexa();

    RawStrHexaDecimal();

    void DisposeHexaValue();

    ~RawStrHexaDecimal();
};