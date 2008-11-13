//**************************************************************************************// Filename:	CFAbstractCMPlugin.h//				Part of Contextual Menu Workshop by Abracode Inc.//// Description:	Base code for CM plugin taking care of COM interface and communication with a host.//				Not needed to be modified in most cases.//				// Usage:		see Documentation.txt//// License:		This code is based on "CFPluginMenu.cp" and "SampleCMPlugin.c"//				of "SampleCMPlugin" from Apple.//				Great thanks to George Warner for providing these sources.//						//**************************************************************************************#ifndef __CFAbstractCMPlugin__#define __CFAbstractCMPlugin__#if defined(__MACH__)    #import <CoreFoundation/CFPluginCOM.h>    #import <Carbon/Carbon.h>#else	#include <CFPluginCOM.h>	#include <Menus.h>#endif //__MACH__#include "CMPluginImpl.h"// The layout for an instance of AbstractCMPluginType.typedef struct AbstractCMPluginType{	ContextualMenuInterfaceStruct	*interface;	CFUUIDRef						factoryID;	UInt32							refCount;	CFBundleRef						bundleRef;//filled in by AllocAbstractCMPluginType() using CM_IMPL_PLUGIN_BUNDLE_INDENTIFIER    CMPluginImplData				implData; //defined and used by plugin implementation} AbstractCMPluginType;// -----------------------------------------------------------------------------//	abstract plugin methods, no need to change it in most cases// -----------------------------------------------------------------------------#ifdef __cplusplusextern "C" {#endif#pragma export on	void *					AbstractCMPluginFactory( CFAllocatorRef allocator, CFUUIDRef typeID );#pragma export reset	HRESULT					AbstractCMPluginQueryInterface( void *thisInstance, REFIID iid, LPVOID *ppv );	ULONG					AbstractCMPluginAddRef( void *thisInstance );	ULONG					AbstractCMPluginRelease( void *thisInstance );	AbstractCMPluginType *	AllocAbstractCMPluginType( CFUUIDRef inFactoryID );	void					DeallocAbstractCMPluginType( AbstractCMPluginType *thisInstance );//	methods required by abstract plugin//	must be implemented by concrete plugin	OSStatus				CMPluginExamineContext( void *thisInstance, const AEDesc *inContext, AEDescList *outCommandPairs );	OSStatus				CMPluginHandleSelection( void *thisInstance, AEDesc *inContext, SInt32 inCommandID );	void					CMPluginPostMenuCleanup( void *thisInstance );#ifdef __cplusplus}#endif#endif //__CFAbstractCMPlugin__