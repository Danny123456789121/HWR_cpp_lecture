#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "Matrix.h"


// ----------------------------------------------------------------------------

Matrix33 Matrix33::zeros()
{
    return Matrix33(0,0,0  ,0,0,0  ,0,0,0);
}


// ----------------------------------------------------------------------------

Matrix33 Matrix33::ones()
{
    return Matrix33(1,1,1  ,1,1,1  ,1,1,1);
}


// ----------------------------------------------------------------------------

Matrix33::Matrix33( double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33 )
{
    m_matrix[0][0] = m11; m_matrix[0][1] = m12; m_matrix[0][2] = m13;
    m_matrix[1][0] = m21; m_matrix[1][1] = m22; m_matrix[1][2] = m23;
    m_matrix[2][0] = m31; m_matrix[2][1] = m32; m_matrix[2][2] = m33;
}


// ----------------------------------------------------------------------------

std::string Matrix33::toString() const
{
    std::stringstream s;
    s << "----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[0][0];
    s << " | " <<std::setw(6) << m_matrix[0][1];
    s << " | " <<std::setw(6) << m_matrix[0][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[1][0];
    s << " | " <<std::setw(6) << m_matrix[1][1];
    s << " | " <<std::setw(6) << m_matrix[1][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[2][0];
    s << " | " <<std::setw(6) << m_matrix[2][1];
    s << " | " <<std::setw(6) << m_matrix[2][2] << " |";
    s << "\n----------------------------\n";

    return s.str();
}


// ----------------------------------------------------------------------------

Matrix33 Matrix33::operator+(const Matrix33 &m2) const{
    Matrix33 res = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++){
            res.m_matrix[i][j] = this->m_matrix[i][j] + m2.m_matrix[i][j];
        }
    }
    return res;
}

Matrix33 Matrix33::operator*( const Matrix33 &m2) {
    Matrix33 res = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                res.m_matrix[i][j] =+ this->m_matrix[k][j] * m2.m_matrix[k][j];
        }
    }
    return res;
}

Matrix33 Matrix33::operator*(int s) {
    Matrix33 res = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++){
            res.get(i,j) = this->get(i, j) * s;
        }
    }
    return res;
}

Matrix33 Matrix33::operator+=(Matrix33 m2) {
    for (int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++){
            this->get(i, j) += m2.get(i, j);
        }
    }
    return *this;
}

Matrix33 operator*(int scalar, const Matrix33 &mat) {
    {
        Matrix33 res = Matrix33::zeros();
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                res.m_matrix[i][j] = scalar * mat.m_matrix[i][j];
            }
        }
        return res;
    }
}

Matrix33::operator double() {
    return m_matrix[0][0] * (m_matrix[1][1] * m_matrix[2][2] - m_matrix[1][2] * m_matrix[2][1])
           - m_matrix[0][1] * (m_matrix[1][0] * m_matrix[2][2] - m_matrix[1][2] * m_matrix[2][0])
           + m_matrix[0][2] * (m_matrix[1][0] * m_matrix[2][1] - m_matrix[1][1] * m_matrix[2][0]);
}

double &Matrix33::get(int row, int col) {
    {
        if(row < 0 || row > 2 || col < 0 || col > 2)
            throw Matrix33WrongIndicesError();
        return m_matrix[row][col];
    }
}
