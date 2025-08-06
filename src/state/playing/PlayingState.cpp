#include "PlayingState.hpp"

#include "../../Game.hpp"
#include "../MenuState.hpp"

// =============== Construction =============== //

PlayingState::PlayingState(Game &game)
    : State(game),
      _grid(game.config(), game.resources(), 10),
      _guiFrameRate(game.resources().font())
{
}

void PlayingState::setup()
{
    addPress("menu", std::bind(&PlayingState::menu, this));
    addPress("exit", std::bind(&PlayingState::exit, this));

    State::setup();

    sf::Vector2f gridSize = toVec2f(_grid.gridSize());
    sf::Vector2f cellSize = Grid::Cell::SIZE;
    sf::Vector2f gridWorldSize = gridSize.componentWiseMul(cellSize);
    sf::Vector2f center(gridWorldSize / 2.f);
    sf::Vector2f size(gridWorldSize.x * _game.config().windowRatio(), gridWorldSize.y);
    _cameraView.setup(center, size, _game.config().zoomToMouse());
}

// ================== State =================== //

void PlayingState::update(double dt)
{
    _guiFrameRate.setDt(_game.getUpdateGoal(), _game.getRenderGoal(), _game.getDt());

    _guiFrameRate.update(dt);
}

void PlayingState::render(sf::RenderWindow &window)
{
    _cameraView.setView(window);

    _grid.render(window);

    // UI
    window.setView(window.getDefaultView());
    _guiFrameRate.render(window);
}

// =============== SFML Events ================ //

void PlayingState::handleEvent(const sf::RenderWindow &window, const sf::Event &event)
{
    _cameraView.handleEvent(window, event);
}

// ================= Actions ================== //

void PlayingState::menu()
{
    _game.stateManager().push<MenuState>();
}

void PlayingState::exit()
{
    _game.stop();
}