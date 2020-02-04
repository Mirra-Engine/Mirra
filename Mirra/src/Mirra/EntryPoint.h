#pragma once

#ifdef ME_PLATFORM_WINDOWS  // will start Mirra on windows... 
extern Mirra::Application* Mirra::CreateApplication();

int main(int argc, char** argv) {
	auto app = Mirra::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Mirra Only Supports Windows
#endif // ME_PLATFORM_WINDOWS
