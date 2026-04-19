class Solution {
public:
    string multiply(string num1, string num2) {
        if (num2 == "0") return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        if (num2.size() > num1.size()) swap(num1,num2);
        string res = "";
        for (int i = 0; i < num2.size(); i++) {
            string to_add = mul(num1, num2[i]);
            cout << num1 << " " << num2[i] << endl;
            reverse(to_add.begin(),to_add.end());
            int j = i;
            while(j--)to_add.push_back('0');
            reverse(to_add.begin(),to_add.end());
            cout << to_add << endl;
            res = add(res, to_add);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string mul(string num1, char num2) {
        string res = "";
        int carry = 0;
        int m = num2 - '0';
        cout << m << endl;
        for (int i = 0; i < num1.size(); i++) {
            int prod = (num1[i] - '0') * m;
            int digit = (prod + carry) % 10;
            carry = (prod + carry) / 10;
            res.push_back(digit + '0');
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        return res;
    }
    string add(string num1, string num2) {
        int carry = 0;
        
        string res = "";
        for (int i = 0; i < num2.size(); i++) {
            int a = 0;

            if (i < num1.size()) {
                a = num1[i] - '0';
            }
            int b = num2[i] - '0';
            int added = a + b;
            int digit = (added + carry) % 10;
            carry = (added + carry) / 10;
            res.push_back(digit + '0');
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        return res;
        
    }
};
