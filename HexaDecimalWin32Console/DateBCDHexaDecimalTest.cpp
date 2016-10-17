#include "stdafx.h"

#include "DateBCDHexaDecimalTest.h"

bool DateBCDHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void DateBCDHexaDecimalTest::DateBCDHexaDecimalTest01()
{
    testSuccess = false;

    int test1yyyy = 2016;
    int test2mm = 6;
    int test3dd = 23;
    DateBCDHexaDecimal * h = new DateBCDHexaDecimal();
    h->SetValue(test1yyyy, test2mm, test3dd);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x20;
    uint8_t test02 = (uint8_t)0x16;
    uint8_t test03 = (uint8_t)0x06;
    uint8_t test04 = (uint8_t)0x23;

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

    delete h;
}

void DateBCDHexaDecimalTest::DateBCDHexaDecimalTest02()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(20);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(16);
    HexaByte * h3 = new HexaByte();
    h3->SetValue(6);
    HexaByte * h4 = new HexaByte();
    h4->SetValue(23);
    std::vector<HexaByte> * testValue = new std::vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    testValue->push_back(*h3);
    testValue->push_back(*h4);
    DateBCDHexaDecimal * h = new DateBCDHexaDecimal();
    h->SetHexa(testValue);
    h->HexaToValue();

    std::string * test = new std::string();
    test->assign("20160623");

    if ((h->GetBCDStr() == test) == 0) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
    delete h3;
    delete h4;
}

void DateBCDHexaDecimalTest::DateBCDHexaDecimalTest03()
{
    testSuccess = false;

    int test1yyyy = 2016;
    int test2mm = 6;
    int test3dd = 23;
    int testSize = 7;
    DateBCDHexaDecimal * h = new DateBCDHexaDecimal();
    h->SetValue(test1yyyy, test2mm, test3dd);
    h->SetSize(testSize);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x00;
    uint8_t test02 = (uint8_t)0x00;
    uint8_t test03 = (uint8_t)0x00;
    uint8_t test04 = (uint8_t)0x20;
    uint8_t test05 = (uint8_t)0x16;
    uint8_t test06 = (uint8_t)0x06;
    uint8_t test07 = (uint8_t)0x23;

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
    if (h->GetHexa()->at(5).GetValue() != test06) {
        testSuccess = false;
    }
    if (h->GetHexa()->at(6).GetValue() != test07) {
        testSuccess = false;
    }

    delete h;
}

void DateBCDHexaDecimalTest::DateBCDHexaDecimalTest04()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(20);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(16);
    HexaByte * h3 = new HexaByte();
    h3->SetValue(6);
    HexaByte * h4 = new HexaByte();
    h4->SetValue(23);
    std::vector<HexaByte> * testValue = new std::vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    testValue->push_back(*h3);
    testValue->push_back(*h4);
    int testSize = 7;
    DateBCDHexaDecimal * h = new DateBCDHexaDecimal();
    h->SetHexa(testValue);
    h->SetSize(testSize);
    h->HexaToValue();

    std::string * test = new std::string();
    test->assign("00000020160623");

    if ((h->GetBCDStr() == test) == 0) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
    delete h3;
    delete h4;
}

DateBCDHexaDecimalTest::DateBCDHexaDecimalTest()
{
}

DateBCDHexaDecimalTest::~DateBCDHexaDecimalTest()
{
}