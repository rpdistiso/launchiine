/****************************************************************************
 * Resource files.
 * This file is generated automatically.
 * Includes 11 files.
 *
 * NOTE:
 * Any manual modification of this file will be overwriten by the generation.
 ****************************************************************************/
#ifndef _FILELIST_H_
#define _FILELIST_H_

typedef struct _RecourceFile
{
	const char          *filename;
	const unsigned char *DefaultFile;
	const unsigned int  &DefaultFileSize;
	unsigned char	    *CustomFile;
	unsigned int        CustomFileSize;
} RecourceFile;

#include "bgMusic_ogg.h"
#include "bootSound_mp3.h"
#include "button_click_mp3.h"
#include "font_ttf.h"
#include "iconEmpty_png.h"
#include "layoutSwitchButton_png.h"
#include "leftArrow_png.h"
#include "noGameIcon_png.h"
#include "rightArrow_png.h"
#include "settingsButton_png.h"
#include "settings_click_2_mp3.h"

static RecourceFile RecourceList[] =
{
	{"bgMusic.ogg", bgMusic_ogg, bgMusic_ogg_size, NULL, 0},
	{"bootSound.mp3", bootSound_mp3, bootSound_mp3_size, NULL, 0},
	{"button_click.mp3", button_click_mp3, button_click_mp3_size, NULL, 0},
	{"font.ttf", font_ttf, font_ttf_size, NULL, 0},
	{"iconEmpty.png", iconEmpty_png, iconEmpty_png_size, NULL, 0},
	{"layoutSwitchButton.png", layoutSwitchButton_png, layoutSwitchButton_png_size, NULL, 0},
	{"leftArrow.png", leftArrow_png, leftArrow_png_size, NULL, 0},
	{"noGameIcon.png", noGameIcon_png, noGameIcon_png_size, NULL, 0},
	{"rightArrow.png", rightArrow_png, rightArrow_png_size, NULL, 0},
	{"settingsButton.png", settingsButton_png, settingsButton_png_size, NULL, 0},
	{"settings_click_2.mp3", settings_click_2_mp3, settings_click_2_mp3_size, NULL, 0},
	{NULL, NULL, 0, NULL, 0}
};

#endif
