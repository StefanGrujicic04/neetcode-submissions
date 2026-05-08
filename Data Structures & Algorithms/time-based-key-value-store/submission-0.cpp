class TimeMap {
    // za svaki kljuc cuvas listu parova (timestamp, value)
    unordered_map<string, vector<pair<int,string>>> store;

public:
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
        // timestamps su uvijek rastuce, lista ostaje sortirana
    }

    string get(string key, int timestamp) {
        // ako kljuc ne postoji
        if (!store.count(key)) return "";

        vector<pair<int,string>>& vals = store[key];

        // binary search — nadji najveci timestamp <= query
        int lo = 0, hi = vals.size() - 1;
        string res = "";

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (vals[mid].first <= timestamp) {
                res = vals[mid].second;  // validan kandidat, trazi desnije
                lo = mid + 1;
            } else {
                hi = mid - 1;           // previse velik, idi lijevo
            }
        }

        return res;
    }
};
