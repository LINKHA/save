#include <iostream>
#include <cassert>

class MemoryPool {
public:
	MemoryPool(size_t sizeOfEachBlock, unsigned int numBlocks) {
		// 初始化内存池
		_blockSize = sizeOfEachBlock;
		_numBlocks = numBlocks;
		_pool = malloc(_blockSize * _numBlocks);
		_freeList = nullptr;

		// 初始化空闲链表
		freeAll();
	}

	~MemoryPool() {
		free(_pool);
	}

	void* allocate() {
		if (!_freeList) {
			std::cerr << "Memory pool out of space." << std::endl;
			return nullptr;
		}

		// 从空闲链表中分配一个块
		Block* head = _freeList;
		_freeList = _freeList->next;
		return head;
	}

	void deallocate(void* ptr) {
		// 将内存块重新加入到空闲链表中
		Block* block = static_cast<Block*>(ptr);
		block->next = _freeList;
		_freeList = block;
	}

	void freeAll() {
		// 重置空闲链表，使其包含所有内存块
		unsigned char* p = static_cast<unsigned char*>(_pool);
		_freeList = reinterpret_cast<Block*>(p);

		Block* block = _freeList;
		for (unsigned int i = 0; i < _numBlocks - 1; ++i) {
			Block* nextBlock = reinterpret_cast<Block*>(p + _blockSize);
			block->next = nextBlock;
			block = nextBlock;
			p += _blockSize;
		}

		block->next = nullptr; // 确保最后一个块的next指针为nullptr
	}

private:
	struct Block {
		Block* next = nullptr; // 指向下一个空闲块的指针
	};

	size_t _blockSize;
	unsigned int _numBlocks;
	void* _pool; // 指向内存池的指针
	Block* _freeList; // 空闲链表的头指针
};

// 示例使用
int main() {
	const int POOL_SIZE = 10;
	MemoryPool pool(sizeof(int), POOL_SIZE); // 创建一个可以存储10个int的内存池

	int* num = static_cast<int*>(pool.allocate()); // 从内存池中分配内存
	*num = 5;
	std::cout << *num << std::endl; // 输出分配的内存中的值

	int* num2 = static_cast<int*>(pool.allocate()); // 从内存池中分配内存
	*num2 = 6;
	std::cout << *num2 << std::endl; // 输出分配的内存中的值

	pool.deallocate(num); // 将内存块释放回内存池

	return 0;
}
