template <typename U, typename V>
class Pair {
public:
    U first;
    V second;

    Pair(U u, V v) {
        first = u;
        second = v;
    }
};

class Bucket {
public:
    list<Pair<int, int>> lst;

    Bucket() {
        // list is automatically initialized
    }

    void put(int key, int val) {
        for (auto &p : lst) {
            if (p.first == key) {
                p.second = val;
                return;
            }
        }

        lst.push_front(Pair<int, int>(key, val));
    }

    int get(int key) {
        for (auto &p : lst) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }

    void remove(int key) {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            if (it->first == key) {
                lst.erase(it);
                return;
            }
        }
    }
};

class MyHashMap {
public:
    vector<Bucket> buckets;
    int keyRange = 769;

    MyHashMap() {
        buckets.resize(keyRange);
    }

    int getIndex(int key) {
        return key % keyRange;
    }

    void put(int key, int value) {
        int bucketIdx = getIndex(key);
        buckets[bucketIdx].put(key, value);
    }

    int get(int key) {
        int bucketIdx = getIndex(key);
        return buckets[bucketIdx].get(key);
    }

    void remove(int key) {
        int bucketIdx = getIndex(key);
        buckets[bucketIdx].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */