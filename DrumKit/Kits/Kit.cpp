/*
 * Kit.cpp
 *
 *  Created on: 21 Aug 2016
 *      Author: jeremy
 */

#include "Kit.h"

#include "../../Util/ErrorHandling.h"
#include "../Triggers/TriggerType.h"
#include "../Instruments/InstrumentFactory.h"

#include <algorithm>

using namespace Util;

namespace DrumKit
{

	Kit::Kit(const KitParameters& params, std::vector<TriggerPtr> const& trigs, std::shared_ptr<Sound::SoundBank> sb)
	: parameters(params), triggers(trigs), soundBank(std::move(sb))
	{

		return;
	}

	Kit::~Kit()
	{

		return;
	}

	void Kit::Enable()
	{

		CreateInstruments();

		return;
	}

	void Kit::Disable()
	{

		std::for_each(instruments.begin(), instruments.end(), [](InstrumentPtr& inst) { inst.reset(); });
		instruments.clear();

		return;
	}

	void Kit::SetInstrumentVolume(int id, float volume)
	{

		this->instruments[id]->SetVolume(volume);
		this->parameters.instrumentParameters[id].volume = volume;

		return;
	}

	std::string Kit::GetInstrumentName(std::size_t id) const
	{

		if(id > parameters.instrumentParameters.size())
		{
			 throw Exception("The instrument could not be found.", error_type_error);
		}

		std::string name = parameters.instrumentParameters[id].instrumentName;

		return name;
	}

	/// PRIVATE METHODS

	void Kit::CreateInstruments()
	{


		for(InstrumentParameters const& instrumentParameters : this->parameters.instrumentParameters)
		{

			// Create instrument
			InstrumentPtr instrumentPtr = InstrumentFactory::CreateInstrument(instrumentParameters.instrumentType, instrumentParameters, soundBank);


			// Create instrument's triggers
			instrumentPtr->SetTriggers(this->triggers);

			// Set instrument sounds
			for(InstrumentSoundInfo const& soundInfo : instrumentParameters.soundsInfo)
			{
				instrumentPtr->SetSound(soundInfo);
			}

			// Add instrument to drum module
			instruments.push_back(instrumentPtr);

		};


		return;
	}


} /* namespace DrumKit */
