#pragma once
#include "Header.h"

typedef enum {
	CL_BLACK,
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_PURPLE,
	CL_YELLOW,
	CL_WHITE,
	CL_LIGHT_BLACK,
	CL_LIGHT_BLUE,
	CL_LIGHT_GREEN,
	CL_LIGHT_CYAN,
	CL_LIGHT_RED,
	CL_LIGHT_PURPLE,
	CL_LIGHT_YELLOW,
	CL_LIGHT_WHITE,
	ר���� = 0,
	�����,
	��˨���,
	�������,
	�������,
	����������,
	ƨ����,
	�����,
	�����,
	������_�����,
	������_��˨���,
	������_�������,
	������_�������,
	������_����������,
	������_ƨ����,
	������_�����
} COLORS, �����;

void SetCursor(short int pnRow, short int pnCol);
void SetColor(int pnColor);
void SetColor(int pnColorBackground, int pnColorText);