class Solution {
public:
    int convertTodays(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = day;
        for (int i = 0; i < month-1; i++) {
            totalDays += days[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aA = convertTodays(arriveAlice);
        int lA = convertTodays(leaveAlice);
        int aB = convertTodays(arriveBob);
        int lB = convertTodays(leaveBob);

        if (aB > lA || aA > lB) {
            return 0;
        }
        if (lA <= lB) {
            return lA - max(aA, aB) + 1;
        }
        
        return lB - max(aA, aB) + 1;
    }
};