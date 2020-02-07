#pragma once

#include "Event.h"

namespace Mirra {
	class MIRRA_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCatagoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;

	};

	class MIRRA_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			:m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline float getOffsetX() const { return m_OffsetX; }

		inline float getoffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCatagoryMouse | EventCategoryInput)
	private:
		float m_OffsetX, m_OffsetY;

	}

	class MIRRA_API MouseButtonEvent : public Event
	{
	public:
		inline float getMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCatagoryMouse | EventCategoryInput)
	protected:
		MouseMovedEvent(int button) : m_Button(button) {}

		int m_Button;

	}
	class MIRRA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	
	}
	class MIRRA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	}
}