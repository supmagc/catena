#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include "Rock.h"

using namespace Rock;
namespace data = boost::unit_test::data;

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

BOOST_AUTO_TEST_CASE(String_Equality)
{
	BOOST_TEST(String(RTXT("a")) == String(RTXT("a")));
	BOOST_TEST(String(RTXT("a")) != String(RTXT("b")));
}

BOOST_AUTO_TEST_CASE(String_SliftL)
{
	wstringstream wss;
	wss << String("azerty");
	BOOST_TEST(wcscmp(wss.str().c_str(), RTXT("azerty")) == 0);

	stringstream ss;
	ss << String("azerty");
	BOOST_TEST(strcmp(ss.str().c_str(), "azerty") == 0);
}

BOOST_AUTO_TEST_CASE(String_SliftR)
{
	String str;
	wstringstream wss;
	wss << RTXT("azerty");
	wss >> str;
	BOOST_TEST(str == String("azerty"));

	stringstream ss;
	ss << ("azerty");
	ss >> str;
	BOOST_TEST(str == String("azerty"));
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

BOOST_AUTO_TEST_CASE(String_CopyAssignment)
{
	String a("azerty");
	String b = a;
	BOOST_TEST(a == b);
}

BOOST_AUTO_TEST_CASE(String_CopyConstructor)
{
	String a("azerty");
	String b(a);
	BOOST_TEST(a == b);
}

unsigned int offsets[] = { 0, 2, 5 };
char const* subStrings[] = { "az", "er", "y" };

BOOST_DATA_TEST_CASE(String_SubString, data::make(offsets) ^ subStrings, offset, subStr)
{
	BOOST_TEST(String("azerty").SubString(offset, 2) == String(subStr));
}

char const* strings[] = { "", " ", "&", "-128", "-3.14", " azerty\t\n", "AzErTy" };
char const* stringsUpper[] = { "", " ", "&", "-128", "-3.14", " AZERTY\t\n", "AZERTY" };
char const* stringsLower[] = { "", " ", "&", "-128", "-3.14", " azerty\t\n", "azerty" };
char const* stringsTrim[] = { "", "", "&", "-128", "-3.14", "azerty", "AzErTy" };
RCHAR const* wstrings[] = { RTXT(""), RTXT(" "), RTXT("&"), RTXT("-128"), RTXT("-3.14"), RTXT(" azerty\t\n"), RTXT("AzErTy") };
unsigned int lengths[] = { 0, 1, 1, 4, 5, 9, 6 };

BOOST_DATA_TEST_CASE(String_GetLength, data::make(strings) ^ lengths, str, len)
{
	BOOST_TEST(String(str).GetLength() == len);
}

BOOST_DATA_TEST_CASE(String_GetData, data::make(strings) ^ wstrings, str, wstr)
{
	BOOST_TEST(wcscmp(String(str).GetData(), wstr) == 0);
}

BOOST_DATA_TEST_CASE(String_ToUpper, data::make(strings) ^ stringsUpper, str, strUpper)
{
	BOOST_TEST(String(str).ToUpper() == String(strUpper));
}

BOOST_DATA_TEST_CASE(String_ToLower, data::make(strings) ^ stringsLower, str, strLower)
{
	BOOST_TEST(String(str).ToLower() == String(strLower));
}

BOOST_DATA_TEST_CASE(String_Trim, data::make(strings) ^ stringsTrim, str, strTrim)
{
	BOOST_TEST(String(str).Trim() == String(strTrim));
}

BOOST_AUTO_TEST_CASE(String_BeginsWith)
{
	BOOST_TEST(String("azerty").BeginsWith("aze") == true);
	BOOST_TEST(String("azerty").BeginsWith("ze") == false);
}

BOOST_AUTO_TEST_CASE(String_EndsWith)
{
	BOOST_TEST(String("azerty").EndsWith("rty") == true);
	BOOST_TEST(String("azerty").EndsWith("rt") == false);
}

BOOST_AUTO_TEST_CASE(String_IndexOf)
{
	BOOST_TEST(String("azert").IndexOf("az") == 0);
	BOOST_TEST(String("azert").IndexOf('z') == 1);
	BOOST_TEST(String("azert").IndexOf(L't') == 4);
	BOOST_TEST(String("azert").IndexOf("y") == -1);
}

BOOST_AUTO_TEST_CASE(String_Replace)
{
	BOOST_TEST(String("azerty").Replace(String("vb"), String("ER")) == String("azerty"));
	BOOST_TEST(String("azer-erty").Replace(String("er"), String("ER")) == String("azER-ERty"));
	BOOST_TEST(String("azererty").Replace(String("er"), String("ER")) == String("azERERty"));
	BOOST_TEST(String("azerty").Replace(String("er"), String("ER")) == String("azERty"));
	BOOST_TEST(String("azerty").Replace(String("e"), String("ER")) == String("azERrty"));
	BOOST_TEST(String("azerty").Replace(String("er"), String("E")) == String("azEty"));
	BOOST_TEST(String("azerty").Replace("er", String("ER")) == String("azERty"));
	BOOST_TEST(String("azerty").Replace(String("er"), "ER") == String("azERty"));
	BOOST_TEST(String("azerty").Replace("er", "ER") == String("azERty"));
}

BOOST_AUTO_TEST_CASE(String_Append)
{
	BOOST_TEST(String("aze") + String("RTY") == String("azeRTY"));
}

BOOST_AUTO_TEST_CASE(String_Format)
{
	String format0 = String::Format(String("%i %c %g %s"), 12, L':', 3.14f, RTXT("min."));
	String format1 = String::Format(RTXT("%i %c %g %s"), 12, L':', 3.14f, RTXT("min."));
	String format2 = String::Format("%i %c %g %s", 12, ':', 3.14f, "min.");
	BOOST_TEST(format0 == String("12 : 3.14 min."));
	BOOST_TEST(format1 == String("12 : 3.14 min."));
	BOOST_TEST(format2 == String("12 : 3.14 min."));
}