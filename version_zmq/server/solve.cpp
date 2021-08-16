//
// Created by trol53 on 03.07.2021.
//

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include "headers/solve.h"
#include <ctime>




void Output::Print(time_t time){
    time_t hours = time / 3600;
    time %= 3600;
    time_t minutes = time / 60;
    time %= 60;
    std::cout << "===== Scan result =====\n";
    std::cout << "Processed files: " << count_file << '\n';
    std::cout << "JS detects: " << count_js <<  '\n';
    std::cout << "UNIX detects: " << count_un << '\n';
    std::cout << "macOS detects: " << count_mac << '\n';
    std::cout << "Errors: " << count_error << '\n';
    std::cout << "Exection time: " << hours << ':' << minutes << ':' << time << '\n';
    std::cout << "=========================\n";
}

void Output::clear(){
    Output new_out;
    *this = new_out;
}


void Output::operator+=(const Output& add){
    count_file += add.count_file;
    count_error += add.count_error;
    count_mac += add.count_mac;
    count_un += add.count_un;
    count_js += add.count_js;
}


Solve::Solve(const std::string& directory) : directory(directory){}


void Solve::res_from_thread(std::vector<Output>& v_out, std::vector<std::string>& file_buff){
    std::thread th1(susp_find, file_buff[0], std::ref(v_out[0]));
    std::thread th2(susp_find, file_buff[1], std::ref(v_out[1]));
    th1.join();
    th2.join();
}

void Solve::Run() {
    time_t start = time(0);
    std::filesystem::path p(directory);
    if (!std::filesystem::is_directory(p)){
        std::cout << "wrong directory name\n";
        return;
    }
    Output out;
    std::vector<Output> v_out(2);
    std::vector<std::string> file_buff;
    for (const auto & entry : std::filesystem::directory_iterator(p)) {
        std::string file_name = entry.path().string();
        file_buff.push_back(file_name);
        if (file_buff.size() == 2){
            res_from_thread(v_out, file_buff);
            out += v_out[0];
            out += v_out[1];
            v_out[0].clear();
            v_out[1].clear();
            file_buff.clear();
        }

    }
    if (!file_buff.empty()){
        susp_find(file_buff[0], v_out[0]);
        out += v_out[0];
    }
    time_t end = time(0);
    out.Print(end - start);

}





