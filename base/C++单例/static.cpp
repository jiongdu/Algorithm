//thread-safe after c++11
class Singleton{
public:
	static Singleton& getInstance(){
		static Singleton instance;
		return instance;
	}
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	Singleton operator=(const Singleton&);
};