//Tutorial 1 on multithreading
// Two threads modifying a common vector

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<int> mList;
std::mutex gMutex;

void func(){

	for(int i=0; i<5; ++i){
		std::lock_guard<std::mutex> guard(gMutex);
		mList.push_back(i);
	}

}

int main(){

	std::thread t1(&func);
	std::thread t2(&func);


	t1.join();
	t2.join();


	for(auto it: mList){
		std::cout<<it<<" ";
	}

	return 0;
}
