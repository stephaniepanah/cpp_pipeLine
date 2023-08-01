/**
	@file PipeSegment.h
	@brief The PipeSegment class header file.

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

	@see	PipeSegment
	@bug	None known

*/

#ifndef PIPESEGMENT_H
#define PIPESEGMENT_H

//STL Headers
#include <vector>

//GATS POC Headers
#include "IPipeSegment.h"

namespace PipeLineProcessing
{

template<class OutputPipeType>
class PipeSegment : public PipeLineProcessing::IPipeSegment<OutputPipeType>
{

protected:
	/*  The following static data-members are included to force the user(s) of this
	 *  class to adhere to the following rule:
	 * 		ALL PIPE SEGMENTS MUST IMPLEMENT AT LEAST THE IPIPESEGMENTBASE INTERFACE
	 *  This method of compile-time detection of illegal template parameter types
	 *  was pilfered from the following article/website:
	 * 		http://www.accu-usa.org/2000-09.html
	*/
	const static IPipeSegmentBase* const OutputPipeType_Substitutable;
		//examine end-of-file for details
	const static unsigned int OutputPipeType_Not_Void = (unsigned int)sizeof(OutputPipeType);
		//illegal if OutputPipeSegmentType is void

	/* @brief These data structures are used to hold the output handlers */
	std::vector<IPipeSegmentBase *> theOutput;

	/* @brief Method to add an output handler to the collection of output handlers - inherited from IPipeSegmentBase */
	virtual bool addOutputHandler(IPipeSegmentBase *output)
		{ if (output == NULL || output == this) return false;	//we can't output to ourselves (infinite recursion), or output to NULL!
		  for (int i=0; i < (int)theOutput.size(); i++) {
			if(theOutput[i] == output) return true; //The output handler is already registered with us!
		  }
		  theOutput.push_back(output);
		  return true;	//The output handler has been added.
		};

	/* @brief Method to remove an output handler from the collection of output handlers - inherited from IPipeSegmentBase */
	virtual bool removeOutputHandler(IPipeSegmentBase *output)
		{ for (int i=0; i < (int)theOutput.size(); i++) {
			if (theOutput[i] == output) {
				theOutput.erase((theOutput.begin() + i));
				return true;	//it was found, and has been removed.
			}
		  }
		  return true; //it was never there to begin with, so it's already removed!
		};

	/* @brief Method to remove all output handlers from the collection of output handlers - inherited from IPipeSegmentBase */
	virtual bool removeAllOutputHandlers()
		{ theOutput.clear(); //all done!
		  return true; //no failure conditions here!
		};

public:
	PipeSegment() {};

	/* @brief Method to connectTo and send output to another object - inherited from IPipeSegment */
	virtual IPipeSegment<OutputPipeType> *connectTo(OutputPipeType *output)
		{ addOutputHandler(output); return this; };

	/* @brief Method to disconnectFrom another object - inherited from IPipeSegment */
	virtual IPipeSegment<OutputPipeType> *disconnectFrom(OutputPipeType *output)
		{ removeOutputHandler(output); return this; };

	/* @brief Method to disconnectFrom all other objects - inherited from IPipeSegment */
	virtual void disconnectFromAll()
		{ removeAllOutputHandlers(); };

	/* @brief Shortened notation for connectTo and sending output to another object - inherited from IPipeSegment */
	virtual void operator+=(OutputPipeType *output)
		{ addOutputHandler(output); };

	/* @brief Shortened notation for disconnectFrom another object - inherited from IPipeSegment */
	virtual void operator-=(OutputPipeType *output)
		{ removeOutputHandler(output); };

	/* @brief Shortened notation for connectTo and sending output to another object - inherited from IPipeSegment */
	virtual void operator+=(OutputPipeType &output)
		{ addOutputHandler(&output); };

	/* @brief Shortened notation for disconnectFrom another object - inherited from IPipeSegment */
	virtual void operator-=(OutputPipeType &output)
		{ removeOutputHandler(&output); };

	virtual ~PipeSegment() {};
};

//This line does a compile-time check that the OutputPipeSegmentType template parameter
//is an IPipeSegmentBase type.  It performs this check by attempting to cast a pointer
//to an OutputPipeSegmentType as a pointer to an IPipeSegmentBase.  If you are very
//clever you will realize that this would not fail with an OutputPipeSegmentType template
//parameter of 'void'.  This is checked inline by the OutputPipeSegmentType_Not_Void static
//data member in the PipeSegment class header file.
template<class OutputPipeType>
const IPipeSegmentBase* const PipeSegment<OutputPipeType>::OutputPipeType_Substitutable = (const OutputPipeType*) 0;


}

#endif /*PIPESEGMENT_H*/
