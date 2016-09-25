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

void TestBaseHexaDecimal::SetHexa(CList<byte> * arg)
{
    hexaValue = arg;
}

CList<byte> * TestBaseHexaDecimal::GetHexa()
{
    return hexaValue;
}

TestBaseHexaDecimal::TestBaseHexaDecimal()
{
    hexaValue = new CList<byte>();
}

TestBaseHexaDecimal::~TestBaseHexaDecimal()
{
}