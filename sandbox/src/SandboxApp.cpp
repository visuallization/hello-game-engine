#include <Hello.h>

class Sandbox : public Hello::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Hello::Application* Hello::CreateApplication() {
	return new Sandbox();
}