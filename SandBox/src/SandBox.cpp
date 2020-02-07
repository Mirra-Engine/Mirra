#include <Mirra.h>

class ExampleLayer : public Mirra::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		LOG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Mirra::Event& event) override
	{
		LOG_TRACE("{0}", event)
	}

};

class SandBox : public Mirra::Application {
public:
	SandBox() {
		PushLayer(new ExampleLayer());
	}
	~SandBox() {}
};

Mirra::Application* Mirra::CreateApplication() {
	return new SandBox();
}

//Change SDK version to 10+