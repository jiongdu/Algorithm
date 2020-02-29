#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) {
        // do intialization if necessary
        cap = capacity;
        size = 0;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (cap <= 0) return;
        //问题在这里，所以set的时候要调用get，这样原来有的情况下也会计算频率的
        int storedValue = get(key);
        if (storedValue != -1) {        //已经有了，直接更新值即可
            m[key].first = value;
            return;
        }   
        // 这样是不对的
        // if (m.count(key) > 0) {
        //     m[key].first = value;        
        //     return;
        // }
        //要先删除元素,删除频率最小的
        if (size >= cap) {
            int delElement = fm[minFreq].front();
            mIter.erase(delElement);        //mIter中删除
            fm[minFreq].pop_front();    //fm中删除
            m.erase(delElement);
            size--;
            // m.erase(fm[minFreq].front());       //移除最小频率中list最前面的
            // mIter.erase(fm[minFreq].front());   //移除最小频率中list最前面的iterator
            // fm[minFreq].pop_front();
            // size--;
        }
        //装入新元素
        std::pair<int, int> newElement = {value, 1};
        m[key] = newElement;
        fm[1].push_back(key);
        mIter[key] = --fm[1].end();
        minFreq = 1;
        size++;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    //傻逼了，是因为赋值符号写成了==
    int get(int key) {
        // write your code here
        // 影响freq
        if (m.count(key) == 0) return -1;
        // 从原来的freq对应的list移除
        fm[m[key].second].erase(mIter[key]);
        // 该key的freq++
        m[key].second++;
        // 在新的freq对应的list中加入, list中存key
        fm[m[key].second].push_back(key);    
        mIter[key] = --fm[m[key].second].end();
        
        //当前所存的最小频率
        if (fm[minFreq].size() == 0) {
            minFreq++;
        }

        return m[key].first;
    }

private:
    int size;
    int cap;
    int minFreq;
    unordered_map<int, pair<int, int>> m;            //key, <value, freq>
    unordered_map<int, list<int>> fm;               //frequency, list<int>
    unordered_map<int, list<int>::iterator> mIter;      //key, list::iterator   
};