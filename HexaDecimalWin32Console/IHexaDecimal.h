/*
*
* IHexaDecimal.h
*
* Copyright 2016 Yuichi Yoshii
*     ‹gˆä—Yˆê @ ‹gˆäŽY‹Æ  you.65535.kir@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

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