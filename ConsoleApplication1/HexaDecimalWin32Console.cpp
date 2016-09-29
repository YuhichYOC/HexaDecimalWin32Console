// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "TestBaseHexaDecimal.h"

int main()
{
    TestBaseHexaDecimal * h1 = new TestBaseHexaDecimal();
    std::vector<byte> * h1Items = new std::vector<byte>();
    h1Items->push_back((byte)1);
    h1Items->push_back((byte)2);
    h1Items->push_back((byte)3);
    h1->SetHexa(h1Items);
    TestBaseHexaDecimal * h2 = new TestBaseHexaDecimal();
    std::vector<byte> * h2Items = new std::vector<byte>();
    h2Items->push_back((byte)3);
    h2Items->push_back((byte)2);
    h2Items->push_back((byte)1);
    h2->SetHexa(h2Items);
    int h1Count = h1->GetHexa()->size();
    int h2Count = h2->GetHexa()->size();
    std::string messageCount = "h1 has : ";
    messageCount.append(std::to_string(h1Count));
    messageCount.append(" items. h2 has : ");
    messageCount.append(std::to_string(h2Count));
    messageCount.append(" items.");
    std::cout << messageCount << std::endl;
    std::string input;
    std::cin >> input;
    std::string h1Item2 = "h1 item of 2 : ";
    h1Item2.append(std::to_string(h1->GetHexa()->at(1)));
    std::cout << h1Item2 << std::endl;
    std::string h2Item2 = "h2 item of 2 : ";
    h2Item2.append(std::to_string(h2->GetHexa()->at(1)));
    std::cout << h2Item2 << std::endl;
    try
    {
        std::cin >> input;
    }
    catch (const std::exception & ex)
    {
    }
    return 0;
}