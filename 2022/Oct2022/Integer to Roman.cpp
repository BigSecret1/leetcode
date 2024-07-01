class Solution {
public:
    string intToRoman(int num) {
		// IV -> 4, IX - > 9, XL -> 40, XC-> 90, CD-> 400, CM-> 900
		vector<string> mp(1001, "0");
		mp[1] = "I";
		mp[4] = "IV";
		mp[5] = "V";
		mp[9] = "IX";
		mp[10] = "X";
		mp[40] = "XL";
		mp[50] = "L";
		mp[90] = "XC";
		mp[100] = "C";
		mp[400] = "CD";
		mp[500] = "D";
		mp[900] = "CM";
		mp[1000] = "M";
		string answer = "";
		for(int i = 1000; i >= 1; --i) {
			if(mp[i] == "0") continue;
			int val = i;
			if(num / val) {
				for(int j = 0; j < num / val; ++j) {
					answer += mp[i];
					}
					num %= val;
				}
			}
			return answer;
    }
};

