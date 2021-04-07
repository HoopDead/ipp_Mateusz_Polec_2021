#pragma once

#include "Window.hpp"
#include "MapLoader.hpp"
#include "Logs.hpp"

struct MapRenderer {
public:
	MapRenderer();
	~MapRenderer();
	void Awake();
	void Draw(Window& window);
private:

	tmx::Map m_map;
	MapLayer m_layer_above_2;
	MapLayer m_layer_above_1;
	MapLayer m_layer_main;
	MapLayer m_layer_below_1;
	MapLayer m_layer_below_2;

};