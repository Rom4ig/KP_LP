#pragma once
#include "IdTable.h"
#include "LexTable.h"
#include "In.h"
#include "FST.h"
#include "Log.h"

namespace LeX
{
	struct LEX  //��������� ��� ������
	{
		LT::LexTable Lextable; //������� ������
		IT::IdTable	IDtable; //������� ���������������
	};
	struct Graph //��������� ��� �����
	{
		char Lexema;  //������ �������
		FST::FST graph; //���� 
	};
	LEX INITLEX(In::IN, Log::LOG &log); //�������� �����.����
}