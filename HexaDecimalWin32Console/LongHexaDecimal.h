#pragma once

#include "stdafx.h"

#include "IHexaDecimal.h"

class LongHexaDecimal : public IHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte *> * hexaValue;

    long myValue;

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte *> * arg);

    vector<HexaByte *> * GetHexa();

    void SetValue(long arg);

    long GetValue();

    int GetNumericValue();

    string GetRawValue();

    void HexaToValue();

    void ValueToHexa();

    LongHexaDecimal();

    void DisposeHexaValue();

    ~LongHexaDecimal();
};
