// bdljsn_writeoptions.cpp                                            -*-C++-*-
#include <bdljsn_writeoptions.h>

#include <bsls_ident.h>
BSLS_IDENT_RCSID(bdljsn_writeoptions_cpp,"$Id$ $CSID$")

#include <bdljsn_writestyle.h>

#include <bsl_cstring.h>
#include <bsl_iomanip.h>
#include <bsl_limits.h>
#include <bsl_ostream.h>

#include <bslim_printer.h>

#include <bsls_assert.h>
#include <bsls_review.h>


namespace BloombergLP {
namespace bdljsn {

                             // ------------------
                             // class WriteOptions
                             // ------------------

// CONSTANTS
const int  WriteOptions::s_DEFAULT_INITIALIZER_INITIAL_INDENT_LEVEL = 0;
const bool WriteOptions::s_DEFAULT_INITIALIZER_SORT_MEMBERS         = false;
const int  WriteOptions::s_DEFAULT_INITIALIZER_SPACES_PER_LEVEL     = 4;
const bdljsn::WriteStyle::Enum WriteOptions::s_DEFAULT_INITIALIZER_STYLE =
                                                 bdljsn::WriteStyle::e_COMPACT;

// CREATORS
WriteOptions::WriteOptions()
: d_initialIndentLevel(s_DEFAULT_INITIALIZER_INITIAL_INDENT_LEVEL)
, d_sortMembers(s_DEFAULT_INITIALIZER_SORT_MEMBERS)
, d_spacesPerLevel(s_DEFAULT_INITIALIZER_SPACES_PER_LEVEL)
, d_style(s_DEFAULT_INITIALIZER_STYLE)
{
}

WriteOptions::WriteOptions(const WriteOptions& original)
: d_initialIndentLevel(original.d_initialIndentLevel)
, d_sortMembers(original.d_sortMembers)
, d_spacesPerLevel(original.d_spacesPerLevel)
, d_style(original.d_style)
{
}

WriteOptions::~WriteOptions()
{
    BSLS_ASSERT(0 <= d_initialIndentLevel);
    BSLS_ASSERT(0 <= d_spacesPerLevel);
}

// MANIPULATORS
WriteOptions& WriteOptions::operator=(const WriteOptions& rhs)
{
    if (this != &rhs) {
        d_initialIndentLevel = rhs.d_initialIndentLevel;
        d_sortMembers        = rhs.d_sortMembers;
        d_spacesPerLevel     = rhs.d_spacesPerLevel;
        d_style              = rhs.d_style;
    }

    return *this;
}

WriteOptions& WriteOptions::reset()
{
    d_initialIndentLevel = s_DEFAULT_INITIALIZER_INITIAL_INDENT_LEVEL;
    d_sortMembers        = s_DEFAULT_INITIALIZER_SORT_MEMBERS;
    d_spacesPerLevel     = s_DEFAULT_INITIALIZER_SPACES_PER_LEVEL;
    d_style              = s_DEFAULT_INITIALIZER_STYLE;
    return *this;
}

// ACCESSORS

                                  // Aspects

bsl::ostream& WriteOptions::print(bsl::ostream& stream,
                                  int           level,
                                  int           spacesPerLevel) const
{
    bslim::Printer printer(&stream, level, spacesPerLevel);
    printer.start();
    printer.printAttribute("initialIndentLevel", d_initialIndentLevel);
    printer.printAttribute("sortMembers", d_sortMembers);
    printer.printAttribute("spacesPerLevel", d_spacesPerLevel);
    printer.printAttribute("style", d_style);
    printer.end();
    return stream;
}

}  // close package namespace
}  // close enterprise namespace

// ----------------------------------------------------------------------------
// Copyright 2022 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
