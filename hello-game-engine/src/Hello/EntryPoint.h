#pragma once

#ifdef HO_PLATFORM_WINDOWS

extern Hello::Application* Hello::CreateApplication();

int main(int argc,  char** argv) {
	printf("Start Hello Engine\n");
	auto app = Hello::CreateApplication();
	app->Run();
	delete app;
}

#endif

