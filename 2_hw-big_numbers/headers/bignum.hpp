// Class for holding big numbers

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

namespace jinx
{

/*
Для этого класса нужно определить методы:

- конструктор перемещения;
- перемещающий оператор присваивания;
- оператор сложения двух больших чисел;
- оператор умножения на число.
*/

	class bignum final
	{
	public:
		// PUBLIC AREA

		// public methods

		void print()
		{
			std::vector<int>::reverse_iterator it = _num.rbegin();
			while (it != _num.rend())
			{
				std::cout << *it;
				it++;
			}

		} // END OF print()

		void raw_print()
		{
			for (const auto& it : _num)
			{
				std::cout << it;
			}

		} // END OF print()

		bool is_null()
		{
			if (this->_num.size() == 0)
				return true;
			return false;
		} // END of is_null()

		int length()
		{
			return this->_num.size();
		} // END of length()

		// overloads

		bignum & operator+(const bignum & other)
		{

			int _reserve = 0;
			std::vector<int> tmp;
			int _dec = 0;

			if (this->length() < other._num.size())
			{
				// this < other
				_reserve = other._num.size() + 2;
			}
			else
			{	
				// this >= other
				_reserve = this->length() + 2;
			}
				
			tmp.reserve(_reserve);
				
			for (int i = 0; i < tmp.capacity(); ++i)				
			{
				int _tempNum = 0 + _dec;

				if (i < _num.size())
				{
					_tempNum += _num[i];
				}

				if (i < other._num.size())
				{
					_tempNum += other._num[i];
				}

				if (_tempNum / 10 != 0)
				{
					_dec = 1;
					_tempNum %= 10;
				}
				else
				{
					_dec = 0;
				}

				if (_tempNum != 0)
				{
					tmp.push_back(_tempNum);
				}
				else if (_tempNum == 0 && i < _reserve - 2)
				{
					tmp.push_back(_tempNum);
				}
			}

			_num.clear();
			_num.reserve(_reserve);
			_num = std::move(tmp);

			std::reverse(_num.begin(), _num.end());			
			
			return *this;
		}

		bignum & operator*(const bignum & other)
		{
			int _reserve = 0;

			_reserve = this->length() + other._num.size() + 5;

			auto _pArr = std::make_unique<int[]>(_reserve);

			for (int i = 0; i < _reserve; ++i)
			{
				_pArr[i] = 0;
			}	 

			for (int i = 0; i < _num.size(); ++i)
			{
				for (int j = 0; j < other._num.size(); ++j)
				{					
					_pArr[i + j] = _num[i] * other._num[j];
				}
			}

			for (int i = 0; i < _reserve - 1; ++i)
			{
				_pArr[i + 1] += _pArr[i] / 10;
				_pArr[i] %= 10;
			}

			while (_pArr[_reserve - 1] == 0)
			{
				_reserve--;
			}

			_num.clear();
			_num.reserve(_reserve);

			for (int i = 0; i < _reserve; ++i)
			{
				_num.push_back(_pArr[i]);
			}

			std::reverse(_num.begin(), _num.end());	

			return *this;
		}

		bignum & operator=(const bignum & other) // оператор копирующего присваивания
		{
			return * this = bignum(other);
		}

		bignum & operator=(bignum && other) noexcept // оператор перемещающего присваивания
		{
			std::swap(_num, other._num);
			return *this;
		}

		// OVERLOAD STEAM << OUTPUT
		friend std::ostream& operator<<(std::ostream& stream, bignum& number);

		// constructors

		bignum() = delete;

		bignum(const std::string & line)
		{
			for (int i = 0; line[i] != '\0'; ++i)
			{
				_num.push_back(static_cast<int>(line[i]));
			}

			std::reverse(_num.begin(), _num.end());
		}

		bignum(const char * line)
		{
			for (int i = 0; *(line + i) != '\0'; ++i)
			{
				_num.push_back(*(line + i) - 48);
			}

			std::reverse(_num.begin(), _num.end());
		}

		bignum(const std::vector<int> & numlist)
		{
			_num = numlist;

			std::reverse(_num.begin(), _num.end());
		}

		bignum(const bignum & other) : bignum(other._num) 
		{
		} // copy

		bignum(bignum && other) noexcept // move
		{
			_num = std::move(other._num);
		}
		
		// destructor

		~bignum() 
		{
		}

	protected:
		// PROTECTED AREA

		// -- 

	private:
		// PRIVATE AREA

		std::vector<int> _num;

	}; // END of class

	std::ostream& operator<<(std::ostream& stream, bignum& number)
	{
		std::vector<int>::reverse_iterator it = number._num.rbegin();
		while (it != number._num.rend())
		{
			stream << *it;
			it++;
		}
		return stream;
	}

} // END OF namespace