#include "mpch.h"

#include "Application.h"
#include "Mirra/Events/ApplicationEvent.h"
#include "Mirra/Logger.h"

namespace Mirra {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			LOG_TRACE(e);
		}

		while (true);
	}
}
