#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace HexaDecimalWin32ConsoleTest
{
    [TestClass]
    public ref class UnitTest
    {
    private:
        TestContext^ testContextInstance;

    public:
        /// <summary>
        ///現在のテストの実行についての情報および機能を
        ///提供するテスト コンテキストを取得または設定します。
        ///</summary>
        property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
        {
            Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
            {
                return testContextInstance;
            }
            System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
            {
                testContextInstance = value;
            }
        };

#pragma region Additional test attributes
        //
        //テストを作成する際には、次の追加属性を使用できます:
        //
        //クラス内で最初のテストを実行する前に、ClassInitialize を使用してコードを実行してください
        //[ClassInitialize()]
        //static void MyClassInitialize(TestContext^ testContext) {};
        //
        //クラス内のテストをすべて実行したら、ClassCleanup を使用してコードを実行してください
        //[ClassCleanup()]
        //static void MyClassCleanup() {};
        //
        //各テストを実行する前に、TestInitialize を使用してコードを実行してください
        //[TestInitialize()]
        //void MyTestInitialize() {};
        //
        //各テストを実行した後に、TestCleanup を使用してコードを実行してください
        //[TestCleanup()]
        //void MyTestCleanup() {};
        //
#pragma endregion

        [TestMethod]
        void TestMethod1()
        {
            //
            // TODO: テスト ロジックをここに追加してください
            //
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
            Assert::AreEqual(h1->GetHexa()->GetCount(), h2->GetHexa()->GetCount());
        };
    };
}