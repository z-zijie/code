/* Problem Number: 1001
 * Author: Zijie Zhang
 * Describe:
 * 		Compute R^n
 * 		R \in Real, n is number <=25
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void EmptyArray(vector<int> &A){
	while(!A.empty()){
		A.pop_back();
	}
}

void convert2array(vector<int> &A, string s){
	A.push_back(0);
	for(int i = 0; i < s.length(); i++){
		if('0' <= s[i] && s[i] <= '9')
			A.push_back(s[i]-'0');
		if(s[i] == '.') A[0] = i;
	}
	while(A.size() - 1 >= A[0] && A.back() == 0)
	   A.pop_back();	
}

void Print(vector<int> ans){
	int dot = ans[0];
	for(int i = 1; i < ans.size(); i++){
//		if(i <= dot && ans[i] == 0 && dot == 1) continue;		
		if(dot == i-1) cout << '.';
		cout << ans[i];
	}
	cout << endl;
}


void multiply(vector<int> &ans, vector<int> base){
	vector<int> temp;
	int add = 0, t = 0;
	EmptyArray(temp);
	while(temp.size() < ans.size() + base.size()) temp.push_back(0);
	for(int basepoint = base.size() - 1; basepoint > 0; basepoint--){
		add = 0;
		for(int anspoint = ans.size() - 1; anspoint > 0; anspoint--){
			t = base[basepoint] * ans[anspoint] + add;
			add = t / 10;
			t = t % 10;
			temp[base.size() - basepoint + ans.size() - anspoint - 1] += t;
		}
		if(add > 0) temp[base.size() - basepoint + ans.size() - 1] += add;
		// debug
		// Print(temp);
	}
	for(int i = 1; i < temp.size(); i++){
		if(temp[i] > 9){
			temp[i + 1] += temp[i] / 10;
			temp[i] %= 10;
		}
	}
	// debug
	//for(int i = 0; i < temp.size(); i++) cout << temp[i] << " "; cout << endl;
	
	int dot = base.size() - base[0] - 1 + ans.size() - ans[0] - 1;
	while(temp.back() == 0 && temp.size() > dot + 1) temp.pop_back();
	// debug
	// cout << base.size() - base[0] - 1 << "," << ans.size() - ans[0] - 1 << endl;
	EmptyArray(ans);
	ans.push_back(temp.size() - dot - 1);
	while(temp.size() > 1){
		ans.push_back(temp.back());
		temp.pop_back();
	}
	while(ans.size() - 1 >= ans[0] && ans.back() == 0)
		ans.pop_back();
	//debug
	//Print(temp2);
}




int main()
{
	// Input
	freopen("1001.in", "r", stdin);
	string s;
	int n;
	vector <int> base;
	vector <int> ans;

	while (cin >> s >> n) {
		//init
		EmptyArray(base); EmptyArray(ans);
		//convert s to array
		convert2array(base, s);
		ans = base;
		
		//multiply n-1 times
		n--;
		while(n--) multiply(ans, base);

		//print answer
		Print(ans);
	}
	return 0;
}
