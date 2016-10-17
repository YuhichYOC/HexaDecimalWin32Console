#include "stdafx.h"

#include "BCDHexaDecimalTest.h"

bool BCDHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void BCDHexaDecimalTest::BCDHexaDecimalTest01()
{
    testSuccess = false;

    int testValue = 201601;
    BCDHexaDecimal * h = new BCDHexaDecimal();
    h->SetValue(testValue);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x20;
    uint8_t test02 = (uint8_t)0x16;
    uint8_t test03 = (uint8_t)0x01;

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

    delete h;
}

void BCDHexaDecimalTest::BCDHexaDecimalTest02()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(20);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(16);
    HexaByte * h3 = new HexaByte();
    h3->SetValue(01);
    std::vector<HexaByte> * testValue = new std::vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    testValue->push_back(*h3);
    BCDHexaDecimal * h = new BCDHexaDecimal();
    h->SetHexa(testValue);
    h->HexaToValue();

    int test = 201601;
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
    delete h3;
}

void BCDHexaDecimalTest::BCDHexaDecimalTest03()
{
    testSuccess = false;

    int testValue = 201601;
    int testSize = 5;
    BCDHexaDecimal * h = new BCDHexaDecimal();
    h->SetValue(testValue);
    h->SetSize(testSize);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x00;
    uint8_t test02 = (uint8_t)0x00;
    uint8_t test03 = (uint8_t)0x20;
    uint8_t test04 = (uint8_t)0x16;
    uint8_t test05 = (uint8_t)0x01;

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
}

void BCDHexaDecimalTest::BCDHexaDecimalTest04()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(20);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(16);
    HexaByte * h3 = new HexaByte();
    h3->SetValue(01);
    std::vector<HexaByte> * testValue = new std::vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    testValue->push_back(*h3);
    int testSize = 5;
    BCDHexaDecimal * h = new BCDHexaDecimal();
    h->SetHexa(testValue);
    h->SetSize(testSize);
    h->HexaToValue();

    int test = 201601;
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
    delete h3;
}

BCDHexaDecimalTest::BCDHexaDecimalTest()
{
}

BCDHexaDecimalTest::~BCDHexaDecimalTest()
{
}