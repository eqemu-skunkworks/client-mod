/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "stdafx.h"
#include "MQ2Main.h"

#define EQCLASS_CALL(function,offset) __declspec(naked) function\
{\
	__asm{mov eax, offset};\
	__asm{jmp eax};\
}

EQCLASS_CALL(void CEverQuest::dsp_chat(char const *,int,bool),[EQADDR_DSPCHAT]);
/*
__declspec(naked) void CEverQuest::dsp_chat(char const *,int,bool)
{
	__asm{mov eax, [EQADDR_DSPCHAT]};
	__asm{jmp eax};
}
*/