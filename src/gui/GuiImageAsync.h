#ifndef _GUIIMAGEASYNC_H_
#define _GUIIMAGEASYNC_H_

#include <gui/GuiImage.h>
#include <gui/system/CThread.h>
#include <mutex>
#include <vector>

class GuiImageAsync : public GuiImage {
public:
    GuiImageAsync(const uint8_t *imageBuffer, const uint32_t &imageBufferSize, GuiImageData *preloadImg);

    GuiImageAsync(const std::string &filename, GuiImageData *preloadImg);

    virtual ~GuiImageAsync();

    static void clearQueue();

    static void removeFromQueue(GuiImageAsync *image) {
        threadRemoveImage(image);
    }

    //! don't forget to LOCK GUI if using this asynchron call
    sigslot::signal1<GuiImageAsync *> imageLoaded;

    static void threadExit();

private:
    static void threadInit();

    GuiImageData *imgData;
    std::string filename;
    const uint8_t *imgBuffer;
    const uint32_t imgBufferSize;

    static void guiImageAsyncThread(CThread *thread, void *arg);

    static void threadAddImage(GuiImageAsync *Image);

    static void threadRemoveImage(GuiImageAsync *Image);

    static std::vector<GuiImageAsync *> imageQueue;
    static CThread *pThread;
    static std::recursive_mutex *pMutex;
    static uint32_t threadRefCounter;
    static GuiImageAsync *pInUse;
    static bool bExitRequested;
};

#endif /*_GUIIMAGEASYNC_H_*/
