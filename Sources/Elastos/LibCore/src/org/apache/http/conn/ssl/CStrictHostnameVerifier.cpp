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

#include "org/apache/http/conn/ssl/CStrictHostnameVerifier.h"

namespace Org {
namespace Apache {
namespace Http {
namespace Conn {
namespace SSL {

CAR_OBJECT_IMPL(CStrictHostnameVerifier)

ECode CStrictHostnameVerifier::Verify(
    /* [in] */ const String& host,
    /* [in] */ ArrayOf<String>* cns,
    /* [in] */ ArrayOf<String>* subjectAlts)
{
    return Verify(host, cns, subjectAlts, TRUE);
}

ECode CStrictHostnameVerifier::ToString(
    /* [out] */ String* str)
{
    VALIDATE_NOT_NULL(str)
    *str = String("STRICT");
    return NOERROR;
}

} // namespace SSL
} // namespace Conn
} // namespace Http
} // namespace Apache
} // namespace Org