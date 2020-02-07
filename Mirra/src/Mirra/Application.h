#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Mirra {
	class MIRRA_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//To Be Defined in Client
	Application* CreateApplication();
}