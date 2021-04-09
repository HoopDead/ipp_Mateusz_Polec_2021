#include "MapRenderer.h"

MapRenderer::MapRenderer() {
	Log("Called MapRenderer Constructor");
}

MapRenderer::~MapRenderer() {
	Log("~Called MapRenderer Destructor");
}

void MapRenderer::Awake() {
	m_map.load("Graphics/map/Onyx_Map.tmx");
	m_layer_above_2.Load(m_map, 0);
	m_layer_above_1.Load(m_map, 1);
	m_layer_main.Load(m_map, 2);
	m_layer_below_1.Load(m_map, 3);
	m_layer_below_2.Load(m_map, 4);
	m_layer_collision.Load(m_map, 5);
}

void MapRenderer::Draw(Window& window) {
	window.Draw(m_layer_above_2);
	window.Draw(m_layer_above_1);
	window.Draw(m_layer_main);
	window.Draw(m_layer_below_1);
	window.Draw(m_layer_below_2);
	window.Draw(m_layer_collision);
}

void MapRenderer::ShowLayers() {
	for (const auto& layer : m_map.getLayers()) {
		if (layer->getName() == "Layer_collision") {
				std::cout << "Layer Collision found!";
			}
		}
	}