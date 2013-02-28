#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Projectile.hpp"

/**
 * Projectile with zone damage
 */
class Missile: public Projectile
{
public:
	Missile(Entity* emitter, const sf::Vector2f& offset, float angle,
		const sf::Texture& image, int speed, int damage);

	~Missile();

	// override
	void onCollision(const Entity& entity);
private:
	float m_angle;
};

#endif // MISSILE_HPP