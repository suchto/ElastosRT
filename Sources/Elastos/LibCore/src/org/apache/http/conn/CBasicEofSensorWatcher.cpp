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
#include "org/apache/http/conn/CBasicEofSensorWatcher.h"
#include "elastos/utility/logging/Logger.h"

using Elastos::IO::ICloseable;
using Elastos::Utility::Logging::Logger;

namespace Org {
namespace Apache {
namespace Http {
namespace Conn {

CAR_INTERFACE_IMPL(CBasicEofSensorWatcher, Object, IEofSensorWatcher)

CAR_OBJECT_IMPL(CBasicEofSensorWatcher)

ECode CBasicEofSensorWatcher::EofDetected(
    /* [in] */ IInputStream* wrapped,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)
    // try {
    if (mAttemptReuse) {
        // there may be some cleanup required, such as
        // reading trailers after the response body:
        ICloseable::Probe(wrapped)->Close();
        mManagedConn->MarkReusable();
    }
    // } finally {
    //     managedConn.releaseConnection();
    // }
    IConnectionReleaseTrigger::Probe(mManagedConn)->ReleaseConnection();
    *result = FALSE;
    return NOERROR;
}

ECode CBasicEofSensorWatcher::StreamClosed(
    /* [in] */ IInputStream* wrapped,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)
    // try {
    if (mAttemptReuse) {
        // this assumes that closing the stream will
        // consume the remainder of the response body:
        ICloseable::Probe(wrapped)->Close();
        mManagedConn->MarkReusable();
    }
    // } finally {
    //     managedConn.releaseConnection();
    // }
    IConnectionReleaseTrigger::Probe(mManagedConn)->ReleaseConnection();
    *result = FALSE;
    return NOERROR;
}

ECode CBasicEofSensorWatcher::StreamAbort(
    /* [in] */ IInputStream* wrapped,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)
    IConnectionReleaseTrigger::Probe(mManagedConn)->AbortConnection();
    *result = FALSE;
    return NOERROR;
}

ECode CBasicEofSensorWatcher::constructor(
    /* [in] */ IManagedClientConnection* conn,
    /* [in] */ Boolean reuse)
{
    if (conn == NULL) {
        Logger::E("CBasicEofSensorWatcher", "Connection may not be null.");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    mManagedConn = conn;
    mAttemptReuse = reuse;
    return NOERROR;
}

} // namespace Conn
} // namespace Http
} // namespace Apache
} // namespace Org
