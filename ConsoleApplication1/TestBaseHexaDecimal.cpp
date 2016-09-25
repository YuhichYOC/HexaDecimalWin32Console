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

TestBaseHexaDecimal::TestBaseHexaDecimal()
{
    hexaValue = new std::vector<byte>();
}

TestBaseHexaDecimal::~TestBaseHexaDecimal()
{
}