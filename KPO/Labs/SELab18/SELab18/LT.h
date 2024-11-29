#pragma once

#define LEXEMA_FIXSIZE 1	//������������� ������ ������
#define LT_MAXSIZE 4096		//���� ���������� ����� � �������
#define LT_TI_NULLIDX 0xffffffff	//��� �������� ��
#define LEX_INTEGER		't'	//������� ��� integer
#define LEX_STRING		't'	//������� ��� string
#define LEX_LITERAL		'l'	//������� ��� ��������
#define LEX_ID			'i'	//������� ��� ��������������
#define LEX_FUNCTION	'f'	//������� ��� function
#define LEX_MAINFUNC	'm'	//������� ��� main
#define LEX_DECLARE		'd'	//������� ��� declare
#define LEX_RETURN		'r'	//return
#define LEX_PRINT		'p'	//print
#define LEX_SEMICOLON	';'	//;
#define LEX_COMMA		','	//,
#define LEX_LEFTBRACE	'{'	//{
#define LEX_RIGHTBRACE  '}'	//}
#define LEX_LEFTHESIS	'('	//(
#define LEX_RIGHTHESIS	')'	//)
#define LEX_PLUS		'v'	//+
#define LEX_MINUS		'v'	//-
#define LEX_MULTIPLICATION		'v'	//*
#define LEX_DIRSLASH	'v'	// /
#define LEX_EQUAL			'='	//=


namespace LT
{
	struct  Entry
	{
		char lexema[LEXEMA_FIXSIZE];
		int sn;
		int idxTI;
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);

	void Add(LexTable& lextable, Entry entry);

	Entry GetEntry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);

};