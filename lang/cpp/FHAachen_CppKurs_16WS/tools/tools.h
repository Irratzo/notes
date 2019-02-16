// Author: A.Voss@FH-Aachen.de
//
// helper functions

#ifndef TOOlS_
#define TOOLS_ 1

#if defined(__cplusplus) 

#if defined(_GLIBCXX_THREAD)    // note: _GLIBCXX_THREAD is g++ specific
#define TOOLS_USE_THREADS_
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <sstream>
#include <thread>
#include <unordered_map>

static const char * tools_course_name_ = "C++";

#if defined(TOOLS_USE_THREADS_)
std::chrono::time_point<std::chrono::system_clock>    tools_start_timestamp_;
std::unordered_map<std::thread::id,std::string>       thread_names_;
#endif

#else  // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char * tools_course_name_ = "C";

#endif  // __cplusplus

static int tools_is_init_ = 0;

inline static void tools_print_end_() 
{
    printf("\n--- '%s' ---\n\n",__BASE_FILE__);
}

inline static int tools_print_begin_() 
{
    // note: __BASE_FILE__ is g++ specific
    printf("\n--- '%s' --- %s training course, FH Aachen ---\n\n",__BASE_FILE__,tools_course_name_);
    printf("Line  Function   ");

#if defined(__cplusplus) && defined(TOOLS_USE_THREADS_)
    tools_start_timestamp_ = std::chrono::system_clock::now();
    thread_names_[std::this_thread::get_id()] = "main";
    printf("  Time  Thread   ");
#endif

    printf(" |  Comment\n\n");
    
    return 1;
}

inline static void tools_print_lineinfo_(unsigned int line, const char * func) 
{
    if (0==tools_is_init_) { tools_is_init_=1; tools_print_begin_(); atexit(tools_print_end_); }
    
    const unsigned int maxlen = 10;
    char funcname[maxlen+1];
    strncpy(funcname,func,maxlen); funcname[maxlen]='\0';

    printf("%4d  %-10s ",line,funcname);

#if defined(__cplusplus) && defined(TOOLS_USE_THREADS_)
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-tools_start_timestamp_);
    double tm = (double)(elapsed.count())/1000.0;

    std::string thread_name = thread_names_[std::this_thread::get_id()];
    if (thread_name.length()==0)
    {
        std::stringstream thread_id; thread_id << std::this_thread::get_id();
        thread_name = thread_id.str();
        if (thread_name.length()>6)
            thread_name = ".."+thread_name.substr(thread_name.length()-6,6);
    }
    else if (thread_name.length()>8)
        thread_name = thread_name.substr(0,8);
   
    printf("%6.3f  %-8s ",tm,thread_name.c_str());
#endif

    printf(" |  ");
    if (strcmp(func,"main"))
        printf("... ");
}
#define tools_log()                     tools_print_lineinfo_(__LINE__,__FUNCTION__)

#if defined(__cplusplus) && defined(TOOLS_USE_THREADS_)
// replace thread-id with variable name
// use: std::thread thread_A(do_work); tools_registerthread(thread_A);
inline static void tools_register_threadname_(const std::thread::id & id, const std::string & s) 
{
    thread_names_[id] = s;
}
#define tools_registerthreadname(THREAD)    tools_register_threadname_((THREAD).get_id(),#THREAD)
#endif

#endif  // TOOlS_

