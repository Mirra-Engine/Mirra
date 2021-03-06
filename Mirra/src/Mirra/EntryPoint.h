#pragma once

#ifdef ME_PLATFORM_WINDOWS  // will start Mirra on windows... 
extern Mirra::Application* Mirra::CreateApplication();

int main(int argc, char** argv) {

	Mirra::Logger::Init();

	LOG_CORE_INFO("Initalized Logger...");
	
	auto app = Mirra::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Mirra Only Supports Windows
#endif // ME_PLATFORM_WINDOWS
