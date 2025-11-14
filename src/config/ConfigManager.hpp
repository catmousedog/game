#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <yaml-cpp/yaml.h>

using Path = std::filesystem::path;

class State;

class ConfigManager
{

	// =============== Construction =============== //
  public:
	ConfigManager();

	void loadSettings();
	void loadKeyBinds(State& state) const;

	// ================= Getters ================== //

	sf::Vector2f absPos(const sf::Vector2f& pos) const;

	sf::Vector2f absPos(float relX, float relY) const;

	sf::Vector2i windowSize() const
	{
		return _windowSize;
	}

	float windowRatio() const
	{
		return static_cast<float>(_windowSize.x) / _windowSize.y;
	}

	float frameTime() const
	{
		return 1.f / (float) _fps;
	}

	float tickTime() const
	{
		return 1.f / (float) _tps;
	}

	bool zoomToMouse() const
	{
		return _zoomToMouse;
	}

	// ================ Variables ================= //

  private:
	// paths
	Path _configDir;
	Path _settingsPath;
	Path _keyBindsPath;

	Path _resourceDir;
	Path _fontPath;

	// settings
	YAML::Node _settingsYAML;
	YAML::Node _keyBindsYAML;

	// cached values
	sf::Vector2i _windowSize;
	uint _fps;
	uint _tps;
	bool _zoomToMouse;
};
