#include <regex>

#include "Keybinds.hpp"
#include "Utils.hpp"
#include "Error.hpp"

#define KEYMAP_ENTRY(KEY)                    \
    {                                        \
        StringUtils::toLower(#KEY), Key::KEY \
    }

#define ACTIONMAP_ENTRY(ACT)                    \
    {                                           \
        StringUtils::toLower(#ACT), Action::ACT \
    }

static const std::unordered_map<string, Action> actionMap = {
    ACTIONMAP_ENTRY(Exit)
};

static const std::unordered_map<string, Key> keyMap = {
    KEYMAP_ENTRY(A),
    KEYMAP_ENTRY(B),
    KEYMAP_ENTRY(C),
    KEYMAP_ENTRY(D),
    KEYMAP_ENTRY(E),
    KEYMAP_ENTRY(F),
    KEYMAP_ENTRY(G),
    KEYMAP_ENTRY(H),
    KEYMAP_ENTRY(I),
    KEYMAP_ENTRY(J),
    KEYMAP_ENTRY(K),
    KEYMAP_ENTRY(L),
    KEYMAP_ENTRY(M),
    KEYMAP_ENTRY(N),
    KEYMAP_ENTRY(O),
    KEYMAP_ENTRY(P),
    KEYMAP_ENTRY(Q),
    KEYMAP_ENTRY(R),
    KEYMAP_ENTRY(S),
    KEYMAP_ENTRY(T),
    KEYMAP_ENTRY(U),
    KEYMAP_ENTRY(V),
    KEYMAP_ENTRY(W),
    KEYMAP_ENTRY(X),
    KEYMAP_ENTRY(Y),
    KEYMAP_ENTRY(Z),
    KEYMAP_ENTRY(Num1),
    KEYMAP_ENTRY(Num2),
    KEYMAP_ENTRY(Num3),
    KEYMAP_ENTRY(Num4),
    KEYMAP_ENTRY(Num5),
    KEYMAP_ENTRY(Num6),
    KEYMAP_ENTRY(Num7),
    KEYMAP_ENTRY(Num8),
    KEYMAP_ENTRY(Num9),
    KEYMAP_ENTRY(Num0),
    KEYMAP_ENTRY(Enter),
    KEYMAP_ENTRY(Escape),
    KEYMAP_ENTRY(Backspace),
    KEYMAP_ENTRY(Tab),
    KEYMAP_ENTRY(Space),
    KEYMAP_ENTRY(Hyphen),
    KEYMAP_ENTRY(Equal),
    KEYMAP_ENTRY(LBracket),
    KEYMAP_ENTRY(RBracket),
    KEYMAP_ENTRY(Backslash),
    KEYMAP_ENTRY(Semicolon),
    KEYMAP_ENTRY(Apostrophe),
    KEYMAP_ENTRY(Grave),
    KEYMAP_ENTRY(Comma),
    KEYMAP_ENTRY(Period),
    KEYMAP_ENTRY(Slash),
    KEYMAP_ENTRY(F1),
    KEYMAP_ENTRY(F2),
    KEYMAP_ENTRY(F3),
    KEYMAP_ENTRY(F4),
    KEYMAP_ENTRY(F5),
    KEYMAP_ENTRY(F6),
    KEYMAP_ENTRY(F7),
    KEYMAP_ENTRY(F8),
    KEYMAP_ENTRY(F9),
    KEYMAP_ENTRY(F10),
    KEYMAP_ENTRY(F11),
    KEYMAP_ENTRY(F12),
    KEYMAP_ENTRY(Pause),
    KEYMAP_ENTRY(Insert),
    KEYMAP_ENTRY(Home),
    KEYMAP_ENTRY(PageUp),
    KEYMAP_ENTRY(Delete),
    KEYMAP_ENTRY(End),
    KEYMAP_ENTRY(PageDown),
    KEYMAP_ENTRY(Right),
    KEYMAP_ENTRY(Left),
    KEYMAP_ENTRY(Down),
    KEYMAP_ENTRY(Up),
    KEYMAP_ENTRY(Numpad1),
    KEYMAP_ENTRY(Numpad2),
    KEYMAP_ENTRY(Numpad3),
    KEYMAP_ENTRY(Numpad4),
    KEYMAP_ENTRY(Numpad5),
    KEYMAP_ENTRY(Numpad6),
    KEYMAP_ENTRY(Numpad7),
    KEYMAP_ENTRY(Numpad8),
    KEYMAP_ENTRY(Numpad9),
    KEYMAP_ENTRY(Numpad0),
};

KeyPressed parseKeybind(string keyString)
{
    keyString = StringUtils::toLower(keyString);
    KeyPressed keyPressed;

    std::regex regex(R"((\w+)\+?(\w+))");
    std::smatch match;

    if (std::regex_match(keyString, match, regex))
    {
        string modifier, key;

        if (match.size() == 3)
        {
            modifier = match[1].str();
            key = match[2].str();

            if (modifier == "ctrl")
                keyPressed.control = true;
            else if (modifier == "shift")
                keyPressed.shift = true;
            else if (modifier == "alt")
                keyPressed.alt = true;
            else
                PRINT_ERROR("Modifier '{}' not recognized in keybind '{}'", modifier, keyString);
        }
        else
        {
            key = match[1].str();
        }

        keyPressed.code = keyMap.at(key);
    }
    else
    {
        PRINT_ERROR("Keybind '{}' not recognized", keyString);
        return keyPressed;
    }

    return keyPressed;
}

Action parseAction(string actionString)
{
    actionString = StringUtils::toLower(actionString);

    auto actionIt = actionMap.find(actionString);
    if (actionIt != actionMap.end())
    {
        return actionIt->second;
    }
    else
    {
        PRINT_ERROR("Action '{}' not recognized", actionString);
        return Action::None;
    }
}