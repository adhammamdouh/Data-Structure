	#pragma once
	#include <iostream>

	template<typename T>

	class Matrix
	{
	private:
		T ** Mate;
		int ROW;
		int COL;
		void BuildMatrix();
	public:
		Matrix();
		Matrix(int ROW , int COL);
		Matrix(const Matrix<T>& Obj);
		Matrix Transpose();
		Matrix operator +(Matrix Other);
		Matrix operator -(Matrix Other);
		Matrix operator *(Matrix Other);
		Matrix& operator =(const Matrix &Other);
		template<typename U>
		friend std::istream& operator >>(std::istream& in, Matrix<U>& Obj);
		template<typename U>
		friend std::ostream& operator << (std::ostream& Out ,const Matrix<U>& Obj);
	

		~Matrix();
	};

	template<typename T>
	Matrix<T>::Matrix()
	{
		ROW = 0;
		COL = 0;
	}

	template<typename T>
	Matrix<T>::Matrix(int ROW, int COL) {
		this->ROW = ROW;
		this->COL = COL;
		this->BuildMatrix();
	}

	template<typename T>
	inline Matrix<T>::Matrix(const Matrix<T>& Obj)
	{
		this->COL = Obj.COL;
		this->ROW = Obj.ROW;
		this->BuildMatrix();
		for (int i = 0; i < Obj.ROW; ++i)
			for (int j = 0; j < Obj.COL; ++j)
				this->Mate[i][j] = Obj.Mate[i][j];
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::Transpose()
	{
		Matrix<double>tmp(this->COL, this->ROW);
		for (int i = 0; i < this->ROW; ++i) {
			for (int j = 0; j < this->COL; ++j) {
				tmp.Mate[j][i] = this->Mate[i][j];
			}
		}
		return tmp;
	}

	

	template<typename T>
	void Matrix<T>::BuildMatrix() {

		Mate = new T*[this->ROW];
		for (int i = 0; i < ROW; ++i) {
			Mate[i] = new T[this->COL];
		}
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator+(Matrix<T> Other){
		Matrix tmp;
		if (this->ROW != Other.ROW || this->COL != Other.COL) return tmp;
	
		tmp.ROW = Other.ROW;
		tmp.COL = Other.COL;
		tmp.BuildMatrix();

		for (int i = 0; i < tmp.ROW; ++i)
			for (int j = 0; j < tmp.COL; ++j)
				tmp.Mate[i][j] = this->Mate[i][j] + Other.Mate[i][j];

		return tmp;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator =(const Matrix<T>& Other) {
		this->ROW = Other.ROW;
		this->COL = Other.COL;
		this->BuildMatrix();
	
		for (int i = 0; i < Other.ROW; ++i)
			for (int j = 0; j < Other.COL; ++j)
				this->Mate[i][j] = Other.Mate[i][j];

		return *this;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator-(Matrix<T> Other){
		Matrix tmp;
		if (this->ROW != Other.ROW || this->COL != Other.COL) return tmp;
	
		tmp.ROW = Other.ROW;
		tmp.COL = Other.COL;
		tmp.BuildMatrix();

		for (int i = 0; i < tmp.ROW; ++i)
			for (int j = 0; j < tmp.COL; ++j)
				tmp.Mate[i][j] = this->Mate[i][j] - Other.Mate[i][j];

		return tmp;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator*(Matrix<T> Other){
		Matrix tmp;
		if (this->COL != Other.ROW) return tmp;
	
		tmp.ROW = this->ROW;
		tmp.COL = Other.COL;
		tmp.BuildMatrix();

		for (int i = 0; i < this->ROW; ++i)
			for (int j = 0; j < Other.COL; ++j)
				for (int k = 0; k < this->COL; ++k)
					tmp.Mate[i][j] = this->Mate[i][k] * Other.Mate[k][j];

		return tmp;
	}

	template<typename T>
	std::istream & operator>>(std::istream& in, Matrix<T>& Obj)
	{
		std::cout << "Enter the dimensions" << std::endl;
		std::cin >> Obj.ROW >> Obj.COL;
		Obj.BuildMatrix();
		std::cout << "Enter the Matrix" << std::endl;
		for (int i = 0; i < Obj.ROW; ++i)
			for (int j = 0; j < Obj.COL; ++j)
				in >> Obj.Mate[i][j];
		return in;
	}

	template<typename T>
	std::ostream & operator<<(std::ostream& Out, const Matrix<T>& Obj)
	{
		for (int i = 0; i < Obj.ROW; ++i) {
			for (int j = 0; j < Obj.COL; ++j) {
				Out << Obj.Mate[i][j] << ' ';
			}
			Out << '\n';
		}
		return Out;
	}

	template<typename T>
	Matrix<T>::~Matrix()
	{
		for (int i = 0; i < this->ROW; ++i) {
			delete Mate[i];
		}
		delete[]Mate;
	}

	
