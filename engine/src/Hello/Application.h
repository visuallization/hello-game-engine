#pragma once

#include "Core.h"
#include "Window.h"

#include "Hello/LayerStack.h"
#include "Hello/Events/Event.h"
#include "Hello/Events/ApplicationEvent.h"
#include "Hello/ImGui/ImGuiLayer.h"

namespace Hello {

	class HELLO_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance;  }
		inline Window& GetWindow() { return *m_Window;  }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

