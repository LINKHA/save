#include <iostream>
#include <cassert>

class MemoryPool {
public:
	MemoryPool(size_t sizeOfEachBlock, unsigned int numBlocks) {
		// ��ʼ���ڴ��
		_blockSize = sizeOfEachBlock;
		_numBlocks = numBlocks;
		_pool = malloc(_blockSize * _numBlocks);
		_freeList = nullptr;

		// ��ʼ����������
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

		// �ӿ��������з���һ����
		Block* head = _freeList;
		_freeList = _freeList->next;
		return head;
	}

	void deallocate(void* ptr) {
		// ���ڴ�����¼��뵽����������
		Block* block = static_cast<Block*>(ptr);
		block->next = _freeList;
		_freeList = block;
	}

	void freeAll() {
		// ���ÿ�������ʹ����������ڴ��
		unsigned char* p = static_cast<unsigned char*>(_pool);
		_freeList = reinterpret_cast<Block*>(p);

		Block* block = _freeList;
		for (unsigned int i = 0; i < _numBlocks - 1; ++i) {
			Block* nextBlock = reinterpret_cast<Block*>(p + _blockSize);
			block->next = nextBlock;
			block = nextBlock;
			p += _blockSize;
		}

		block->next = nullptr; // ȷ�����һ�����nextָ��Ϊnullptr
	}

private:
	struct Block {
		Block* next = nullptr; // ָ����һ�����п��ָ��
	};

	size_t _blockSize;
	unsigned int _numBlocks;
	void* _pool; // ָ���ڴ�ص�ָ��
	Block* _freeList; // ���������ͷָ��
};

// ʾ��ʹ��
int main() {
	const int POOL_SIZE = 10;
	MemoryPool pool(sizeof(int), POOL_SIZE); // ����һ�����Դ洢10��int���ڴ��

	int* num = static_cast<int*>(pool.allocate()); // ���ڴ���з����ڴ�
	*num = 5;
	std::cout << *num << std::endl; // ���������ڴ��е�ֵ

	int* num2 = static_cast<int*>(pool.allocate()); // ���ڴ���з����ڴ�
	*num2 = 6;
	std::cout << *num2 << std::endl; // ���������ڴ��е�ֵ

	pool.deallocate(num); // ���ڴ���ͷŻ��ڴ��

	return 0;
}
