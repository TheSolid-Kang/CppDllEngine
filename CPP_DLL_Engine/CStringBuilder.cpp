#include "pch.h"
#include "CStringBuilder.h"



CStringBuilder* CreateStringBuilder()
{
	return new CStringBuilder();
}

void DeleteStringBuilder(CStringBuilder* _obj)
{
	delete _obj;
}

CStringBuilder& Append(CStringBuilder* const _obj, const TString& _str) {
	return (*_obj).Append(_str);
}

CStringBuilder& AppendLine(CStringBuilder* const _obj, const TString& _str) {
	return (*_obj).Append(_str + _T("\n"));
}

const TString& ToString(CStringBuilder* const _obj) {
	return (*_obj).ToString();
}

void Clear(CStringBuilder* const _obj) {
	(*_obj).Clear();
}


/*

CStringBuilder& CStringBuilder::Append(const TString& str)
{
	scratch.append(str);
	if (scratch.size() > ScratchSize) {
		main.append(scratch);
		scratch.resize(0);
	}
	return *this;
}

CStringBuilder& CStringBuilder::AppendLine(const TString& str)
{
	Append(str);
	Append(_T("\n"));
	return *this;
}

const TString& CStringBuilder::ToString()
{
	if (scratch.size() > 0) {
		main.append(scratch);
		scratch.resize(0);
	}
	return main;
}

void CStringBuilder::Clear()
{
	main.resize(0);
	scratch.resize(0);
}*/