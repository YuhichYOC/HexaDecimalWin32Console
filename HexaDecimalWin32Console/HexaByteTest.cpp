#include "stdafx.h"

#include "HexaByteTest.h"

bool HexaByteTest::GetTestSuccess()
{
    return testSuccess;
}

void HexaByteTest::HexaByteTest01()
{
    testSuccess = false;

    char testValue = 123;
    HexaByte * h = new HexaByte();
    h->SetValue(testValue);
    
    std::string * test = new std::string("7B");
    
    if (h->GetRawStr() == test) {
        testSuccess = true;
    }

    delete h;
}

void HexaByteTest::HexaByteTest02()
{
    testSuccess = false;

    char testValue[3] = "7B";
    HexaByte * h = new HexaByte();
    h->SetHexa(testValue);

    char test = 123;

    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
}

HexaByteTest::HexaByteTest()
{
}

HexaByteTest::~HexaByteTest()
{
}
