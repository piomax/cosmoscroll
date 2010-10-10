#include "Label.hpp"
#include "Menu.hpp"

using namespace gui;


Label::Label(Menu* owner, const sf::Unicode::Text& text, int x, int y) :
	Widget(owner, false)
{
	WidgetStyle& style = owner->GetWidgetStyle();
	text_.SetText(text);
	text_.SetColor(style.label_text_color);
	text_.SetFont(*style.global_font);
	text_.SetSize(style.global_text_size);
	text_.SetPosition(0, 0);

	SetRect(x, y, text_.GetRect().GetWidth(), text_.GetRect().GetHeight());
}


void Label::SetText(const sf::Unicode::Text& text)
{
	text_.SetText(text);
}


std::string Label::GetText() const
{
	return text_.GetText();
}


void Label::SetSize(int size)
{
	text_.SetSize(size);
}


void Label::Render(sf::RenderTarget& target) const
{
	target.Draw(text_);
}