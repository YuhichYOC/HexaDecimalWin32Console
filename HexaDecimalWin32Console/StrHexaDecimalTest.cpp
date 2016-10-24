#include "stdafx.h"

#include "StrHexaDecimalTest.h"

bool StrHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void StrHexaDecimalTest::StrHexaDecimalTest01()
{
    testSuccess = false;

    StrHexaDecimal * s1 = new StrHexaDecimal();
    s1->SetValue(string("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    s1->ValueToHexa();
    s1->HexaToValue();

    cout << s1->GetValue() << "\n";

    delete s1;

    testSuccess = true;
}

StrHexaDecimalTest::StrHexaDecimalTest()
{
}

StrHexaDecimalTest::~StrHexaDecimalTest()
{
}