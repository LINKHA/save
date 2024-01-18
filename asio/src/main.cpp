#include <asio.hpp>
#include <iostream>
#include <thread>

void myTask(asio::io_context& ioContext) {
	std::cout << "Executing myTask in thread: " << std::this_thread::get_id() << std::endl;

	// Perform asynchronous operations using ioContext
}

int main() {
	const int numThreads = 3;
	std::vector<std::thread> threads;
	std::vector<asio::io_context> ioContexts(numThreads);

	for (int i = 0; i < numThreads; ++i) {
		threads.emplace_back([&ioContext = ioContexts[i]] {
			asio::executor_work_guard<asio::io_context::executor_type> workGuard(ioContext.get_executor());
			ioContext.run();
			});
	}

	// Dispatch tasks to different io_contexts
	for (int i = 0; i < numThreads; ++i) {
		asio::post(ioContexts[i], [i, &ioContext = ioContexts[i]] {
			myTask(ioContext);
			});
	}

	// Wait for all threads to finish
	for (auto& thread : threads) {
		thread.join();
	}
	return 0;
}