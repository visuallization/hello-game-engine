#include <Hello.h>

class ExampleLayer : public Hello::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		if (Hello::Input::GetKeyPressed(HO_KEY_TAB)) {
			HO_TRACE("Tab key is pressed! (poll)");
		}
	}

	void OnEvent(Hello::Event& event) override {
		if (event.GetEventType() == Hello::EventType::KeyPressed) {
			Hello::KeyPressedEvent& e = (Hello::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HO_KEY_TAB) {
				HO_TRACE("Tab key is pressed! (event)");
			}
			HO_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Hello::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hello::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Hello::Application* Hello::CreateApplication() {
	return new Sandbox();
}