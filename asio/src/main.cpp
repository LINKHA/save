#include <iostream>
#include <asio.hpp>
#include <vector>

class AsioIOContextPool
{
public:
	using IOContext = asio::io_context;
	using Work = asio::io_context::work;
	using WorkPtr = std::unique_ptr<Work>;

	//返回当前系统支持的并发线程数
	AsioIOContextPool(std::size_t size = std::thread::hardware_concurrency()) :
		ioContexts_(size),
		works_(size),
		nextIOContext_(0)
	{
		for (std::size_t i = 0; i < size; ++i)
		{
			works_[i] = std::unique_ptr<Work>(new Work(ioContexts_[i]));
		}

		for (std::size_t i = 0; i < ioContexts_.size(); ++i)
		{
			threads_.emplace_back([this, i]() {
				ioContexts_[i].run();
				});
		}
	}

	AsioIOContextPool(const AsioIOContextPool&) = delete;
	AsioIOContextPool& operator=(const AsioIOContextPool&) = delete;

	asio::io_context& getIOContext()
	{
		auto& context = ioContexts_[nextIOContext_++];
		if (nextIOContext_ == ioContexts_.size())
		{
			nextIOContext_ = 0;
		}
		return context;
	}

	void stop()
	{
		for (auto& work : works_)
		{
			work.reset();
		}

		for (auto& t : threads_)
		{
			t.join();
		}
	}

private:
	std::vector<IOContext> ioContexts_;
	std::vector<WorkPtr> works_;
	std::vector<std::thread> threads_;
	std::size_t nextIOContext_;
};

int main()
{
	std::mutex mtx;
	AsioIOContextPool pool;
	asio::steady_timer timer{ pool.getIOContext(), std::chrono::seconds{2} };
	timer.async_wait([&mtx](const asio::error_code& ec) {
		std::lock_guard<std::mutex> lock(mtx);
		std::cout << "Hello, World!" << std::endl;
		});

	pool.stop();
	return 0;
}