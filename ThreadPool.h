#pragma once;
#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include<vector>
#include<string>
#include<map>
struct dataPackage
{
	int num;
	struct data
	{
		void *dataPtr;
		data *nextData;
	};
};

class threadManager
{
	typedef void(*funPtr)();
	friend threadManager& getThreadManager();
protected:
	int setNumofThread(int newValue){
		int oldValue = MaxNumOfThread;
		MaxNumOfThread = newValue;
		return oldValue;
	}
	int runThreadWithoutParameter(std::string threadName, funPtr ptr);
	int getThread(std::string threadName);
	void runAsSocketServer(funPtr ptr, dataPackage data, 
		std::string LocalPort = 0, std::string LocalIPAdress = 0);
	void runAsSocketClient(funPtr ptr, dataPackage data,
		std::string Port, std::string IPAdress, std::string LocalPort = 0, std::string LocalIPAdress = 0);
	void linkTwoThreadByTwoWayPipe(std::string Thread1, std::string Thread2);
	void linkTwoThreadByOneWayPipe(std::string Thread1, std::string Thread2);
private:
	int NameTransToNum(std::string name);
	std::string NumTransToName(int num);
private:
	threadManager();
	threadManager(const threadManager& rhs);
	threadManager& operator=(const threadManager& rhs);
	~threadManager();
private:
	static int MaxNumOfThread;
	static std::map<std::string, int> tIdMap;
};

threadManager& getThreadManager(){
	static threadManager staticObject;
	return staticObject;
}
#endif