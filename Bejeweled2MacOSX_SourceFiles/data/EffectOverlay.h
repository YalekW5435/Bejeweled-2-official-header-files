#ifndef __EFFECTOVERLAY_H__#define __EFFECTOVERLAY_H__#include "../SexyAppFramework/Widget.h"namespace Sexy{class WinDMApp;class MemoryImage;#define NUM_POINT_SETS 4enum{	TEXTSTATE_IDLE,	TEXTSTATE_IN,	TEXTSTATE_OUT};typedef std::vector<IntPoint> PointVector;typedef std::vector<std::string> StringVector;class TinyGem{public:	int						mType;	float					mX;	float					mY;	float					mVelY;	float					mDestY;};typedef std::vector<TinyGem> TinyGemVector;class Line{public:	int						mPointIdx1;	int						mPointIdx2;};typedef std::vector<Line> LineVector;typedef std::vector<int> IntVector;class Polygon{public:	Color					mColor;	IntVector				mPoints;};typedef std::vector<Polygon> PolygonVector;class EffectOverlay : public Widget{public:	enum	{		FACESTATE_NONE,		FACESTATE_BARS,		FACESTATE_GEMS,		FACESTATE_LINES,		FACESTATE_FLASH,		FACESTATE_FLASH_WHITE,		FACESTATE_TALK,		FACESTATE_FADE,		FACESTATE_HYPER_SWIRL,		FACESTATE_DONE	};public:	WinDMApp*				mApp;		int						mTextState;	MemoryImage*			mTextImage;		int						mTextWidth;	float					mTextFade;	float					mOverallScale;	float					mScale;	float					mScaleAdd;	float					mStrechiness;	float					mStrechinessAdd;	float					mRigidness;	float					mChunkSpacing;	int						mOutDelay;	int						mFadeDelay;	int						mShrinkDelay;	int						mStayDelay;	bool					mFirstDraw;	bool					mPortalOpening;	float					mPortalPercent;	int						mPortalDelay;	int						mFaceUpdateCnt;	int						mFaceAnimUpdateCnt;		PointVector				mFacePoints[NUM_POINT_SETS];	PointVector				mFacePointsFrom;	PointVector				mFaceCurPoints;	LineVector				mFaceLines;	PolygonVector			mFacePolygons;	TinyGemVector			mFaceTinyGemVector;	int						mFaceLastClickTick;	float					mFaceLinePct;	int						mFaceStateDelay;	float					mFaceFlashPct;		int						mFaceState;	float					mFaceHyperCubeX;	float					mFaceHyperCubeY;		float					mFaceHyperSwirlPct;	float					mFaceAlpha;	float					mFaceModePct;	int						mFaceFadeDelay;	int						mFaceBarSize;		StringVector			mCreditLines;public:	void					DoUpdate();	FPoint					InterpolatePointF(const IntPoint& thePoint1, const IntPoint& thePoint2, float theFactor);	IntPoint				InterpolatePoint(const FPoint& thePoint1, const FPoint& thePoint2, float theFactor);public:	EffectOverlay(WinDMApp* theApp);	virtual ~EffectOverlay();	virtual void			Update();	virtual void			Draw(Graphics* g);	void					DoPortal();	void					DoStrechyText(const std::string& theText, int theExtraDelay);	void					InitFace();	void					MouseDown(int x, int y, int theBtnNum, int theClickCount);};}#endif //__EFFECTOVERLAY_H__