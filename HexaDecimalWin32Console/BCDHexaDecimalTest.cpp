#include "stdafx.h"

#include "BCDHexaDecimalTest.h"

bool BCDHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void BCDHexaDecimalTest::BCDHexaDecimalTest01()
{
    testSuccess = false;
    BCDHexaDecimal * h = new BCDHexaDecimal();
    h->SetValue(201601);
    h->ValueToHexa();
}

void BCDHexaDecimalTest::BCDHexaDecimalTest02()
{
    testSuccess = false;
    BCDHexaDecimal * h = new BCDHexaDecimal();
}

BCDHexaDecimalTest::BCDHexaDecimalTest()
{
}

BCDHexaDecimalTest::~BCDHexaDecimalTest()
{
}