#include "stdafx.h"
#include "TestBaseHexaDecimal.h"

void TestBaseHexaDecimal::SetType(ValueType arg)
{
    myType = arg;
}

ValueType TestBaseHexaDecimal::GetType()
{
    return myType;
}

void TestBaseHexaDecimal::SetSize(int arg)
{
    mySize = arg;
}

int TestBaseHexaDecimal::GetSize()
{
    return mySize;
}

void TestBaseHexaDecimal::SetHexa(std::vector<byte> * arg)
{
    hexaValue = arg;
}

std::vector<byte> * TestBaseHexaDecimal::GetHexa()
{
    return hexaValue;
}

void TestBaseHexaDecimal::SetValue(std::string * arg)
{
    myValue = arg;
}

std::string * TestBaseHexaDecimal::GetValue()
{
    return myValue;
}

void TestBaseHexaDecimal::HexaToValue()
{

}

void TestBaseHexaDecimal::ValueToHexa()
{
    std::string starts = "0x";
    if (myValue->substr(0, 2) == starts)
    {
        myValue = &(myValue->substr(2, myValue->length));
    }
}

TestBaseHexaDecimal::TestBaseHexaDecimal()
{
    hexaValue = new std::vector<byte>();
    myValue = new std::string();
}

TestBaseHexaDecimal::~TestBaseHexaDecimal()
{
}