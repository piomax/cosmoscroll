#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP

#include <SFML/Graphics.hpp>
#include "entities/EntityManager.hpp"
#include "entities/Bonus.hpp"


/**
 * HUD: panel displaying various data about player status, current level, ...
 */
class ControlPanel: public sf::Drawable
{
public:
	// height in pixels, width is Game::WIDTH
	enum { HEIGHT = 56 };

	static ControlPanel& GetInstance();

	void Init(EntityManager::Mode mode);

	void Update(float frametime);

	/**
	 * @param text: texte d'information
	 */
	void SetGameInfo(const sf::Unicode::Text& text);

	void SetPoints(int points);

	/**
	 * @param seconds: nombre de secondes écoulées
	 */
	void SetTimer(float seconds);

	/// @return true si le panel est en haut de l'écran
	bool IsOnTop() const;

	// Set durée du niveau courant, en secondes
	void SetLevelDuration(int seconds);

	// setters progress bars --------------------------------------------------

	/**
	 * Set current player HP and max HP
	 */
	void SetShipHP(int value);
	void SetMaxShipHP(int max);

	/**
	 * Set current shield points and max shield points
	 */
	void SetShield(int value);
	void SetMaxShield(int max);

	/**
	 * Set current heat and max heat
	 */
	void SetHeat(int value);
	void SetMaxHeat(int max);

	/**
	 * Enable/disable overheat effect on heat progress bar
	 */
	void SetOverheat(bool overheat);

	// setters bonus slots ----------------------------------------------------

	// Set coolers count
	void SetCoolers(int coolers);

	// Set missiles count
	void SetMissiles(int count);

	void ActiveSpeedBonus(int seconds);

	void ActiveAttackBonus(int seconds, Bonus::Type bonus_type);


private:
	ControlPanel();
	ControlPanel(const ControlPanel& other);

	// inherited
	void Render(sf::RenderTarget& target) const;


	struct ProgressBar
	{
		enum
		{
			SHIELD, HP, HEAT, _PBAR_COUNT
		};

		ProgressBar();

		void Init(const sf::Unicode::Text& text, const sf::Font& font, const sf::Color& color);

		// redimensionne la barre
		void SetValue(int value);

		// position de l'ensemble label/bar
		void SetPosition(int x, int y);

		sf::String label_;

		sf::Shape bar_;
		sf::String value_;
		int max_value_;
	};

	class BonusSlot
	{
	public:
		enum Type { COUNTER, TIMER };

		void Init(Bonus::Type bonus_type, Type type);
		// set widget position
		void SetPosition(int x, int y);

		void SetValue(int value);

		void Update(float frametime);

		void Show(sf::RenderTarget& target) const;

	private:
		sf::Sprite icon_;
		sf::String label_;
		sf::Sprite glow_;
		float timer_;
		enum GlowingStatus { UP, DOWN, STOP } glowing_;
		Type type_;
	};

	ProgressBar pbars_[ProgressBar::_PBAR_COUNT];
	BonusSlot bs_coolers_;
	BonusSlot bs_missiles_;
	BonusSlot bs_attack_;
	BonusSlot bs_speed_;

	sf::String timer_;
	sf::String game_info_;
	sf::Sprite panel_;

	EntityManager::Mode game_mode_;
	// story
	int level_duration_;
	sf::Sprite level_cursor_;
	sf::Sprite level_bar_;
	// arcade
	sf::String str_points_;
	sf::Sprite bar_mask_;
};

#endif // CONTROLPANEL_HPP

