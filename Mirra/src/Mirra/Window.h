#pragma once
#include "mpch.h"

#include "Mirra/Core.h"
#include "Mirra/Events/Event.h"
#include "Mirra/Events/ApplicationEvent.h"
#include "Mirra/Events/MouseEvent.h"
#include "Mirra/Events/KeyEvent.h"

namespace Mirra 
{
	struct WindowProps 
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Mirra Engine", 
			unsigned int width = 1280, unsigned int height = 720) 
			: Title(title), Width(width), Height(height) 
		{
		
		}
	};
	//interface representing a desktop system based window
	class MIRRA_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}