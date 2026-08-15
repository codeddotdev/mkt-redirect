#include <jni.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>


#include <android/log.h>


#ifndef ANDROID_LOG_INFO
#define ANDROID_LOG_INFO 4
#endif

#define LOG_TAG "NetRedirector"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// store the original getaddrinfo func
int (*orig_getaddrinfo)(const char* node, const char* service,
    const struct addrinfo* hints, struct addrinfo** res);


int hooked_getaddrinfo(const char* node, const char* service,
    const struct addrinfo* hints, struct addrinfo** res) {
    if (node != NULL) {
        // sniff for the original ip
        LOGI("[DISCOVERY] Game is requesting network address for: %s", node);

        
        if (strstr(node, "nintendo.com") != NULL ||
            strstr(node, "nintendo.net") != NULL ||
            strstr(node, "dena.jp") != NULL) {

            LOGI("Intercepted: %s -> Rerouting traffic!", node);

           // change ip 
            node = "127.0.0.1"; // change to actual ip of server
        }
    }
    return orig_getaddrinfo(node, service, hints, res);
}


// Memory address patching mechanism (Inline hook helper)
void hook_function(void* target, void* hook, void** original) {
    *original = target;
    // Note: If you face crashes during early engine initialization, 
    // swap this helper with an architecture-safe hooking framework like Dobby.
}

// Executed automatically by Android OS as soon as System.loadLibrary() is invoked
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("Redirector sub-library injected successfully. Initialising hooks...");

    // Look up the physical location of getaddrinfo inside Android's libc system binary
    void* getaddrinfo_addr = (void*)getaddrinfo;

    if (getaddrinfo_addr != NULL) {
        hook_function(getaddrinfo_addr, (void*)hooked_getaddrinfo, (void**)&orig_getaddrinfo);
        LOGI("Successfully hooked libc.so -> getaddrinfo");
    }
    else {
        LOGI("ERROR: Failed to resolve getaddrinfo address in libc.");
    }

    return JNI_VERSION_1_6;
}