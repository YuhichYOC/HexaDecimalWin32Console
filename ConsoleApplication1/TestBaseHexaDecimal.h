#pragma once

#include <afxtempl.h>

enum ValueType
{
    HEX, NUM_INT, NUM_LONG, NUM_DECIMAL, BCD, BCD_LONG, BCD_DATE, BCD_DATE_LONG, RAW_STR, STR
};

class TestBaseHexaDecimal
{
private:
    ValueType myType;
    int mySize;
    CList<byte> * hexaValue;
public:
    void SetType(ValueType arg);
    ValueType GetType();
    void SetSize(int arg);
    int GetSize();
    void SetHexa(CList<byte> * arg);
    CList<byte> * GetHexa();
    TestBaseHexaDecimal();
    ~TestBaseHexaDecimal();
};
