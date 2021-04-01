#include "Matrix.h"
#include <iomanip>

std::ostream &operator<<(std::ostream &stream, const Matrix &v1)
{
    for(size_t i=0; i<v1.R; i++)
    {
        stream<<"| ";
        for(size_t k=0; k<v1.C; k++)
        {
            stream<<std::setw(5)<<v1.tab[i][k]<<" ";
            if(k==v1.C-1)                              
                stream<<" |";
        }
        stream<<std::endl;
    }

return stream;
}

std::istream &operator>>(std::istream &stream, Matrix &v1)
{
    for(size_t i=0; i<v1.R; i++)
    {
        for(size_t k=0; k<v1.C; k++)
        {
            stream>>v1.tab[i][k];
        }
    }
    return stream;
}


