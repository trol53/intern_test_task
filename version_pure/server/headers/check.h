//
// Created by trol53 on 03.07.2021.
//

#ifndef EASY_TASK_CHECK_H
#define EASY_TASK_CHECK_H

#include <string>
#include <fstream>

class Check {
public:
    Check();
    Check(const std::string& file_name, const std::string& find_str);
    int Run();
    void Restart(const std::string& file_name, const std::string& find_str);

private:
    bool OpenFile();
    int FindSusp();


    std::string file_name;
    std::string find_str;
    std::ifstream file;
};


#endif //EASY_TASK_CHECK_H
