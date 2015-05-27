#pragma once
#include<vector>
#include<iostream>
#include <QString>

using namespace std;

typedef vector<unsigned char>  data_type;

class BigInteger
{
public:
        data_type Value;
	BigInteger();
	~BigInteger();
	BigInteger(const BigInteger&);
	BigInteger(int);
        //��������� BigInteger � string
        friend QString BigIntegerToStr(BigInteger number);
	BigInteger operator=(const BigInteger&);
        //��������� string � BigInteger
        BigInteger(std::string &x);

        int toInt();
        //������ ���������� ��������� << ��� ������ BigInteger
        friend ostream& operator<<(ostream&, const BigInteger&);
        //���������� ���������
	friend bool operator==(const BigInteger&, const BigInteger&);
	friend bool operator!=(const BigInteger&, const BigInteger&);
	friend bool operator>(const BigInteger&, const BigInteger&);
	friend bool operator<(const BigInteger&, const BigInteger&);
        //�������������� ���������
	friend BigInteger operator+(const BigInteger&, const BigInteger&);
	friend BigInteger operator-(const BigInteger&, const BigInteger&);
	friend BigInteger operator*(const BigInteger&, const BigInteger&);
	friend BigInteger operator/(const BigInteger&, const BigInteger&);
	friend BigInteger operator%(const BigInteger&, const BigInteger&);
         //(a*b) % mod ��������� �� ������
        friend BigInteger modul_mult(BigInteger&, BigInteger&, BigInteger&);
        //(a^b) % mod ���������� � ������� �� ������
        friend BigInteger fast_power(BigInteger&, BigInteger&, BigInteger&);
protected:


	bool Sign;
};

const BigInteger zero(0);
const BigInteger one(1);
const BigInteger two(2);
const int LENGTH(8);
const int PROBABILITY(5); // �����������

class RSA
{
public:
	RSA();
	~RSA();
        //���������� (e � n ������� �� ���������)
	void encryption(BigInteger&, BigInteger&);
        //���������� (e � n �������� ������������� � �������������� ����)
        void encryption(BigInteger &, BigInteger &,BigInteger & exp,BigInteger & mod);
        //�����������
	void decryption(BigInteger&, BigInteger&);
        //��������� ����
	void publish_keys(BigInteger&, BigInteger&);
private:
        //�������� �������
	BigInteger euclid(const BigInteger&, const BigInteger&);
        //���������� ��������� (�����) �����
	void Randomiser(BigInteger &, int);
        //���������� ��������� ����� ������� ��������������� �������� �����(��� ����� ������-�������)
	void RangeRandomiser(BigInteger &, const BigInteger &);
        //���� ������-�������
	bool IsPrime(BigInteger &);
        //���������� ��������� ����� ������ ������, ����� ���������, �������� �� ����� �������
	void PrimeGenerator(BigInteger &);
	BigInteger e; // �������� ����������
	BigInteger d; // ��������� ����������
	BigInteger n; // p*q, ��� p � q ������� ����� (BigInteger)


};

