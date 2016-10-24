#pragma once

#include "stdafx.h"

#include "IHexaDecimal.h"

class LongDateBCDHexaDecimal : public IHexaDecimal
{
private:

    ValueType myType;

    int mySize;

    vector<HexaByte *> * hexaValue;

    int yyyy;

    string YYYYtoString();

    int mm;

    string MMtoString();

    int dd;

    string DDtoString();

    int hh24;

    string HH24toString();

    int mi;

    string MItoString();

    int ss;

    string SStoString();

public:

    void SetType(ValueType arg);

    ValueType GetType();

    void SetSize(int arg);

    int GetSize();

    void SetHexa(vector<HexaByte *> * arg);

    vector<HexaByte *> * GetHexa();

    void SetValue(int arg1yyyy, int arg2mm, int arg3dd, int hh24, int mi, int ss);

    string GetBCDStr();

    int GetNumericValue();

    string GetRawValue();

    void HexaToValue();

    void ValueToHexa();

    LongDateBCDHexaDecimal();

    void DisposeHexaValue();

    ~LongDateBCDHexaDecimal();
};
