/*
 * KitParameters.h
 *
 *  Created on: 7 Feb 2016
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_KITMANAGER_KITPARAMS_H_
#define SOURCE_DRUMKIT_KITMANAGER_KITPARAMS_H_

#include "../Instruments/InstrumentParameters.h"

#include <string>
#include <vector>

namespace DrumKit
{

	struct KitParameters
	{

		std::string kitName;
		std::string kitFolder;

		std::vector<InstrumentParameters> instrumentParameters;

	};

}


#endif /* SOURCE_DRUMKIT_KITMANAGER_KITPARAMS_H_ */
