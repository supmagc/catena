
#include "Rock_Std.h"
#include "Rock_Functions.h"
#include "Rock_StringBuilder.h"

using namespace Rock;

StringBuilder::StringBuilder() : m_nLength(0) {

}

StringBuilder::StringBuilder(String const& s) {

}

StringBuilder& StringBuilder::Append(String const& s) {
	m_lData.push_back(s);
	m_nLength += s.GetLength();
	return *this;
}

RBOOL StringBuilder::operator==(StringBuilder const& sb) const {
	if (m_nLength != sb.m_nLength || m_lData.size() != sb.m_lData.size())
		return false;

	t_container::const_iterator it0 = m_lData.begin();
	t_container::const_iterator it1 = sb.m_lData.begin();
	for (; it0 < m_lData.end(); ++it0, ++it1)
		if (*it0 != *it1)
			return false;

	return true;
}

String StringBuilder::ToString() const {
	String result;
	result.m_nLength = m_nLength + 1;
	result.m_aData = new RCHAR[result.m_nLength];

	RINT nOffset = 0;
	for (t_container::const_iterator it = m_lData.begin(); it != m_lData.end(); ++it) {
		catMemCopy(it->m_aData, &(result.m_aData[nOffset]), it->GetLength());
		nOffset += it->GetLength();
	}
	result.m_aData[nOffset] = 0;

	return result;
}