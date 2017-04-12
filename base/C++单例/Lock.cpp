//读写都要加锁，对于读是不必要的开销
Singleton* Singleton::getInstance(){
	Lock lock;
	if(instance==nullptr){
		instance = new Singleton();
	}
	return instance;
}

//双检查，但由于内存reorder，不是线程安全
Singleton* Singleton::getInstance(){
	if(instance==nullptr){
		Lock lock;
		if(instance==nullptr){
			instance = new Singleton();
		}
	}
	return instance;
}