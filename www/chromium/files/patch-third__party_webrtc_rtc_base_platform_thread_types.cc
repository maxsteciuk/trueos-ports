--- third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2018-07-19 22:28:12.880328000 +0200
+++ third_party/webrtc/rtc_base/platform_thread_types.cc	2018-07-19 22:30:17.907866000 +0200
@@ -11,7 +11,9 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -27,8 +29,10 @@
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) && !defined(__FreeBSD__)
   return syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #else
   // Default implementation for nacl and solaris.
   return reinterpret_cast<pid_t>(pthread_self());
@@ -55,6 +59,7 @@
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__FreeBSD__)
 #if defined(WEBRTC_WIN)
   struct {
     DWORD dwType;
@@ -72,6 +77,7 @@
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
