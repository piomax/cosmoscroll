#include "DumbMusic.hpp"

#define DELTA          65536.0f / SAMPLING_RATE

bool DumbMusic::inited_ = false;


void DumbMusic::Exit()
{
	dumb_exit();
}


DumbMusic::DumbMusic()
{
	if (!inited_)
	{
		dumb_register_stdfiles();
		inited_ = true;
	}

	module_ = NULL;
	player_ = NULL;
}


DumbMusic::~DumbMusic()
{
	if (player_ != NULL)
		duh_end_sigrenderer(player_);
	if (module_ != NULL)
		unload_duh(module_);
}


bool DumbMusic::openFromFile(const std::string& filename)
{
	initialize(N_CHANNELS, SAMPLING_RATE);
	module_ = dumb_load_mod_quick(filename.c_str());
	return module_ != NULL;
}


void DumbMusic::onSeek(sf::Time timeOffset)
{
	// TODO: implement seeking using timeoffset
	const int sig = 0;
	const long pos = 0;
	player_ = duh_start_sigrenderer(module_, sig, N_CHANNELS, pos);
}


bool DumbMusic::onGetData(Chunk& data)
{
	// FIXME: le /2 est magique [sans lui, skipping]
	duh_render(player_, 16, 0, 1.0f, DELTA, BUFFER_SIZE / 2, samples_);

	data.samples = samples_;
	data.sampleCount = BUFFER_SIZE; // nombre de samples
	return true;
}


