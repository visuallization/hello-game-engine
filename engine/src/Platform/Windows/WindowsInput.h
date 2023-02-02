#pragma once
#include "Hello/Input.h"

namespace Hello {
	class WindowsInput: public Input {
	protected:
		virtual bool GetKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}
