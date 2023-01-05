#ifndef E4D7D491_B7B7_4CF1_9F04_56649138439F
#define E4D7D491_B7B7_4CF1_9F04_56649138439F
/*
    File contains implementation of Mouse Event classes
*/

//Includes
#include "Event.hpp"

namespace Barrel
{
    // Mouse moved class
    class MouseMovedEvent : public Event
    {
    public:
        // Constructor
        MouseMovedEvent(const float x, const float y)
            : m_MouseX(x), m_MouseY(y) {}
        // Custom functions
        float getX() const { return m_MouseX; }
        float getY() const { return m_MouseY; }
        // Override functions
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        // Member variables
        float m_MouseX, m_MouseY;
    };

    // Mouse moved class
    class MouseScrolledEvent : public Event
	{
	public:
        // Constructor
		MouseScrolledEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}
        // Custom functions
		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }
        // Override functions
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
        // Member variables
		float m_XOffset, m_YOffset;
	};

    // Mouse button Event - abstract class 
	class MouseButtonEvent : public Event
	{
	public:
        // Public functions
		int GetMouseButton() const { return m_Button; }
        // Override functions
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
        // Constructor
		MouseButtonEvent(const int button)
			: m_Button(button) {}
        // Member variables
		int m_Button;
	};

    // Mouse button pressed event class
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
        // Constructor
		MouseButtonPressedEvent(const int button)
			: MouseButtonEvent(button) {}
        // Override functions
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

    // Mouse button released event class
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
        // Constructor
		MouseButtonReleasedEvent(const int button)
			: MouseButtonEvent(button) {}
        // Override functions
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif /* E4D7D491_B7B7_4CF1_9F04_56649138439F */
