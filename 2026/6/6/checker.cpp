#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

// 运行程序并获取其输出（保存到临时文件）
bool runAndGetOutput(const std::string& exeName, const std::string& outputFile) {
#ifdef _WIN32
    std::string cmd = exeName + " > " + outputFile + " 2>&1";
    int ret = std::system(cmd.c_str());
    return (ret == 0);
#else
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程：重定向输出到文件
        freopen(outputFile.c_str(), "w", stdout);
        execlp(exeName.c_str(), exeName.c_str(), nullptr);
        perror("execlp failed");
        exit(1);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) && WEXITSTATUS(status) == 0;
    } else {
        perror("fork failed");
        return false;
    }
#endif
}

// 比较两个文件是否完全相同
bool compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1), f2(file2);
    if (!f1.is_open() || !f2.is_open()) return false;
    
    std::string line1, line2;
    while (std::getline(f1, line1)) {
        if (!std::getline(f2, line2)) return false;
        // 去除行尾回车符（Windows格式兼容）
        while (!line1.empty() && (line1.back() == '\r' || line1.back() == '\n'))
            line1.pop_back();
        while (!line2.empty() && (line2.back() == '\r' || line2.back() == '\n'))
            line2.pop_back();
        if (line1 != line2) return false;
    }
    // 检查第二个文件是否还有多余行
    std::string extra;
    if (std::getline(f2, extra)) return false;
    return true;
}

// 获取 ans.exe 的运行时间（毫秒）
long long getAnsRunTime() {
    auto start = std::chrono::high_resolution_clock::now();
    
#ifdef _WIN32
    // 使用 CreateProcess 精确测量时间（避免 system 的额外开销）
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    CreateProcessA("ans.exe", nullptr, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
#else
    pid_t pid = fork();
    if (pid == 0) {
        execlp("./ans.exe", "ans.exe", nullptr);
        exit(1);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    }
#endif
    
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int main() {
    const std::string blOut = "bl_output.tmp";
    const std::string ansOut = "ans_output.tmp";
    
    // 1. 运行 bl.exe
    if (!runAndGetOutput("bl.exe", blOut)) {
        std::cerr << "Error: Failed to run bl.exe or bl.exe not found.\n";
        return 1;
    }
    
    // 2. 运行 ans.exe 并计时
    auto startTime = std::chrono::high_resolution_clock::now();
    if (!runAndGetOutput("ans.exe", ansOut)) {
        std::cerr << "Error: Failed to run ans.exe or ans.exe not found.\n";
        return 1;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    long long runTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    
    // 3. 比较输出
    if (compareFiles(blOut, ansOut)) {
        std::cout << "Output matches. ans.exe runtime: " << runTimeMs << " ms" << std::endl;
    } else {
        std::cout << "Output mismatch!" << std::endl;
        return 1;
    }
    
    // 清理临时文件
    std::remove(blOut.c_str());
    std::remove(ansOut.c_str());
    
    return 0;
}