#ifndef __PROFILE_H__#define __PROFILE_H__#include "../SexyAppFramework/Common.h"#include "WinDMApp.h"namespace Sexy{typedef std::vector<uchar> ByteVector;class PuzzleProgress{public:	std::string				mPackName;	ByteVector				mPuzzleStateVector;	int						mLastPuzzleNum;};typedef std::map<std::string, PuzzleProgress> PuzzlesProgressMap;typedef std::vector<std::string> StringVector;class Profile{public:	enum	{		HINT_BAD_MOVE,		HINT_PIECE_POWER_GEM,		HINT_PIECE_HYPER_CUBE,		HINT_HELP_SCREEN,		HINT_PUZZLE_END_HINT,		HINT_TIMER	};public:	StringVector			mProfileList;	std::string				mProfileName;	PuzzlesProgressMap		mPuzzlesProgressMap;	std::string				mLastPuzzlePackName;		bool					mIsNew;	int						mBestScore;		int						mSecondsPlayed;	int						mPuzzlesSolved;	int						mGemsCleared;		int						mBiggestCascade;	int						mBiggestCombo;	int						mNumPowerGemsCreated;	int						mNumHyperGemsCreated;	bool					mRandomBackdrops;	int						mNumDefaultPuzzlesSolved;	int						mHighestLevel[MODE_MAX];		ulong					mHintDisableFlags;protected:	bool					LoadProfileHelper(const std::string& theProfileName);public:	bool					ListAddName(const std::string& theName);	bool					ListRemoveName(const std::string& theName);	public:	Profile();	void					ReadProfileList();	void					WriteProfileList();	StringVector&			GetProfileList();	bool					RenameProfile(const std::string& theProfileName);	bool					LoadProfile(const std::string& theProfileName);	bool					CreateProfile(const std::string& theProfileName);	bool					RenameProfile(const std::string& theOldProfileName, const std::string& theNewProfileName);	bool					DeleteProfile(const std::string& theProfileName);	bool					WriteProfile();	bool					GetAnyProfile();	void					SelectPuzzlePack(const std::string& thePackName);	bool					GetProfileDir(FSRef *profileFolder, const char *profileName = NULL);		PuzzleProgress*			GetPuzzleProgress();		int						GetPuzzleNum();	bool					WantsHint(int theHintType);	void					DisableHint(int theHintType);	bool					IsModeUnlocked(int theModeNum);};}#endif //__PROFILE_H__