/**
	@class IPipeSegmentBase
	@brief Provides a very basic, base class for dealing with any portion of the pipeline

	This class provides the interface that all objects that are a portion of the processing pipeline
	must implement/adhere to - whether they are heads of the pipeline, tails of the pipeline, or even just
	interfaces somewhere in the middle.  All the methods defined in the interface are protected, since
	the specialization of the output is not intended to happen until another layer of inheritance
	(IPipeSegment, to be precise).  Additionally, processing interfaces may be interested in
	inheriting from PipeSegmentBaseAdapter instead of this object, since that adapter provides an
	empty (who cares?) implementation on this interface.

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
		- IPipeSegment.h
		- IPipeSegment
		- PipeSegmentBaseAdapter
	@bug	None known

*/

#include "IPipeSegmentBase.h"
