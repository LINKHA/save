#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>
#include <unistd.h>

// 获取系统总内存和可用内存
void getMemoryInfo() {
	struct sysinfo info;

	if (sysinfo(&info) != 0) {
		std::cerr << "获取系统信息失败" << std::endl;
		return;
	}

	std::cout << "系统总内存: " << info.totalram / (1024 * 1024) << " MB" << std::endl;
	std::cout << "可用内存: " << info.freeram / (1024 * 1024) << " MB" << std::endl;
}

// 获取CPU核数
void getCPUInfo() {
	std::cout << "CPU 数量: " << sysconf(_SC_NPROCESSORS_ONLN) << std::endl;
}

// 获取磁盘信息
void getDiskInfo() {
	std::ifstream diskinfo("/proc/mounts");

	if (!diskinfo.is_open()) {
		std::cerr << "无法打开 /proc/mounts 文件" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(diskinfo, line)) {
		std::cout << "挂载点信息: " << line << std::endl;
	}

	diskinfo.close();
}

int main() {
	std::cout << "==== 系统信息 ====" << std::endl;
	getMemoryInfo();
	getCPUInfo();

	std::cout << "\n==== 磁盘信息 ====" << std::endl;
	getDiskInfo();

	return 0;
}
