#include "stdafx.h"

#include "RawStrHexaDecimalTest.h"

bool RawStrHexaDecimalTest::GetTestSuccess()
{
    return testSuccess;
}

void RawStrHexaDecimalTest::RawStrHexaDecimalTest01()
{
    testSuccess = false;

    string testValue;
    testValue.assign("0x0102030405");
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetValue(testValue);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x01;
    uint8_t test02 = (uint8_t)0x02;
    uint8_t test03 = (uint8_t)0x03;
    uint8_t test04 = (uint8_t)0x04;
    uint8_t test05 = (uint8_t)0x05;

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

void RawStrHexaDecimalTest::RawStrHexaDecimalTest02()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue(255);
    HexaByte * h2 = new HexaByte();
    h2->SetValue(255);
    vector<HexaByte> * testValue = new vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetHexa(testValue);
    h->HexaToValue();

    string test;
    test.assign("0xFFFF");

    /*
    if ((h->GetValue() == test) == 0) {
        testSuccess = true;
    }
    */
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
}

void RawStrHexaDecimalTest::RawStrHexaDecimalTest03()
{
    testSuccess = false;

    string testValue;
    testValue.assign("0x0102030405");
    int testSize = 7;
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetValue(testValue);
    h->SetSize(testSize);
    h->ValueToHexa();

    uint8_t test01 = (uint8_t)0x01;
    uint8_t test02 = (uint8_t)0x02;
    uint8_t test03 = (uint8_t)0x03;
    uint8_t test04 = (uint8_t)0x04;
    uint8_t test05 = (uint8_t)0x05;
    uint8_t test06 = (uint8_t)0x00;
    uint8_t test07 = (uint8_t)0x00;

    testSuccess = true;
    if (h->GetHexa()->size() < 7) {
        testSuccess = false;
    }
    else {
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
    }

    delete h;
}

void RawStrHexaDecimalTest::RawStrHexaDecimalTest04()
{
    testSuccess = false;

    HexaByte * h1 = new HexaByte();
    h1->SetValue((uint8_t)0x01);
    HexaByte * h2 = new HexaByte();
    h2->SetValue((uint8_t)0x02);
    HexaByte * h3 = new HexaByte();
    h3->SetValue((uint8_t)0x03);
    HexaByte * h4 = new HexaByte();
    h4->SetValue((uint8_t)0x04);
    HexaByte * h5 = new HexaByte();
    h5->SetValue((uint8_t)0x05);
    vector<HexaByte> * testValue = new vector<HexaByte>();
    testValue->push_back(*h1);
    testValue->push_back(*h2);
    testValue->push_back(*h3);
    testValue->push_back(*h4);
    testValue->push_back(*h5);
    int testSize = 7;
    RawStrHexaDecimal * h = new RawStrHexaDecimal();
    h->SetHexa(testValue);
    h->SetSize(testSize);
    h->HexaToValue();

    string test;
    test.assign("0x01020304050000");

    /*
    if ((h->GetValue() == test) == 0) {
    testSuccess = true;
    }
    */
    if (h->GetValue() == test) {
        testSuccess = true;
    }

    delete h;
    delete h1;
    delete h2;
    delete h3;
    delete h4;
    delete h5;
}

RawStrHexaDecimalTest::RawStrHexaDecimalTest()
{
}

RawStrHexaDecimalTest::~RawStrHexaDecimalTest()
{
}