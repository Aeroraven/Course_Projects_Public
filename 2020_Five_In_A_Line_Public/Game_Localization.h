#pragma once
#include "Game_Common.h"
#include "Game_Algorithm.h"
class Game_Localization : public Game_Common {
private:
	int defaultArea = 0;
	int defaultCode = 0;
	map<int, string> dictionary[5];
	Game_Algorithm::Base64 b64;
public:
	//构造函数
	Game_Localization(int areaId = base_DefaultAreaId);

	//字符串显示设置
	enum lang_AreaIndex {
		AREA_ENGLISH_CN_GBK = 1,
		AREA_ENGLISH_UTF8 = 2,
		AREA_SIMPLIFIED_CHINESE_GBK = 3,
		AREA_SIMPLIFIED_CHINESE_UTF8 = 4,
	};
	enum lang_CodeIndex {
		ENCODING_GBK=2,
		ENCODING_UTF8=1,
	};
	enum lang_ExprIndex {
		SYMBOL_TABLE_LTCORNER = 100,
		SYMBOL_TABLE_RTCORNER = 101,
		SYMBOL_TABLE_LBCORNER = 102,
		SYMBOL_TABLE_RBCORNER = 103,
		SYMBOL_TABLE_CROSS = 104,
		SYMBOL_TABLE_LBRANCH = 105,
		SYMBOL_TABLE_RBRANCH = 106,
		SYMBOL_TABLE_TBRANCH = 107,
		SYMBOL_TABLE_BBRANCH = 108,
		SYMBOL_TABLE_HORZLINE = 109,
		SYMBOL_TABLE_VERTLINE = 110,

		SYMBOL_PRESET_RECT = 150,
		SYMBOL_PRESET_TRIANGLE = 151,
		SYMBOL_PRESET_CIRCLE = 152,
		SYMBOL_PRESET_DIAMOND = 153,
		SYMBOL_PRESET_FILLED_STAR = 154,
		SYMBOL_PRESET_HOLLOW_STAR = 155,
		SYMBOL_PRESET_CROSS_WITH_DOT = 156,

		SYMBOL_PRESET_SHARP = 170,
		SYMBOL_PRESET_ZERO = 171,
		SYMBOL_PRESET_AT = 172,
		SYMBOL_PRESET_ADD = 173,
		SYMBOL_PRESET_CROSS = 174,
		SYMBOL_PRESET_PERCENT = 175,
		SYMBOL_PRESET_DOLLAR = 176,

		SYMBOL_FWNUMBER_0 = 190,
		SYMBOL_FWNUMBER_1 = 191,
		SYMBOL_FWNUMBER_2 = 192,
		SYMBOL_FWNUMBER_3 = 193,
		SYMBOL_FWNUMBER_4 = 194,
		SYMBOL_FWNUMBER_5 = 195,
		SYMBOL_FWNUMBER_6 = 196,
		SYMBOL_FWNUMBER_7 = 197,
		SYMBOL_FWNUMBER_8 = 198,
		SYMBOL_FWNUMBER_9 = 199,

		SYMBOL_SQUARE_1 = 301,
		SYMBOL_SQUARE_2 = 302,

		SYMBOL_FWEXT_QUESTIONMARK = 400,

		TEXT_GUIDE_INPUT_PLACECOORD = 1001,
		TEXT_GUIDE_INPUT_MOVECOORD = 1002,
		TEXT_GUIDE_INPUT_PLAYERNAME = 1003,
		TEXT_GUIDE_INPUT_PLAYERORDER = 1004,
		TEXT_GUIDE_INPUT_SOURCECOORD_X = 1005,
		TEXT_GUIDE_INPUT_SOURCECOORD_Y = 1006,
		TEXT_GUIDE_INPUT_DESTCOORD_X = 1007,
		TEXT_GUIDE_INPUT_DESTCOORD_Y = 1008,
		TEXT_GUIDE_INPUT_CLICK_SOURCECOORD = 1009,
		TEXT_GUIDE_INPUT_CLICK_DESTCOORD = 1010,
		TEXT_GUIDE_INPUT_COORD = 1011,

		TEXT_LABEL_SCORES = 2001,
		TEXT_LABEL_REMOVE_CNT = 2002,
		TEXT_LABEL_REMOVE_SCORE = 2003,
		TEXT_LABEL_CURRENT_PLAYER = 2004,
		TEXT_LABEL_CURRENT_PLAYER_PLACEHOLDER = 2005,
		TEXT_LABEL_FINAL_SCORE = 2006,
		TEXT_LABEL_REMOVE_TOTALSCORE = 2007,
		TEXT_LABEL_TOTALMOVES = 2008,
		TEXT_LABEL_AUTHOR_NAME = 2009,
		TEXT_LABEL_AUTHOR_STUID = 2010,
		TEXT_LABEL_FORESEE = 2011,
		TEXT_LABEL_RESET_INPUT = 2012,
		TEXT_LABEL_SOURCE_CELL = 2013,
		TEXT_LABEL_SYSTEM_REMOVAL = 2014,

		TEXT_LABEL_ALERTTITLE_COMMON = 3000,
		TEXT_LABEL_ALERTTITLE_RESTART = 3001,
		TEXT_LABEL_ALERTTITLE_HELP = 3002,
		TEXT_LABEL_ALERTTITLE_EXIT = 3003,
		TEXT_LABEL_ALERTTITLE_ANTICHEAT = 3004,
		TEXT_LABEL_ALERTTITLE_SETTINGS = 3005,
		TEXT_LABEL_ALERTTITLE_SETTINGS_INPUTDEVICE = 3006,
		TEXT_LABEL_ALERTTITLE_SETTINGS_LANG = 3007,
		TEXT_LABEL_ALERTTITLE_SETTINGS_GAMERULE_FORESEE = 3008,
		TEXT_LABEL_ALERTTITLE_SETTINGS_GAMERULE_MOVELIMIT = 3009,
		TEXT_LABEL_ALERTTITLE_CREDIT = 3010,
		TEXT_LABEL_ALERTTITLE_LANGUAGE = 3011,
		TEXT_LABEL_ALERTTITLE_SETTINGS_GAMERULE_SHOWROUTE = 3012,
		
		TEXT_INFO_INVALID_MOVE_UNCONNECTED = 4001,
		TEXT_INFO_INVALID_MOVE_OCCUPIED = 4002,
		TEXT_INFO_INVALID_MOVE_EMPTY = 4003,
		TEXT_INFO_INVALID_MOVE_HEADER = 4000,

		TEXT_INFO_COMPLETE_OCCPUIED = 4100,
		TEXT_INFO_NEWBEADS_PLACED = 4201,
		TEXT_INFO_MOVE_SUCCESS = 4202,
		TEXT_INFO_PRESS_ANY_KEY_TO_CONTINUE = 4203,
		TEXT_INFO_PRESS_ENTER_TO_CONTINUE = 4204,
		TEXT_INFO_INVALID_COORD = 4205,
		TEXT_INFO_MOVE_WITHOUT_REMOVAL = 4206,
		TEXT_INFO_GAIN_ANOTHER_CHANCE = 4207,
		TEXT_INFO_GAME_RESTARTED = 4208,
		TEXT_INFO_INVALID_INPUT = 4209,
		TEXT_INFO_RESTARTING_CONFIRM = 4210,
		TEXT_INFO_CHEAT_DETECTED = 4211,
		TEXT_INFO_EXIT_CONFIRM = 4219,
		TEXT_INFO_KEYBOARD_UNSUPPORTED = 4212,
		TEXT_INFO_MOUSE_UNSUPPORTED = 4213,
		TEXT_INFO_MOVELIMIT_CONFIRM = 4214,
		TEXT_INFO_MOVELIMIT_CONFIRM_2 = 4224,
		TEXT_INFO_MOVELIMIT_DISABLED = 4215,
		TEXT_INFO_MOVELIMIT_ENABLED = 4216,
		TEXT_INFO_INPUTDEVICE_SWITCH_CONFIRM = 4217,
		TEXT_INFO_COMING_SOON = 4218,
		TEXT_INFO_FORESEE_CONFIRM = 4220,
		TEXT_INFO_GAME_STARTED = 4221,
		TEXT_INFO_MAINTITLE_OPTION_SWITCH = 4222,
		TEXT_INFO_LANG_SWITCH_A = 4223,
		TEXT_INFO_LANG_SWITCH_B = 4225,
		TEXT_INFO_DO_NOT_DISTRIBUTE = 4226,
        TEXT_INFO_OS_NOT_SUPPORTED = 4227,
		TEXT_INFO_SHOWROUTE_CONFIRM = 4228,
		TEXT_INFO_NOT_INPUTTED = 4229,
		TEXT_INFO_INPUT_RESET = 4230,
		TEXT_INFO_GAME_SAVED = 4231,
		TEXT_INFO_GAME_LOADED = 4232,
		TEXT_INFO_NO_AVAILABLE_MOVES = 4233,

		TEXT_OPTION_RESTART = 8000,
		TEXT_OPTION_EXIT = 8001,
		TEXT_OPTION_WITHDRAW = 8002,
		TEXT_OPTION_ABORT = 8003,
		TEXT_OPTION_SETTING = 8004,
		TEXT_OPTION_CREDIT = 8005,
		TEXT_OPTION_HELP = 8006,
		TEXT_OPTION_TITLESCENE = 8007,
		TEXT_OPTION_EXIT2 = 8008,
		TEXT_OPTION_OPERATION_DEVICE = 8009,
		TEXT_OPTION_OPERATION_DEVICE_KEYBOARD = 8010,
		TEXT_OPTION_OPERATION_DEVICE_MOUSE = 8011,
		TEXT_OPTION_LANGUAGE = 8012,
		TEXT_OPTION_LANGUAGE_ZHCN = 8013,
		TEXT_OPTION_LANGUAGE_ENUS = 8014,
		TEXT_OPTION_MAINTITLE_STARTGAME = 8015,
		TEXT_OPTION_MAINTITLE_AUTHOR = 8016,
		TEXT_OPTION_MAINTITLE_EXIT = 8017,
		TEXT_OPTION_LANGUAGE_ZHCN_GBK = 8018,
		TEXT_OPTION_LANGUAGE_ZHCN_UTF8 = 8019,
		TEXT_OPTION_LANGUAGE_ENUS_GBK = 8020,
		TEXT_OPTION_LANGUAGE_ENUS_UTF8 = 8021,
		TEXT_OPTION_MAINTITLE_LOAD = 8022,
		TEXT_OPTION_SAVE = 8023,


		TEXT_OPTION_GAMERULE_FORESEE = 8501,
		TEXT_OPTION_GAMERULE_MOVE_LIMIT = 8502,
		TEXT_OPTION_GAMERULE_SHOWROUTE = 8503,



		TEXT_OPTION_YES = 8900,
		TEXT_OPTION_NO = 8901,
		TEXT_OPTION_CLOSE = 8902,
		TEXT_OPTION_CANCEL = 8903,
		TEXT_OPTION_ON = 8904,
		TEXT_OPTION_OFF = 8905,
		TEXT_OPTION_KNOWN = 8906,


		TEXT_HELP_1 = 9001,
		TEXT_HELP_2 = 9002,
		TEXT_HELP_3 = 9003,
		TEXT_HELP_4 = 9004,
		TEXT_HELP_5 = 9005,
		TEXT_HELP_6 = 9006,
		TEXT_HELP_7 = 9007,
		TEXT_HELP_8 = 9008,
		TEXT_HELP_9 = 9009,
		TEXT_HELP_10 = 9010,
		TEXT_HELP_11 = 9011,

		TEXT_BORDERLINE_1 = 10001,
		TEXT_BORDERLINE_2 = 10002,
		TEXT_BORDERLINE_3 = 10003,

		//WITHOUT DEFINITION

		TEXT_EXCEPTHANDLE_HEADER = 15000,
		TEXT_EXCEPTHANDLE_SELECT_EXIT_AND_IGNORE = 15001,
		TEXT_EXCEPTHANDLE_SELECT_EXIT_ONLY = 15002,

		TEXT_EXCEPTION_FILEIO_INPUT_DENIED = 20001,
		TEXT_EXCEPTION_FILEIO_OUTPUT_DENIED = 20002,
		TEXT_EXCEPTION_FILEIO_INPUT_INVALID = 20003,
		TEXT_EXCEPTION_FILEIO_INPUT_HASH_CONFLICT = 20004,
		TEXT_EXCEPTION_FILEIO_INPUT_FAILED=20005,
		TEXT_EXCEPTION_FILEIO_OUTPUT_FAILED = 20006,
		TEXT_EXCEPTION_FILEIO_FILE_BROKEN = 20007,
		TEXT_EXCEPTION_FILEIO_SIGNATURE_CONFLICT = 20008,
		TEXT_EXCEPTION_FILEIO_VALIDATOR_CONFLICT = 20009,
		TEXT_EXCEPTION_FILEIO_GAMESETTINGS_CONFLICT = 20010,

		TEXT_EXCEPTION_CODEPAGE_NOT_SUPPORTED = 20100,
		TEXT_EXCEPTION_CODEPAGE_NOT_SUPPORTED_2 = 20101,
	};
	string lang_GetString(lang_ExprIndex stringIdx, bool useSetArea = true, int langArea = 1);
	int lang_GetDefaultArea();
	int lang_GetDefaultCode();
	void lang_Init(int areaId = base_DefaultAreaId);

	//字符串常量预设
	//void langPre_SetChineseS();
	void langPre_SetChineseS_b64_gbk();
	void langPre_SetChineseS_b64_utf8();
	void langPre_SetEnglish_b64_gbk();
	void langPre_SetEnglish_b64_utf8();
	void langPre_SetEnglish_common(int x);

	void langPre_SetSymbol_b64_gbk(int x);
	void langPre_SetSymbol_b64_utf8(int x);

	//其他
	

	//赋值重载
	Game_Localization operator =(const Game_Localization& x);
};

class Game_LocalizationGadget : public Game_Common {
public:
	class FwNumConversion {
	public:
		string Num2Fw(int x,int minDigit, Game_Localization* encodeSetting);
	};

};