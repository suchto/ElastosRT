//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "Elastos.CoreLibrary.IO.h"
#include "MacSpi.h"

namespace Elastosx {
namespace Crypto {

CAR_INTERFACE_IMPL(MacSpi, Object, IMacSpi)

MacSpi::MacSpi()
{
}

MacSpi::~MacSpi()
{
}

ECode MacSpi::constructor()
{
    return NOERROR;
}

ECode MacSpi::EngineUpdate(
    /* [in] */ IByteBuffer * input)
{
	Boolean b;
	IBuffer::Probe(input)->HasRemaining(&b);
    if (!b) {
        return NOERROR;
    }
    AutoPtr<ArrayOf<Byte> > bInput;
    IBuffer::Probe(input)->HasArray(&b);
    Int32 position;
    IBuffer::Probe(input)->GetPosition(&position);
    Int32 limit;
    IBuffer::Probe(input)->GetLimit(&limit);
    if (b) {
        input->GetArray((ArrayOf<Byte>**)&bInput);
        Int32 offset;
        IBuffer::Probe(input)->GetArrayOffset(&offset);
        EngineUpdate(bInput, offset + position, limit - position);
        IBuffer::Probe(input)->SetPosition(limit);
    } else {
        bInput = ArrayOf<Byte>::Alloc(limit - position);
        input->GetArray((ArrayOf<Byte>**)&bInput);
        EngineUpdate(bInput, 0, bInput->GetLength());
    }
    return NOERROR;
}

ECode MacSpi::Clone(
    /* [out] */ IInterface** result)
{
    assert(0);
    VALIDATE_NOT_NULL(result)
    return NOERROR;
}

ECode MacSpi::CloneImpl(
    /* [in] */ IMacSpi* spi)
{
    assert(spi);

    return NOERROR;
}

} // Crypto
} // Elastosx