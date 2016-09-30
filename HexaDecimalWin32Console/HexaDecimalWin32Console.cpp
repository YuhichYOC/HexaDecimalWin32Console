// HexaDecimalWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


#include "IntHexaDecimalTest.h"
#include "RawStrHexaDecimalTest.h"

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
        std::cout << "iTest test01 success." << "\n";
    }
    else {
        std::cout << "iTest test01 failed." << "\n";
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
    IntHexaDecimalTest01();
    IntHexaDecimalTest02();

    RawStrHexaDecimalTest01();
    RawStrHexaDecimalTest02();

    std::string testOut01;
    std::cin >> testOut01;

    return 0;
}
