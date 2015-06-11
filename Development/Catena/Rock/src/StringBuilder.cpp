
#include "Rock_Std.h"
#include "Rock_StringBuilder.h"

using namespace Rock;

StringBuilder::StringBuilder() {

}

StringBuilder::StringBuilder(String const& s) {

}

RUINT StringBuilder::GetLength() const {
	return m_nLength;
}

StringBuilder& StringBuilder::Append(String const& s) {
	m_lData.push_back(s);
	m_nLength += s.GetLength();
	return *this;
}

RBOOL StringBuilder::operator==(StringBuilder const& sb) const {
	if (m_nLength != sb.m_nLength || m_lData.size() != sb.m_lData.size())
		return false;

	t_container::const_iterator it0 = m_lData.begin;
	t_container::const_iterator it1 = sb.m_lData.begin;
	for (; it0 < m_lData.end(); ++it0, ++it1)
		if (*it0 != *it1)
			return false;

	return true;
}

String StringBuilder::ToString() const {
	String result;
	// reserve space in 'result'

	for (t_container::const_iterator it = m_lData.begin(); it != m_lData.end(); ++it) {
		result += *it;
	}

	return result;
}