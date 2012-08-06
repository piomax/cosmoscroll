#ifndef INTROLEVELSCENE_HPP
#define INTROLEVELSCENE_HPP

#include "scenes/BaseScene.hpp"
#include "utils/sfml_helper.hpp"

/**
 * Scène d'introduction avant le début d'un niveau
 */
class IntroLevelScene: public BaseScene
{
public:
	IntroLevelScene();

	// inherited
	void OnEvent(const sf::Event& event);

	// inherited
	void Show(sf::RenderTarget& target) const;

	// inherited
	void OnFocus();

private:
	xsf::Text description_;
	xsf::Sprite background_;
	xsf::Sprite title_;
};

#endif // INTROLEVELSCENE_HPP

