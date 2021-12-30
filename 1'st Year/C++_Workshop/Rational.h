#pragma once
class Rational
{
public:
	Rational(int myMone, int myMechane); // c-tor
	Rational(const Rational& num) :numerator(num.getNumerator()), denominator(num.getDenominator()) {}// copy c-tor
	~Rational(){} //dstor
	Rational operator + (const Rational& rhs) const; // + plus two Rational num
	Rational operator - (const Rational& rhs) const; // - minus two Rational num
	Rational operator + (const int& rhs) const; // + plus rational with int
	Rational operator * (const Rational& rhs) const; // * multiplay two Rational num
	Rational operator / (const Rational& rhs) const; //  / devert two Rational num
	Rational& operator++ (); //++ add one before
	Rational operator++ (int); // ++ add one after 
	Rational& operator-- (); //-- minus one before
	Rational operator-- (int); // -- minus one after
	bool operator== (const Rational& rhs) const; // == equal
	bool operator!= (const Rational& rhs) const; // != not equal
	bool operator>= (const Rational& rhs) const; // >= bigger or equal
	bool operator> (const Rational& rhs) const; // > bigger
	bool operator<= (const Rational& rhs) const; // smaller ot equal
	bool operator< (const Rational& rhs) const; // smaller

	void setDenominator(int myMone) { numerator = myMone; }
	void setNumerator(int myMechane) { denominator = myMechane; }
	int getDenominator()const { return denominator; }
	int getNumerator() const { return numerator; }
	void print();
	//bool equal(Rational num);
	Rational reduction(Rational num);
	
private:
	int numerator;
	int denominator;
};