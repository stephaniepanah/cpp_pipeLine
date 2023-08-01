/**
	@class IPipeSegment
	@brief Provides a further, templated interface on top of the IPipeSegmentBase interface

	This class provides the intermediate magic that allows the pipeline to groove the way it does.
	This class inherits from the IPipeSegmentBase interface, and extends it's interface to
	include public members that enable the implementor to connectTo, disconnectFrom, and
	disconnectFromAll.  These methods are templated to provide generic extendability.  For more
	information on the single template parameter, see the PipeSegment class, which is the
	only known implementor of this interface.

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
		- IPipeSegmentBase
		- PipeSegment
	@bug	None known

*/

#include "IPipeSegment.h"
