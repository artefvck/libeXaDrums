/*
 * IInstrument.h
 *
 *  Created on: 15 Nov 2015
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_INSTRUMENTS_INSTRUMENT_H_
#define SOURCE_DRUMKIT_INSTRUMENTS_INSTRUMENT_H_

#include "../../IO/SensorType.h"
#include "../../IO/ISensor.h"
#include "../../IO/HddSensor.h"
#include "../../IO/SpiSensor.h"
#include "../../Sound/Mixer.h"
#include "../TriggerParameters.h"
#include "../Trigger.h"
#include "InstrumentParameters.h"

#include <vector>
#include <string>
#include <memory>

namespace DrumKit
{

	class Instrument
	{

	public:

		Instrument(InstrumentParameters parameters);

		virtual void CreateTrigger();
		virtual bool Trig(float& strength);

		virtual std::string GetSoundFile() const { return this->parameters.soundFile; }
		virtual int GetId() const { return this->parameters.id; }

		virtual ~Instrument();

	protected:

		InstrumentParameters parameters;
		std::shared_ptr<IO::ISensor> sensor;
		std::shared_ptr<Trigger> trigger;

	private:



	};

}

#endif /* SOURCE_DRUMKIT_INSTRUMENTS_INSTRUMENT_H_ */