#pragma once
#include <string>
#include <tchar.h>

#ifdef CPPDLLENGINE_EXPORTS
#define MYDLL_DECLSPEC extern "C" __declspec(dllexport)
#else
#define MYDLL_DECLSPEC extern "C" __declspec(dllimport)
#endif

#if UNICODE 
using TString = std::wstring;
#else
using TString = std::string;
#endif;

#define DEF_CAP 2048


class CStringBuilder {
private:
	TString main;
	TString scratch;

	const TString::size_type ScratchSize = 1024;   // 다른 임의의 숫자 넣어도 됨.

public:
	CStringBuilder& Append(const TString& str) {
		scratch.append(str);
		if (scratch.size() > ScratchSize) {
			main.append(scratch);
			scratch.resize(0);
		}
		return *this;
	}

	CStringBuilder& AppendLine(const TString& str) {
		Append(str);
		Append(_T("\n"));
		return *this;
	}

	const TString& ToString() {
		if (scratch.size() > 0) {
			main.append(scratch);
			scratch.resize(0);
		}
		return main;
	}

	void Clear() {
		main.resize(0);
		scratch.resize(0);
	}
};


MYDLL_DECLSPEC CStringBuilder* CreateStringBuilder();
MYDLL_DECLSPEC void DeleteStringBuilder(CStringBuilder* _obj);
MYDLL_DECLSPEC CStringBuilder& Append(CStringBuilder* const _obj, const TString& _str);
MYDLL_DECLSPEC CStringBuilder& AppendLine(CStringBuilder* const _obj, const TString& _str);
MYDLL_DECLSPEC const TString& ToString(CStringBuilder* const _obj);
MYDLL_DECLSPEC void Clear(CStringBuilder* const _obj);