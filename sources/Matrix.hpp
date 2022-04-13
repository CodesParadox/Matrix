#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace zich{


    class Matrix{

        private:
        int col, row;   //sizes
        vector<double> matcal; // The matrix calculator

        public:

            Matrix(vector<double> &data, int row, int col);
            //Matrix();
            //double& operator[] (const double&);

            Matrix operator+ (const Matrix&);
            Matrix& operator+= (const Matrix&);
            
            Matrix operator- (const Matrix&);
            Matrix& operator-= (const Matrix&);

            Matrix operator*(const double&);
            Matrix& operator*=(const double&);
            Matrix operator*(const Matrix&);
            

            Matrix& operator++ ();
            Matrix& operator++ (int);
            Matrix& operator-- ();
            Matrix& operator-- (int);

            Matrix operator- () const;

            bool operator< (const Matrix&);
            bool operator<= (const Matrix&);
            bool operator> (const Matrix&);
            bool operator>= (const Matrix&);
            bool operator== (const Matrix&);
            bool operator!= (const Matrix&);

            friend ostream& operator<< (ostream&out, const Matrix&mat);  //2 String
            friend istream &operator>>(istream&inp, const Matrix &mat);
            friend Matrix operator*(double scalar, const Matrix &mat);
            static vector<string> saperate(string input, char ch);
    };

}
