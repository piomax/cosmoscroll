#include "PauseMenu.hpp"
#include "core/Game.hpp"
#include "core/ControlPanel.hpp"
#include "core/ParticleSystem.hpp"
#include "core/SoundSystem.hpp"
#include "entities/EntityManager.hpp"
#include "utils/I18n.hpp"


PauseMenu::PauseMenu()
{
	SetTitle(_t("menu.pause.title"), 120);
	SetBackground(sf::Sprite());

	gui::VBoxLayout layout(210, 200);
	layout.Add(new CosmoButton(this, _t("menu.pause.resume")))->SetCallbackID(1);
	layout.Add(new CosmoButton(this, _t("menu.back_main_menu")))->SetCallbackID(2);
	layout.Add(new CosmoButton(this, _t("menu.pause.quit")))->SetCallbackID(3);
}


void PauseMenu::OnEvent(const sf::Event& event)
{
	Input::Action action = Input::GetInstance().EventToAction(event);
	if (action == Input::PAUSE && event.type != sf::Event::LostFocus) // resume
	{
		Game::GetInstance().SetNextScene(Game::SC_InGameScene);
		SoundSystem::GetInstance().PlayMusic();
	}
	else
	{
		BaseMenu::OnEvent(event);
	}
}


void PauseMenu::EventCallback(int id)
{
	Game& game = Game::GetInstance();
	switch (id)
	{
		case 1:
			game.SetNextScene(Game::SC_InGameScene);
			SoundSystem::GetInstance().PlayMusic();
			break;
		case 2:
			game.SetNextScene(Game::SC_MainMenu);
			break;
		case 3:
			game.Quit();
			break;
	}
}


void PauseMenu::Update(float frametime)
{
	ParticleSystem::GetInstance().Update(frametime);
}


void PauseMenu::Show(sf::RenderTarget& target) const
{
	target.draw(ControlPanel::GetInstance());
	target.draw(EntityManager::GetInstance());
	target.draw(GetTitle());
	gui::Menu::Show(target);
}

