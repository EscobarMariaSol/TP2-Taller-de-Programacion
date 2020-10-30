#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include <string>
#include <queue>

class FileRepository {

private:
    std::queue<std::string> files;

public:
    FileRepository();
    ~FileRepository();
    void addFile(const std::string file_path);
    std::string getFile();
};

#endif // FILE_REPOSITORY_H