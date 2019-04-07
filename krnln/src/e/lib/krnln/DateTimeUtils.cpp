#include "DateTimeUtils.h"
#include <Windows.h>
#include <sstream>
e::system::string e::lib::krnln::DateTimeUtils::DateTimeToString(e::system::datetime value, std::optional<int> mode)
{
	bool convertDate, convertTime;
	switch (mode.value_or(ConvertDateTime))
	{
	case ConvertDate:
		convertDate = true;
		convertTime = false;
		break;
	case ConvertTime:
		convertDate = false;
		convertTime = true;
		break;
	default:
		convertDate = convertTime = true;
		break;
	}

	std::stringstream s;
	SYSTEMTIME info;
	VariantTimeToSystemTime(value.value, &info);
	if (convertDate)
	{
		s << info.wYear;
		s << "��";
		s << info.wMonth;
		s << "��";
		s << info.wDay;
		s << "��";
	}
	if (convertTime && (info.wHour | info.wMinute | info.wDay))
	{
		s << info.wHour;
		s << "ʱ";
		s << info.wMinute;
		s << "��";
		s << info.wDay;
		s << "��";
	}
	return e::system::string(s.str().c_str());
}

e::system::datetime e::lib::krnln::DateTimeUtils::Now()
{
	SYSTEMTIME info;
	e::system::datetime result;
	GetLocalTime(&info);
	SystemTimeToVariantTime(&info, &result.value);
	return result;
}
