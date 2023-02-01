#include <Hello.h>

class ExampleLayer : public Hello::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		if (Hello::Input::GetKeyPressed(HO_KEY_TAB)) {
			HO_TRACE("Tab key is pressed!");
		}
	}

	void OnEvent(Hello::Event& event) override {
		//HO_TRACE("{0}", event);
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