#ifndef _D2CLIENT_H
#define _D2CLIENT_H

//#define D2CLIENT_API D2API
//#define D2CLIENTCALL D2CALL
#define D2CLIENT_API_(T) D2API_(T)
#define D2CLIENTCALL_(T) D2CALL_(T)
#define D2CLIENTDATA D2DATA

#ifdef __cplusplus
extern "C" {
#endif

//----- Ordinal Exports -----------------
// Existing exports
D2CLIENT_API_(DWORD) D2Client_10001();
D2CLIENT_API_(DWORD) D2Client_10002();
D2CLIENT_API_(DWORD) D2Client_10003();
D2CLIENT_API_(DWORD) D2Client_10004();

// New Added exports
D2CLIENTCALL_(DWORD)
	D2Client_10005(int,int,int,int,DWORD,DWORD);	// FillRect
D2CLIENTCALL_(LPUNIT)	D2Client_10006();		// GetClient
D2CLIENTDATA POINT		D2Client_10007;			// PTMOUSE
D2CLIENTDATA int		D2Client_10008;			// gScreenX
D2CLIENTDATA int		D2Client_10009;			// gScreenY
D2CLIENTCALL_(DWORD)	D2Client_10010(LPVOID);	// GetMercClass


D2CLIENTDATA DWORD D2Client_10501;			// Tag for highest available ord

//------ human readable names -----------

#define D2ClientFillRect D2Client_10005		// +0xBB0F0
#define D2ClientGetClient D2Client_10006	// +0x883D0

#define ptMouse D2Client_10007				// +0x121AE4
#define gScreenX D2Client_10008				// +0x0D40EC
#define gScreenY D2Client_10009				// +0x0D40F0
#define GetMercClass D2Client_10010			// +0x011AE0


//---------------------------------------
#define D2CLIENT_LASTORD D2Client_10501;

#ifdef __cplusplus
}
#endif

#endif
