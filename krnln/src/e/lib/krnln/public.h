#pragma once
#include <e/system/basic_type.h>
#include <e/system/func.h>
#include <iostream>
#include "Converter.h"
#include "Operator/Operator.h"
#include "DateTimeUtils.h"
#include "ArrayUtils.h"
#include "TextUtils.h"
#include "BinUtils.h"

namespace e
{
	namespace lib
	{
		namespace krnln
		{
			namespace constant
			{
				const e::system::string NewLine("\r\n");

				const int32_t StdOut(1);
				const int32_t StdErr(2);

				const int32_t UInt8Type(1);
				const int32_t Int16Type(2);
				const int32_t Int32Type(3);
				const int32_t Int64Type(4);
				const int32_t FloatType(5);
				const int32_t DoubleType(6);
				const int32_t BoolType(7);
				const int32_t DateTimeType(8);
				const int32_t MethodPtrType(9);
				const int32_t StringType(10);
			}
			inline void Print(std::optional<int32_t> �������)
			{
				return;
			}
			template<class T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0> inline void Print(std::optional<int32_t> �������, T ���������)
			{
				std::ostream& out = �������.value_or(constant::StdOut) == constant::StdOut ? std::cout : std::cerr;
				out << ���������;
			}
			inline void Print(std::optional<int32_t> �������, bool ���������)
			{
				std::ostream& out = �������.value_or(constant::StdOut) == constant::StdOut ? std::cout : std::cerr;
				out << (��������� ? "��" : "��");
			}
			inline void Print(std::optional<int32_t> �������, const e::system::string& ���������)
			{
				std::ostream& out = �������.value_or(constant::StdOut) == constant::StdOut ? std::cout : std::cerr;
				out << ���������.c_str();
			}
			inline void Print(std::optional<int32_t> �������, e::system::datetime ���������)
			{
				std::ostream& out = �������.value_or(constant::StdOut) == constant::StdOut ? std::cout : std::cerr;
				out << "e::system::datetime(" << ���������.value << ")";
			}
			inline void Print(std::optional<int32_t> �������, const e::system::any& ���������)
			{
				if (���������.type() == typeid(int32_t))
				{
					Print(�������, ���������.cast<int32_t>());
					return;
				}
				if (���������.type() == typeid(uint8_t))
				{
					Print(�������, ���������.cast<uint8_t>());
					return;
				}
				if (���������.type() == typeid(int16_t))
				{
					Print(�������, ���������.cast<int16_t>());
					return;
				}
				if (���������.type() == typeid(int64_t))
				{
					Print(�������, ���������.cast<int64_t>());
					return;
				}
				if (���������.type() == typeid(double))
				{
					Print(�������, ���������.cast<double>());
					return;
				}
				if (���������.type() == typeid(float))
				{
					Print(�������, ���������.cast<float>());
					return;
				}
				if (���������.type() == typeid(bool))
				{
					Print(�������, ���������.cast<bool>());
					return;
				}
				if (���������.type() == typeid(e::system::string))
				{
					Print(�������, ���������.cast<e::system::string>());
					return;
				}
				Print(�������, ���������.cast<e::system::datetime>());
			}
			template <typename Arg1, typename Arg2, typename ... MoreArgs> void Print(std::optional<int32_t> �������, const Arg1& arg1, const Arg2& arg2, const MoreArgs&... moreArgs)
			{
				int dummy[] = { 
					(Print(�������, arg1), 0),
					(Print(�������, arg2), 0),
					(Print(�������, moreArgs), 0)...
				};
			}
			e::system::string Input(std::optional<bool> �Ƿ���� = std::nullopt);
			e::system::any GetDataFromBin(const e::system::bin& from, int32_t type, std::optional<std::reference_wrapper<int32_t>> pos = std::nullopt);
		}
	}
}