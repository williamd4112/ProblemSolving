/* Sparse Matrix, implemented by array */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include "polynomial.h"

using namespace std;

typedef struct MatrixTerm{
    int row, col, val;
    
    MatrixTerm operator +(MatrixTerm& m){
        return MatrixTerm{row, col, val + m.val};
    }
    
    MatrixTerm operator -(MatrixTerm& m){
        return MatrixTerm{row, col, val - m.val};
    }
    
    MatrixTerm operator*(MatrixTerm& m){
        return MatrixTerm{row, col, val * m.val};
    }
    
    friend MatrixTerm operator +(const MatrixTerm& a, const MatrixTerm& b){
        return MatrixTerm{b.row, b.col, a.val + b.val};
    }
    
    friend MatrixTerm operator -(const MatrixTerm& a, const MatrixTerm& b){
        return MatrixTerm{b.row, b.col, a.val - b.val};
    }
    
    friend MatrixTerm operator *(const MatrixTerm& a, const MatrixTerm& b){
        return MatrixTerm{b.row, b.col, a.val * b.val};
    }
    
    bool operator ==(MatrixTerm& m){
        return row == m.row && col == m.col; 
    }
    
    bool operator < (MatrixTerm& m){
        if(row == m.row)
            return (col > m.col);
        else
            return (row > m.row);
    }
}MatrixTerm;


typedef struct Matrix{
    int cRows, cCols, cTerms;
    MatrixTerm *mArray, *begin, *end;
    
    Matrix(int cRows, int cCols, int cTerms){
        this->cRows = cRows;
        this->cCols = cCols;
        this->cTerms = cTerms;
        this->mArray = new MatrixTerm[cTerms];
        this->begin = this->end = this->mArray;
    }
    
    void addTerm(int row, int col, int val){
        *end++ = MatrixTerm{row, col, val};
    }
    
    Matrix operator +(Matrix& b){
        Matrix m(cRows, cCols, cTerms + b.cTerms);
        m.end = polynomial_addition(m.begin, begin, end, b.begin, b.end, plus<MatrixTerm>(), MatrixTerm{0, 0, 0});
        m.cTerms = m.end - m.begin;
        return m;
    }
    
    Matrix operator -(Matrix& b){
        Matrix m(cRows, cCols, cTerms + b.cTerms);
        m.end = polynomial_addition(m.begin, begin, end, b.begin, b.end, minus<MatrixTerm>(), MatrixTerm{0, 0, 0});
        m.cTerms = m.end - m.begin;
        return m;
    }
    
    Matrix operator *(Matrix& b){
        Matrix a = *this;
        Matrix mulm(a.cRows, b.cCols, a.cRows * b.cCols);
        Matrix bt = b.transpose();
        int rowSize_a[a.cRows], rowStart_a[a.cRows];
        int rowSize_b[bt.cRows], rowStart_b[bt.cRows];
        
        fill(rowSize_a, rowSize_a + a.cRows, 0);
        fill(rowStart_a, rowStart_a + a.cRows, 0);
        
        fill(rowSize_b, rowSize_b + b.cRows, 0);
        fill(rowStart_b, rowStart_b + b.cRows, 0);
        
        for(MatrixTerm *it = a.begin; it != a.end; it++)
            rowSize_a[it->row]++;
            
        for(MatrixTerm *it = bt.begin; it != bt.end; it++){
            rowSize_b[it->row]++;
        }
        
        for(int i = 1; i < a.cRows; i++)
            rowStart_a[i] = rowStart_a[i - 1] + rowSize_a[i - 1];
            
        for(int i = 1; i < b.cRows; i++)
            rowStart_b[i] = rowStart_b[i - 1] + rowSize_b[i - 1];
        
        for(int ra = 0; ra < a.cRows; ra++){
            MatrixTerm *row_start_a = a.begin + rowStart_a[ra];
            MatrixTerm *row_end_a = row_start_a + rowSize_a[ra];

            for(int rb = 0; rb < bt.cRows; rb++){
                row_start_a = a.begin + rowStart_a[ra];
                MatrixTerm rowProduct[a.cCols];
                MatrixTerm *dest = rowProduct;
                MatrixTerm *row_start_b = bt.begin + rowStart_b[rb];
                MatrixTerm *row_end_b = row_start_b + rowSize_b[rb];
                
                for(; row_start_a != row_end_a && row_start_b != row_end_b;){
                    if((*row_start_a).col == (*row_start_b).col){
                        *dest++ = MatrixTerm{(*row_start_a).row, (*row_start_b).row, (*row_start_b).val * (*row_start_a).val};
                        row_start_a++; row_start_b++;
                        
                    } else if((*row_start_a).col > (*row_start_b).col)
                        row_start_b++;
                    else
                        row_start_a++;
                    
                }
                
                int val = 0;
                for(MatrixTerm *it = rowProduct; it != dest; it++)
                    val += it->val;
                if(val != 0)
                    mulm.addTerm(ra, rb, val);
            }
            
        }
        mulm.cTerms = mulm.end - mulm.begin;
        return mulm;
    }
    
    Matrix transpose(){
        Matrix mt(cCols, cRows, cTerms);
        int rowSize[cCols];
        int rowStart[cCols];
        fill(rowSize, rowSize + cCols, 0);
        fill(rowStart, rowStart + cCols, 0);
        
        for(MatrixTerm *it = begin; it != end; it++)
            rowSize[it->col]++;
        for(int i = 1; i < cCols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1]; 
            
        for(MatrixTerm *it = begin; it != end; it++)
            if(rowSize[it->col] > 0)
                mt.mArray[rowStart[it->col]++] = MatrixTerm{it->col, it->row, it->val};
        mt.end = mt.begin + mt.cTerms;
        return mt;
    }
    
    void print(){
        printf("%d %d %d\n",cRows, cCols, cTerms);
        for(MatrixTerm *it = begin; it != begin + cTerms; it++){
            printf("%d %d %d\n",it->row, it->col, it->val);
        }
    }
    
}Matrix;

int main(){
    freopen("in.txt","r",stdin);
    
    int cRows, cCols, cTerms;
    int row, col, val;
    
    scanf("%d%d%d",&cRows, &cCols, &cTerms);
    Matrix ma(cRows, cCols, cTerms);
    for(int i = 0; i < cTerms; i++){
        scanf("%d%d%d",&row, &col, &val);
        ma.addTerm(row, col, val);
    }
    
    scanf("%d%d%d",&cRows, &cCols, &cTerms);
    Matrix mb(cRows, cCols, cTerms);
    for(int i = 0; i < cTerms; i++){
        scanf("%d%d%d",&row, &col, &val);
        mb.addTerm(row, col, val);
    }
    
    Matrix pc = ma + mb;
    Matrix mc = ma - mb;
    Matrix mulm = ma * mb;
    mulm.print();
    
    //Matrix mt = ma.transpose();
    //mc.print();
    //pc.print();
    //mc.print();
    return 0;
}