#pragma once

#include "stdafx.h"

#include "HexaByte.h"

class IHexaDecimal
{
public:

    virtual void SetType(ValueType arg) = 0;

    virtual ValueType GetType() = 0;

    virtual void SetSize(int arg) = 0;

    virtual int GetSize() = 0;

    virtual int GetNumericValue() = 0;

    virtual string GetRawValue() = 0;

    virtual void HexaToValue() = 0;

    virtual void ValueToHexa() = 0;
};