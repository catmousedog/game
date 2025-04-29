/**
 * @brief Enum to define global actions the Game can perform. These are indirectly
 * invoked by the State Actions and thus don't have keybinds.
 */
enum class GameAction
{
    None,
    Exit,
    Save,
    Load
};