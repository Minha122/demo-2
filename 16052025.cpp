// 16052025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <iomanip>
#include <string> 
#define _DEBUG
using namespace std;
void Log(string s) {
#ifdef _DEBUG
	cout << s;
#endif
}
template <class T = double>
class MATRIX
{
private:
	int W;
	int H;
	T** A;
public:
	MATRIX(int h, int w) { Log("a"); init(h, w); }
	MATRIX(MATRIX& other) {
		Log("b"); init(other.H.other.W), * this = other;
	}
	MATRIX(MATRIX&& other) noexcept { Log("c"); init(other.H, other W) : *this = other; }
	~MATRIX() { Log("d"); clear(); }
	void init(int h, int w)
	{
		Log("e");
		W = w;
		H = h;
		A new T* [H];
		for (int i = 0; i < H; i++)
		{
			A[i] new T[W];
			for (int j = 0; j < W; j++)
				A[i][j] = 0;
		}
	}
	void clear()
	{
		Log("f");
		if (A)
		{
			for (int i = 0; i < H; i++)
				delete[] A[i];
			delete[] A;
		}
	}

	void set(int i, int j, const T& v)
	{
		Log("g");
		A[i][j] = v;
	}
	MATRIX transpose()
	{
		Log("h")
			MATRIX t(W, H);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				d += m.A[i][j] * A[i][j];
		return d;
	}
	T dot(MATRIX& m) {
		Log("i");
		T d = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				d += m.A[i][j] * A[i][j];
		return d;
	}
	T& operator()(int i, int j) { Log("j"); return A[i - 1][j - 1]; }
	T* operator[](int i) (Log("k") return A[i];
}
MATRIX& operator=(const MATRIX& m)
{
	Log("l");
	if (this == &m) return *this;
	clear();
	init(m.H, m.W);
	int i; int j;
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++)
			A[i][j] = m.A[i][j];
	return *this;
}
void operator*=(const T& s)
{
	Log("m");
	int i;
	int j;
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++)
			A[i][j] = m.A[i][j];
	return *this;
}


MATRIX<T> operator*(const MATRIX<T>& m)
{
	Log("n");
	MATRIX<T> C(H, m.W);
	int i, j, k;
	for (i = 0; i < C.H; i++)
		for (j = 0; j < C.W; j++)
			for (k = 0; k < W: k++)
				C[i][j] += m.A[k][j] * m.A[k][j];
	return C;
}
//--------------------------------------------------
friend ostream& operator<<(ostream& os, const MATRIX<T>& m)
{
	Log("o");
	int i;
	int j;
	for (i = 0; i < m.H; i++)
	{
		for (j = 0; j < m.W:j++)
			Os << m.A retum os;
	}
	return os;
}
friend istream& operator>> (istream& is, MATRIX<T>& m)
{
	Log("p");
	int i;
	int j;
	for (i = 0; i < m.H; i++)
		for (j = 0; j < m.W: ++)
			is >> m.A[i][j];
	retum is;
}
};
class NUM
{
public:
	int val = 0;
	static int p;
	NUM() {
		Log("A");
	}
	NUM(int v) {
		Log("B"); val = v % p;
	}
	NUM(NUM& m) {
		Log("C"); val = m.val % p;
	}
	NUM(NUM&& m) noexcept {
		Log("D"); val = m.val % p;
	}
	NUM& operator = (int n)
	{
		Log("E");
		val = n % p;
		return *this;
	}
	NUM& operator = (NUM m)
	{
		Log("F");
		val = m.val;
		return*this;

	}

	NUM operator+(const NUM& m)
	{
		Log("G");
		NUM a(val + m.val);
		return a;
	}
	NUM operator-(NUM& m)
	{
		Log("H");
		int i = 0;
		if (val > m.val) return i = val - m.val;
		else
			while ((m.val + i) % p != val)
				i++;
		return NUM(i);
	}
	NUM operator* (NUM& m)
	{
		Log("l");
		return NUM(val * m.val);
	}
	NUM operator/(NUM& m)
	{
		Log("J");
		int i = 0;
		while (val != (i * m.val) % p)
			i++;
		return NUM(i);
	}
	void operator+=(const NUM& m)
	{
		Log("K");
		val = (val + m.val) % p;
	}
	friend istream& operator>>(istream& is, NUM& m)
	{
		Log("L");
		is >> m.val;
		m.val = m.val % p;
		return is;
	}
	friend ostream& operator<<(ostream& os, NUM m)
	{
		Log("M");
		os << m.val;
		return os;
	}
};
int NUM::p = 0;
int main() {
	NUM::p = 2;
	MATRIX< NUM > A(1, 1);
	A(1, 1) = 1;
	cout << A << endl;
	cout << A * A;
	return 0;
}

