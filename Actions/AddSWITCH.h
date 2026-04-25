#ifndef _ADD_SWITCH_H
#define _ADD_SWITCH_H

#include "..\Actions\Action.h"
#include "..\Components\SWITCH.h"

class AddSWITCH : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	AddSWITCH(ApplicationManager* pApp);
	virtual ~AddSWITCH(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif