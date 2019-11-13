int flag = 1;
//初始化
void initial(string &a, string &b){
    while (a.size()<b.size())a = '0' + a;
    while (b.size()<a.size())b = '0' + b;
}
//打印
void print(string &a, string &b){
    cout << a << endl;
    cout << b << endl;
}
//找出最大的字符串
void findMax(string &a, string &b){
    string tmp;
    if (a<b){
        tmp = b;
        b = a;
        a = tmp;
    }
}
//删除第一个字符'0'
bool del(string &a){
    if (a[0] == '0'){
        a.erase(0, 1);
        return true;
    }
    else
        return false;
}
//删除前面所有的 0
void delAllZroe(string &a){
    while (del(a)){
        del(a);
    };
}
//大数加法
string bigItergeAdd(string a, string b){
    initial(a, b);
    a = '0' + a;
    b = '0' + b;
    for (int i = a.size() - 1; i >= 0; i--){
        int num1 = a[i] - '0';
        int num2 = b[i] - '0';
        if (num1 + num2>9){
            a[i - 1] = a[i - 1] - '0' + 1 + '0';
            a[i] = (num1 + num2) - 10 + '0';
        }
        else{
            a[i] = (num1 + num2) + '0';
        }
    }
    del(a);
    //	cout<<a<<endl;
    return a;
}
//大数减法
string bigItergeSub(string a, string b){
    initial(a, b);
    string tmp = a;
    findMax(a, b);
    if(a != tmp){
        flag = -1;
    }
    for (int i = a.size() - 1; i >= 0; i--){
        int num1 = a[i] - '0';
        int num2 = b[i] - '0';
        if (num1<num2){
            a[i - 1] = a[i - 1] - '0' - 1 + '0';
            a[i] = (num1 + 10 - num2) + '0';
        }
        else{
            a[i] = (num1 - num2) + '0';
        }
    }
    del(a);
    //	cout<<a<<endl;
    return a;
}
//大数乘法(大数加法实现)
void bigItergeMul(string a, string b){
    delAllZroe(a);
    delAllZroe(b);
    if (a == "" || b == ""){
        printf("0\n"); return;
    }
    initial(a, b);
    findMax(a, b);
    string res = "0";
    int count = 0;
    delAllZroe(b);
    for (int i = b.size() - 1; i >= 0; i--){
        int num1 = b[i] - '0';
        if (i != b.size() - 1)		a = a + '0';
        for (int j = 1; j <= num1; j++){
            res = bigItergeAdd(res, a);
        }
    }
    delAllZroe(res);
    cout << res << endl;
}
//大数除法
void bigItergeDiv(string a, string b){
    initial(a, b);
    if (a<b){ cout << "0" << endl;	return; }
    delAllZroe(b);
    string res = "0";
    string restmp = "1";
    string tmp = b;
    for (int i = 1; i<(a.size() - b.size()); i++){
        tmp += '0';
        restmp += '0';
    }
    initial(a, b);
    while (a >= b){
        initial(a, tmp);
        if (a >= tmp){
            a = bigItergeSub(a, tmp);
            res = bigItergeAdd(res, restmp);
        }
        else{
            tmp.erase(tmp.size() - 1);
            restmp.erase(restmp.size() - 1);
            initial(a, tmp);
            if (a >= tmp){
                a = bigItergeSub(a, tmp);
                res=bigItergeAdd(res, restmp);
            }
        }
        initial(a, b);
    }
    cout << res << endl;
}

int main(void) {
    string a, b;
    while (cin >> a >> b){
        string ans;
        //ans = bigItergeAdd(a,b);
		ans = bigItergeSub(a,b);
//		bigItergeMul(a,b);
//		bigItergeDiv(a,b);
        if(flag == -1){
            cout << '-';
        }
        cout << ans << endl;
    }
}