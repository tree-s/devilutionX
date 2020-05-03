#include "controls/menu_controls.h"

#include "controls/controller.h"
#include "controls/remap_keyboard.h"

namespace dvl {

MenuAction GetMenuAction(const SDL_Event &event)
{
	const ControllerButtonEvent ctrl_event = ToControllerButtonEvent(event);
	if (ctrl_event.button != ControllerButton::NONE)
		sgbControllerActive = true;

	if (!ctrl_event.up) {
		switch (ctrl_event.button) {
		case ControllerButton::IGNORE:
			return MenuAction::NONE;
		case ControllerButton::BUTTON_B: // Right button
		case ControllerButton::BUTTON_START:
			return MenuAction::SELECT;
		case ControllerButton::BUTTON_BACK:
		case ControllerButton::BUTTON_A: // Bottom button
			return MenuAction::BACK;
		case ControllerButton::BUTTON_X: // Left button
			return MenuAction::DELETE;
		case ControllerButton::BUTTON_DPAD_UP:
			return MenuAction::UP;
		case ControllerButton::BUTTON_DPAD_DOWN:
			return MenuAction::DOWN;
		case ControllerButton::BUTTON_DPAD_LEFT:
			return MenuAction::LEFT;
		case ControllerButton::BUTTON_DPAD_RIGHT:
			return MenuAction::RIGHT;
		case ControllerButton::BUTTON_LEFTSHOULDER:
			return MenuAction::PAGE_UP;
		case ControllerButton::BUTTON_RIGHTSHOULDER:
			return MenuAction::PAGE_DOWN;
		default:
			break;
		}
	}

#if HAS_KBCTRL == 0
	if (event.type >= SDL_KEYDOWN && event.type < SDL_JOYAXISMOTION)
		sgbControllerActive = false;

	if (event.type == SDL_KEYDOWN) {
		auto sym = event.key.keysym.sym;
		remap_keyboard_key(&sym);
		switch (sym) {
		case SDLK_UP:
			return MenuAction::UP;
		case SDLK_DOWN:
			return MenuAction::DOWN;
		case SDLK_TAB:
			if (SDL_GetModState() & KMOD_SHIFT)
				return MenuAction::UP;
			else
				return MenuAction::DOWN;
		case SDLK_PAGEUP:
			return MenuAction::PAGE_UP;
		case SDLK_PAGEDOWN:
			return MenuAction::PAGE_DOWN;
		case SDLK_RETURN: {
			const Uint8 *state = SDLC_GetKeyState();
			if (!state[SDLC_KEYSTATE_LALT] && !state[SDLC_KEYSTATE_RALT]) {
				return MenuAction::SELECT;
			}
			break;
		}
		case SDLK_KP_ENTER:
			return MenuAction::SELECT;
		case SDLK_SPACE:
			if (!SDL_IsTextInputActive()) {
				return MenuAction::SELECT;
			}
			break;
		case SDLK_DELETE:
			return MenuAction::DELETE;
		case SDLK_LEFT:
			return MenuAction::LEFT;
		case SDLK_RIGHT:
			return MenuAction::RIGHT;
		case SDLK_ESCAPE:
			return MenuAction::BACK;
		default:
			break;
		}
	}
#endif

	return MenuAction::NONE;
} // namespace dvl

} // namespace dvl
