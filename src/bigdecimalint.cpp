#include "bigdecimalint.h"
#include <iostream>
#include <string>
using namespace std;

void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
bigdecimalint::bigdecimalint()
{
    num="";
}

bool ckvalid(bigdecimalint &b)
{
    if (b.num[0]!='+'&&b.num[0]!='-'&&b.num[0]>'9'&&b.num[0]<'0')
    {
        return 0;
    }
    for (int i=1; i<b.num.length(); i++)
    {
        if (b.num[i]>'9'&&b.num[i]<'0')
        {
            return 0;
        }
    }
    return 1;
}

bigdecimalint::bigdecimalint(string decstr)
{
    num=decstr;
}

bigdecimalint :: bigdecimalint (int decint)
{
    if (decint < 0)
    {
        decint*=-1;

        while ( decint!=0)
    {

        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;

    }
    num+='-';
    }

 else   if (decint == 0)
    {

        num="0";
    }

else if (decint >0 ){
    while ( decint!=0)
    {
        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;
    }
}
    reverseStr(num);//need reverse cus storing int as a string reverses it //

}
ostream& operator<< (ostream& output, bigdecimalint a)
{
    cout<<a.num;
}
bool cksign(bigdecimalint &b)
{
    string c="";
    if (b.num[0]=='-')
    {
        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 1;
    }

    else if(b.num[0]=='+')
    {

        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 0;

    }
    else
    {
        return 0;
    }


}

bool operator>(string a, string b)
{
    if (a.length()==b.length())
    {
        for (int i=0; i<a.length(); i++)
        {
            if (a[i]>b[i])
            {

                return 1;
            }
            else if (b[i]>a[i])
            {

                return 0;
            }
        }

    }

}

bool operator<(string a, string b)
{

    for (int i=0;i<a.length();i++)
    {
        if (a[i]==b[i])
        {
            continue;
        }
        else
            return 0;

    }

    return 1;
}


bigdecimalint bigdecimalint::operator+(bigdecimalint b)
{

   if ((num[0]=='-')&&(b.num[0]=='+'))
    {
        cksign(*this);
        return b - *this;
    }

    if ((num[0]<='9'&&num[0]>='0')&&(b.num[0]=='-'))
    {
        cksign(b);
        return *this - b;
    }


    if (b.num.length()>num.length())
    {
        int diff=b.num.length()-num.length();

        bigdecimalint c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i+diff]-2*'0'+c.carry;//-'0' transforms char into int ;//
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }

            c.num+=c.sum+'0';
        }
        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        reverseStr(c.num) ;
        return c;
    }
    else if (num.length()>b.num.length())
    {

        int diff=num.length()-b.num.length();
        bigdecimalint c;
        c.num="";
        c.carry=0;

        for (int i=(b.num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=num[i+diff]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }
        reverseStr(c.num) ;
        return c;
    }

    else
    {
        bigdecimalint c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';
        }
        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }
        reverseStr(c.num) ;
        return c;

    }
}

bigdecimalint bigdecimalint::operator-(bigdecimalint b)
{
    if (b.num[0]=='-'&&(num[0]=='+'||(num[0]<='9'&&num[0]>='0')))
    {
        cksign(b);
        return *this+b;
    }

    else if (num[0]=='-'&&(b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0')))
    {
        cksign(*this);
        return *this + b;
    }

    else if (b.num[0]=='-'&&num[0]=='-')
    {
        cksign(b);
        cksign(*this);
        return b- *this;
    }

    if (num.length()>b.num.length())
    {

        int diff = num.length()-b.num.length();
        bigdecimalint c;
        c.num="";
        c.carry=0;
        for (int i=(b.num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=num[i+diff]-b.num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';
        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }

            c.num+=c.sum+'0';
        }

        reverseStr(c.num);

        return c;
    }

    if (b.num.length()>num.length())
    {

        int diff =b.num.length()-num.length();
        bigdecimalint c;
        c.num="";
        c.carry=0;
        for (int i=(num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=b.num[i+diff]-num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';
        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';
        }

        c.num+='-';

        reverseStr(c.num);

        return c;
    }

    if (num.length()==b.num.length())
    {
        if (operator<(num,b.num))
        {
            bigdecimalint c;
            c.num="0";
            return c;
        }

        if (operator>(num,b.num))
        {
            bigdecimalint c;
            c.num="";
            c.carry=0;
            for (int i=(num.length()-1); i>=0; i--)
            {
                c.sum=0;
                c.sum=num[i]-b.num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';
            }
            reverseStr(c.num) ;

            return c;
        }

        else if (operator>(b.num,num))
        {

            bigdecimalint c;
            c.num="";
            c.carry=0;
            for (int i=(b.num.length()-1); i>=0; i--)
            {
                c.sum=0;
                c.sum=b.num[i]-num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';
            }
            c.num+='-';
            reverseStr(c.num) ;

            return c;
        }
    }
}

int bigdecimalint ::size()
{
    return num.length();
}

