#include "Component_MapParser.hpp"

Component_MapParser::Component_MapParser(Object* owner) : Component(owner) {

}

void Component_MapParser::Awake() {
	m_map.load("Graphics/map/Onyx_Map.tmx");
	m_layer_above.Load(m_map, 0);
	m_layer_main.Load(m_map, 1);
	m_layer_below.Load(m_map, 2);
	m_layer_below_1.Load(m_map, 3);
}

void Component_MapParser::Draw(Window& window) {
	window.Draw(m_layer_above);
	window.Draw(m_layer_main);
	window.Draw(m_layer_below);
	window.Draw(m_layer_below_1);
}