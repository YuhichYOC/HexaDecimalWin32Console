#pragma once

#include <afxtempl.h>
#include <vector>

enum ValueType
{
    HEX, NUM_INT, NUM_LONG, NUM_DECIMAL, BCD, BCD_LONG, BCD_DATE, BCD_DATE_LONG, RAW_STR, STR
};

class TestBaseHexaDecimal
{
private:
    ValueType myType;
    int mySize;
    std::vector<byte> * hexaValue;
public:
    void SetType(ValueType arg);
    ValueType GetType();
    void SetSize(int arg);
    int GetSize();
    void SetHexa(std::vector<byte> * arg);
    std::vector<byte> * GetHexa();
    TestBaseHexaDecimal();
    ~TestBaseHexaDecimal();
};
