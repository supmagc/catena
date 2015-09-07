#include <boost/test/unit_test.hpp>
#include "Rock_String.h"

using namespace Rock;

BOOST_AUTO_TEST_CASE(String_Constructors)
{
	BOOST_TEST(String() == String(RTXT("")));
	BOOST_TEST(String("azerty&é") == String(RTXT("azerty&é")));
	BOOST_TEST(String('?') == String(RTXT("?")));
	BOOST_TEST(String('?') == String(RTXT("?")));
	BOOST_TEST(String(L'?') == String(RTXT("?")));
	BOOST_TEST(String((RINT8)-128) == String(RTXT("-128")));
	BOOST_TEST(String((RUINT8)255) == String(RTXT("255")));
	BOOST_TEST(String((RINT16)-32767) == String(RTXT("-32767")));
	BOOST_TEST(String((RUINT16)65535) == String(RTXT("65535")));
	BOOST_TEST(String((RINT32)-2147483647) == String(RTXT("-2147483647")));
	BOOST_TEST(String((RUINT32)4294967295) == String(RTXT("4294967295")));
	BOOST_TEST(String((RINT64)-9223372036854775807) == String(RTXT("-9223372036854775807")));
	BOOST_TEST(String((RUINT64)18446744073709551615) == String(RTXT("18446744073709551615")));
	BOOST_TEST(String((RFLOAT)-3.14f) == String(RTXT("-3.14")));
	BOOST_TEST(String(-3.14) == String(RTXT("-3.14")));
	BOOST_TEST(String(true) == String(RTXT("1")));
	BOOST_TEST(String(false) == String(RTXT("")));
}


BOOST_AUTO_TEST_CASE(String_Conversions)
{
	BOOST_TEST(String((RINT8)-128).ToInt8() == -128);
	BOOST_TEST(String((RUINT8)255).ToUInt8() == 255);
	BOOST_TEST(String((RINT16)-32767).ToInt16() == -32767);
	BOOST_TEST(String((RUINT16)65535).ToUInt16() == 65535);
	BOOST_TEST(String((RINT32)-2147483647).ToInt32() == -2147483647);
	BOOST_TEST(String((RUINT32)4294967295).ToUInt32() == 4294967295);
	BOOST_TEST(String((RINT64)-9223372036854775807).ToInt64() == -9223372036854775807);
	BOOST_TEST(String((RUINT64)18446744073709551615).ToUInt64() == 18446744073709551615);
	BOOST_TEST(String((RFLOAT)-3.14f).ToFloat() == -3.14f);
	BOOST_TEST(String(-3.14).ToDouble() == -3.14);
	BOOST_TEST(String(1).ToBool() == true);
	BOOST_TEST(String().ToBool() == false);
	BOOST_TEST(String() == RTXT(""));
	BOOST_TEST(String() == "");
}
