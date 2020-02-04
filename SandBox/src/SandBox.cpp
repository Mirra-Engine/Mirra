#include <Mirra.h>

class SandBox : public Mirra::Application {
public:
	SandBox() {}
	~SandBox() {}
};

Mirra::Application* Mirra::CreateApplication() {
	return new SandBox();
}
