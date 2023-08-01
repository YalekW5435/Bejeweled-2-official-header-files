#ifndef __PUZZLEPACKSELECTOR_H__#define __PUZZLEPACKSELECTOR_H__#include "PodDialog.h"#include "../SexyAppFramework/ListListener.h"namespace Sexy{class DialogButton;class ListWidget;class ScrollbarWidget;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////class PuzzlePackSelector : public PodDialog, public ListListener{protected:	ListWidget *mPackList;	ScrollbarWidget *mScrollbarWidget;	public:	PuzzlePackSelector();	virtual ~PuzzlePackSelector();	virtual void Resize(int theX, int theY, int theWidth, int theHeight);	virtual int	GetPreferredHeight(int theWidth);	virtual void AddedToManager(WidgetManager *theWidgetManager);	virtual void RemovedFromManager(WidgetManager *theWidgetManager);	virtual void ListClicked(int theId, int theIdx, int theClickCount);	virtual void ButtonDepress(int theId);		std::string GetSelName();};} // namespace Sexy#endif // __PUZZLEPACKSELECTOR_H__