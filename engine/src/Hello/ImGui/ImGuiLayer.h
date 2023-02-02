#pragma once

#include "Hello/Layer.h"

#include "Hello/Events/MouseEvent.h"
#include "Hello/Events/KeyEvent.h"
#include "Hello/Events/ApplicationEvent.h"

namespace Hello {
	class HELLO_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);

		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);

		bool OnWindowResizeEvent(WindowResizeEvent& event);

	private:
		float m_Time = 0.0f;
	};
}