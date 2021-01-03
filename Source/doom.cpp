/**
 * @file doom.cpp
 *
 * Implementation of the map of the stars quest.
 */
#include "all.h"

DEVILUTION_BEGIN_NAMESPACE

int doom_quest_time;
int doom_stars_drawn;
BYTE *pDoomCel;
DIABOOL doomflag;
int DoomQuestState;

/*
void doom_reset_state()
{
    if (DoomQuestState <= 0) {
        DoomQuestState = 0;
    }
}

void doom_play_movie()
{
    if (DoomQuestState < 36001) {
        DoomQuestState++;
        if (DoomQuestState == 36001) {
            PlayInGameMovie("gendata\\doom.smk");
            DoomQuestState++;
        }
    }
}
*/

int doom_get_frame_from_time()
{
	if (DoomQuestState == 36001) {
		return 31;
	}

	return DoomQuestState / 1200;
}

void doom_cleanup()
{
	if (pDoomCel != NULL) {
		MemFreeDbg(pDoomCel);
		pDoomCel = NULL;
	}
}

static BOOLEAN doom_alloc_cel()
{
	doom_cleanup();
	pDoomCel = DiabloAllocPtr(0x39000);
	return pDoomCel ? TRUE : FALSE;
}

static BOOLEAN doom_load_graphics()
{
	BOOLEAN ret;

	ret = FALSE;
	strcpy(tempstr, "Items\\Map\\MapZtown.CEL");
	if (LoadFileWithMem(tempstr, pDoomCel))
		ret = TRUE;
	return ret;
}

void doom_init()
{
	if (doom_alloc_cel()) {
		doom_quest_time = doom_get_frame_from_time() == 31 ? 31 : 0;
		if (doom_load_graphics()) {
			doomflag = TRUE;
		} else {
			doom_close();
		}
	}
}

void doom_close()
{
#ifndef HELLFIRE
	if (doomflag) {
#endif
		doomflag = FALSE;
		doom_cleanup();
#ifndef HELLFIRE
	}
#endif
}

void doom_draw()
{
	if (!doomflag) {
		return;
	}
#ifndef HELLFIRE
	if (doom_quest_time != 31) {
		doom_stars_drawn++;
		if (doom_stars_drawn >= 5) {
			doom_stars_drawn = 0;
			doom_quest_time++;
			if (doom_quest_time > doom_get_frame_from_time()) {
				doom_quest_time = 0;
			}
			doom_load_graphics();
		}
	}
#endif

	CelDraw(PANEL_X, PANEL_Y - 1, pDoomCel, 1, 640);
}

DEVILUTION_END_NAMESPACE
