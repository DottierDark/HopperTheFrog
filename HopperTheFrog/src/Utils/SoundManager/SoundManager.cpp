#include <cstdio>  // for printf
#include <fstream>
#include <vector>
#include <Utils/SoundManager/SoundManager.hpp>

SoundManager::SoundManager() {
	device = alcOpenDevice(nullptr); // Open default device
	if (!device) {
		printf("Failed to open sound device.\n");
		exit(EXIT_FAILURE);
	}

	context = alcCreateContext(device, nullptr); // Create context
	if (!alcMakeContextCurrent(context)) {
		printf("Failed to set sound context.\n");
		exit(EXIT_FAILURE);
	}

	alGenSources(1, &backgroundSource); // Create a source for background music
	ALenum error = alGetError();
	if (error != AL_NO_ERROR) {
		printf("Error generating background source: %s\n", alGetString(error));
	}
}

bool isWavFileValid(const char* header) {
	return (header[0] == 'R' && header[1] == 'I' && header[2] == 'F' && header[3] == 'F') &&
		(header[8] == 'W' && header[9] == 'A' && header[10] == 'V' && header[11] == 'E') &&
		(header[20] == 1 && header[21] == 0); // PCM format
}


SoundManager::~SoundManager() {
	for (auto& pair : soundBuffers) {
		alDeleteBuffers(1, &pair.second);
	}
	alDeleteSources(1, &backgroundSource);

	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void SoundManager::loadWavFile(const std::string& filepath, ALuint* buffer) {
	std::ifstream file(filepath, std::ios::binary);
	if (!file.is_open()) {
		printf("Could not open file: %s\n", filepath.c_str());
		return;
	}

	// Read WAV header
	char header[44];
	file.read(header, 44);
	if (!isWavFileValid(header)) {
		printf("Invalid or unsupported WAV file: %s\n", filepath.c_str());
		file.close();
		return;
	}

	// Extract metadata
	short channels;
	memcpy(&channels, &header[22], sizeof(short));

	int sampleRate;
	memcpy(&sampleRate, &header[24], sizeof(int));

	short bitsPerSample;
	memcpy(&bitsPerSample, &header[34], sizeof(short));

	if (bitsPerSample != 16) {
		printf("Unsupported WAV format: only 16-bit PCM supported.\n");
		file.close();
		return;
	}

	// Locate data chunk
	file.seekg(12, std::ios::beg);
	char chunkId[4];
	int chunkSize;
	while (file.read(chunkId, 4)) {
		file.read(reinterpret_cast<char*>(&chunkSize), 4);
		if (std::strncmp(chunkId, "data", 4) == 0) {
			break;
		}
		file.seekg(chunkSize, std::ios::cur);
	}

	if (std::strncmp(chunkId, "data", 4) != 0) {
		printf("No data chunk found in WAV file.\n");
		file.close();
		return;
	}

	// Read data
	std::vector<char> data(chunkSize);
	file.read(data.data(), chunkSize);
	file.close();

	// Determine OpenAL format
	ALenum format = (channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;

	// Generate buffer and load data
	alGenBuffers(1, buffer);
	if (alGetError() != AL_NO_ERROR) {
		printf("Error generating buffer.\n");
		return;
	}

	alBufferData(*buffer, format, data.data(), chunkSize, sampleRate);
	if (alGetError() != AL_NO_ERROR) {
		printf("Error buffering data.\n");
	}
}


void SoundManager::addSound(const std::string& name, const std::string& filepath) {
	ALuint buffer;
	loadWavFile(filepath, &buffer);
	soundBuffers[name] = buffer;
}

void SoundManager::playSound(const std::string& name) {
	if (soundBuffers.find(name) != soundBuffers.end()) {
		ALuint effectSource;
		alGenSources(1, &effectSource); // Generate a new source for the sound effect

		if (alIsSource(effectSource)) {
			alSourcei(effectSource, AL_BUFFER, soundBuffers[name]);

			alSourcePlay(effectSource); // Play the sound effect

			// Check for any error
			ALenum error = alGetError();
			if (error != AL_NO_ERROR) {
				printf("Error playing sound effect: %s\n", alGetString(error));
			}
		}
		else {
			printf("Invalid source for sound effect.\n");
		}
	}
	else {
		printf("Sound effect %s not found.\n", name.c_str());
	}
}



void SoundManager::playBackgroundMusic(const std::string& name, bool loop) {
	if (soundBuffers.find(name) != soundBuffers.end()) {
		alSourcei(backgroundSource, AL_BUFFER, soundBuffers[name]);
		alSourcei(backgroundSource, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
		alSourcePlay(backgroundSource);

		// Check for any error
		ALenum error = alGetError();
		if (error != AL_NO_ERROR) {
			printf("Error playing background music: %s\n", alGetString(error));
		}
	}
	else {
		printf("Background music %s not found.\n", name.c_str());
	}
}

void SoundManager::stopBackgroundMusic() {
	alSourceStop(backgroundSource); // Stop the background music
}
