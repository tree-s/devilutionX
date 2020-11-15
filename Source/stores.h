/**
 * @file stores.h
 *
 * Interface of functionality for stores and towner dialogs.
 */
#ifndef __STORES_H__
#define __STORES_H__

DEVILUTION_BEGIN_NAMESPACE

#ifdef __cplusplus
extern "C" {
#endif

extern ItemStruct boyitem;
extern ItemStruct premiumitem[SMITH_PREMIUM_ITEMS];
extern BYTE *pSTextBoxCels;
extern int premiumlevel;
extern int talker;
#ifdef HELLFIRE
extern ItemStruct witchitem[25];
#else
extern ItemStruct witchitem[20];
#endif
extern int numpremium;
extern ItemStruct healitem[20];
extern ItemStruct golditem;
extern BYTE *pSTextSlidCels;
extern BYTE *pSPentSpn2Cels;
extern int boylevel;
extern ItemStruct smithitem[SMITH_ITEMS];
extern int stextdown;
extern char stextflag;

void InitStores();
int PentSpn2Spin();
void SetupTownStores();
void FreeStoreMem();
void PrintSString(int x, int y, BOOL cjustflag, const char *str, char col, int val);
void DrawSLine(int y);
void DrawSTextHelp();
void ClearSText(int s, int e);
void StartStore(char s);
void DrawSText();
void STextESC();
void STextUp();
void STextDown();
void STextPrior();
void STextNext();
void SetGoldCurs(int pnum, int i);
void SetSpdbarGoldCurs(int pnum, int i);
void TakePlrsMoney(int cost);
void STextEnter();
void CheckStoreBtn();
void ReleaseStoreBtn();

/* rdata */

#ifdef __cplusplus
}
#endif

DEVILUTION_END_NAMESPACE

#endif /* __STORES_H__ */
