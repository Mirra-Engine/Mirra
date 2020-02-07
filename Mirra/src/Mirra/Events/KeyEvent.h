#pragma once

#include "Event.h"


namespace Mirra {
	class MIRRA_API KeyEvent : public Event
	{
	public:
		//getter for the keycode
		inline int GetKeyCode() const { return m_KeyCode; }

		//sets the category of the event
		EVENT_CLASS_CATEGORY(EventCatategoryKeyboard | EventCatagoryInput)
	protected:
		//protected constructor
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		//the actual keycode
		int m_KeyCode
	};
	
	class MIRRA_API KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		// get for the repeat count
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << ", Repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		// how many times the key has been called since its been pressed down
		int m_RepeatCount;
	};
	class MIRRA_API KeyReleasedEvent : public Event
	{
	public :
		KeyReleasedEvent(int keycode)
			: KeyCode(keycode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(KeyReleased)
	};
}