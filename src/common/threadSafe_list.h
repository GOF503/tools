#include <boost/thread.hpp>
#include <list>
#include "common.h"

template<typename T>
class CThreadSafeList
{

public:
	CThreadSafeList() {}
	~CThreadSafeList() 
	{
		if (!list_.empty())
		{
			list_.clear();
		}

	}

	void push_back(const T &pt) 
	{
		boost::mutex::scoped_lock oLock(mutex_);
		list_.push_back(pt);
	}

	T pop_front() 
	{
		boost::mutex::scoped_lock oLock(mutex_);
		if (list_.size() > 0) 
		{
			T oThread = list_.front();
			list_.pop_front();
			return oThread;
		}

		return t_object_;
	}

	void earse(T &Object) 
	{
		boost::mutex::scoped_lock oLock(mutex_);
		typedef typename list<T>::iterator iter_thread;
		for (iter_thread it = list_.begin(); it != list_.end();) 
		{
			if (Object == *it) 
			{
				list_.erase(it++);
				break;
			}
			else 
			{
				++it;
			}
		}
	}

	void clear()
	{    
		boost::mutex::scoped_lock oLock(mutex_);
		if (!list_.empty())
		{
			list_.clear();
		}

		return;
	}

	int size() 
	{
		boost::mutex::scoped_lock oLock(mutex_);
		return list_.size();
	}

	bool empty()
	{
		boost::mutex::scoped_lock oLock(mutex_);
		return list_.empty();
	}

public:
	boost::mutex mutex_;

private:
	std::list<T> list_;
	T t_object_;
};