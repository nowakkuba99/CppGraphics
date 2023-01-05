#ifndef B48B6F7C_C8ED_4F71_AB61_6735D6F9879E
#define B48B6F7C_C8ED_4F71_AB61_6735D6F9879E
// Includes
#pragma warning(push, 0)    //Ignore warnings from external libs
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)
// User defined includes

namespace Barrel
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    public:
        // Constructor
        Log();
        // Destructor
        ~Log();
        // Member functions
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;};
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;};
        
        static void Init();
    };
    
}

/* Core Macros defines */
#define BR_CORE_TRACE(s,...)  ::Barrel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BR_CORE_INFO(...)   ::Barrel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BR_CORE_WARN(...)   ::Barrel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BR_CORE_ERROR(...)  ::Barrel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BR_CORE_FATAL(...)  ::Barrel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client Macros defines */
#define BR_TRACE(...)  ::Barrel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BR_INFO(...)   ::Barrel::Log::GetClientLogger()->info(__VA_ARGS__)
#define BR_WARN(...)   ::Barrel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BR_ERROR(...)  ::Barrel::Log::GetClientLogger()->error(__VA_ARGS__)
#define BR_FATAL(...)  ::Barrel::Log::GetClientLogger()->fatal(__VA_ARGS)


//#define BR_CORE_TRACE(...)  ::Barrel::Log::GetCoreLogger()->(((std::string)"📘 " + S__VA_ARGS__).c_str())
//#define BR_CORE_INFO(...)   ::Barrel::Log::GetCoreLogger()->info(((std::string)"📗 " + __VA_ARGS__).c_str())
//#define BR_CORE_WARN(...)   ::Barrel::Log::GetCoreLogger()->warn(((std::string)"📙 " + __VA_ARGS__).c_str())
//#define BR_CORE_ERROR(...)  ::Barrel::Log::GetCoreLogger()->error(((std::string)"📕 " + __VA_ARGS__).c_str())
//#define BR_CORE_FATAL(...)  ::Barrel::Log::GetCoreLogger()->fatal(((std::string)"🛑 " + __VA_ARGS__).c_str())
//
///* Client Macros defines */
//#define BR_TRACE(...)  ::Barrel::Log::GetClientLogger()->trace(((std::string)"📘 " + __VA_ARGS__).c_str())
//#define BR_INFO(...)   ::Barrel::Log::GetClientLogger()->info(((std::string)"📗 " + __VA_ARGS__).c_str())
//#define BR_WARN(...)   ::Barrel::Log::GetClientLogger()->warn(((std::string)"📙 " + __VA_ARGS__).c_str())
//#define BR_ERROR(...)  ::Barrel::Log::GetClientLogger()->error(((std::string)"📕 " + __VA_ARGS__).c_str())
//#define BR_FATAL(...)  ::Barrel::Log::GetClientLogger()->fatal(((std::string)"🛑 " + __VA_ARGS__).c_str())

#endif /* B48B6F7C_C8ED_4F71_AB61_6735D6F9879E */
