/*==============================================*/
/** @file error.hpp
 *  @brief Error logger definition.
 *
 *  This file defiens various functions related to 
 *  error handling in D2External functions.
 */
/*==============================================*/

#ifndef __ERROR_HPP__INCLUDED__
#define __ERROR_HPP__INCLUDED__

#include <wchar.h>
#include <wctype.h>

#define ERRCALL __cdecl 
/*==============================================*/
/** 
 *  @brief Log file initialisation.
 *
 *  Create and open a log file to write down
 *  any message or errors that can occurs during
 *  any D2External functions.
 *
 *  @param pPath : path to the log file relatively
 *  to the D2External.dll directory.
 *
 */
/*==============================================*/

void ERRCALL  set_logfile( const char* pPath );

/*==============================================*/
/** 
 *  @brief Write an error to the log-file.
 *
 *  Write an error description to the log-file.
 *  It also generate a dialog box telling the 
 *  player what happened.
 *
 *  @param pLocation : File name of the file 
 *  containing the function that cause the error. 
 *  Use __FILE__ macro to be safe.
 *
 *  @param pDesc : Description of the error.
 *
 */
/*==============================================*/

void ERRCALL  log_error( const char* pLocation, const char* pDesc );

/*==============================================*/
/** 
 *  @brief Write info to the log-file.
 *
 *  Write a simple message to the logfile.
 *
 *  @param pMessage: Message to write to the log.
 *
 */
/*==============================================*/

void ERRCALL log_info( const char* pMessage );

/*==============================================*/
/** 
 *  @brief Write formatted message to the logfile.
 *
 *  Write a printf like message to the log.
 *
 *  @param pFormat : printf like format to
 *  display string to the log. Other arguments
 *  are passed like in the printf C standard function.
 *
 */
/*==============================================*/

void ERRCALL log_message( const char* pFormat, ... );
/*==============================================*/
/** 
 *  @brief Write formatted message to the logfile.
 *
 *  Write a wprintf like message to the log.
 *
 *  @param pFormat : printf like format to
 *  display string to the log. Other arguments
 *  are passed like in the printf C standard function.
 *
 */
/*==============================================*/

void ERRCALL slog_wmessage( const wchar_t* pFormat, ... );

/*==============================================*/
/** 
 *  @brief Emergency exit function.
 *
 *  Close and shutdown both D2external.dll
 *  and Diablo II application when a critical error 
 *  occurs. Use it with care.
 *
 */
/*==============================================*/

void ERRCALL emergency_exit();

/*==============================================*/
/** 
 *  @brief Assertion test.
 *
 *  Verify if the pCondition argument is false.
 *  If it's false, the function throw an error and 
 *  an error dialog box to notify the user.
 *
 *  @param pCondition : Condition to verify before
 *  throwing an assertion error.
 *  @param pLocation : Filename of the file containing
 *  the assertion check. For safety, use the __FILE__
 *  macro.
 *  @param pMessage : A short description of the condition
 *  that's beign verified.
 *  @param pLineNbr : Line nbr of the assertion check.
 *  Use __LINE__ macro to be safe.
 *
 */
/*==============================================*/

void ERRCALL d2_assert( bool pCondition, char* pLocation, char* pMessage, int pLineNbr );


static char log_file[4096] = "";
static bool log_init = false;

#endif