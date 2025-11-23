#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iomanip>
#include <map>
#include <limits>
#include <fstream>  // 用于文件输入输出
#include <windows.h>


using namespace std;



// ------------------ 作物结构 ------------------
struct Crop {
	Crop(string n, int g, int p, int s)
		: name(n), growDays(g), price(p), sellPrice(s),
		  currentGrow(0), isPlanted(false) {}

	Crop() : name(""), growDays(0), price(0), sellPrice(0),
		currentGrow(0), isPlanted(false) {}

	string name;//植物名字
	int growDays;//生长天数
	int price;//价格
	int sellPrice;//售价
	int currentGrow = 0;//现在生长的天数
	bool isPlanted = false;//是否种植

	bool isMature() const {
		return currentGrow >= growDays;
	}
};

// ------------------ 动物结构 ------------------
struct Animal {
	string name;        // 名称
	int growDays;       // 成长所需天数
	int currentGrow;    // 当前成长天数
	int price;          // 购买价格
	int productValue;   // 每次产出价值
	bool isOwned;       // 是否拥有
	bool isMature;      // 是否成熟

	Animal(string n, int g, int p, int v)
		: name(n), growDays(g), price(p), productValue(v),
		  currentGrow(0), isOwned(false), isMature(false) {}

	Animal() : name(""), growDays(0), price(0), productValue(0),
		currentGrow(0), isOwned(false), isMature(false) {}
};

// ------------------ 土地与玩家结构 ------------------
struct Land {
	bool unlocked = false;
	bool occupied = false;
	int level = 1;
	int harvestCount = 0;
	Crop crop;
};

struct Player {
	int coins = 100;//金币数量
	vector<Land> lands;//土地
	map<string, int> seeds;//种子
	int fertilizer = 0;//肥料
	int feed = 0; // 新增：饲料数量
	vector<Animal> animals; //  新增：玩家的动物列表
};

//设置颜色 白色(7) 黄色(14) 绿色(10) 红色(12) 蓝色(9)
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}







// ------------------ 全局：随机事件状态 ------------------
double g_priceMultiplier = 1.0;      // 价格倍率（事件影响）
int g_priceBuffDaysRemaining = 0;    // 价格倍率剩余天数（收获后消失）
bool g_lastEventOccurred = false;    // 是否当天触发事件（用于提示）

// ------------------ 动画效果 ------------------
void printSpinner(const string& action, int durationMs = 800) {
	const char spinChars[] = {'-', '\\', '|', '/'};
	cout << action << " ";
	for (int i = 0; i < 8; ++i) {
		cout << "\r" << action << " " << spinChars[i % 4] << flush;
		this_thread::sleep_for(chrono::milliseconds(durationMs / 8));
	}
	cout << "\r" << action << " 完成！(￣▽￣)b   " << endl;
}

void printProgressBar(const string& action, int steps = 20, int durationMs = 1000) {
	cout << action << " ";
	for (int i = 0; i <= steps; ++i) {
		int percent = i * 100 / steps;
		cout << "\r" << action << " [" << string(i, '#') << string(steps - i, ' ')
		     << "] " << setw(3) << percent << "%" << flush;
		this_thread::sleep_for(chrono::milliseconds(durationMs / steps));
	}
	cout << "\r" << action << " 完成！(＾▽＾)ノ           " << endl;
}

// ------------------ 菜单 ------------------
void showMenu() {
	cout << "\n================= 智能农场 (＾▽＾)ノ=====================\n";
	cout << "||\t1. 查看土地\t\t\t2. 购买种子\t||\n";
	cout << "||\t3. 种植作物\t\t\t4. 等待一天\t||\n";
	cout << "||\t5. 收获作物\t\t\t6. 解锁土地\t||\n";
	cout << "||\t7. 查看库存\t\t\t8. 物品商店\t||\n";
	cout << "||\t9. 游戏说明\t\t\t10. 畜牧系统\t||\n";
	cout << "||\t0. 退出游戏\t\t\t\t\t||\n";
	cout << "==========================================================\n";
	cout << "请选择操作：";
}

// ------------------ 天气 ------------------
string generateWeather() {
	int r = rand() % 100;
	if (r < 50) return "晴天 sunny ";
	else if (r < 80) return "阴天 cloudy ";
	else return "雨天 rainy ";
}

int weatherGrowthEffect(const string& weather) {
	if (weather.find("晴天") != string::npos) return 1;
	else if (weather.find("阴天") != string::npos) return 0;
	else if (weather.find("雨天") != string::npos) return 2;
	return 1;
}

// ------------------ 随机事件系统（新增） ------------------
void triggerRandomEvent(Player &player) {
	// 触发概率 30%
	int chance = rand() % 100;
	g_lastEventOccurred = false;

	if (chance >= 30) {
		// 无事件
		cout << "\n今天风平浪静，什么特别的事都没发生 (＾ω＾)\n";
		return;
	}

	// 有事件：随机选择一种
	int ev = rand() % 5; // 0..4 共5种事件
	g_lastEventOccurred = true;

	switch (ev) {
		case 0: { // 及时雨：所有作物 +1 成长
			cout << "\n=== 今日事件：及时雨 ===\n";
			cout << "一场及时雨滋润了农田，所有作物额外成长 +1！(≧▽≦)\n";
			for (auto &land : player.lands)
				if (land.occupied) land.crop.currentGrow += 1;
			break;
		}
		case 1: { // 虫害：随机减少某些作物成长或小范围损害
			cout << "\n=== 今日事件：虫害来袭 ===\n";
			cout << "糟糕！部分作物被虫子侵扰，生长进度受影响 (；′Д｀)\n";
			// 影响 1~max(1, floor(n/3)) 块占用土地
			int n = (int)player.lands.size();
			int maxAffected = max(1, n / 3);
			int affected = 1 + rand() % maxAffected;
			for (int k = 0; k < affected; ++k) {
				int idx = rand() % n;
				if (player.lands[idx].occupied) {
					// reduce progress by 1 (不能小于0)
					if (player.lands[idx].crop.currentGrow > 0) {
						player.lands[idx].crop.currentGrow = max(0, player.lands[idx].crop.currentGrow - 1);
						cout << "地块" << idx+1 << " 的 " << player.lands[idx].crop.name << " 被虫害影响，成长 -1 (′ω`)\n";
					} else {
						// 若进度已为0，有一定几率作物被破坏
						if (rand() % 100 < 40) {
							cout << "地块" << idx+1 << " 的 " << player.lands[idx].crop.name << " 不幸被破坏了 (╯︵╰,)\n";
							player.lands[idx].occupied = false;
						}
					}
				}
			}
			break;
		}
		case 2: { // 市场繁荣：本次收获价格翻倍（一次性）
			cout << "\n=== 今日事件：市场繁荣 ===\n";
			cout << "市场需求暴增！本次收获卖价翻倍！ヽ(＾▽＾)ノ\n";
			g_priceMultiplier = 2.0;
			g_priceBuffDaysRemaining = 1; // 一次性，下一次收获适用（或当天内）
			break;
		}
		case 3: { // 肥料礼包：获得1肥料
			cout << "\n=== 今日事件：肥料礼包 ===\n";
			cout << "邻居送来了一包肥料，真是及时！获得 肥料 x1 (＾ω＾)\n";
			player.fertilizer += 1;
			break;
		}
		case 4: { // 小风暴：随机一块未成熟作物被毁
			cout << "\n=== 今日事件：小风暴 ===\n";
			cout << "发生了小风暴，几块地受损 (；へ：) 请检查土地。\n";
			int n = (int)player.lands.size();
			int idx = rand() % n;
			if (player.lands[idx].occupied && !player.lands[idx].crop.isMature()) {
				player.lands[idx].occupied = false;
				cout << "地块" << idx+1 << " 的作物被风暴摧毁了 (T_T)\n";
			} else {
				cout << "风暴掠过，但没有发现未成熟作物被摧毁 (￣ー￣)\n";
			}
			break;
		}
		default:
			break;
	}
}

// ------------------ 查看土地 ------------------
void viewLands(const Player &player) {
	cout << "\n---- >>>>土地情况 <<<<----\n";
	for (int i = 0; i < player.lands.size(); ++i) {
		cout << "地块" << i + 1 << " [Lv" << player.lands[i].level << "]: ";
		if (!player.lands[i].unlocked)
			cout << "未解锁 (╯︵╰,)" << endl;
		else if (!player.lands[i].occupied)
			cout << "空地 ( ω)" << endl;
		else {
			if(player.lands[i].crop.currentGrow >= player.lands[i].crop.growDays) {
				setColor(12);//如果满了，那就变为红色
			} else {
				setColor(7);//如果没有满，那还是白色
			}
			cout << player.lands[i].crop.name
			     << " (" << player.lands[i].crop.currentGrow
			     << "/" << player.lands[i].crop.growDays << "天)" << endl;
		}
		setColor(7);//重置为默认颜色
	}

	cout << "---- >>>>土地情况 <<<<----\n";
}

// ------------------ 种子商店 ------------------

enum class Color {
    normal,highLevel,superHighLevel
};

//通过生长天数来简单判断是否是高级植物
Color isHighLevel(const Crop &c) {
	if(c.growDays <= 5) return Color::normal;
	else if(c.growDays > 5 && c.growDays <=10) return Color::highLevel;
	return Color::superHighLevel;
}




void shopSeeds(Player &player, vector<Crop> &shop) {
	cout << "\n------------>>>> 种子商店 <<<<------------\n";
	for (int i = 0; i < shop.size(); ++i) {
		switch(isHighLevel(shop[i])) {
			case Color::normal:
				setColor(7); // 白色
				break;
			case Color::highLevel:
				setColor(14); // 黄色
				break;
			case Color::superHighLevel:
				setColor(10); // 绿色
				break;
		}
		cout << i + 1 << ". " << shop[i].name
		     << " - 价格: " << shop[i].price
		     << "金币, 收益: " << shop[i].sellPrice
		     << " 生长天数: " << shop[i].growDays << endl;
	}
	setColor(7); // 恢复默认颜色



	cout << "------------------------------------------\n";
	cout << "请选择要购买的种子编号：";
	int buyIndex;
	cin >> buyIndex;
	if (buyIndex < 1 || buyIndex > shop.size()) return;
    cout << "请选择要购买的种子数量：";
    int buyCount;
    cin>>buyCount;
	Crop c = shop[buyIndex - 1];
	if (player.coins < c.price*buyCount) {
		cout << "(＞﹏＜) 金币不够啦！\n";
		return;
	}

	player.coins -= c.price*buyCount;
	player.seeds[c.name]+=buyCount;
	printProgressBar("购买中", 10, 800);
	cout << "(*^▽^*) 你购买了 "<<buyCount<<" 个 " << c.name << " 种子！\n";
}

// ------------------ 物品商店 ------------------
void itemShop(Player &player) {
	cout << "\n------------>>>> 物品商店 <<<<------------\n";
	cout << "1. 肥料（+2成长） - 价格: 15金币\n";
	cout << "2. 饲料（喂养动物用） - 价格: 20金币\n";
	cout << "0. 返回\n";
	cout << "------------------------------------------\n";
	cout << "请选择购买的物品：";

	int choice;
	cin >> choice;
    cout << "请选择购买的数量：";
    int cnt;
    cin>>cnt;
	if (choice == 1) {
		if (player.coins < 15*cnt) {
			cout << "(T△T) 金币不足，买不起肥料！\n";
			return;
		}
		player.coins -= 15*cnt;
		player.fertilizer+=cnt;
		printProgressBar("购买肥料中", 10, 800);
		cout << "获得肥料 x"<<cnt<<"，现在共有 " << player.fertilizer << " 个。(｀ω′)\n";
	} else if (choice == 2) {
		if (player.coins < 20*cnt) {
			cout << "金币不足！\n";
			return;
		}
		player.coins -= 20*cnt;
		player.feed+=cnt;
		printProgressBar("购买饲料中", 10, 800);
		cout << "获得饲料 x"<<cnt<<"，现在共有 " << player.feed << " 个。\n";
	} else {
		cout << "返回游戏菜单 (￣ω￣)\n";
	}
}

// ------------------ 种植 ------------------
void plantCrop(Player &player, vector<Crop> &shop) {
	cout << "\n--- 当前种子库存 ---\n";
	int index = 1;
	vector<string> availableSeeds;
	for (auto &pair : player.seeds) {
		cout << index << ". " << pair.first << " (数量: " << pair.second << ")\n";
		availableSeeds.push_back(pair.first);
		index++;
	}
	cout << "请选择要种植的作物编号：";
	int cropIndex;
	cin >> cropIndex;
	if (cropIndex < 1 || cropIndex > availableSeeds.size()) return;

	string cropName = availableSeeds[cropIndex - 1];
	if (player.seeds[cropName] <= 0) {
		cout << "(>_<)你没有 " << cropName << " 种子。"<<endl;
		for (auto &c : shop) {
			if (c.name == cropName && player.coins >= c.price) {
				cout<<endl<<c.name<< " - 价格: " << c.price << "金币, 收益: " << c.sellPrice <<" 生长天数："<<c.growDays<<"天"<<endl;
			}
		}
		cout<<"\n是否购买？(1=是, 0=否): ";
		int buy;
		cin >> buy;
		if (buy == 1) {
			for (auto &c : shop) {
				if (c.name == cropName && player.coins >= c.price) {
					player.coins -= c.price;
					player.seeds[c.name]++;
					cout << "你购买了 1 个 " << c.name << " 种子。\n";
				}
			}
		} else {
			cout << "取消种植，那就下次再种吧 (·︿ ·)\n";
			return;
		}
	}

	cout << "选择要种植的土地编号：";
	int landIndex;
	cin >> landIndex;

	if (landIndex < 1 || landIndex > player.lands.size() ||
	        !player.lands[landIndex - 1].unlocked || player.lands[landIndex - 1].occupied) {
		cout << "无法种植！(╯°□°）╯︵ ┻━┻\n";
		return;
	}

	for (auto &c : shop) {
		if (c.name == cropName) {
			player.lands[landIndex - 1].crop = c;
			player.lands[landIndex - 1].occupied = true;
			player.seeds[c.name]--;
			printProgressBar("种植中", 15, 1000);
			cout << "(つ-ω-)つ 在地块" << landIndex << " 种下了 " << c.name << "！\n";
			break;
		}
	}
}

// ------------------ 浇水施肥 ------------------
void waterOrFertilize(Player &player, const string& weather) {
	cout << "\n1. 浇水 (+1成长)\n";
	cout << "2. 施肥 (+2成长, 消耗肥料)\n";
	cout << "0. 什么都不做\n";
	cout << "请选择操作：";
	int action;
	cin >> action;

	switch (action) {
		case 1:
			for (auto &land : player.lands)
				if (land.occupied) land.crop.currentGrow++;
			cout << "(｀ω′)ゞ 你认真地浇了水，作物成长 +1！\n";
			break;
		case 2:
			if (player.fertilizer <= 0) {
				cout << "(>_<) 没有肥料啦！去商店买点吧。\n";
				break;
			}
			player.fertilizer--;
			for (auto &land : player.lands)
				if (land.occupied) land.crop.currentGrow += 2;
			cout << " 你施了肥，所有作物成长 +2！(剩余肥料: " << player.fertilizer << ")\n";
			break;
		case 0:
			cout << "今天什么都没干 (～￣▽￣)～\n";
			break;
		default:
			cout << "无效操作 (￣△￣；)\n";
			break;
	}
}

// ------------------ 时间推进 ------------------
void waitDay(Player &player, int &day) {
	string weather = generateWeather();
	printProgressBar("时间流逝中", 15, 1000);
	++day;
	cout << "\n今天的天气是：" << weather << endl;

	if (weather.find("雨天") == string::npos)
		waterOrFertilize(player, weather);
	else
		cout << "(￣▽￣)ノ下雨啦～作物自动成长 +2！\n";

	int growthEffect = weatherGrowthEffect(weather);
	for (auto &land : player.lands)
		if (land.occupied) land.crop.currentGrow += growthEffect;

	cout << "\n新的一天开始啦 (＾▽＾)/\n";

	// <-- 在每天推进完后触发随机事件（新增）
	triggerRandomEvent(player);

	// 如果有价格加成天数，递减（如果你希望加成覆盖多个天数，可调整逻辑）
	if (g_priceBuffDaysRemaining > 0) {
		g_priceBuffDaysRemaining--;
		if (g_priceBuffDaysRemaining == 0) {
			g_priceMultiplier = 1.0; // 重置
		}
	}
}

// ------------------ 收获 ------------------
void harvestCrops(Player &player) {
	printSpinner("收获中");
	int totalEarn = 0;
	for (auto &land : player.lands) {
		if (land.occupied && land.crop.isMature()) {
			double bonus = 1.0 + (land.level - 1) * 0.1;
			int baseEarn = land.crop.sellPrice;
			int earn = static_cast<int>(baseEarn * bonus * g_priceMultiplier); // 考虑事件价格倍率
			totalEarn += earn;

			cout << "地块 Lv" << land.level << " 的 " << land.crop.name
			     << " 卖出获得 " << earn << " 金币！（收益加成 x" << bonus;
			if (g_priceMultiplier != 1.0) cout << ", 市场 x" << g_priceMultiplier;
			cout << "）(≧▽≦)\n";

			land.harvestCount++;
			land.occupied = false;

			if (land.harvestCount % 3 == 0) {
				land.level++;
				cout << " 地块升级啦！现在是 Lv" << land.level << "！产量更高啦！(≧ω≦)\n";
			}
		}
	}
	player.coins += totalEarn;
	if (totalEarn == 0) cout << "没有成熟的作物 (′ω`)\n";

	// 收获后如果市场加成是一次性的，清除它（以防多次收获重复加成）
	if (g_priceBuffDaysRemaining <= 0 && g_priceMultiplier != 1.0) {
		g_priceMultiplier = 1.0;
	}
}

// ------------------ 解锁土地 ------------------
void unlockLand(Player &player) {
    cout<<"解锁土地要80币哦(￣▽￣)~"<<endl<<"0.确定"<<endl<<"1.非常确定（划掉）拒绝";
    int flag=0;
    cin>>flag;
    if(flag){
        return ;
    }
	for (int i = 0; i < player.lands.size(); ++i) {
		if (!player.lands[i].unlocked) {
			if (player.coins >= 80) {
				printProgressBar("解锁新土地中", 20, 1200);
				player.coins -= 80;
				player.lands[i].unlocked = true;
				cout << "新的土地已解锁！(*▽*)\n";
			} else {
				cout << "(╯︵╰,) 金币不足，解锁失败～需要80金币。\n";
			}
			return;
		}
	}
	cout << "所有土地都已解锁 (￣▽￣)~*\n";
}

// ------------------ 查看库存 ------------------
void viewInventory(const Player &player) {
	cout << "\n--- 库存 ---\n";
	cout << "金币: " << player.coins << endl;
	cout << "肥料: " << player.fertilizer << " 个\n";
	cout << "种子库存：\n";
	for (auto &pair : player.seeds)
		cout << " - " << pair.first << ": " << pair.second << " 个\n";
	cout << "(＾ω＾) 农场蒸蒸日上呢！\n";
}

// ------------------ 游戏说明 ------------------
void showHelp() {
	cout << "\n================= 游戏说明 =================\n";
	cout << "欢迎来到《智能农场》(＾▽＾)ノ\n\n";
	cout << "【玩法简介】\n";
	cout << "你是一位农场主，通过购买种子、种植作物、收获并卖出，赚取金币。\n";
	cout << "金币可以用于购买更多种子、肥料，或解锁新土地。\n\n";

	cout << "【核心系统】\n";
	cout << "1. 天气系统：每天随机晴、阴、雨，不同天气影响作物成长速度。\n";
	cout << "2. 浇水系统：晴天或阴天可手动浇水提升成长速度。\n";
	cout << "3. 肥料系统：可购买肥料，提升作物成长（+2成长）。\n";
	cout << "4. 土地升级：每块土地收获3次后自动升级，提高收益。\n";
	cout << "5. 随机事件：第二天开始可能会有特殊事件影响农场。\n\n";

	cout << "【操作指南】\n";
	cout << "1. 查看土地 —— 查看每块地的状态。\n";
	cout << "2. 购买种子 —— 花金币购买不同种类的种子。\n";
	cout << "3. 种植作物 —— 在空闲土地上种下你拥有的种子。\n";
	cout << "4. 等待一天 —— 推进时间，天气会变化，作物成长。\n";
	cout << "5. 收获作物 —— 成熟的作物可以卖出获得金币。\n";
	cout << "6. 解锁土地 —— 用金币扩建农场。\n";
	cout << "7. 查看库存 —— 查看你的金币、肥料和种子数量。\n";
	cout << "8. 物品商店 —— 购买肥料等物品。\n";
	cout << "9. 游戏说明 —— 查看本页面。\n";
	cout << "0. 退出游戏 —— 保存并离开。\n\n";

	cout << "【温馨提示】\n";
	cout << "· 雨天作物会自动成长，不需要浇水。\n";
	cout << "· 金币不足时无法购买种子或土地。\n";
	cout << "· 多积累金币解锁更多土地，收益会更快！\n";
	cout << "· 随时回来看看，作物也会在成长中等你哦。\n\n";
	cout << "=============================================\n";
	cout << "按 Enter 返回主菜单...";
	cin.ignore();
	cin.get();
}

// ------------------ 保存与读取游戏数据 ------------------
void saveGame(const Player &player, int day) {
	ofstream fout("farmerData.txt");
	if (!fout.is_open()) {
		cout << "(×_×) 无法保存数据文件！" << endl;
		return;
	}

	// 基本信息
	fout << day << " " << player.coins << " " << player.fertilizer << endl;

	// 土地信息
	fout << player.lands.size() << endl;
	for (auto &land : player.lands) {
		fout << land.unlocked << " " << land.occupied << " " << land.level << " " << land.harvestCount << " ";
		if (land.occupied) {
			fout << land.crop.name << " " << land.crop.currentGrow << " " << land.crop.growDays << " "
			     << land.crop.price << " " << land.crop.sellPrice;
		} else {
			fout << "none 0 0 0 0";
		}
		fout << endl;
	}

	// 种子库存
	fout << player.seeds.size() << endl;
	for (auto &p : player.seeds) {
		fout << p.first << " " << p.second << endl;
	}

	fout.close();
	cout << "(＾▽＾) 存档成功！数据已保存到 farmerData.txt\n";
}

bool loadGame(Player &player, int &day) {
	ifstream fin("farmerData.txt");
	if (!fin.is_open()) {
		cout << "未找到存档，将创建新游戏。(￣▽￣)\n";
		return false;
	}

	fin >> day >> player.coins >> player.fertilizer;

	int landCount;
	fin >> landCount;
	player.lands.resize(landCount);

	for (int i = 0; i < landCount; ++i) {
		Land land;
		fin >> land.unlocked >> land.occupied >> land.level >> land.harvestCount;
		string cropName;
		fin >> cropName >> land.crop.currentGrow >> land.crop.growDays >> land.crop.price >> land.crop.sellPrice;
		if (cropName != "none") {
			land.crop.name = cropName;
			land.crop.isPlanted = true;
		}
		player.lands[i] = land;
	}

	int seedCount;
	fin >> seedCount;
	player.seeds.clear();
	for (int i = 0; i < seedCount; ++i) {
		string name;
		int count;
		fin >> name >> count;
		player.seeds[name] = count;
	}

	fin.close();
	cout << "(￣▽￣) 读取存档成功！欢迎回来，农场主！\n";
	
	return true;
}

void animalSystem(Player &player, vector<Animal> &animalShop) {
	while (true) {
		cout << "\n------------>>>>畜牧系统 <<<<------------\n";
		cout << setw(20)<<"1. 查看畜舍\t\t2. 购买动物\n";
		cout << setw(20)<<"3. 喂养动物\t\t4. 收取产出\n";
		cout << "0. 返回主菜单\n";
		cout << "============================================\n";
		cout << "请选择操作：";
		int choice;
		cin >> choice;

		if (choice == 0) break;
		switch (choice) {
			case 1: { // 查看畜舍
				cout << "\n--- 畜舍情况 ---\n";
				if (player.animals.empty()) {
					cout << "(￣ω￣;) 你还没有动物呢～\n";
				} else {
					for (auto &a : player.animals) {
						if (a.isMature) setColor(14);
						cout << a.name << " (" << a.currentGrow << "/" << a.growDays
						     << " 天)";
						if (a.isMature) cout << " ? 已成熟";
						cout << endl;
						setColor(7);
					}
				}
				break;
			}
			case 2: { // 购买动物
				cout << "\n--- 动物商店 ---\n";
				for (int i = 0; i < animalShop.size(); ++i) {
					cout << i + 1 << ". " << animalShop[i].name
					     << " - 价格: " << animalShop[i].price
					     << " 金币, 成长天数: " << animalShop[i].growDays
					     << ", 每日产出价值: " << animalShop[i].productValue << endl;
				}
				cout << "请选择要购买的动物编号：";
				int idx;
				cin >> idx;
				if (idx < 1 || idx > animalShop.size()) break;

				Animal a = animalShop[idx - 1];
				if (player.coins < a.price) {
					cout << "(>_<) 金币不足！\n";
				} else {
					player.coins -= a.price;
					a.isOwned = true;
					player.animals.push_back(a);
					printProgressBar("购买动物中", 10, 800);
					cout << "欢迎新的小动物 " << a.name << " 加入农场！(≧▽≦)\n";
				}
				break;
			}
			case 3: { // 喂养动物
				if (player.feed <= 0) {
					cout << "(T_T) 没有饲料啦，去商店买点吧。\n";
					break;
				}
				player.feed--;
				for (auto &a : player.animals) {
					if (!a.isMature) {
						a.currentGrow += 2;
						if (a.currentGrow >= a.growDays) {
							a.isMature = true;
							cout << "(≧ω≦) " << a.name << " 已经成熟啦！\n";
						}
					}
				}
				cout << "(＾▽＾) 喂养完成，动物们很开心！(剩余饲料：" << player.feed << ")\n";
				break;
			}
			case 4: { // 收取产出
				int totalEarn = 0;
				for (auto &a : player.animals) {
					if (a.isMature) {
						totalEarn += a.productValue;
						cout << a.name << " 产出了价值 " << a.productValue << " 金币的产品！\n";
					}
				}
				player.coins += totalEarn;
				if (totalEarn == 0)
					cout << "还没有成熟动物产出哦 (?_?;)\n";
				else
					cout << "今日总收益：" << totalEarn << " 金币！$$$$\n";
				break;
			}
			default:
				cout << "无效选项 (￣△￣；)\n";
		}
	}
}

// ------------------ 主循环 ------------------
int main() {
	srand(time(0));

	Player player;

	int day = 1;
	// 尝试读取存档
	bool loaded = loadGame(player, day);
	if (!loaded) {
		// 初始化新游戏
		player.lands.resize(6);
		player.lands[0].unlocked = true;
		player.lands[1].unlocked = true;
	}

	vector<Crop> shop = {
		{"小麦", 2, 10, 20},   // 普通
		{"玉米", 3, 20, 40},
		{"番茄", 4, 30, 60},
		{"西瓜", 6, 50, 120},  // 高级
		{"葡萄", 8, 80, 200},  // 高级
		{"稻谷", 10, 100, 250}, // 高级
		{"猫山王榴莲", 13, 130, 600}, // 超高级
		{"黄金椰子", 13, 180, 780} // 超高级
	};

	vector<Animal> animalShop = {
		{"小鸡", 3, 40, 25},
		{"奶牛", 6, 100, 60},
		{"绵羊", 5, 80, 50},
		{"鸭子", 4, 50, 30},
		{"猪", 8, 150, 100}
	};


	for (auto &c : shop) player.seeds[c.name] = 0;

	int choice;

	cout << "欢迎来到智能农场！(⌒▽⌒)☆\n";
	cout << "退出游戏前记得要按 数字 0 来进行存档\n";
	printProgressBar("加载农场中", 10, 1500);

	while (true) {
		cout << "\n当前金币：" << player.coins << "  当前天数：" << day << endl;
		showMenu();
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "(⊙_⊙;) 输入无效，请重新输入。\n";
			continue;
		}

		switch (choice) {
			case 0:
				printSpinner("保存进度");
				saveGame(player, day);  // 退出时自动保存
				cout << "(￣▽￣)ノ Bye~ 农场主！";
				return 0;
			case 1:
				viewLands(player);
				break;
			case 2:
				shopSeeds(player, shop);
				break;
			case 3:
				plantCrop(player, shop);
				break;
			case 4:
				waitDay(player, day);
				break;
			case 5:
				harvestCrops(player);
				break;
			case 6:
				unlockLand(player);
				break;
			case 7:
				viewInventory(player);
				break;
			case 8:
				itemShop(player);
				break;
			case 9:
				showHelp();
				break;
			case 10:
				animalSystem(player, animalShop);
				break;

			default:
				cout << "(￣へ￣) 无效选项，请重新输入。\n";
				break;
		}
	}
	return 0; 
}
