#ifndef _D2LAUNCH_H
#define _D2LAUNCH_H

#define D2LAUNCH_API_(T) D2API_(T)
#define D2LAUNCHCALL_(T) D2CALL_(T)
#define D2LAUNCHDATA D2DATA



#ifdef __cplusplus
extern "C" {
#endif


// Existing exports
D2LAUNCH_API_(DWORD) D2Launch_1();	// QueryInterface
//;----------------------------------
// Added exports


D2LAUNCHDATA DWORD D2Launch_10464;
 
//;----------------------------------


#define D2LAUNCH_LASTORD D2Launch_10464;
#define D2LAUNCH_BASE D2Launch_10464;



#ifdef __cplusplus
}
#endif

#endif