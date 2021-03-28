#pragma once
#include "Component.hpp"
#include "MapLoader.hpp"

class Component_MapParser : public Component {
public:

	Component_MapParser(Object* owner);
	void Awake() override;
	void Draw(Window& window) override;

private:
	tmx::Map m_map;
	MapLayer m_layer_above;
	MapLayer m_layer_main;
	MapLayer m_layer_below;
	MapLayer m_layer_below_1;

};