#include "AudioMenu.hpp"
#include "../core/Game.hpp"
#include "../core/SoundSystem.hpp"
#include "../utils/I18n.hpp"


AudioMenu::AudioMenu()
{
	SetTitle(I18n::t("menu.audio.title"));
	SetOffsetY(100);

	AddOption("Space Song", 1);
	AddOption("Aurora", 2);
	AddOption("Escape For Assault", 3);
	AddSpacer();
	AddOption(I18n::t("menu.audio.no_music"), 4);
	AddOption(I18n::t("menu.audio.decrease_volume"), 5);
	AddOption(I18n::t("menu.audio.increase_volume"), 6);
	AddOption(I18n::t("menu.back"), 0);
}


void AudioMenu::Callback(int id)
{
	SoundSystem& sound = SoundSystem::GetInstance();
	switch (id)
	{
		case 0:
			Game::GetInstance().SetNextScene(Game::SC_OptionMenu);
			break;
		case 1:
			sound.PlayMusic("space", true);
			break;
		case 2:
			sound.PlayMusic("aurora", true);
			break;
		case 3:
			sound.PlayMusic("escape_for_assault", true);
			break;
		case 4:
			sound.EnableMusic(false);
			SetItemActive(5, false);
			SetItemActive(6, false);
			break;
		case 5:
			sound.SetMusicVolume(sound.GetMusicVolume() - 10);
			break;
		case 6:
			sound.SetMusicVolume(sound.GetMusicVolume() + 10);
			break;
	}
	if (id >= 1 && id <= 3)
	{
		SetItemActive(5, true);
		SetItemActive(6, true);
	}
}
