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

#include "org/apache/harmony/security/x509/CSubjectPublicKeyInfoHelper.h"
#include "org/apache/harmony/security/x509/CSubjectPublicKeyInfo.h"

namespace Org {
namespace Apache {
namespace Harmony {
namespace Security {
namespace X509 {

CAR_SINGLETON_IMPL(CSubjectPublicKeyInfoHelper)

CAR_INTERFACE_IMPL(CSubjectPublicKeyInfoHelper, Singleton, ISubjectPublicKeyInfoHelper)

ECode CSubjectPublicKeyInfoHelper::GetASN1(
    /* [out] */ IASN1Sequence** ppAsn1)
{
    VALIDATE_NOT_NULL(ppAsn1);
    *ppAsn1 = CSubjectPublicKeyInfo::ASN1;
    REFCOUNT_ADD(*ppAsn1);
    return NOERROR;
}

} // namespace X509
} // namespace Security
} // namespace Harmony
} // namespace Apache
} // namespace Org