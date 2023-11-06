// Starter file for CSCI 60 Homework 6; due Monday 2/20/23
// Mengxi He

#include <iostream>
#include <vector>
using namespace std;

// complete implementation of a simple class for storing immutable fractions
class Fraction {
public:
  Fraction(int num, int denom) : n(num), d(denom) {}
  Fraction() : Fraction(0,1) {}
  Fraction operator +(const Fraction& rhs) const; 
  friend ostream& operator <<(ostream& o, const Fraction& f); 
private:
  const int n;
  const int d;
};

Fraction Fraction::operator +(const Fraction& rhs) const {
  return Fraction(n*rhs.d+rhs.n*d,d*rhs.d);
}

ostream& operator <<(ostream& o, const Fraction& f) {
  return o << f.n << "/" << f.d;
}

// Milestone 1: overload << for vector
template <typename T>
ostream& operator <<(ostream& o, const vector<T> v)
{
  for (int i=0; i<v.size(); i++)
  {
    o<<v[i]<<", ";
  }
  return o;
}

// Milestone 2: design and implement the HetPair class
template <typename T, typename U>
class HetPair
{
public:
  HetPair() : x(T()), y(U()){}
  HetPair(T lhs, U rhs) : x(lhs), y(rhs){}
  T getX() const {return x; }
  U getY() const {return y; }
  HetPair<T, U> operator + (const HetPair<T, U> rhs);
private:
  T x;
  U y;
};

template <typename T, typename U>
HetPair<T, U> HetPair<T, U>::operator + (const HetPair<T, U> rhs)
{
  HetPair<T, U> sum;
  sum.x = x + rhs.x;
  sum.y = y + rhs.y;
  return sum;
}

template <typename T, typename U>
ostream& operator << (ostream& o, HetPair<T, U> h)
{
  o << "(" << h.getX() << ", " << h.getY() << ")";
  return o;
}

// Driver program to test as you go
int main() {
  // Milestone 1 testcode
  vector<int> intVec; // the standard version of templatized dynamic bag
  intVec.push_back(2); // push_back is analogous to insert
  intVec.push_back(4);
  intVec.push_back(4);
  intVec.push_back(-1);

  vector<Fraction> FVec;
  FVec.push_back(Fraction(3,11));
  FVec.push_back(Fraction(-1,2));
  FVec.push_back(Fraction(2,1));

  cout << intVec << endl;
  cout << FVec << endl;

  // Milestone 2 testcode
  HetPair<double, int> p(1.5, 4);
  cout << p << endl;
  HetPair<int, double> p1(1, 0.6);
  HetPair<int, double> p2(4, 0.8);
  HetPair<int, double> sum;
  sum = p1 + p2;
  cout << sum << endl;

  vector<HetPair<Fraction,double>> vH;
  int x, y;
  while(true)
  {
    cout << "enter numerator and denominator (0 denom to quit): " ;
    cin >> x >> y;
    if (y == 0) break;
    else 
    {
      Fraction f1(x, y);
      double d1 = (1.0*x) / y;
      HetPair<Fraction,double> h1(f1,d1);
      vH.push_back(h1);
    }
  }

  for (int i=0; i<vH.size(); i++)
  {
    cout << vH[i] << ", ";
  }
  cout << endl;
  return 0;
}
