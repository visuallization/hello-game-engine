#include "Application.h"

#include "Hello/Events/ApplicationEvent.h"
#include "Hello/Log.h"

namespace Hello {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			HO_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			HO_TRACE(e);
		}

		while (true);
	}
}