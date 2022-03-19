#pragma once

#include "Core.h"
#include "Window.h"

#include "Hello/LayerStack.h"
#include "Hello/Events/Event.h"
#include "Hello/Events/ApplicationEvent.h"

namespace Hello {

	class HELLO_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

