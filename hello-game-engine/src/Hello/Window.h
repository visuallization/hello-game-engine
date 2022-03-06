#pragma once

#include "hopch.h"

#include "Hello/Core.h"
#include "Hello//Events/Event.h"

namespace Hello {

	struct WindowProps {
		std::string Title;
		unsigned int With;
		unsigned int Height;
		
		WindowProps(
			const std::string& title = "Hello Engine",
			const unsigned int width = 1280,
			const unsigned int height = 720
		) : Title(title), With(width), Height(height) {}
	};

	class HELLO_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}