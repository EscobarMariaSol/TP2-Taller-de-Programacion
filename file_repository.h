#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include <string>
#include <queue>
#include <mutex>
#include <iostream>
#include <functional>

class FileRepository {

private:
    std::queue<std::string> files;
    std::mutex mutex;

public:
    FileRepository();
    ~FileRepository();
    void addFile(const std::string& file_path);
    std::string getFile();
    FileRepository(const FileRepository&);
    FileRepository& operator=(const FileRepository&);

    
};

#endif // FILE_REPOSITORY_H