/*
 * KitCreator.h
 *
 *  Created on: 22 Nov 2016
 *      Author: jeremy
 */

#ifndef SOURCE_API_KITCREATOR_API_H_
#define SOURCE_API_KITCREATOR_API_H_


#include "../DrumKit/Kits/KitCreator.h"

#include <string>
#include <vector>

namespace eXaDrumsApi
{

	class KitCreator
	{

	public:

		KitCreator(const char* dataLocation);
		virtual ~KitCreator();

		// Kit
		void CreateNewKit();
		void CreateFromModel(const char* loc);
		int GetNumInstruments() const;
		void SetKitName(const char* name);
		void SaveKit(const char* file) const;
		void SaveKit() const;


		// Instrument
		void CreateNewInstrument();
		void AddInstrumentToKit();
		void SetInstrumentName(const char* name);
		void SetInstrumentType(const char* type);
		void SetInstrumentVolume(const float volume);
		void AddInstrumentSound(const char* file, const char* type);
		void AddInstrumentTrigger(const int id, const char* location);


		// Enums
		// Instruments
		std::vector<std::string> GetInstrumentsTypes();
		std::vector<std::string> GetInstrumentsNames();

		// Triggers
		std::vector<int> GetTriggersIds() const;
		std::vector<std::string> GetTriggersLocations(const std::string instrumentType);

		// Sounds
		std::vector<std::string> GetSoundsFiles();
		std::vector<std::string> GetSoundsTypes(const std::string instrumentType);


	private:

		void GetTriggersIds_(int* data, unsigned int& size) const;
		void GetSoundFiles_(const char** data, unsigned int& size);
		void GetSoundTypes_(const char* instrumentType, const char** data, unsigned int& size);
		void GetInstrumentsTypes_(const char** data, unsigned int& size);
		void GetInstrumentsNames_(const char** data, unsigned int& size);
		void GetTriggersLocations_(const char* instrumentType, const char** data, unsigned int& size);

		// Local copies of all the enums
		std::vector<std::string> soundsFiles;
		std::vector<std::string> soundsTypes;
		std::vector<std::string> instrumentsTypes;
		std::vector<std::string> triggersLocations;
		std::vector<std::string> instrumentsNames;

		// Controller
		DrumKit::KitCreator& controller;

	};

} /* namespace eXaDrumsApi */

#include "KitCreator_api.hpp"

#endif /* SOURCE_API_KITCREATOR_API_H_ */
