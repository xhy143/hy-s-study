#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include <array>
#include <iomanip>
#include <vector>
#include <algorithm>

class HighPerformanceRandom {
private:
    static constexpr size_t NUM_GENERATORS = 8;
    std::array<std::mt19937, NUM_GENERATORS> generators;
    std::array<std::uniform_int_distribution<int>, NUM_GENERATORS> distributions;
    std::atomic<size_t> current_generator{0};
    
public:
    HighPerformanceRandom() {
        auto seed_time = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        
        for (size_t i = 0; i < NUM_GENERATORS; ++i) {
            std::vector<uint32_t> seed_data = {
                static_cast<uint32_t>(seed_time + i),
                static_cast<uint32_t>(seed_time >> 32),
                static_cast<uint32_t>(std::hash<std::thread::id>{}(std::this_thread::get_id()) + i),
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(this) + i)
            };
            
            std::seed_seq seed_seq(seed_data.begin(), seed_data.end());
            
            generators[i].seed(seed_seq);
            distributions[i] = std::uniform_int_distribution<int>(1, 32768);
        }
    }
    
    int generate() {
        size_t idx = current_generator.fetch_add(1, std::memory_order_relaxed) % NUM_GENERATORS;
        return distributions[idx](generators[idx]);
    }
};

HighPerformanceRandom& get_global_random() {
    static HighPerformanceRandom instance;
    return instance;
}

int rand_for_me() {
    return get_global_random().generate();
}

using namespace std;

void print_frame(int width = 50) {
    cout << "+";
    for(int i = 0; i < width-2; i++) cout << "-";
    cout << "+\n";
}

void print_middle(const string& text, int width = 50) {
    int padding = (width - 2 - text.length()) / 2;
    cout << "|";
    for(int i = 0; i < padding; i++) cout << " ";
    cout << text;
    for(int i = 0; i < width - 2 - text.length() - padding; i++) cout << " ";
    cout << "|\n";
}

void print_bottom(int width = 50) {
    cout << "+";
    for(int i = 0; i < width-2; i++) cout << "-";
    cout << "+\n";
}

void loading_animation(const string& message, int duration_ms = 500) {
    cout << message;
    for(int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(duration_ms/3));
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

void countdown_effect() {
    for(int i = 3; i > 0; i--) {
        cout << "\r" << i << "..." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\r开始！" << endl;
}

void flash_number_effect(int number, int flashes = 3) {
    for(int i = 0; i < flashes; i++) {
        cout << "\r>>>>> 【 " << number << " 】 <<<<<";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "\r                    ";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\r>>>>> 【 " << number << " 】 <<<<<" << endl;
}

int get_random_student_id() {
    int r = rand_for_me() % 42 + 1;
    while (r == 12) {
        r = rand_for_me() % 42 + 1;
    }
    return r;
}

int chou() {
    system("cls");
    print_frame(40);
    print_middle("学号抽奖系统", 40);
    print_middle("", 40);
    print_middle("正在抽选幸运学号...", 40);
    print_bottom(40);
    
    loading_animation("抽奖中", 800);
    
    countdown_effect();
    
    int r = get_random_student_id();
    
    flash_number_effect(r);
    
    this_thread::sleep_for(chrono::milliseconds(800));
    
    return r;
}

void show_title() {
    system("cls");
    print_frame(50);
    print_middle("", 50);
    print_middle("神秘学号抽奖器", 50);
    print_middle("", 50);
    print_middle("班级学号范围：1-42号", 50);
    //print_middle("所有学号机会均等", 50);
    print_middle("", 50);
    print_bottom(50);
}

void display_statistics(const vector<int>& results) {
    system("cls");
    print_frame(50);
    print_middle("抽奖结果汇总", 50);
    print_middle("", 50);
    
    if(results.empty()) {
        print_middle("没有抽奖记录", 50);
    } else {
        print_middle("本次共抽取 " + to_string(results.size()) + " 个学号", 50);
        print_middle("", 50);
        
        vector<int> sorted_results = results;
        sort(sorted_results.begin(), sorted_results.end());
        
        cout << "| ";
        int count = 0;
        for(int i = 0; i < sorted_results.size(); i++) {
            cout << setw(3) << sorted_results[i];
            count++;
            if(count == 10) {
                cout << " |\n| ";
                count = 0;
            } else if(i < sorted_results.size() - 1) {
                cout << " ";
            }
        }
        if(count > 0) {
            for(int i = count; i < 10; i++) cout << "    ";
            cout << " |\n";
        }
        
        print_middle("", 50);
        
        vector<int> frequency(43, 0);
        for(int num : results) {
            frequency[num]++;
        }
        
        int max_freq = *max_element(frequency.begin(), frequency.end());
        if(max_freq > 1) {
            print_middle("重复出现的学号：", 50);
            for(int i = 1; i <= 42; i++) {
                if(i != 12 && frequency[i] > 1) {
                    string info = "学号 " + to_string(i) + " 出现 " + to_string(frequency[i]) + " 次";
                    print_middle(info, 50);
                }
            }
        } else {
            print_middle("所有学号均不重复", 50);
        }
    }
    
    print_bottom(50);
}

int main() {
    show_title();
    
    cout << "\n按回车键继续...";
    cin.ignore();
    cin.get();
    
    while(true) {
        system("cls");
        show_title();
        
        print_frame(30);
        print_middle("1. 开始抽奖", 30);
        print_middle("2. 批量抽奖", 30);
        print_middle("3. 退出系统", 30);
        print_bottom(30);
        
        cout << "\n请选择 (1-3): ";
        int choice;
        cin >> choice;
        
        if(choice == 1) {
            system("cls");
            show_title();
            chou();
            
            cout << "\n按回车键返回主菜单...";
            cin.ignore();
            cin.get();
            
        } else if(choice == 2) {
            system("cls");
            show_title();
            
            print_frame(40);
            print_middle("批量抽奖模式", 40);
            print_bottom(40);
            
            cout << "\n输入抽奖次数: ";
            int times;
            cin >> times;
            
            if(times > 0) {
                vector<int> all_results;
                
                for(int i = 0; i < times; i++) {
                    cout << "\n第 " << i+1 << " 次抽奖：" << endl;
                    int result = chou();
                    all_results.push_back(result);
                    
                    if(i < times-1) {
                        this_thread::sleep_for(chrono::milliseconds(1000));
                    }
                }
                
                cout << "\n批量抽奖完成！按回车键查看汇总...";
                cin.ignore();
                cin.get();
                
                display_statistics(all_results);
                
                cout << "\n按回车键返回主菜单...";
                cin.ignore();
                cin.get();
            }
            
        } else if(choice == 3) {
            system("cls");
            show_title();
            
            print_frame(40);
            print_middle("感谢使用！", 40);
            print_middle("祝同学们好运！", 40);
            print_bottom(40);
            
            this_thread::sleep_for(chrono::milliseconds(1500));
            break;
            
        } else {
            cout << "\n无效选择，请重新输入！";
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }
    
    return 0;
}