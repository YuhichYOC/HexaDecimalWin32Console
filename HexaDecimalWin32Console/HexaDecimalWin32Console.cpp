// HexaDecimalWin32Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "HexaByte.h"
#include "RawStrHexaDecimal.h"
#include "IntHexaDecimal.h"

int main()
{
    //char testValue01 = 123;
    //char testValue02[3] = "7B";

    //HexaByte * h = new HexaByte(testValue02);
    //TestBaseHexaDecimal * h = new TestBaseHexaDecimal();
    //std::string * value = new std::string("0x0102030405");
    //h->SetValue(value);
    //h->ValueToHexa();
    //h->GetHexa();
    //h->HexaToValue();

    //uint8_t testValue03 = 255;
    //HexaByte * h = new HexaByte(testValue03);
    //std::cout << "testValue03 の 16 進数表現？" << "0x" << h->GetHexa()[0] << h->GetHexa()[1] << "\n";
    IntHexaDecimal * h = new IntHexaDecimal();
    int value = 65535;
    h->SetValue(value);
    h->ValueToHexa();
    h->HexaToValue();

    //std::cout << "testValue01 の 16 進数表現？" << "0x" << h->GetHexa()[0] << h->GetHexa()[1] << "\n";
    std::string testOut01;
    std::cin >> testOut01;
    return 0;
}