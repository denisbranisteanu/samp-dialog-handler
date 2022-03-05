#include <a_samp>
#include <dialog-handler>

public OnPlayerText(playerid, text[])
{
	if(!strcmp(text, "msgbox", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_MSGBOX, "Caption", "Info %d\n\tInfo %s", "Button 1", "Button 2", 69, "Marcel");
	}

	if(!strcmp(text, "input", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_INPUT, "Caption", "Enter information below %s:", "Button 1", "Button 2", "the circle");
	}

	if(!strcmp(text, "list", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_LIST, "Caption", "Item %d\n{FFFF00}Item %d\nItem %d", "Button 1", "Button 2", 1, 2, 3);
	}

	if(!strcmp(text, "password", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_PASSWORD, "Caption", "%s", "Button 1", "Button 2", "parola baiatuu");
	}

	if(!strcmp(text, "tablist", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_TABLIST, "Caption",
			"Deagle\t$5000\t100\n\
			{FF0000}Sawnoff\t{33AA33}$5000\t100\n\
			Pistol\t$1000\t50\n\
			%s\t$%d\t%d",
			"Button 1", "Button 2", "puli", random(10), random(10));
	}

	if(!strcmp(text, "tablistheaders", false))
	{
		return DisplayDialog(playerid, dialogupulii, DIALOG_STYLE_TABLIST_HEADERS, "Caption",
			"Header 1\tHeader 2\tHeader 3\n\
			Item 1 Column 1\tItem 1 Column 2\tItem 1 Column 3\n\
			{FF0000}Item 2 Column 1\t{33AA33}Item 2 Column 2\tItem 2 Column%d 3",
			"Button 1", "Button 2", 69);
	}

	if(!strcmp(text, "close", false))
	{
		return HideDialog(playerid);
	}

	if(!strcmp(text, "check", false))
	{
		return SendClientMessage(playerid, -1, IsDialogDisplayed(playerid) ? "Dialogul este pe ecran." : "Dialogul nu este pe ecran.");
	}
	return 1;
}

Dialog:dialogupulii(playerid, response, listitem, inputtext[])
{
	return printf("playerid = %d, response = %d, listitem = %d, inputtext = %s", playerid, response, listitem, inputtext);
}

main() {
}