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

#ifndef __ELASTOSX_XML_NAMESPACE_CQNAMEHELPER_H__
#define __ELASTOSX_XML_NAMESPACE_CQNAMEHELPER_H__

#include "Singleton.h"
#include "_Elastosx_Xml_Namespace_CQNameHelper.h"

using Elastos::Core::Singleton;

namespace Elastosx {
namespace Xml {
namespace Namespace {

CarClass(CQNameHelper)
    , public Singleton
    , public IQNameHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI ValueOf(
        /* [in] */ const String& qNameAsString,
        /* [out] */ Elastosx::Xml::Namespace::IQName ** ppName);
};

} // namespace Namespace
} // namespace Xml
} // namespace Elastosx

#endif // __CQNAMEHELPER_H__
