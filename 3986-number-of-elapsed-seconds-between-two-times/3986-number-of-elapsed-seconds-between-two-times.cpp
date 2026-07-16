class Solution {
public:
    int time(string s) {
        int h   = stoi(s.substr(0, 2));   // hours
        int m   = stoi(s.substr(3, 2));   // minutes
        int sec = stoi(s.substr(6, 2));   // seconds
        return h * 3600 + m * 60 + sec;  // total seconds since midnight
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return time(endTime) - time(startTime);
    }
};