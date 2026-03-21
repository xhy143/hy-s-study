#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>

// 配置结构
struct KeyMapping {
    DWORD mouseButton;  // 鼠标按钮
    DWORD keyCode;      // 映射的键盘按键
    std::string name;   // 描述
    bool isShift;       // 是否是Shift键（特殊处理）
};

// 全局变量
HHOOK g_mouseHook = NULL;
HHOOK g_keyboardHook = NULL;
HINSTANCE g_hInst = NULL;
std::ofstream g_logFile;
bool g_logging = false;
bool g_mappingEnabled = false;  // 映射开关，默认关闭
bool g_ctrlPressed = false;      // Ctrl键状态
bool g_f2Pressed = false;        // F2键状态

// 热键组合: Ctrl + F2
const UINT HOTKEY_MODIFIER = MOD_CONTROL;
const UINT HOTKEY_KEY = VK_F2;

// 映射配置
std::vector<KeyMapping> g_mappings;

// 日志函数
void WriteLog(const std::string& message) {
    if (g_logging) {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0';
        g_logFile << "[" << dt << "] " << message << std::endl;
        g_logFile.flush();
    }
}

// 切换映射状态
void ToggleMapping() {
    g_mappingEnabled = !g_mappingEnabled;
    
    // 显示状态变化（使用MessageBox或控制台输出）
    if (GetConsoleWindow() != NULL) {
        std::cout << (g_mappingEnabled ? "? 映射已启用" : "? 映射已禁用") << std::endl;
    }
    
    // 播放声音提示
    if (g_mappingEnabled) {
        MessageBeep(MB_OK);  // 启用时发出声音
    } else {
        MessageBeep(MB_ICONASTERISK);  // 禁用时发出不同声音
    }
    
    WriteLog(std::string("映射状态: ") + (g_mappingEnabled ? "启用" : "禁用"));
}

// 初始化默认映射配置
void InitDefaultMappings() {
    g_mappings.clear();
    
    // 左键映射为Shift
    g_mappings.push_back({WM_LBUTTONDOWN, 0, "左键 -> Shift", true});
    
    // 右键映射为空格
    g_mappings.push_back({WM_RBUTTONDOWN, VK_SPACE, "右键 -> 空格", false});
    
    // 可以添加其他映射
    // g_mappings.push_back({WM_MBUTTONDOWN, 'C', "中键 -> C", false});
}

// 模拟按键（支持Shift）
void SimulateKeyPress(const KeyMapping& mapping) {
    std::vector<INPUT> inputs;
    
    if (mapping.isShift) {
        // 处理Shift键
        // 按下Shift
        INPUT ipShift = {};
        ipShift.type = INPUT_KEYBOARD;
        ipShift.ki.wVk = VK_SHIFT;
        inputs.push_back(ipShift);
        
        // 注意：Shift键需要保持按下状态，因为我们只需要按下事件
        // 不要立即释放，让系统保持Shift按下状态
        
        WriteLog("按下 Shift 键");
    } else {
        // 处理普通按键
        // 按下按键
        INPUT ipDown = {};
        ipDown.type = INPUT_KEYBOARD;
        ipDown.ki.wVk = mapping.keyCode;
        inputs.push_back(ipDown);
        
        // 释放按键
        INPUT ipUp = ipDown;
        ipUp.ki.dwFlags = KEYEVENTF_KEYUP;
        inputs.push_back(ipUp);
        
        WriteLog("模拟按键: " + mapping.name);
    }
    
    if (!inputs.empty()) {
        SendInput(inputs.size(), inputs.data(), sizeof(INPUT));
    }
}

// 释放Shift键（当左键释放时调用）
void ReleaseShiftKey() {
    INPUT ip = {};
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    
    WriteLog("释放 Shift 键");
}

// 键盘钩子回调 - 用于检测热键
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        
        // 检测Ctrl键状态
        if (kbStruct->vkCode == VK_CONTROL) {
            if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
                g_ctrlPressed = true;
            } else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
                g_ctrlPressed = false;
            }
        }
        
        // 检测F2键状态
        if (kbStruct->vkCode == VK_F2) {
            if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
                g_f2Pressed = true;
                
                // 检测组合键 Ctrl + F2
                if (g_ctrlPressed) {
                    ToggleMapping();
                    return 1; // 阻止原始按键事件，避免影响其他程序
                }
            } else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
                g_f2Pressed = false;
            }
        }
    }
    
    return CallNextHookEx(g_keyboardHook, nCode, wParam, lParam);
}

// 鼠标钩子回调
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && g_mappingEnabled) {  // 仅在映射启用时处理
        MSLLHOOKSTRUCT* mouseStruct = (MSLLHOOKSTRUCT*)lParam;
        
        // 处理鼠标按键事件
        for (const auto& mapping : g_mappings) {
            if (wParam == mapping.mouseButton) {
                // 根据按键类型处理
                if (wParam == WM_LBUTTONDOWN) {
                    // 左键按下 - 按下Shift
                    SimulateKeyPress(mapping);
                } 
                else if (wParam == WM_LBUTTONUP) {
                    // 左键释放 - 释放Shift
                    ReleaseShiftKey();
                }
                else if (wParam == WM_RBUTTONDOWN) {
                    // 右键按下 - 模拟空格键（按下并释放）
                    SimulateKeyPress(mapping);
                }
                else if (wParam == WM_RBUTTONUP) {
                    // 右键释放 - 不需要额外处理，因为空格键已经释放
                    // 但可以在这里添加特殊处理如果需要
                }
                
                return 1; // 阻止原始鼠标事件
            }
        }
    }
    
    return CallNextHookEx(g_mouseHook, nCode, wParam, lParam);
}

// 隐藏控制台窗口
void HideConsole() {
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
}

// 显示控制台窗口
void ShowConsole() {
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
}

// 保存配置到文件
void SaveConfig(const std::string& filename) {
    std::ofstream config(filename);
    if (config.is_open()) {
        for (const auto& mapping : g_mappings) {
            config << mapping.mouseButton << " " 
                   << mapping.keyCode << " " 
                   << mapping.isShift << " "
                   << mapping.name << std::endl;
        }
        config.close();
    }
}

// 从文件加载配置
void LoadConfig(const std::string& filename) {
    std::ifstream config(filename);
    if (config.is_open()) {
        g_mappings.clear();
        DWORD mouseBtn, keyCode;
        bool isShift;
        std::string name;
        while (config >> mouseBtn >> keyCode >> isShift) {
            config.ignore();
            std::getline(config, name);
            g_mappings.push_back({mouseBtn, keyCode, name, isShift});
        }
        config.close();
    } else {
        // 如果配置文件不存在，使用默认配置
        InitDefaultMappings();
        SaveConfig(filename);
    }
}

// 主函数
int main() {
    // 解析命令行参数
    bool hideWindow = false;
    bool enableLogging = false;
    
    LPWSTR* szArglist;
    int nArgs;
    szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
    
    if (szArglist) {
        for (int i = 1; i < nArgs; i++) {
            if (wcscmp(szArglist[i], L"-hide") == 0) {
                hideWindow = true;
            }
            else if (wcscmp(szArglist[i], L"-log") == 0) {
                enableLogging = true;
            }
        }
        LocalFree(szArglist);
    }
    
    // 加载配置
    LoadConfig("mouse_mapping.conf");
    
    // 初始化日志
    if (enableLogging) {
        g_logFile.open("mouse_mapping.log", std::ios::app);
        g_logging = true;
        WriteLog("程序启动");
    }
    
    // 显示窗口或隐藏
    if (hideWindow) {
        HideConsole();
    } else {
        std::cout << "鼠标按键映射工具 v3.0" << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "当前映射配置:" << std::endl;
        for (const auto& mapping : g_mappings) {
            std::cout << "  " << mapping.name << std::endl;
        }
        std::cout << "=================================" << std::endl;
        std::cout << "快捷键: Ctrl + F2 切换映射开关" << std::endl;
        std::cout << "当前状态: " << (g_mappingEnabled ? "已启用" : "已禁用") << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "命令参数:" << std::endl;
        std::cout << "  -hide    : 隐藏窗口后台运行" << std::endl;
        std::cout << "  -log     : 启用日志记录" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "按 Ctrl+C 退出程序" << std::endl;
    }
    
    // 安装钩子
    g_hInst = GetModuleHandle(NULL);
    
    // 安装键盘钩子（用于检测热键）
    g_keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, g_hInst, 0);
    if (g_keyboardHook == NULL) {
        if (!hideWindow) {
            std::cerr << "安装键盘钩子失败！错误代码: " << GetLastError() << std::endl;
        }
        return 1;
    }
    
    // 安装鼠标钩子
    g_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, g_hInst, 0);
    if (g_mouseHook == NULL) {
        if (!hideWindow) {
            std::cerr << "安装鼠标钩子失败！错误代码: " << GetLastError() << std::endl;
        }
        UnhookWindowsHookEx(g_keyboardHook);
        return 1;
    }
    
    if (!hideWindow) {
        std::cout << "钩子安装成功！" << std::endl;
    }
    
    WriteLog("程序初始化完成");
    
    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    // 清理
    if (g_mouseHook) {
        UnhookWindowsHookEx(g_mouseHook);
    }
    if (g_keyboardHook) {
        UnhookWindowsHookEx(g_keyboardHook);
    }
    
    if (g_logging) {
        WriteLog("程序退出");
        g_logFile.close();
    }
    
    return 0;
}