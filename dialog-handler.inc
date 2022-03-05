//////////////////////////////////////////////////
//////    Definitions                      //////
////////////////////////////////////////////////

#if defined dialog_handler_included
	#endinput
#endif

#define dialog_handler_included

//////////////////////////////////////////////////
//////    Includes                         //////
////////////////////////////////////////////////

#include <YSI_Coding\y_hooks>
#include <YSI_Coding\y_va>

//////////////////////////////////////////////////
//////    Definitions                      //////
////////////////////////////////////////////////

#define Dialog:%0(%1) _dh_%0(%1); public _dh_%0(%1)
#define DisplayDialog(%0,%1, display_dialog(%0, #%1,
#define HideDialog(%0) hide_dialog(%0)

#if !defined DIALOG_HANDLER_MAIN_ID
	#define DIALOG_HANDLER_MAIN_ID 0x7ffd
#endif

#if !defined DIALOG_HANDLER_MAX_INFO
	#define DIALOG_HANDLER_MAX_INFO 0x1000
#endif

//////////////////////////////////////////////////
//////    Declarations                     //////
////////////////////////////////////////////////

static
	dialog_function[MAX_PLAYERS][32],
	useful_string[DIALOG_HANDLER_MAX_INFO + 1];

//////////////////////////////////////////////////
//////    Functions                        //////
////////////////////////////////////////////////

stock hide_dialog(const playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	dialog_function[playerid][0] = 0x00;
	return ShowPlayerDialog(playerid, -1, 0, " ", " ", " ", " ");
}

stock display_dialog(const playerid, const function[], const style, const caption[], const info[], const button1[], const button2[] = "", {Float, _}:...)
{
	if(info[0] == 0x00)
		return 0;

	if(numargs() < 7)
		return ShowPlayerDialog(playerid, DIALOG_HANDLER_MAIN_ID, style, caption, info, button1, button2);

	va_format(useful_string, sizeof useful_string, info, ___(7));
	format(dialog_function[playerid], 32, "_dh_%s", function);

	return ShowPlayerDialog(playerid, DIALOG_HANDLER_MAIN_ID, style, caption, useful_string, button1, button2);
}

stock bool:IsDialogDisplayed(const playerid)
	return IsPlayerConnected(playerid) && dialog_function[playerid][0] != 0x00;

//////////////////////////////////////////////////
//////    Hooked Callbacks                 //////
////////////////////////////////////////////////

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid != DIALOG_HANDLER_MAIN_ID)
		return 1;

	CallRemoteFunction(dialog_function[playerid], "ddds", playerid, response, listitem, !inputtext[0] ? "\1" : inputtext);
	return hide_dialog(playerid);
}