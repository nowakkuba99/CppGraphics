#ifndef C2FBE8C5_F6E9_432E_8D2D_780ED3F88731
#define C2FBE8C5_F6E9_432E_8D2D_780ED3F88731

/*
    File contains implementation of Application Event classes
*/
// Includes
#include "Event.hpp"

namespace Barrel
{
    // Window resize event class
    class WindowResizeEvent : public Event
    {
    public:
        // Constructor
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}
        // Custom functions
        unsigned int getWidth() const { return m_Width; }
        unsigned int getHeigth() const { return m_Height; }
        // Override functions
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        // Member variables
        unsigned int m_Width, m_Height;
    };

    // Window close event class
    class WindowCloseEvent : public Event
	{
	public:
        // Constructor
		WindowCloseEvent() = default;
        // Override functions
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public Event
	{
	public:
        // Constructor
		AppTickEvent() = default;
        // Override functions
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public Event
	{
	public:
        // Constructor
		AppUpdateEvent() = default;
        // Override functions
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public Event
	{
	public:
        // Constructor
		AppRenderEvent() = default;
        // Override functions
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}

#endif /* C2FBE8C5_F6E9_432E_8D2D_780ED3F88731 */
