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

#ifndef __ORG_XML_SAX_HELPERS_DEFAULTHANDLER_H__
#define __ORG_XML_SAX_HELPERS_DEFAULTHANDLER_H__

#include "Elastos.CoreLibrary.External.h"
#include "Object.h"

namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {

/**
 * Default base class for SAX2 event handlers.
 *
 * <blockquote>
 * <em>This module, both source code and documentation, is in the
 * Public Domain, and comes with <strong>NO WARRANTY</strong>.</em>
 * See <a href='http://www.saxproject.org'>http://www.saxproject.org</a>
 * for further information.
 * </blockquote>
 *
 * <p>This class is available as a convenience base class for SAX2
 * applications: it provides default implementations for all of the
 * callbacks in the four core SAX2 handler classes:</p>
 *
 * <ul>
 * <li>{@link org.xml.sax.EntityResolver EntityResolver}</li>
 * <li>{@link org.xml.sax.DTDHandler DTDHandler}</li>
 * <li>{@link org.xml.sax.ContentHandler ContentHandler}</li>
 * <li>{@link org.xml.sax.ErrorHandler ErrorHandler}</li>
 * </ul>
 *
 * <p>Application writers can extend this class when they need to
 * implement only part of an interface; parser writers can
 * instantiate this class to provide default handlers when the
 * application has not supplied its own.</p>
 *
 * <p>This class replaces the deprecated SAX1
 * {@link org.xml.sax.HandlerBase HandlerBase} class.</p>
 *
 * @since SAX 2.0
 * @author David Megginson,
 * @version 2.0.1 (sax2r2)
 * @see org.xml.sax.EntityResolver
 * @see org.xml.sax.DTDHandler
 * @see org.xml.sax.ContentHandler
 * @see org.xml.sax.ErrorHandler
 */
class DefaultHandler
    : public Object
    , public IEntityResolver
    , public IDTDHandler
    , public IContentHandler
    , public IErrorHandler
{
public:
    CAR_INTERFACE_DECL()

    /**
     * Resolve an external entity.
     *
     * <p>Always return null, so that the parser will use the system
     * identifier provided in the XML document.  This method implements
     * the SAX default behaviour: application writers can override it
     * in a subclass to do special translations such as catalog lookups
     * or URI redirection.</p>
     *
     * @param publicId The public identifer, or null if none is
     *                 available.
     * @param systemId The system identifier provided in the XML
     *                 document.
     * @return The new input source, or null to require the
     *         default behaviour.
     * @exception java.io.IOException If there is an error setting
     *            up the new input source.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.EntityResolver#resolveEntity
     */
    CARAPI ResolveEntity(
        /* [in] */ const String& publicId,
        /* [in] */ const String& systemId,
        /* [out] */ IInputSource** src);

    /**
     * Receive notification of a notation declaration.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass if they wish to keep track of the notations
     * declared in a document.</p>
     *
     * @param name The notation name.
     * @param publicId The notation public identifier, or null if not
     *                 available.
     * @param systemId The notation system identifier.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.DTDHandler#notationDecl
     */
    CARAPI NotationDecl(
        /* [in] */ const String& name,
        /* [in] */ const String& publicId,
        /* [in] */ const String& systemId);

    /**
     * Receive notification of an unparsed entity declaration.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to keep track of the unparsed entities
     * declared in a document.</p>
     *
     * @param name The entity name.
     * @param publicId The entity public identifier, or null if not
     *                 available.
     * @param systemId The entity system identifier.
     * @param notationName The name of the associated notation.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.DTDHandler#unparsedEntityDecl
     */
    CARAPI UnparsedEntityDecl(
        /* [in] */ const String& name,
        /* [in] */ const String& publicId,
        /* [in] */ const String& systemId,
        /* [in] */ const String& notationName);

    /**
     * Receive a Locator object for document events.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass if they wish to store the locator for use
     * with other document events.</p>
     *
     * @param locator A locator for all SAX document events.
     * @see org.xml.sax.ContentHandler#setDocumentLocator
     * @see org.xml.sax.Locator
     */
    CARAPI SetDocumentLocator(
        /* [in] */ ILocator* locator);

    /**
     * Receive notification of the beginning of the document.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the beginning
     * of a document (such as allocating the root node of a tree or
     * creating an output file).</p>
     *
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#startDocument
     */
    CARAPI StartDocument();

    /**
     * Receive notification of the end of the document.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the end
     * of a document (such as finalising a tree or closing an output
     * file).</p>
     *
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#endDocument
     */
    CARAPI EndDocument();

    /**
     * Receive notification of the start of a Namespace mapping.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the start of
     * each Namespace prefix scope (such as storing the prefix mapping).</p>
     *
     * @param prefix The Namespace prefix being declared.
     * @param uri The Namespace URI mapped to the prefix.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#startPrefixMapping
     */
    CARAPI StartPrefixMapping(
        /* [in] */ const String& prefix,
        /* [in] */ const String& uri);

    /**
     * Receive notification of the end of a Namespace mapping.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the end of
     * each prefix mapping.</p>
     *
     * @param prefix The Namespace prefix being declared.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#endPrefixMapping
     */
    CARAPI EndPrefixMapping(
        /* [in] */ const String& prefix);

    /**
     * Receive notification of the start of an element.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the start of
     * each element (such as allocating a new tree node or writing
     * output to a file).</p>
     *
     * @param uri The Namespace URI, or the empty string if the
     *        element has no Namespace URI or if Namespace
     *        processing is not being performed.
     * @param localName The local name (without prefix), or the
     *        empty string if Namespace processing is not being
     *        performed.
     * @param qName The qualified name (with prefix), or the
     *        empty string if qualified names are not available.
     * @param attributes The attributes attached to the element.  If
     *        there are no attributes, it shall be an empty
     *        Attributes object.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#startElement
     */
    CARAPI StartElement(
        /* [in] */ const String& uri,
        /* [in] */ const String& localName,
        /* [in] */ const String& qName,
        /* [in] */ IAttributes* atts);

    /**
     * Receive notification of the end of an element.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions at the end of
     * each element (such as finalising a tree node or writing
     * output to a file).</p>
     *
     * @param uri The Namespace URI, or the empty string if the
     *        element has no Namespace URI or if Namespace
     *        processing is not being performed.
     * @param localName The local name (without prefix), or the
     *        empty string if Namespace processing is not being
     *        performed.
     * @param qName The qualified name (with prefix), or the
     *        empty string if qualified names are not available.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#endElement
     */
    CARAPI EndElement(
        /* [in] */ const String& uri,
        /* [in] */ const String& localName,
        /* [in] */ const String& qName);

    /**
     * Receive notification of character data inside an element.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method to take specific actions for each chunk of character data
     * (such as adding the data to a node or buffer, or printing it to
     * a file).</p>
     *
     * @param ch The characters.
     * @param start The start position in the character array.
     * @param length The number of characters to use from the
     *               character array.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#characters
     */
    CARAPI Characters(
        /* [out] */ ArrayOf<Char32>* ch,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

    /**
     * Receive notification of ignorable whitespace in element content.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method to take specific actions for each chunk of ignorable
     * whitespace (such as adding data to a node or buffer, or printing
     * it to a file).</p>
     *
     * @param ch The whitespace characters.
     * @param start The start position in the character array.
     * @param length The number of characters to use from the
     *               character array.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#ignorableWhitespace
     */
    CARAPI IgnorableWhitespace(
        /* [out] */ ArrayOf<Char32>* ch,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

    /**
     * Receive notification of a processing instruction.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions for each
     * processing instruction, such as setting status variables or
     * invoking other methods.</p>
     *
     * @param target The processing instruction target.
     * @param data The processing instruction data, or null if
     *             none is supplied.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#processingInstruction
     */
    CARAPI ProcessingInstruction(
        /* [in] */ const String& target,
        /* [in] */ const String& data);

    /**
     * Receive notification of a skipped entity.
     *
     * <p>By default, do nothing.  Application writers may override this
     * method in a subclass to take specific actions for each
     * processing instruction, such as setting status variables or
     * invoking other methods.</p>
     *
     * @param name The name of the skipped entity.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ContentHandler#processingInstruction
     */
    CARAPI SkippedEntity(
        /* [in] */ const String& name);


    ////////////////////////////////////////////////////////////////////
    // Default implementation of the ErrorHandler interface.
    ////////////////////////////////////////////////////////////////////

    /**
     * Receive notification of a parser warning.
     *
     * <p>The default implementation does nothing.  Application writers
     * may override this method in a subclass to take specific actions
     * for each warning, such as inserting the message in a log file or
     * printing it to the console.</p>
     *
     * @param e The warning information encoded as an exception.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ErrorHandler#warning
     * @see org.xml.sax.SAXParseException
     */
    CARAPI Warning(
        /* [in] */ ECode exception);

    /**
     * Receive notification of a recoverable parser error.
     *
     * <p>The default implementation does nothing.  Application writers
     * may override this method in a subclass to take specific actions
     * for each error, such as inserting the message in a log file or
     * printing it to the console.</p>
     *
     * @param e The warning information encoded as an exception.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ErrorHandler#warning
     * @see org.xml.sax.SAXParseException
     */
    CARAPI Error(
        /* [in] */ ECode exception);

    /**
     * Report a fatal XML parsing error.
     *
     * <p>The default implementation throws a SAXParseException.
     * Application writers may override this method in a subclass if
     * they need to take specific actions for each fatal error (such as
     * collecting all of the errors into a single report): in any case,
     * the application must stop all regular processing when this
     * method is invoked, since the document is no longer reliable, and
     * the parser may no longer report parsing events.</p>
     *
     * @param e The error information encoded as an exception.
     * @exception org.xml.sax.SAXException Any SAX exception, possibly
     *            wrapping another exception.
     * @see org.xml.sax.ErrorHandler#fatalError
     * @see org.xml.sax.SAXParseException
     */
    CARAPI FatalError(
        /* [in] */ ECode exception);
};

} // namespace Helpers
} // namespace Sax
} // namespace Xml
} // namespace Org

#endif // __ORG_XML_SAX_HELPERS_DEFAULTHANDLER_H__
