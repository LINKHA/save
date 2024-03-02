#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	// ��ʼ��unordered_map
	std::unordered_map<std::string, int> myMap;

	// ʹ��insert���Ԫ��
	myMap.insert({ "apple", 5 });
	myMap.insert(std::make_pair("banana", 2));

	// ʹ��emplaceֱ���������ڹ���Ԫ��
	myMap.emplace("cherry", 3);
	myMap.emplace(std::make_pair("date", 4));

	// ����Ԫ��
	std::cout << "apple count: " << myMap["apple"] << std::endl;
	// ʹ��at�������ʣ���������������׳�std::out_of_range�쳣
	try {
		std::cout << "banana count: " << myMap.at("banana") << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Key not found: " << e.what() << std::endl;
	}

	// ���Ԫ���Ƿ����
	if (myMap.find("cherry") != myMap.end()) {
		std::cout << "cherry found" << std::endl;
	}

	// ����Ԫ��
	myMap["apple"] = 10;

	// ɾ��Ԫ��
	myMap.erase("banana");

	// ����unordered_map
	std::cout << "Current map: " << std::endl;
	for (const auto& pair : myMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	// ��ȡԪ������
	std::cout << "Number of elements: " << myMap.size() << std::endl;

	// ���unordered_map
	myMap.clear();

	// ����Ƿ�Ϊ��
	if (myMap.empty()) {
		std::cout << "Map is now empty." << std::endl;
	}

	return 0;
}
