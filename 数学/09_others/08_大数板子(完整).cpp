//\\ \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //
//\\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //
//\\ \\ \\ \\ \\ \\          o8888888o            // // // // // //
//\\ \\ \\ \\ \\             88" . "88               // // // // //
//\\ \\ \\ \\                (| -_- |)                  // // // //
//\\ \\ \\                   O\  =  /O                     // // //
//\\ \\                   ____/`---'\____                     // //
//\\                    .'  \\|     |//  `.                      //
//==                   /  \\|||  :  |||//  \                     ==
//==                  /  _||||| -:- |||||-  \                    ==
//==                  |   | \\\  -  /// |   |                    ==
//==                  | \_|  ''\---/''  |   |                    ==
//==                  \  .-\__  `-`  ___/-. /                    ==
//==                ___`. .'  /--.--\  `. . ___                  ==
//==              ."" '<  `.___\_<|>_/___.'  >'"".               ==
//==            | | :  `- \`.;`\ _ /`;.`/ - ` : | |              \\
////            \  \ `-.   \_ __\ /__ _/   .-` /  /              \\
////      ========`-.____`-.___\_____/___.-`____.-'========      \\
////                           `=---='                           \\
//// //   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \\ \\
//// // //      佛祖保佑      永无BUG      永不修改        \\ \\ \\ \\
//// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ \\

/***
*               ii.                                         ;9ABH,
*              SA391,                                    .r9GG35&G
*              &#ii13Gh;                               i3X31i;:,rB1
*              iMs,:,i5895,                         .5G91:,:;:s1:8A
*               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
*                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
*                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
*               :SB9s:,............................,,,.,,,SASh53h,1G.
*            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
*          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
*        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
*       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
*      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
*      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
*      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
*      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
*     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
*     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
*    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
*   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
*  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
*  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
*  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
*  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
*  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
*   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
*    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
*     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
*      ,8X5;   .     .......                                       ,;iihS8Gi
*         1831,                                                 .,;irrrrrs&@
*           ;5A8r.                                            .:;iiiiirrss1H
*             :X@H3s.......                                .,:;iii;iiiiirsrh
*              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
*             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
*             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
*            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
*            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
真——手动狗头*/
//by ACM-er vegetable birds

#include<bits/stdc++.h>

using namespace std;
const int maxn = 10005;/*精度位数,自行调整*/
//1.如果需要控制输出位数的话，在str()里面把len调成需要的位数
//2.很大的位数是会re的，所以如果是幂运算的话，如 计算x^p的位数n, n=p*log(10)x+1;(注意要加一）
//3.还可以加上qmul，取模的过程也就是str()，c_str()再搞一次
class bign {
    //io*2 bign*5*2 bool*6
    friend istream &operator>>(istream &, bign &);

    friend ostream &operator<<(ostream &, const bign &);

    friend bign operator+(const bign &, const bign &);

    friend bign operator+(const bign &, int &);

    friend bign operator*(const bign &, const bign &);

    friend bign operator*(const bign &, int &);

    friend bign operator-(const bign &, const bign &);

    friend bign operator-(const bign &, int &);

    friend bign operator/(const bign &, const bign &);

    friend bign operator/(const bign &, int &);

    friend bign operator%(const bign &, const bign &);

    friend bign operator%(const bign &, int &);

    friend bool operator<(const bign &, const bign &);

    friend bool operator>(const bign &, const bign &);

    friend bool operator<=(const bign &, const bign &);

    friend bool operator>=(const bign &, const bign &);

    friend bool operator==(const bign &, const bign &);

    friend bool operator!=(const bign &, const bign &);

private://如果想访问len,改成public
    int len, s[maxn];
public:
    bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    bign operator=(const char *num) {
        int i = 0, ol;
        ol = len = strlen(num);
        while (num[i++] == '0' && len > 1)
            len--;
        memset(s, 0, sizeof(s));
        for (i = 0; i < len; i++)
            s[i] = num[ol - i - 1] - '0';
        return *this;
    }

    bign operator=(int num) {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    bign(int num) {
        *this = num;
    }

    bign(const char *num) {
        *this = num;
    }

    string str() const {
        string res = "";
        for (int i = 0; i < len; i++)
            res = char(s[i] + '0') + res;
        if (res == "")
            res = "0";
        return res;
    }
};

bool operator<(const bign &a, const bign &b) {
    int i;
    if (a.len != b.len)
        return a.len < b.len;
    for (i = a.len - 1; i >= 0; i--)
        if (a.s[i] != b.s[i])
            return a.s[i] < b.s[i];
    return false;
}

bool operator>(const bign &a, const bign &b) {
    return b < a;
}

bool operator<=(const bign &a, const bign &b) {
    return !(a > b);
}

bool operator>=(const bign &a, const bign &b) {
    return !(a < b);
}

bool operator!=(const bign &a, const bign &b) {
    return a < b || a > b;
}

bool operator==(const bign &a, const bign &b) {
    return !(a < b || a > b);
}

bign operator+(const bign &a, const bign &b) {
    int up = max(a.len, b.len);
    bign sum;
    sum.len = 0;
    for (int i = 0, t = 0; t || i < up; i++) {
        if (i < a.len)
            t += a.s[i];
        if (i < b.len)
            t += b.s[i];
        sum.s[sum.len++] = t % 10;
        t /= 10;
    }
    return sum;
}

bign operator+(const bign &a, int &b) {
    bign c = b;
    return a + c;
}

bign operator*(const bign &a, const bign &b) {
    bign res;
    for (int i = 0; i < a.len; i++) {
        for (int j = 0; j < b.len; j++) {
            res.s[i + j] += (a.s[i] * b.s[j]);
            res.s[i + j + 1] += res.s[i + j] / 10;
            res.s[i + j] %= 10;
        }
    }
    res.len = a.len + b.len;
    while (res.s[res.len - 1] == 0 && res.len > 1)
        res.len--;
    if (res.s[res.len])
        res.len++;
    return res;
}

bign operator*(const bign &a, int &b) {
    bign c = b;
    return a * c;
}

//只支持大数减小数
bign operator-(const bign &a, const bign &b) {
    bign res;
    int len = a.len;
    for (int i = 0; i < len; i++) {
        res.s[i] += a.s[i] - b.s[i];
        if (res.s[i] < 0) {
            res.s[i] += 10;
            res.s[i + 1]--;
        }
    }
    while (res.s[len - 1] == 0 && len > 1)
        len--;
    res.len = len;
    return res;
}

bign operator-(const bign &a, int &b) {
    bign c = b;
    return a - c;
}

bign operator/(const bign &a, const bign &b) {
    int i, len = a.len;
    bign res, f;
    for (i = len - 1; i >= 0; i--) {
        f = f * 10;
        f.s[0] = a.s[i];
        while (f >= b) {
            f = f - b;
            res.s[i]++;
        }
    }
    while (res.s[len - 1] == 0 && len > 1)
        len--;
    res.len = len;
    return res;
}

bign operator/(const bign &a, int &b) {
    bign c = b;
    return a / c;
}

bign operator%(const bign &a, const bign &b) {
    int len = a.len;
    bign f;
    for (int i = len - 1; i >= 0; i--) {
        f = f * 10;
        f.s[0] = a.s[i];
        while (f >= b)
            f = f - b;
    }
    return f;
}

bign operator%(const bign &a, int &b) {
    bign c = b;
    return a % c;
}

bign &operator+=(bign &a, const bign &b) {
    a = a + b;
    return a;
}

bign &operator-=(bign &a, const bign &b) {
    a = a - b;
    return a;
}

bign &operator*=(bign &a, const bign &b) {
    a = a * b;
    return a;
}

bign &operator/=(bign &a, const bign &b) {
    a = a / b;
    return a;
}

bign &operator++(bign &a) {
    a = a + 1;
    return a;
}

bign &operator++(bign &a, int) {
    bign t = a;
    a = a + 1;
    return t;
}

bign &operator--(bign &a) {
    a = a - 1;
    return a;
}

bign &operator--(bign &a, int) {
    bign t = a;
    a = a - 1;
    return t;
}

istream &operator>>(istream &in, bign &x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream &operator<<(ostream &out, const bign &x) {
    out << x.str();
    return out;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bign a;
    bign b;
    cin >> a >> b;
    cout << a / b << endl;
}