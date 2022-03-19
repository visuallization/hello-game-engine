#include <Hello.h>

class ExampleLayer : public Hello::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		HO_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hello::Event& event) override {
		HO_TRACE("{0}", event);
	}
};

class Sandbox : public Hello::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Hello::Application* Hello::CreateApplication() {
	return new Sandbox();
}