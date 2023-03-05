#ifndef Matrix3
#define Matrix3

#include <string>

class Matrix33
{
public:

    // Static Class-Functions
    static Matrix33 zeros();
    static Matrix33 ones();

    // Construction
    Matrix33( double m11, double ml2, double m13, 
              double m21, double m22, double m23, 
              double m31, double m32, double m33 );
    
    double& get(int row, int col);

    std::string toString() const;

    Matrix33 operator+(const Matrix33 &m2) const;
    Matrix33 operator*(const Matrix33 &m2);
    Matrix33 operator*(int s);
    Matrix33 operator+=(Matrix33 m2);
    operator double();


private:
    double m_matrix[3][3];
    friend Matrix33 operator*(int scalar, const Matrix33 &mat);
};

class Matrix33WrongIndicesError {
public:
    std::string what() const{
        return "Wrong Indices";
    }
};



#endif