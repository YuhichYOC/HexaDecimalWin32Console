// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "TestBaseHexaDecimal.h"

int main()
{
    TestBaseHexaDecimal * h1 = new TestBaseHexaDecimal();
    CList<byte> * hValueArray1 = new CList<byte>();
    hValueArray1->AddTail((byte)1);
    hValueArray1->AddTail((byte)2);
    hValueArray1->AddTail((byte)3);
    h1->SetHexa(hValueArray1);
    TestBaseHexaDecimal * h2 = new TestBaseHexaDecimal();
    CList<byte> * hValueArray2 = new CList<byte>();
    hValueArray2->AddTail((byte)3);
    hValueArray2->AddTail((byte)2);
    hValueArray2->AddTail((byte)1);
    h2->SetHexa(hValueArray2);
    int h1Count = h1->GetHexa()->GetCount();
    int h2Count = h2->GetHexa()->GetCount();
    std::string messageCount = "h1 has : ";
    messageCount.append(std::to_string(h1Count));
    messageCount.append(" items. h2 has : ");
    messageCount.append(std::to_string(h2Count));
    messageCount.append(" items.");
    std::cout << messageCount << std::endl;
    std::string input;
    std::cin >> input;
    return 0;
}