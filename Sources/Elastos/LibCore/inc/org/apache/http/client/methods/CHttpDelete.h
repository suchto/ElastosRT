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

#ifndef __ORG_APACHE_HTTP_CLIENT_METHODS_CHTTPDELETE_H_
#define __ORG_APACHE_HTTP_CLIENT_METHODS_CHTTPDELETE_H_

#include "_Org_Apache_Http_Client_Methods_CHttpDelete.h"
#include "org/apache/http/client/methods/HttpRequestBase.h"

namespace Org {
namespace Apache {
namespace Http {
namespace Client {
namespace Methods {

/**
 * HTTP DELETE method
 * <p>
 * The HTTP DELETE method is defined in section 9.7 of
 * <a href="http://www.ietf.org/rfc/rfc2616.txt">RFC2616</a>:
 * <blockquote>
 * The DELETE method requests that the origin server delete the resource
 * identified by the Request-URI. [...] The client cannot
 * be guaranteed that the operation has been carried out, even if the
 * status code returned from the origin server indicates that the action
 * has been completed successfully.
 * </blockquote>
 */
CarClass(CHttpDelete)
    , public HttpRequestBase
    , public IHttpDelete
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI GetMethod(
        /* [out] */ String* method);

    CARAPI Clone(
        /* [out] */ IInterface** obj);

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IURI* uri);

    CARAPI constructor(
        /* [in] */ const String& uri);
};

} // Methods
} // Client
} // namespace Http
} // namespace Apache
} // namespace Org

#endif // __ORG_APACHE_HTTP_CLIENT_METHODS_CHTTPDELETE_H_
