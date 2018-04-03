#include"ThreadPool.h"
threadManager::threadManager()
{
	tIdMap.clear();
	for (int i = MaxNumOfThread; i > 0; --i){
		int id = i;
		tIdMap.insert(std::make_pair("DEFAULT_NAME", id));
	}
}

threadManager::~threadManager()
{
}