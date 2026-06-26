class TimeMap {
public:

    struct Element{
        string value;
        int timestamp;
    };

    unordered_map<string, vector<Element>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(m[key].begin(), m[key].end(), timestamp, [](int target, const Element& e) {
            return target < e.timestamp;
        });

        if (it != m[key].begin()) {
            return (--it)->value;
        }
        return "";
    }
};
