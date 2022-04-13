#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace zich;

     Matrix::Matrix(vector<double>&data, int row, int col) {

         if(row < 1 || col < 1 )
         __throw_runtime_error(" invalid inputs - check again the rows and cols to be positive");

         if(data.size() != row*col){
            __throw_runtime_error(" invalid inputs ");
         }

        this->row = row;
        this->col = col;
        // should check if need to add (size_t) or its not necessary, same in the 4-loop 
        for(int i = 0; i< row*col; i++ ){
            this->matcal[i] = data[i];
        }
     }


    // double& Matrix::operator[] (const double& met){

    //     double* a = new double;

    //     return *a;
    // }

    Matrix Matrix::operator+(const Matrix& other){
         
         vector <double> temp= {};
         int i =0;
        //check if the rows and cols equals to the other matrix 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        while(i<matcal.size(){
            temp.push_back(this->matcal[i] + other.matcal[i]);
            i++;
        }
       
       
        return Matrix(temp, row, col); //maybe this->row,col 
    }

    Matrix& Matrix::operator+= (const Matrix& other){
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols"); }

    for (int i = 0; i < this->matcal.size(); i++)
    {
        this->matcal[i] += other.matcal[i];
        //matcal[i] += other.matcal[i];
    }  
        return *this;
    }
            
    Matrix Matrix::operator- (const Matrix& other){
        vector <double> temp= {};
        int i =0;
        //check if the rows and cols equals to the other matrix 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }

        while(i< matcal.size){
            temp.push_back(this->matcal[i] - other.matcal[i]); 
            i++;
        }
       

        return Matrix(temp, row, col); //maybe this->row,col 
    }

    Matrix& Matrix::operator-= (const Matrix& other){
        int i =0;
        //check if the rows and cols equals to the other matrix 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        
        while(i< matcal.size()){
            this->matcal[i] += other.matcal[i]; 
            i++;
        }
       
        return *this;  
    }

    Matrix Matrix::operator* (const double& scalar){

          vector <double> temp= {};
        int i =0;
        while( i< matcal.size()){
            temp.push_back(this->matcal[i] * scalar); 
            i++;
        }
       

        return Matrix(temp, row, col); //maybe this->row,col 
    }

    Matrix& Matrix::operator*= (const double& scalar){
        int i=0;
        while(i< matcal.size()){
            this->matcal[i]-=scalar; 
            i++;
        }

        return *this;
    }

    Matrix Matrix::operator* (const Matrix& other){
        //check if row of other matrix equal to col 
        if(this->col != other.row){
            __throw_invalid_argument("row isnt equal to the col to make the oparator works");
        }
        vector <double> v = {};

        double sum = 0;
        int check =0;
        double originMatcal, otherMatcal;
        for(int i=0; i<this->row; i++){
            for(int j=0; j<other.col; j++){
                while(check < this->col){
                    originMatcal = i *this->col +check;
                    otherMatcal = check *other.col + j;
                    sum = sum + this->matcal[originMatcal] * other.matcal[otherMatcal];
                    check++;
                }
                v.push_back(sum);
                sum = 0;
            }
        }
        this->matcal = v;
        this->col = other.col;

        return *this;
    }

    //    Matrix operator*(double num, const Matrix &mat) {
    //     vector<double> temp;
    //     for (int i = 0; i < mat.row * matcal.col; i++) //need to check mat.matcal.size()
    //     {
    //         temp.push_back(mat.matcal[i] * num);
    //     }
    //     return Matrix(temp, mat.row, mat.col);
    // }
        

    Matrix& Matrix::operator++ (){
        int i=0;
        while(i< matcal.size()){
            this->matcal[i]+= 1;
            i++;
        }
        return *this; 
    }

    Matrix& Matrix::operator++(int){
        //Can use the ++ operator for help
        Matrix v(this->matcal, this->row, this->col);
        ++(*this);
        return v;
        
    }

    Matrix& Matrix::operator--(){
        int i =0;
      while(i< matcal.size()){
            this->matcal[i]-= 1;
            i++;
        }
        return *this; 
    }

    Matrix& Matrix::operator--(int){

         Matrix v(this->matcal, this->row, this->col);
        //Can use the operator -- as helper 
        //++(*this);
        int i =0;
        while(i<matcal.size()){
            this-> matcal[i] -= 1 ;
            i++;
        }

        return v;
    
    }

    Matrix Matrix::operator- () const{
       vector<double> temp;
        int i = 0;
        while(i < row*col){
        temp.push_back(this->matcal[i] * (-1));
        i++ ;}
    return Matrix(temp, this->row, this->col);
    }

    bool Matrix::operator< (const Matrix& other)
    { 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        int sumOfOriginal, sumOfOther = 0;
        for(int i =0; i<this->matcal.size(); i++){
            sumOfOriginal = sumOfOriginal + this->matcal[i];
            sumOfOther+= other.matcal[i];
        }

        if(sumOfOriginal < sumOfOther)
            return true;

        return false;
    }
    bool Matrix::operator<= (const Matrix& other){
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        int sumOfOriginal, sumOfOther = 0;
        for(int i =0; i<this->matcal.size(); i++){
            sumOfOriginal = sumOfOriginal + this->matcal[i];
            sumOfOther+= other.matcal[i];
        }

        if(sumOfOriginal <= sumOfOther)
            return true;

        return false;
         }

    bool Matrix::operator> (const Matrix& other){ 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        int sumOfOriginal, sumOfOther = 0;
        for(int i =0; i<this->matcal.size(); i++){
            sumOfOriginal = sumOfOriginal + this->matcal[i];
            sumOfOther+= other.matcal[i];
        }

        if(sumOfOriginal > sumOfOther)
            return true;

        return false;
        }

    bool Matrix::operator>= (const Matrix& other){ 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        int sumOfOriginal, sumOfOther = 0;
        for(int i =0; i<this->matcal.size(); i++){
            sumOfOriginal = sumOfOriginal + this->matcal[i];
            sumOfOther+= other.matcal[i];
        }

        if(sumOfOriginal >= sumOfOther)
            return true;

        return false;  }
    
    bool Matrix::operator== (const Matrix& other){ 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
          for (int i = 0; i < this->matcal.size(); i++) {
        if (this->matcal[i] != other.matcal[i]){
            return false; } 
            }

        return true;}
    
    bool Matrix::operator!= (const Matrix& other){ 
        if(this->row != other.row || this->col !=other.col ){
            __throw_invalid_argument("invalid rows or cols");
        }
        if(*this == other)
                return false;
        return true;}

vector<string> Matrix::saperate(string input, char ch)
{
    vector<string> temp;
    for (size_t i = 0; i < input.size(); i++)   
    {
        string str;
        while (input[i] != ch && i < input.size())  
        {
            str += input[i++];                          
        }
        temp.push_back(str);                          
    return temp;
}


namespace zich{
       Matrix operator*(double num, const Matrix &mat)
    {
        vector<double> temp;
        for (size_t i = 0; i < mat.matcal.size(); i++)
        {
            temp.push_back(mat.matcal[i] * num);
        }
        return Matrix(temp, mat.row, mat.col);
    }

    ostream& operator<< (ostream& out, const Matrix& mat){ 
          string str;
          int endOfTheRoad = 0;
        for (int i = 0; i < mat.row; i++)
        {
            out << "[";
            for (int j = 0; j < mat.col; j++)
            {
                out << mat.matcal[i * mat.col + j];
                endOfTheRoad = (j + 1) %mat.col; /
                if (endOfTheRoad != 0) { out << " "; }
            }
            if (i + 1 != mat.row){ out << "]\n"; }
            else{out<< "]";}
        }
        return (out << str);
    }

/*
need to fix that 

*/


   istream &operator>>(istream &input, const Matrix &mat){

        return input;
   }

};
