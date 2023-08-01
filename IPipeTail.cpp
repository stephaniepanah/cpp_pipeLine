/**
	@class IPipeTail
	@brief Provides a very basic (empty) interface for the last object in the processing pipeline

	Use this interface as follows when you intend the class you are building to be the last object in a
	pipeline configuration (a pipe tail, or a pipe segment with no output):<BR>
	<PRE>
		class MyPipeTail : public PipeLineProcessing::IPipeTail
	</PRE>
	<BR>
	You could accomplish the same thing by making MyPipeTail inherit from IPipeSegmentBase,
	PipeSegmentBaseAdapter, or even PipeSegment<AnyIPipeSegmentBaseType>, however this
	interface is provided for the expressed	purpose of making it semantically clear what the programmer
	intends.  Please use it appropriately.

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
		- IPipeTail.h
		- IPipeSegment
	@bug	None known

*/

#include "IPipeTail.h"
