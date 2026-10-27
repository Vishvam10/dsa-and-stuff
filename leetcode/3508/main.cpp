#include <bits/stdc++.h>
using namespace std;

class Router {
    // {src, dest, timestamp}
    using Packet = array<int, 3>;

    int limit;
    deque<Packet> dq;
    set<Packet> mp;

    // destination -> timstamp
    unordered_map<int, vector<int>> times;
    unordered_map<int, int> head;

    void removePacket(const Packet& p) {
        mp.erase(p);
        head[p[1]]++;
    }

public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p = {source, destination, timestamp};

        if (mp.count(p)) return false;
        if (dq.size() == limit) {
            Packet old = dq.front();
            dq.pop_front();
            removePacket(old);
        }

        dq.push_back(p);
        mp.insert(p);
        times[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty()) return {};

        Packet p = dq.front();
        dq.pop_front();
        removePacket(p);

        return {p[0], p[1], p[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = times.find(destination);
        if (it == times.end()) return 0;

        auto& v = it->second;
        int h = head[destination];

        auto lo = lower_bound(v.begin() + h, v.end(), startTime);
        auto hi = upper_bound(v.begin() + h, v.end(), endTime);

        return hi - lo;
    }
};
