#include<iostream>
#include <string>
using namespace std;
/*
Date Date::operator++( int )
{
Date temp = *this; // hold current state of object
helpIncrement();
// return unincremented, saved, temporary object
return temp; // value return; not a reference return
} // end function operator++
*/
class HugeInt
{
    friend bool operator>=(int,const HugeInt);
    friend bool operator>=(const HugeInt,int);
    friend bool operator>=(const HugeInt,const HugeInt);
    friend bool operator>=(const HugeInt, string);
    friend bool operator>=(string ,const HugeInt);
    friend HugeInt operator+(int,HugeInt);// i + Hi
    friend HugeInt operator+(string,HugeInt);// string + HugeInt
    friend ostream& operator<<(ostream &, const HugeInt &);
    public:
    static const int digits = 30;
    HugeInt(long = 0);
    HugeInt operator++( int); // ++
    HugeInt(const string &);
    //HI+HI
    HugeInt operator+(const HugeInt &) const;
    // HI + I
    HugeInt operator+(int) const;
    // addition string
    HugeInt operator+(const string &) const;
    HugeInt &add();
    private:
    short integer[digits];
};
HugeInt &HugeInt::add()
{
    HugeInt temp;
    int carry = 0;
    temp.integer[digits-1] = 1;
    for ( int i = digits-1; i>=0;i--)
    {
        integer[i] = temp.integer[i]+integer[i] + carry;
    
    if (integer[i] > 9)
    {
        integer[i]%=10;
        carry = 1;
    }
    else 
    carry = 0;
    }
    return *this;
}
HugeInt HugeInt::operator++(int a)
{
    HugeInt temp1 = *this;
    *this = *this + (HugeInt)1;
    return temp1;
}
bool operator>=(const HugeInt a,const HugeInt b)
{
    for ( int i = 0 ; i < HugeInt::digits ; i++)
    {
        /*
        if ( a.integer[i] >= b.integer[i] )
        {
            return true;
        }
        */
        if ( a.integer[i] == b.integer[i] )
        {
            continue;
        }
        if ( a.integer[i] < b.integer[i] )
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    return true;
}
bool operator>=(const HugeInt a,int b)
{
    // if n3 >= 100 return true
    HugeInt x(b); // b -> HugeInt
    for ( int i = 0 ; i < HugeInt::digits ; i++)
    {
        /*
        if ( a.integer[i] >= b.integer[i] )
        {
            return true;
        }
        */
        if ( a.integer[i] == x.integer[i] )
        {
            continue;
        }
        if ( a.integer[i] < x.integer[i] )
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    return false;
}
bool operator>=(int a,const HugeInt b)
{
    // if n3 >= 100 return true
    HugeInt x(a); // a -> HugeInt
    for ( int i = 0 ; i < HugeInt::digits ; i++)
    {
        /*
        if ( a.integer[i] >= b.integer[i] )
        {
            return true;
        }
        */
        if ( x.integer[i] == b.integer[i] )
        {
            continue;
        }
        if ( x.integer[i] < b.integer[i] )
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    return false;
}
bool operator>=(const HugeInt a, string b)
{
    // if n3 >= 100 return true
    HugeInt x(b); // a -> HugeInt
    for ( int i = 0 ; i < HugeInt::digits ; i++)
    {
        if ( a.integer[i] == x.integer[i] )
        {
            continue;
        }
        if ( a.integer[i] < x.integer[i] )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
HugeInt operator+(int a,HugeInt b)
{
    return (HugeInt)a+b;
}
HugeInt operator+(string a,HugeInt b)
{
    return (HugeInt)a+b;
}
HugeInt::HugeInt(long value)
{
    for ( int i = 0 ; i < digits ; i++ )
    integer[i] = 0;
    for ( int j = digits - 1; value != 0 && j >= 0; j-- )
    {
        integer[j] = value%10;
        value/=10;
    }
}
HugeInt::HugeInt( const string &number )
{
    for ( int i = 0 ; i < digits ; i++ )
    integer[i] = 0;
    int length = number.size();
    for ( int j = digits - length, k = 0 ;j < digits; j++, k++ )
    {
        if ( isdigit( number[k]))
        integer[j] = number[k] - '0';
    }
}
bool operator>=(string a,const HugeInt b)
{
    // if n3 >= 100 return true
    HugeInt x(a); // a -> HugeInt
    for ( int i = 0 ; i < HugeInt::digits ; i++)
    {
        if ( x.integer[i] == b.integer[i] )
        {
            continue;
        }
        if ( x.integer[i] < b.integer[i] )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
HugeInt HugeInt::operator+( const HugeInt &op2 )const
{
    HugeInt temp;
    int carry = 0;
    for ( int i = digits-1; i >=0;i--)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
    
    if (temp.integer[i] > 9)
    {
        temp.integer[i]%=10;
        carry = 1;
    }
    else 
    carry = 0;
    }
    return temp;
}
HugeInt HugeInt::operator+(int op2) const
{
    return *this + HugeInt(op2);
}
HugeInt HugeInt::operator+(const string &op2) const
{
    return *this + HugeInt(op2);
}
ostream &operator<<(ostream &output, const HugeInt & num)
{
    int i;
    for ( i = 0; (num.integer[i] == 0 )&&(i <= HugeInt::digits); i++);
    if ( i == HugeInt::digits )
    output << 0;
    else 
    for ( ;i < HugeInt::digits; i++)
    output << num.integer[i];
    
    return output;
}
int main()
{
    
    HugeInt n1(7654321);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5(n4);
    cout << "n1 is " << n1 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nn5 is " << n5 << "\n\n";
    HugeInt n6 = n3 + n4;
    cout <<"test"<< n1+n1 << endl ;
    cout << "n6 = " << n3 << '+' << n4 << " = " << n6 << "\n\n";
    cout << "9+n1 = " << 9 + n1 << " " << "9" + n1 << "  " << n1+9 << endl;
    cout << "n4+100+900+n5= " << n4+100+900+n5 << endl;
    cout << "n3++=" << n3++ << endl;
    cout << "n3=" << n3 << endl;
    
    if ( n3 >= n1 )
    cout << "\nyes-1" << endl;
    else cout << "no-1" << endl;
    if ( n3 >= 100 )
    cout << "\nyes-2" << endl;
    else cout << "no-2" << endl;
    if ( 100 >= n3 )
    cout << "\nyes-3" << endl;
    else cout << "no-3" << endl;
    if ( n3 >= "100" )
    cout << "\nyes-4" << endl;
    else cout << "no-4" << endl;
    if ( "100" >= n3 )
    cout << "\nyes-5" << endl;
    else cout << "no-5" << endl;
}