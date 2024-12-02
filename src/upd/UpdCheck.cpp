#include "UpdCheck.h"
#include <curl/curl.h>
#include <jansson.h>
#include <coreinit/filesystem.h>
#include <coreinit/core.h>
#include <whb/log.h>

struct FileWriteData {
    FSFileHandle handle;
    FSClient* client;
    FSCmdBlock* cmdBlock;
};

FSClient* UpdCheck::fsClient = nullptr;
FSCmdBlock* UpdCheck::cmdBlock = nullptr;

size_t UpdCheck::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t UpdCheck::WriteFile(void* ptr, size_t size, size_t nmemb, void* userp) {
    FileWriteData* fwd = (FileWriteData*)userp;
    uint32_t bytesWritten = 0;
    FSStatus status = FSWriteFile(
        fwd->client,
        fwd->cmdBlock,
        ptr,
        size * nmemb,
        1,
        fwd->handle,
        0,
        FS_ERROR_FLAG_NONE);
    
    if (status < 0) {
        return 0;
    }
    return size * nmemb;
}

bool UpdCheck::downloadUpdate(const std::string& url, const std::string& output_path) {
    if (!fsClient) {
        fsClient = (FSClient*)MEMAllocFromDefaultHeap(sizeof(FSClient));
        FSAddClient(fsClient, FS_ERROR_FLAG_NONE);
    }
    
    if (!cmdBlock) {
        cmdBlock = (FSCmdBlock*)MEMAllocFromDefaultHeap(sizeof(FSCmdBlock));
        FSInitCmdBlock(cmdBlock);
    }

    FSFileHandle fileHandle;
    FSStatus status = FSOpenFile(fsClient, cmdBlock, 
                                output_path.c_str(), 
                                "w", 
                                &fileHandle, 
                                FS_ERROR_FLAG_NONE);
    
    if (status < 0) {
        return false;
    }

    CURL* curl = curl_easy_init();
    if (!curl) {
        FSCloseFile(fsClient, cmdBlock, fileHandle, FS_ERROR_FLAG_NONE);
        return false;
    }

    FileWriteData fwd = {fileHandle, fsClient, cmdBlock};

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFile);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fwd);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode res = curl_easy_perform(curl);
    
    curl_easy_cleanup(curl);
    FSCloseFile(fsClient, cmdBlock, fileHandle, FS_ERROR_FLAG_NONE);

    return res == CURLE_OK;
}
if (res == CURLE_OK) {
        // If men.rpx downloaded successfully, download version.txt
        return downloadUpdate(update->tag + "/version.txt", 
                            "/vol/external01/wiiu/environments/aroma/version.txt");
    }
    
    return false;
