#ifndef __PODDIALOG_H__#define __PODDIALOG_H__#include "../SexyAppFramework/Dialog.h"#include "../SexyAppFramework/ButtonListener.h"namespace Sexy{class WinDMApp;class DialogButtonWidget;class MemoryImage;class PodDialogButton;class PodDialog : public Dialog{public:	WinDMApp*				mApp;	std::string				mPodTitle;	MemoryImage*			mTopFontGlowImage;	bool					mCancelled;	PodDialogButton*		mCancelButton;	bool					mIncludeCancelButton;	int						mTitleWidth;protected:	DialogButton*			MakePodButton(ButtonWidget* theWidget);	IntRect					GetHeaderRect();	void					DrawTopText(Graphics* g);	void					CreateFontGlowImages();public:	PodDialog(WinDMApp* theApp, int theId, bool isModal, const std::string& theDialogHeader, const std::string& theDialogLines, const std::string& theDialogFooter, int theButtonMode);	virtual ~PodDialog();	void					SetIncludeCancelButton(bool include);	virtual int				GetPreferredHeight(int theWidth);	virtual void			AddedToManager(WidgetManager* theWidgetManager);	virtual void			RemovedFromManager(WidgetManager* theWidgetManager);	virtual void			Resize(int theX, int theY, int theWidth, int theHeight);	virtual void			KeyDown(KeyCode theKey);	virtual void			Draw(Graphics* g);	void					DrawEditBox(Graphics* g, const IntRect& theRect);	virtual void			ButtonPress(int theId);	virtual void			ButtonDepress(int theId);};}#endif //__PODDIALOG_H__