class MyCalendar {
public:
    set<pair<int, int>> cal;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        auto nxt = cal.lower_bound({startTime, endTime});

        if (nxt != cal.end() && nxt->first < endTime) return false;
        if (nxt != cal.begin() && prev(nxt)->second > startTime) return false;

        cal.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

class MyCalendar {
public:
    vector<pair<int, int>> cal;
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        for(const auto& [start, end] : cal) {
            if(startTime < end && endTime > start) return false;
        }
        cal.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */