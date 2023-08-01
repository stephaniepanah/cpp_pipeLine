/**
	@file PipeSegmentBaseAdapter.h
	@brief The PipeSegmentBaseAdapter class header file.

	@datecreated January 13, 2006

	@version 0.1

	@author
		- Patrick McMichael

	@license

	This program is released to the public domain by GATS, Inc.
	(www.gats-inc.com) subject to the following conditions.  It is
	provided "AS IS" without any warranty expressed or implied,
	including the warranty of non-infringement and the implied
	warranties of merchantability and fitness for a particular
	purpose.  GATS will not be liable for any loss or damage
	incurred as a result of using the software.  In no event will
	GATS be liable for any special, indirect or consequential
	damages or lost profits, or for any third party claims of any
	kind.  By installing, using or copying this software you agree
	to accept these terms and conditions.  Any other use is
	expressly forbidden.

	@see	PipeSegmentBaseAdapter
	@bug	None known

*/

#ifndef PIPESEGMENTBASEADAPTER_H
#define PIPESEGMENTBASEADAPTER_H

#include "IPipeSegmentBase.h"

namespace PipeLineProcessing
{

class PipeSegmentBaseAdapter : public PipeLineProcessing::IPipeSegmentBase
{
protected:
	PipeSegmentBaseAdapter() {};

	virtual bool addOutputHandler(IPipeSegmentBase *output) { return true; };
	virtual bool removeOutputHandler(IPipeSegmentBase *output) { return true; };
	virtual bool removeAllOutputHandlers() { return true; };

public:

	virtual ~PipeSegmentBaseAdapter() {};
};

}

#endif /*PIPESEGMENTBASEADAPTER_H*/
