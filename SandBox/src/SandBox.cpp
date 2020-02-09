#include <Mirra.h>
#include "Mirra\ImGui\ImGuiLayer.h"
class ExampleLayer : public Mirra::Layer {
public:
	ExampleLayer()
		: Layer("Example") {
		

	}

	void OnUpdate() override
	{
		
		if (Mirra::Input::IsKeyPressed(MIRRA_KEY_TAB)) {
			LOG_INFO("Tab was Pressed...");
		}
	}

	void OnEvent(Mirra::Event& event) override
	{
		//LOG_TRACE("{0}", event)
		if (event.GetEventType() == Mirra::EventType::KeyPressed) {
			Mirra::KeyPressedEvent& e = (Mirra::KeyPressedEvent&)event;
			LOG_TRACE("KeyCode-> {0}", (char)e.GetKeyCode());
		}
	}

};

class SandBox : public Mirra::Application {
public:
	SandBox() {
		LOG_INFO("Welcome to Mirra Engine {0}", "XxSadPandaxX");
		PushLayer(new ExampleLayer());
		PushOverlay(new Mirra::ImGuiLayer());

	}
	~SandBox() {}
};

Mirra::Application* Mirra::CreateApplication() {
	return new SandBox();
}

//Change SDK version to 10+