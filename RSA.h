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
        //переводит BigInteger в string
        friend QString BigIntegerToStr(BigInteger number);
	BigInteger operator=(const BigInteger&);
        //переводит string в BigInteger
        BigInteger(std::string &x);

        int toInt();
        //делаем перегрузку оператора << для вывода BigInteger
        friend ostream& operator<<(ostream&, const BigInteger&);
        //логические операторы
	friend bool operator==(const BigInteger&, const BigInteger&);
	friend bool operator!=(const BigInteger&, const BigInteger&);
	friend bool operator>(const BigInteger&, const BigInteger&);
	friend bool operator<(const BigInteger&, const BigInteger&);
        //математические операторы
	friend BigInteger operator+(const BigInteger&, const BigInteger&);
	friend BigInteger operator-(const BigInteger&, const BigInteger&);
	friend BigInteger operator*(const BigInteger&, const BigInteger&);
	friend BigInteger operator/(const BigInteger&, const BigInteger&);
	friend BigInteger operator%(const BigInteger&, const BigInteger&);
         //(a*b) % mod умножение по модулю
        friend BigInteger modul_mult(BigInteger&, BigInteger&, BigInteger&);
        //(a^b) % mod возведение в степень по модулю
        friend BigInteger fast_power(BigInteger&, BigInteger&, BigInteger&);
protected:


	bool Sign;
};

const BigInteger zero(0);
const BigInteger one(1);
const BigInteger two(2);
const int LENGTH(8);
const int PROBABILITY(5); // вероятность

class RSA
{
public:
	RSA();
	~RSA();
        //шифрование (e и n берутся из программы)
	void encryption(BigInteger&, BigInteger&);
        //шифрование (e и n вводятся пользователем в соотвествующие окна)
        void encryption(BigInteger &, BigInteger &,BigInteger & exp,BigInteger & mod);
        //расшифровка
	void decryption(BigInteger&, BigInteger&);
        //публичный ключ
	void publish_keys(BigInteger&, BigInteger&);
private:
        //алгоритм Евклида
	BigInteger euclid(const BigInteger&, const BigInteger&);
        //генерирует случайные (любые) числа
	void Randomiser(BigInteger &, int);
        //генерирует случайное число меньшее сгенерированных случайно ранее(для теста Рабина-Миллера)
	void RangeRandomiser(BigInteger &, const BigInteger &);
        //тест Рабина-Миллера
	bool IsPrime(BigInteger &);
        //генерирует случайные числа нужной длинны, потом проверяет, является ли число простым
	void PrimeGenerator(BigInteger &);
	BigInteger e; // Открытая экспонента
	BigInteger d; // Секртеная экспонента
	BigInteger n; // p*q, где p и q простые числа (BigInteger)


};

