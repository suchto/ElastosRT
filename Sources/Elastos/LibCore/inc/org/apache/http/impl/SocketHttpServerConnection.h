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

#ifndef __ORG_APACHE_HTTP_IMPL_SOCKETHTTPSERVERCONNECTION_H__
#define __ORG_APACHE_HTTP_IMPL_SOCKETHTTPSERVERCONNECTION_H__

#include "Elastos.CoreLibrary.Net.h"
#include "org/apache/http/impl/AbstractHttpServerConnection.h"

using Elastos::Net::IInetAddress;
using Elastos::Net::ISocket;
using Org::Apache::Http::IHttpInetConnection;
using Org::Apache::Http::IO::ISessionInputBuffer;
using Org::Apache::Http::IO::ISessionOutputBuffer;
using Org::Apache::Http::Params::IHttpParams;

namespace Org {
namespace Apache {
namespace Http {
namespace Impl {

/**
 * Implementation of a server-side HTTP connection that can be bound to a
 * network Socket in order to receive and transmit data.
 *
 * @author <a href="mailto:oleg at ural.ru">Oleg Kalnichevski</a>
 *
 * @version $Revision: 561083 $
 *
 * @since 4.0
 */
class SocketHttpServerConnection
    : public AbstractHttpServerConnection
    , public IHttpInetConnection
{
public:
    SocketHttpServerConnection();

    CAR_INTERFACE_DECL()

    CARAPI IsOpen(
        /* [out] */ Boolean* isOpen);

    CARAPI GetLocalAddress(
        /* [out] */ IInetAddress** address);

    CARAPI GetLocalPort(
        /* [out] */ Int32* port);

    CARAPI GetRemoteAddress(
        /* [out] */ IInetAddress** address);

    CARAPI GetRemotePort(
        /* [out] */ Int32* port);

    CARAPI SetSocketTimeout(
        /* [in] */ Int32 timeout);

    CARAPI GetSocketTimeout(
        /* [out] */ Int32* timeout);

    CARAPI Shutdown();

    CARAPI Close();

protected:
    CARAPI AssertNotOpen();

    CARAPI AssertOpen();

    CARAPI CreateHttpDataReceiver(
        /* [in] */ ISocket* socket,
        /* [in] */ Int32 buffersize,
        /* [in] */ IHttpParams* params,
        /* [out] */ ISessionInputBuffer** inputBuffer);

    CARAPI CreateHttpDataTransmitter(
        /* [in] */ ISocket* socket,
        /* [in] */ Int32 buffersize,
        /* [in] */ IHttpParams* params,
        /* [out] */ ISessionOutputBuffer** outputBuffer);

    CARAPI Bind(
        /* [in] */ ISocket* socket,
        /* [in] */ IHttpParams* params);

    CARAPI_(AutoPtr<ISocket>) GetSocket();

private:
    volatile Boolean mOpen;
    AutoPtr<ISocket> mSocket;
};

} // namespace Impl
} // namespace Http
} // namespace Apache
} // namespace Org

#endif // __ORG_APACHE_HTTP_IMPL_SOCKETHTTPSERVERCONNECTION_H__
