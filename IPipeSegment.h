/**
	@file IPipeSegment.h
	@brief The IPipeSegment class header file.

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

	@see	IPipeSegment
	@bug	None known

*/

#ifndef IPIPESEGMENT_H
#define IPIPESEGMENT_H

#include "IPipeSegmentBase.h"

namespace PipeLineProcessing
{
template<class OutputPipeType>
class IPipeSegment : public virtual PipeLineProcessing::IPipeSegmentBase
{
protected:

	/*  The following static data-members are included to force the user(s) of this
	 *  class to adhere to the following rule:
	 * 		ALL PIPE SEGMENTS MUST IMPLEMENT THE IPIPESEGMENTBASE INTERFACE
	 *  This method of compile-time detection of illegal template parameter types
	 *  was pilfered from the following article/website:
	 * 		http://www.accu-usa.org/2000-09.html
	*/
	const static IPipeSegmentBase* const OutputPipeType_Substitutable;		//examine the end of this file for details
	const static unsigned int OutputPipeType_Not_Void = (unsigned int)sizeof(OutputPipeType); //illegal if OutputPipeSegmentType is void

	//These methods are inherited from the IPipeSegmentBase interface
	virtual bool addOutputHandler(IPipeSegmentBase *output)=0;
	virtual bool removeOutputHandler(IPipeSegmentBase *output)=0;
	virtual bool removeAllOutputHandlers()=0;

public:

	virtual IPipeSegment<OutputPipeType> *connectTo(OutputPipeType *output)=0;
	virtual IPipeSegment<OutputPipeType> *disconnectFrom(OutputPipeType *output)=0;
	virtual void disconnectFromAll()=0;

	virtual void operator+=(OutputPipeType *output)=0;
	virtual void operator-=(OutputPipeType *output)=0;

	virtual void operator+=(OutputPipeType &output)=0;
	virtual void operator-=(OutputPipeType &output)=0;

	virtual ~IPipeSegment() {};
};

//This line does a compile-time check that the OutputPipeType template parameter
//is an IPipeSegmentBase type.  It performs this check by attempting to cast a pointer
//to an OutputPipeType as a pointer to an IPipeSegmentBase.  If you are very
//clever you will realize that this would not fail with an OutputPipeType template
//parameter of 'void'.  This is checked inline by the OutputPipeType_Not_Void static
//data member in the IPipeSegment class header file (above).
template<class OutputPipeType>
const IPipeSegmentBase* const IPipeSegment<OutputPipeType>::OutputPipeType_Substitutable = (const OutputPipeType*) 0;

}

#endif /*IPIPESEGMENT_H*/
