class Solution {
public:

    double roundToFiveDecimalPlaces(double value) {
    double factor = pow(10.0, 5); // 10^5
    return round(value * factor) / factor;
}
    double averageWaitingTime(vector<vector<int>>& customers) {
        double answer = 0;
        vector<int> waiting;
        waiting.push_back(customers[0][0] + customers[0][1]);
        int n = customers.size();
        for(int i = 1; i < n; ++i) {
            int lastWaiting = waiting.back();
            waiting.push_back(customers[i][0] <= lastWaiting ? lastWaiting + customers[i][1]: customers[i][1] + customers[i][0]);
        }
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            long long difference = (waiting[i] - customers[i][0]);
            sum += difference;
        }
        answer = double(sum) / n;
        return roundToFiveDecimalPlaces(answer);
    }
};

