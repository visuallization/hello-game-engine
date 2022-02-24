#pragma once

#ifdef HO_PLATFORM_WINDOWS

extern Hello::Application* Hello::CreateApplication();

int main(int argc,  char** argv) {
	Hello::Log::Init();
	HO_CORE_INFO("Initializing Logging System!");
	HO_CORE_WARN("Hello Core Logger");
	HO_INFO("Hello Client Logger");

	auto app = Hello::CreateApplication();
	app->Run();
	delete app;
}

#endif

