//
// Created by trol53 on 03.07.2021.
//

#ifndef EASY_TASK_SOLVE_H
#define EASY_TASK_SOLVE_H

#include <vector>
#include <string>
#include <filesystem>
#include "check.h"

const std::string JSSUSP = "<script>evil_script()</script>";
const std::string USUSP = "rm -rf ~/Documents";
const std::string MSUSP = "system(\"launchctl load /Library/LaunchAgents/com.malware.agent\"";

struct Output{
    int count_file = 0;
    int count_error = 0;
    int count_js = 0;
    int count_un = 0;
    int count_mac = 0;

    void Print(time_t time);
    void clear();
    void operator+=(const Output& add);
};

class Solve{
public:
    Solve(const std::string& directory);
    void Run();

private:
    static bool is_js(const std::string& file){
        return file.size() > 3 && file.substr(file.size() - 3, 3) == ".js";
    }
    static void susp_find(const std::string& file_name, Output& out){
        Check ch;
        int count = 0;
        if (is_js(file_name)){
            ch.Restart(file_name, JSSUSP);
            count = ch.Run();
            if (count != -1)
                out.count_js += count;
        } else{
            ch.Restart(file_name, USUSP);
            count = ch.Run();
            if (count == 0){
                ch.Restart(file_name, MSUSP);
                count = ch.Run();
                if (count != -1)
                    out.count_mac += count;
            } else {
                if (count != -1)
                    out.count_un += count;
            }
        }
        out.count_file++;
        if (count == -1)
            out.count_error++;
    }
    void res_from_thread(std::vector<Output>& v_out, std::vector<std::string>& file_buff);

    std::string directory;
};

#endif //EASY_TASK_SOLVE_H
