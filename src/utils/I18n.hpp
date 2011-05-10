#ifndef I18N_HPP
#define I18N_HPP

#include <map>
#include <SFML/System.hpp>


// shortcut _t(key) => I18n::GetInstance().Translate(key)
#define _t(key) (I18n::GetInstance().Translate(key))

/**
 * Singleton dédié à l'intertionalisation (dit i18n)
 */
class I18n
{
public:
	static I18n& GetInstance();

	/**
	 * Get translated text
	 * @param key: text identifier
	 */
	const sf::Unicode::Text& Translate(const char* key) const;

	/**
	 * Tente de charger le fichier de traduction de la langue du système
	 * @return true si langue du système trouvée, sinon false
	 */
	bool LoadSystemLanguage();

	/**
	 * Get system language identifier
	 * @return 2 lower-case characters
	 */
	std::string GetLocaleCode() const;

	/**
	 * Obtenir le code de la langue chargée
	 */
	const char* GetCurrentCode() const;

	/**
	 * Charger un fichier de traduction particulier
	 * @param filename: nom du fichier à charger
	 */
	bool LoadFromFile(const char* filename);

	bool LoadFromCode(const std::string& code);

private:
	I18n();
	I18n(const I18n&);

	void DecodeUTF8(const std::string& src, std::wstring& dest);

	mutable char code_[3];
	typedef std::map<std::string, sf::Unicode::Text> TextMap;
	TextMap content_;
};

#endif // I18N_HPP
