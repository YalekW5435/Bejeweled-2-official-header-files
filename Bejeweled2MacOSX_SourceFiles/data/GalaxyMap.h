#ifndef __GALAXYMAP_H__#define __GALAXYMAP_H__#include "../SexyAppFramework/Widget.h"#include "../SexyAppFramework/Point.h"#include "../SexyAppFramework/ButtonListener.h"namespace Sexy{class WinDMApp;class PodButton;class MemoryImage;class GalaxyMoon{public:	MemoryImage*			mImage;		float					mHilitePct;	bool					mSolved;};typedef std::vector<GalaxyMoon> GalaxyMoonVector;class GalaxyPlanet{public:		bool					mIsSun;	int						mMapX;	int						mMapY;	MemoryImage*			mImage;	bool					mAvailable;	bool					mSolved;		bool					mFullySolved;	GalaxyMoonVector		mGalaxyMoonVector;public:	IntPoint					GetMoonPos(int theMoonNum);};typedef std::vector<GalaxyPlanet> GalaxyPlanetVector;class GalaxyMap : public Widget, ButtonListener{public:		WinDMApp*				mApp;	PodButton*				mWarpButton;	PodButton*				mCloseButton;	GalaxyPlanetVector		mGalaxyPlanetVector;		int						mBoard[8][8];	int						mSelectedMoon;	bool					mSettingUp;	std::string				mPlanetName;	std::string				mMoonName;	std::string				mDescription;	MemoryImage*			mMapImage;	MemoryImage*			mTopFontGlowImage;	MemoryImage*			mPlanetFontGlowImage;	MemoryImage*			mMoonFontGlowImage;protected:			void					LoadPuzzleData(int thePuzzleNum);	int						GetMoonAt(int x, int y);	int						GetPlanetAt(int x, int y);	void					Warp();	void					Cleanup();		void					CreateFontGlowImages();public:	GalaxyMap(WinDMApp* theApp);	virtual ~GalaxyMap();		static void				SetupStub(void* theParam);	void					StartSetup();	virtual void			MouseMove(int x, int y);	virtual void			MouseLeave();	virtual void			MouseDown(int x, int y, int theClickCount);	virtual void			MouseUp(int x, int y, int theClickCount);	virtual void			MouseDrag(int x, int y);	virtual void			KeyChar(char theChar);	virtual void			Update();		virtual	void			Draw(Graphics* g);		virtual void			AddedToManager(WidgetManager* theWidgetManager);	virtual void			RemovedFromManager(WidgetManager* theWidgetManager);	virtual void			Resize(int theX, int theY, int theWidth, int theHeight);		virtual void			ButtonPress(int theId);	virtual void			ButtonDepress(int theId);				void					Setup();};}#endif //__GALAXYMAP_H__