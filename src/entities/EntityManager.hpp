#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <string>
#include <list>
#include <map>
#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Weapon.hpp"
#include "SpaceShip.hpp"

class EntityManager: public sf::Drawable
{
public:
	/**
	 * Obtenir l'instance unique
	 */
	static EntityManager& GetInstance();

	/**
	 * Mettre à jour les entités
	 * @param[in] frametime: temps de la frame courante
	 */
	void Update(float frametime);

	/**
	 * Ajouter une entité
	 * @param[in] entity: entité à ajouter
	 */
	void AddEntity(Entity* entity);

	/**
	 * Supprimer toutes les entités
	 */
	void Clear();

	/**
	 * @return nombre d'entités
	 */
	int Count() const;

	Weapon BuildWeapon(int id) const;

	SpaceShip* CreateSpaceShip(int id, int x, int y);

private:
	EntityManager();
	EntityManager(const EntityManager&);
	~EntityManager();

	/// inherited
	void Render(sf::RenderTarget& target) const;

	/**
	 * Charger les définitions des armes
	 * @param[in] filename: fichier XML des armes
	 */
	void LoadWeapons(const char* filename);

	void LoadSpaceShips(const char* filename);

	struct WeaponDefinition
	{
		std::string name;       // generic name
		float heat_cost;        // cost per shot
		float fire_rate;        // shot per second
		int speed;              // bullet speed (pixels per second)
		int damage;             // inflicted damage
		const sf::Image* image; // hit image
		std::string sound;      // sound name
	};


	typedef std::map<int, SpaceShip*> SpaceShipMap;
	SpaceShipMap spaceships_defs_;

	typedef std::map<int, WeaponDefinition> WeaponMap;
	WeaponMap weapon_defs_;

	typedef std::list<Entity*> EntityList;

	EntityList entities_;
	int last_id_;
};


#endif /* ENTITYMANAGER_HPP */