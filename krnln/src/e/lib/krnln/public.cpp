﻿#include "public.h"
e::system::any e::lib::krnln::GetDataFromBin(const e::system::bin& from, int32_t type, std::optional<std::reference_wrapper<int32_t>> pos)
{
	int realPos = pos.has_value() ? pos.value().get() : 1;
	e::system::any result;
	auto size = from.GetSize();
	switch (type)
	{
	case constant::UInt8Type:
		if (realPos > 0 && realPos + sizeof(uint8_t) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<uint8_t*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(uint8_t(0));
		}
		realPos += sizeof(uint8_t);
		break;
	case constant::Int16Type:
		if (realPos > 0 && realPos + sizeof(int16_t) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<int16_t*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(int16_t(0));
		}
		realPos += sizeof(int16_t);
		break;
	case constant::Int32Type:
		if (realPos > 0 && realPos + sizeof(int32_t) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<int32_t*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(int32_t(0));
		}
		realPos += sizeof(int32_t);
		break;
	case constant::Int64Type:
		if (realPos > 0 && realPos + sizeof(int64_t) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<int64_t*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(int64_t(0));
		}
		realPos += sizeof(int64_t);
		break;
	case constant::FloatType:
		if (realPos > 0 && realPos + sizeof(float) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<float*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(float(0));
		}
		realPos += sizeof(float);
		break;
	case constant::DoubleType:
		if (realPos > 0 && realPos + sizeof(double) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<double*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(double(0));
		}
		realPos += sizeof(double);
		break;
	case constant::BoolType:
		if (realPos > 0 && realPos + sizeof(int32_t) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<int32_t*>(&from.At(realPos)) ? true : false);
		}
		else
		{
			result = e::system::any(false);
		}
		realPos += sizeof(int32_t);
		break;
	case constant::DateTimeType:
		if (realPos > 0 && realPos + sizeof(e::system::datetime) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<e::system::datetime*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(e::system::datetime(0));
		}
		realPos += sizeof(e::system::datetime);
		break;
	case constant::MethodPtrType:
		if (realPos > 0 && realPos + sizeof(e::system::methodptr) - 1 <= size)
		{
			result = e::system::any(*reinterpret_cast<e::system::methodptr*>(&from.At(realPos)));
		}
		else
		{
			result = e::system::any(e::system::methodptr());
		}
		realPos += sizeof(e::system::methodptr);
		break;
	case constant::StringType:
		if (realPos > 0 && realPos <= int32_t(size))
		{
			const char* startPtr = reinterpret_cast<const char*>(&from.At(realPos));
			size_t strSize = size - realPos + 1;
			const char* endPtr = reinterpret_cast<const char*>(std::memchr(startPtr, 0, strSize));
			if (endPtr == nullptr)
			{
				realPos = -1;
				e::system::string tempStrResult(strSize);
				std::memcpy(tempStrResult.c_str(), startPtr, strSize);
				tempStrResult.c_str()[strSize] = '\0';
				result = e::system::any(tempStrResult);
			}
			else
			{
				strSize = reinterpret_cast<intptr_t>(endPtr) - reinterpret_cast<intptr_t>(startPtr);
				realPos += (int)strSize;
				e::system::string tempStrResult(strSize);
				std::memcpy(tempStrResult.c_str(), startPtr, strSize);
				result = e::system::any(tempStrResult);
			}
		}
		else
		{
			result = e::system::any(e::system::string());
		}
		break;
	default:
		break;
	}
	if (realPos > int32_t(size))
	{
		realPos = -1;
	}
	if (pos.has_value())
	{
		pos.value() = realPos;
	}
	return result;
}