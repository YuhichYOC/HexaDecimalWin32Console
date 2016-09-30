#include "stdafx.h"
#include "RawStrHexaDecimalTest.h"

bool RawStrHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void RawStrHexaDecimalTest::RawStrHexaDecimalTest01()
{
    testSuccess = false;

    std::string * testValue = new std::string();
    testValue->assign("0x0102030405");
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetValue(testValue);
    h->ValueToHexa();
    
    char test01 = 1;
    char test02 = 2;
    char test03 = 3;
    char test04 = 4;
    char test05 = 5;

    testSuccess = true;
    if (h->GetHexa()->at(0).GetValue() != test01) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(1).GetValue() != test02) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(2).GetValue() != test03) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(3).GetValue() != test04) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(4).GetValue() != test05) {
        testSuccess = false;
    }

    delete h;
    delete testValue;
}

void RawStrHexaDecimalTest::RawStrHexaDecimalTest02()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(255);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(255);
    std::vector<HexaByte> * testValue = new std::vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetHexa(testValue);
    h->HexaToValue();

    std::string * test = new std::string();
    test->assign("0xFFFF");

    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete test;
    delete h;
    delete testValue;
    delete h1;
    delete h2;
}

RawStrHexaDecimalTest::RawStrHexaDecimalTest()
{
}

RawStrHexaDecimalTest::~RawStrHexaDecimalTest()
{
}