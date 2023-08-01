/**
	@class PipeSegment
	@brief Provides the basic necessities of a segment of the pipe.

	This class provides the programmer a simple way to create new objects
	that can be inserted anywhere in the processing pipeline.  He/she
	simply creates a new class of his or her choice, and inherits from this
	class.  However, the astute observer will notice that this is a template
	class and will inquire as to what the value of the template paramter IS.
	The template parameter allows the programmer to specify which type of
	classes this object connects to.  In this sense, "connecting to" another
	object is synonymous with "sending output to".  Observe the following
	code:<BR>
	<PRE>
		class MyPipeSegment : public PipeLineProcessing::PipeSegment<IPipeSegmentInterface>
	</PRE>
	In this example, a class called MyPipeSegment is created with
	appropriate connect/disconnect methods built for objects of type IPipeSegmentInterface.
	Therefore, if a user attempts to connectTo(IAnotherPipeSegmentInterface)
	on an object of type MyPipeSegment, the code will fail at compile time.
	Understanding this programming sleight-of-hand is crucial in understanding
	and extending the Pipeline Processing framework.

	<B>NOTE:</B>  When completing a pipeline (the final nodes in the pipeline), inherit
	from IPipeTail instead of this object.  This will result in cleaner code.

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

	@see
		- PipeSegment.h
		- IPipeSegment
		- IPipeTail

	@bug	None known

*/

#include "PipeSegment.h"
