class LFUCache {
public:

    int cap;
    int minFreq;

    // key -> iterator pointing to {key,value,freq}
    unordered_map<int, list<vector<int>>::iterator> mp;

    // freq -> list of {key,value,freq}
    unordered_map<int, list<vector<int>>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void makeMostFrequencyUsed(int key) {

        auto it = mp[key];

        int value = (*it)[1];
        int f = (*it)[2];

        // remove from old frequency list
        freq[f].erase(it);

        // if old list becomes empty
        if (freq[f].empty()) {

            freq.erase(f);

            // if minimum frequency list vanished
            if (minFreq == f)
                minFreq++;
        }

        // increase frequency
        f++;

        // insert into new frequency list
        freq[f].push_front({key, value, f});

        // update iterator
        mp[key] = freq[f].begin();
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        int value = (*(mp[key]))[1];

        makeMostFrequencyUsed(key);

        return value;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        // key already present
        if (mp.find(key) != mp.end()) {

            (*(mp[key]))[1] = value;

            makeMostFrequencyUsed(key);

            return;
        }

        // cache full
        if (mp.size() == cap) {

            // remove least recently used
            // from minimum frequency list

            auto node = freq[minFreq].back();

            int delKey = node[0];

            freq[minFreq].pop_back();

            mp.erase(delKey);

            if (freq[minFreq].empty())
                freq.erase(minFreq);
        }

        // every new node starts with frequency 1

        freq[1].push_front({key, value, 1});

        mp[key] = freq[1].begin();

        minFreq = 1;
    }
};