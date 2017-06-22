// =============================================================================
//  CADET - The Chromatography Analysis and Design Toolkit
//  
//  Copyright © 2008-2017: The CADET Authors
//            Please see the AUTHORS and CONTRIBUTORS file.
//  
//  All rights reserved. This program and the accompanying materials
//  are made available under the terms of the GNU Public License v3.0 (or, at
//  your option, any later version) which accompanies this distribution, and
//  is available at http://www.gnu.org/licenses/gpl.html
// =============================================================================

#include <cstddef>
#include <cmath>
#include <algorithm>
#include "AutoDiff.hpp"


#if defined(ACTIVE_ADOLC) || defined(ACTIVE_SFAD) || defined(ACTIVE_SETFAD)
	ACTIVE_INIT
#endif

namespace cadet
{
	namespace ad
	{

#if defined(ACTIVE_ADOLC)

#elif defined(ACTIVE_SFAD) || defined(ACTIVE_SETFAD)

#endif

	} // namespace ad
}  // namespace cadet
