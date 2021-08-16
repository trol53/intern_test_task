//
// Created by trol53 on 03.07.2021.
//

#include "headers/check.h"
#include <iostream>

Check::Check(const std::string& file_name, const std::string& find_str): file_name(file_name), find_str(find_str) {}

Check::Check() = default;

bool Check::OpenFile() {
    file.open(file_name);
    return file.is_open();
}

int Check::FindSusp() {
    int count(0);
    std::string tmp;
    while (getline(file, tmp)){
        size_t i(0);
        for ( i = tmp.find(find_str, i++); i != std::string::npos; i = tmp.find(find_str, i + 1))
            count++;
    }
    file.close();
    return count;
}

int Check::Run() {
    if (!OpenFile()){
        return -1;
    }
    return FindSusp();
}

void Check::Restart(const std::string &file_name, const std::string &find_str) {
    this->file_name = file_name;
    this->find_str = find_str;
}
