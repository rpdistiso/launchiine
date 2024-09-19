#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include "fs/DirList.h"
#include "utils/StringTools.h"

DirList::DirList() {
  Flags = 0;
  Filter = 0;
  Depth = 0;
}

DirList::DirList(const std::string & path,
  const char * filter, uint32_t flags, uint32_t maxDepth) {
  this -> LoadPath(path, filter, flags, maxDepth);
  this -> SortList();
}

DirList::~DirList() {
  ClearList();
}

BOOL DirList::LoadPath(const std::string & folder,
  const char * filter, uint32_t flags, uint32_t maxDepth) {
  if (folder.empty())
    return false;

  Flags = flags;
  Filter = filter;
  Depth = maxDepth;

  std::string folderpath(folder);
  uint32_t length = folderpath.size();

  //! clear path of double slashes
  StringTools::RemoveDoubleSlashs(folderpath);

  //! remove last slash if exists
  if (length > 0 && folderpath[length - 1] == '/')
    folderpath.erase(length - 1);

  //! add root slash if missing
  if (folderpath.find('/') == std::string::npos) {
    folderpath += '/';
  }

  return InternalLoadPath(folderpath);
}

BOOL DirList::InternalLoadPath(std::string & folderpath) {
  if (folderpath.size() < 3)
    return false;

  struct dirent * dirent = nullptr;
  DIR * dir = nullptr;

  dir = opendir(folderpath.c_str());
  if (dir == nullptr)
    return false;

  while ((dirent = readdir(dir)) != 0) {
    BOOL isDir = dirent -> d_type & DT_DIR;
    const char * filename = dirent -> d_name;

    if (isDir) {
      if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0)
        continue;

      if ((Flags & CheckSubfolders) && (Depth > 0)) {
        int32_t length = folderpath.size();
        if (length > 2 && folderpath[length - 1] != '/') {
          folderpath += '/';
        }
        folderpath += filename;

        Depth--;
        InternalLoadPath(folderpath);
        folderpath.erase(length);
        Depth++;
      }

      if (!(Flags & Dirs))
        continue;
    } else if (!(Flags & Files)) {
      continue;
    }

    if (Filter) {
      char * fileext = strrchr(filename, '.');
      if (!fileext)
        continue;

      if (StringTools::strtokcmp(fileext, Filter, ",") == 0)
        AddEntrie(folderpath, filename, isDir);
    } else {
      AddEntrie(folderpath, filename, isDir);
    }
  }
  closedir(dir);

  return true;
}

void DirList::AddEntrie(const std::string & filepath,
  const char * filename, BOOL isDir) {
  if (!filename)
    return;

  int32_t pos = FileInfo.size();

  FileInfo.resize(pos + 1);

  FileInfo[pos].FilePath = (char * ) malloc(filepath.size() + strlen(filename) + 2);
  if (!FileInfo[pos].FilePath) {
    FileInfo.resize(pos);
    return;
  }

  sprintf(FileInfo[pos].FilePath, "%s/%s", filepath.c_str(), filename);
  FileInfo[pos].isDir = isDir;
}

void DirList::ClearList() {
  for (uint32_t i = 0; i < FileInfo.size(); ++i) {
    if (FileInfo[i].FilePath) {
      free(FileInfo[i].FilePath);
      FileInfo[i].FilePath = nullptr;
    }
  }

  FileInfo.clear();
  std::vector < DirEntry > ().swap(FileInfo);
}

const char * DirList::GetFilename(int32_t ind) const {
  if (!valid(ind))
    return "";

  return StringTools::FullpathToFilename(FileInfo[ind].FilePath);
}

static BOOL SortCallback(const DirEntry & f1,
  const DirEntry & f2) {
  if (f1.isDir && !(f2.isDir))
    return true;
  if (!(f1.isDir) && f2.isDir)
    return false;

  if (f1.FilePath && !f2.FilePath)
    return true;
  if (!f1.FilePath)
    return false;

  if (strcasecmp(f1.FilePath, f2.FilePath) > 0)
    return false;

  return true;
}

void DirList::SortList() {
  if (FileInfo.size() > 1)
    std::sort(FileInfo.begin(), FileInfo.end(), SortCallback);
}

void DirList::SortList(BOOL( * SortFunc)(const DirEntry & a,
  const DirEntry & b)) {
  if (FileInfo.size() > 1)
    std::sort(FileInfo.begin(), FileInfo.end(), SortFunc);
}

uint64_t DirList::GetFilesize(int32_t index) const {
  struct stat st;
  const char * path = GetFilepath(index);

  if (!path || stat(path, & st) != 0)
    return 0;

  return st.st_size;
}

int32_t DirList::GetFileIndex(const char * filename) const {
  if (!filename)
    return -1;

  for (uint32_t i = 0; i < FileInfo.size(); ++i) {
    if (strcasecmp(GetFilename(i), filename) == 0)
      return i;
  }

  return -1;
}
