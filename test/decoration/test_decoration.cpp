//
//                              libieeep1788
//
//   An implementation of the preliminary IEEE P1788 standard for
//   interval arithmetic
//
//
//   Copyright 2013
//
//   Marco Nehmeier (nehmeier@informatik.uni-wuerzburg.de)
//   Institute of Computer Science,
//   University of Wuerzburg, Germany
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   UnF<double>::less required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#define BOOST_TEST_MODULE "Decorations [p1788/decoration/decoration]"
#include "test/util/boost_test_wrapper.hpp"

#include <boost/test/output_test_stream.hpp>

#include "p1788/decoration/decoration.hpp"


typedef p1788::decoration::decoration DEC;


BOOST_AUTO_TEST_CASE(minimal_decoration_equal_test)
{
    BOOST_CHECK( (DEC::trv == DEC::trv) );
    BOOST_CHECK( !(DEC::trv == DEC::def) );
    BOOST_CHECK( !(DEC::trv == DEC::dac) );
    BOOST_CHECK( !(DEC::trv == DEC::com) );
    BOOST_CHECK( !(DEC::trv == DEC::ill) );

    BOOST_CHECK( !(DEC::def == DEC::trv) );
    BOOST_CHECK( (DEC::def == DEC::def) );
    BOOST_CHECK( !(DEC::def == DEC::dac) );
    BOOST_CHECK( !(DEC::def == DEC::com) );
    BOOST_CHECK( !(DEC::def == DEC::ill) );

    BOOST_CHECK( !(DEC::dac == DEC::trv) );
    BOOST_CHECK( !(DEC::dac == DEC::def) );
    BOOST_CHECK( (DEC::dac == DEC::dac) );
    BOOST_CHECK( !(DEC::dac == DEC::com) );
    BOOST_CHECK( !(DEC::dac == DEC::ill) );

    BOOST_CHECK( !(DEC::com == DEC::trv) );
    BOOST_CHECK( !(DEC::com == DEC::def) );
    BOOST_CHECK( !(DEC::com == DEC::dac) );
    BOOST_CHECK( (DEC::com == DEC::com) );
    BOOST_CHECK( !(DEC::com == DEC::ill) );

    BOOST_CHECK( !(DEC::ill == DEC::trv) );
    BOOST_CHECK( !(DEC::ill == DEC::def) );
    BOOST_CHECK( !(DEC::ill == DEC::dac) );
    BOOST_CHECK( !(DEC::ill == DEC::com) );
    BOOST_CHECK( (DEC::ill == DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_not_equal_test)
{
    BOOST_CHECK( !(DEC::trv != DEC::trv) );
    BOOST_CHECK( (DEC::trv != DEC::def) );
    BOOST_CHECK( (DEC::trv != DEC::dac) );
    BOOST_CHECK( (DEC::trv != DEC::com) );
    BOOST_CHECK( (DEC::trv != DEC::ill) );

    BOOST_CHECK( (DEC::def != DEC::trv) );
    BOOST_CHECK( !(DEC::def != DEC::def) );
    BOOST_CHECK( (DEC::def != DEC::dac) );
    BOOST_CHECK( (DEC::def != DEC::com) );
    BOOST_CHECK( (DEC::def != DEC::ill) );

    BOOST_CHECK( (DEC::dac != DEC::trv) );
    BOOST_CHECK( (DEC::dac != DEC::def) );
    BOOST_CHECK( !(DEC::dac != DEC::dac) );
    BOOST_CHECK( (DEC::dac != DEC::com) );
    BOOST_CHECK( (DEC::dac != DEC::ill) );

    BOOST_CHECK( (DEC::com != DEC::trv) );
    BOOST_CHECK( (DEC::com != DEC::def) );
    BOOST_CHECK( (DEC::com != DEC::dac) );
    BOOST_CHECK( !(DEC::com != DEC::com) );
    BOOST_CHECK( (DEC::com != DEC::ill) );

    BOOST_CHECK( (DEC::ill != DEC::trv) );
    BOOST_CHECK( (DEC::ill != DEC::def) );
    BOOST_CHECK( (DEC::ill != DEC::dac) );
    BOOST_CHECK( (DEC::ill != DEC::com) );
    BOOST_CHECK( !(DEC::ill != DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_lower_test)
{
    BOOST_CHECK( !(DEC::trv < DEC::trv) );
    BOOST_CHECK( (DEC::trv < DEC::def) );
    BOOST_CHECK( (DEC::trv < DEC::dac) );
    BOOST_CHECK( (DEC::trv < DEC::com) );
    BOOST_CHECK( !(DEC::trv < DEC::ill) );

    BOOST_CHECK( !(DEC::def < DEC::trv) );
    BOOST_CHECK( !(DEC::def < DEC::def) );
    BOOST_CHECK( (DEC::def < DEC::dac) );
    BOOST_CHECK( (DEC::def < DEC::com) );
    BOOST_CHECK( !(DEC::def < DEC::ill) );

    BOOST_CHECK( !(DEC::dac < DEC::trv) );
    BOOST_CHECK( !(DEC::dac < DEC::def) );
    BOOST_CHECK( !(DEC::dac < DEC::dac) );
    BOOST_CHECK( (DEC::dac < DEC::com) );
    BOOST_CHECK( !(DEC::dac < DEC::ill) );

    BOOST_CHECK( !(DEC::com < DEC::trv) );
    BOOST_CHECK( !(DEC::com < DEC::def) );
    BOOST_CHECK( !(DEC::com < DEC::dac) );
    BOOST_CHECK( !(DEC::com < DEC::com) );
    BOOST_CHECK( !(DEC::com < DEC::ill) );

    BOOST_CHECK( (DEC::ill < DEC::trv) );
    BOOST_CHECK( (DEC::ill < DEC::def) );
    BOOST_CHECK( (DEC::ill < DEC::dac) );
    BOOST_CHECK( (DEC::ill < DEC::com) );
    BOOST_CHECK( !(DEC::ill < DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_lower_equal_test)
{
    BOOST_CHECK( (DEC::trv <= DEC::trv) );
    BOOST_CHECK( (DEC::trv <= DEC::def) );
    BOOST_CHECK( (DEC::trv <= DEC::dac) );
    BOOST_CHECK( (DEC::trv <= DEC::com) );
    BOOST_CHECK( !(DEC::trv <= DEC::ill) );

    BOOST_CHECK( !(DEC::def <= DEC::trv) );
    BOOST_CHECK( (DEC::def <= DEC::def) );
    BOOST_CHECK( (DEC::def <= DEC::dac) );
    BOOST_CHECK( (DEC::def <= DEC::com) );
    BOOST_CHECK( !(DEC::def <= DEC::ill) );

    BOOST_CHECK( !(DEC::dac <= DEC::trv) );
    BOOST_CHECK( !(DEC::dac <= DEC::def) );
    BOOST_CHECK( (DEC::dac <= DEC::dac) );
    BOOST_CHECK( (DEC::dac <= DEC::com) );
    BOOST_CHECK( !(DEC::dac <= DEC::ill) );

    BOOST_CHECK( !(DEC::com <= DEC::trv) );
    BOOST_CHECK( !(DEC::com <= DEC::def) );
    BOOST_CHECK( !(DEC::com <= DEC::dac) );
    BOOST_CHECK( (DEC::com <= DEC::com) );
    BOOST_CHECK( !(DEC::com <= DEC::ill) );

    BOOST_CHECK( (DEC::ill <= DEC::trv) );
    BOOST_CHECK( (DEC::ill <= DEC::def) );
    BOOST_CHECK( (DEC::ill <= DEC::dac) );
    BOOST_CHECK( (DEC::ill <= DEC::com) );
    BOOST_CHECK( (DEC::ill <= DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_greater_test)
{
    BOOST_CHECK( !(DEC::trv > DEC::trv) );
    BOOST_CHECK( !(DEC::trv > DEC::def) );
    BOOST_CHECK( !(DEC::trv > DEC::dac) );
    BOOST_CHECK( !(DEC::trv > DEC::com) );
    BOOST_CHECK( (DEC::trv > DEC::ill) );

    BOOST_CHECK( (DEC::def > DEC::trv) );
    BOOST_CHECK( !(DEC::def > DEC::def) );
    BOOST_CHECK( !(DEC::def > DEC::dac) );
    BOOST_CHECK( !(DEC::def > DEC::com) );
    BOOST_CHECK( (DEC::def > DEC::ill) );

    BOOST_CHECK( (DEC::dac > DEC::trv) );
    BOOST_CHECK( (DEC::dac > DEC::def) );
    BOOST_CHECK( !(DEC::dac > DEC::dac) );
    BOOST_CHECK( !(DEC::dac > DEC::com) );
    BOOST_CHECK( (DEC::dac > DEC::ill) );

    BOOST_CHECK( (DEC::com > DEC::trv) );
    BOOST_CHECK( (DEC::com > DEC::def) );
    BOOST_CHECK( (DEC::com > DEC::dac) );
    BOOST_CHECK( !(DEC::com > DEC::com) );
    BOOST_CHECK( (DEC::com > DEC::ill) );

    BOOST_CHECK( !(DEC::ill > DEC::trv) );
    BOOST_CHECK( !(DEC::ill > DEC::def) );
    BOOST_CHECK( !(DEC::ill > DEC::dac) );
    BOOST_CHECK( !(DEC::ill > DEC::com) );
    BOOST_CHECK( !(DEC::ill > DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_greater_equal_test)
{
    BOOST_CHECK( (DEC::trv >= DEC::trv) );
    BOOST_CHECK( !(DEC::trv >= DEC::def) );
    BOOST_CHECK( !(DEC::trv >= DEC::dac) );
    BOOST_CHECK( !(DEC::trv >= DEC::com) );
    BOOST_CHECK( (DEC::trv >= DEC::ill) );

    BOOST_CHECK( (DEC::def >= DEC::trv) );
    BOOST_CHECK( (DEC::def >= DEC::def) );
    BOOST_CHECK( !(DEC::def >= DEC::dac) );
    BOOST_CHECK( !(DEC::def >= DEC::com) );
    BOOST_CHECK( (DEC::def >= DEC::ill) );

    BOOST_CHECK( (DEC::dac >= DEC::trv) );
    BOOST_CHECK( (DEC::dac >= DEC::def) );
    BOOST_CHECK( (DEC::dac >= DEC::dac) );
    BOOST_CHECK( !(DEC::dac >= DEC::com) );
    BOOST_CHECK( (DEC::dac >= DEC::ill) );

    BOOST_CHECK( (DEC::com >= DEC::trv) );
    BOOST_CHECK( (DEC::com >= DEC::def) );
    BOOST_CHECK( (DEC::com >= DEC::dac) );
    BOOST_CHECK( (DEC::com >= DEC::com) );
    BOOST_CHECK( (DEC::com >= DEC::ill) );

    BOOST_CHECK( !(DEC::ill >= DEC::trv) );
    BOOST_CHECK( !(DEC::ill >= DEC::def) );
    BOOST_CHECK( !(DEC::ill >= DEC::dac) );
    BOOST_CHECK( !(DEC::ill >= DEC::com) );
    BOOST_CHECK( (DEC::ill >= DEC::ill) );
}

BOOST_AUTO_TEST_CASE(minimal_decoration_output_test)
{
    boost::test_tools::output_test_stream output;

    output << DEC::trv;
    BOOST_CHECK( output.is_equal( "trv" ) );

    output << DEC::def;
    BOOST_CHECK( output.is_equal( "def" ) );

    output << DEC::dac;
    BOOST_CHECK( output.is_equal( "dac" ) );

    output << DEC::com;
    BOOST_CHECK( output.is_equal( "com" ) );

    output << DEC::ill;
    BOOST_CHECK( output.is_equal( "ill" ) );

}

BOOST_AUTO_TEST_CASE(minimal_decoration_input_test)
{
    BOOST_CHECK( false );
}
