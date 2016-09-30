// HexaDecimalWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "BCDHexaDecimalTest.h"
#include "HexaByteTest.h"
#include "IntHexaDecimalTest.h"
#include "RawStrHexaDecimalTest.h"

void BCDHexaDecimalTest01()
{
    BCDHexaDecimalTest * bTest = new BCDHexaDecimalTest();
    bTest->BCDHexaDecimalTest01();
    if (bTest->GetTestSuccess()) {
        std::cout << "bTest test01 success." << "\n";
    }
    else {
        std::cout << "bTest test01 failed." << "\n";
    }
    delete bTest;
}

void BCDHexaDecimalTest02()
{
    BCDHexaDecimalTest * bTest = new BCDHexaDecimalTest();
    bTest->BCDHexaDecimalTest02();
    if (bTest->GetTestSuccess()) {
        std::cout << "bTest test02 success." << "\n";
    }
    else {
        std::cout << "bTest test02 failed." << "\n";
    }
    delete bTest;
}

void HexaByteTest01()
{
    HexaByteTest * hTest = new HexaByteTest();
    hTest->HexaByteTest01();
    if (hTest->GetTestSuccess()) {
        std::cout << "hTest test01 success." << "\n";
    }
    else {
        std::cout << "hTest test01 failer." << "\n";
    }
    delete hTest;
}

void HexaByteTest02()
{
    HexaByteTest * hTest = new HexaByteTest();
    hTest->HexaByteTest02();
    if (hTest->GetTestSuccess()) {
        std::cout << "hTest test02 success." << "\n";
    }
    else {
        std::cout << "hTest test02 failed." << "\n";
    }
    delete hTest;
}

void HexaByteTest03()
{
    HexaByteTest * hTest = new HexaByteTest();
    hTest->HexaByteTest03();
    if (hTest->GetTestSuccess()) {
        std::cout << "hTest test03 success." << "\n";
    }
    else {
        std::cout << "hTest test03 failed." << "\n";
    }
    delete hTest;
}

void IntHexaDecimalTest01()
{
    IntHexaDecimalTest * iTest = new IntHexaDecimalTest();
    iTest->IntHexaDecimalTest01();
    if (iTest->GetTestSuccess()) {
        std::cout << "iTest test01 success." << "\n";
    }
    else {
        std::cout << "iTest test01 failed." << "\n";
    }
    delete iTest;
}

void IntHexaDecimalTest02()
{
    IntHexaDecimalTest * iTest = new IntHexaDecimalTest();
    iTest->IntHexaDecimalTest02();
    if (iTest->GetTestSuccess()) {
        std::cout << "iTest test02 success." << "\n";
    }
    else {
        std::cout << "iTest test02 failed." << "\n";
    }
    delete iTest;
}

void RawStrHexaDecimalTest01()
{
    RawStrHexaDecimalTest * rTest = new RawStrHexaDecimalTest();
    rTest->RawStrHexaDecimalTest01();
    if (rTest->GetTestSuccess()) {
        std::cout << "rTest test01 success." << "\n";
    }
    else {
        std::cout << "rTest test01 failed." << "\n";
    }
    delete rTest;
}

void RawStrHexaDecimalTest02()
{
    RawStrHexaDecimalTest * rTest = new RawStrHexaDecimalTest();
    rTest->RawStrHexaDecimalTest02();
    if (!rTest->GetTestSuccess()) {
        std::cout << "rTest test02 success." << "\n";
    }
    else {
        std::cout << "rTest test02 failed." << "\n";
    }
    delete rTest;
}

int main()
{
    BCDHexaDecimalTest01();
    BCDHexaDecimalTest02();

    HexaByteTest01();
    HexaByteTest02();
    HexaByteTest03();

    IntHexaDecimalTest01();
    IntHexaDecimalTest02();

    RawStrHexaDecimalTest01();
    RawStrHexaDecimalTest02();

    std::string testOut01;
    std::cin >> testOut01;

    return 0;
}