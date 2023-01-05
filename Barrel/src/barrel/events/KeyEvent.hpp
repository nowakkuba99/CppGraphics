#ifndef C230FB5D_1772_4BF8_918D_3D61CBF28C94
#define C230FB5D_1772_4BF8_918D_3D61CBF28C94
/*
    File contains implementation of Key Event classes
*/
// Includes

// User includes
#include "Event.hpp"

namespace Barrel
{
    // KeyEvent class - abstract class
    class KeyEvent : public Event
    {
    public:
        int GetKeyCode()    const {return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        // Member variables
        int m_KeyCode;
        // Constructor
        KeyEvent(const int keyCode)
            : m_KeyCode(keyCode) {}
    };

    // KeyPressedEvent class
    class KeyPressedEvent : public KeyEvent
    {
    public:
        // Constructor
        KeyPressedEvent(const int keyCode, bool isRepeat = false)
            : KeyEvent(keyCode), m_isRepeat(isRepeat) {}
        // Custom functions
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: "<< m_KeyCode << " (reapeat = " << m_isRepeat <<")";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)
    private:
        bool m_isRepeat;
    };

    //Key Released class
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        // Constructor
        KeyReleasedEvent(const int keyCode)
            : KeyEvent(keyCode) {}
        // Custom functions
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };

    //KeyTypedEvent class
    class KeyTypedEvent: public KeyEvent
    {
    public:
        // Constructor
        KeyTypedEvent(const int keyCode)
            : KeyEvent(keyCode) {}
        // Custom functions
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str(); 
        }
        EVENT_CLASS_TYPE(KeyTyped)
    };
}
#endif /* C230FB5D_1772_4BF8_918D_3D61CBF28C94 */
