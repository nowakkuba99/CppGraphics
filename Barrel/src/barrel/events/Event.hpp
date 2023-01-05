#ifndef A27158E7_9A81_430A_B5D2_DCADA47E86B8
#define A27158E7_9A81_430A_B5D2_DCADA47E86B8
/*
    Main file regarding event system
*/

/* --------------- MACROS --------------- */
// Bitfield macro
#define BIT(x) (1 << x) //Move 1 x bits to the left

// User includes

// Event system
namespace Barrel
{
    // Enums for different event types
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,   // Window event group
        AppTick, AppUpdate, AppRender,                                          // App event group
        KeyPressed, KeyReleased, KeyTyped,                                      // Key event group
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled        // Mouse event group
    };

    // Enums for event categories
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    // MACROS used to override virtual functions
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                                virtual const char* GetName() const override { return #type; }
    
    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    
    //  Event Class - Interface (base class) for different event types
    class Event
    {
        friend class EventDispatcher;   //?
    public:
        // Pure virtual functions - need to be implemented
        virtual EventType GetEventType() const = 0;     // Function to get event type
        virtual const char* GetName() const = 0;        // Function to get event name
        virtual int GetCategoryFlags()  const = 0;      //Function to get event category
        // Virtual functions - may be overwritten
        virtual std::string ToString() const {return GetName();}

        // Other functions
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
        bool m_Handled = false;     // Variable to keep track if event has been handled
    };

    // Event dispatcher class
    class EventDispatcher
    {
    public:
        // Constructor
        EventDispatcher(Event& event)
            :m_Event(event) {}
        // Custom functions
        template<typename T, typename F>
        bool dispatch(const F& func)                                      //Function that checks if event type matches the type of function and runs function releated with event type
        {
            if(m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    
    private:
        // Member variables
        Event& m_Event;
    };

    // Override output string operator << to log events
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os<< e.ToString();
    }

}






#endif /* A27158E7_9A81_430A_B5D2_DCADA47E86B8 */
