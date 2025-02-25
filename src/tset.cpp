// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	TBitField temp(this->BitField);
	return temp;
	//return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
	//return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet& s) // присваивание
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;
}

int TSet::operator==(const TSet& s) const // сравнение
{
	return BitField == s.BitField;
	//return 0;
}

int TSet::operator!=(const TSet& s) const // сравнение
{
	return BitField != s.BitField;
  //return 0;
}

TSet TSet::operator+(const TSet& s) // объединение
{
	TSet temp(BitField | s.BitField);
	return temp;
  //return TSet(0);
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	if (Elem > BitField.GetLength())
	{
		throw 'E>L';
	}
	TSet tmp(BitField);
	tmp.InsElem(Elem);
	return tmp;
  //return TSet(0);
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet tmp(MaxPower);
	tmp.DelElem(Elem);
	return tmp;
  //return TSet(0);
}

TSet TSet::operator*(const TSet& s) // пересечение
{
	TSet tmp(BitField & s.BitField);
	return tmp;
  //return TSet(0);
}

TSet TSet::operator~(void) // дополнение
{
	TSet tmp(~BitField);
	return tmp;
  //return TSet(0);
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
	int i = 0;
	char c;
	do
	{
		istr >> c;
	} while (c != '{');
	do
	{
		istr >> i;
		s.InsElem(i);
		do
		{
			istr >> c;
		} while ((c == ',') && (c == '}'));
	} while (c != '}');
	return istr;
  //return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
	ostr << '{';
	for (int i = 0; i < s.GetMaxPower(); i++)
	{
		if (s.IsMember(i))
		{
			ostr << ' ' << i << ',';
		}
	}
	ostr << '}';
	return ostr;
	//return ostr;
}
