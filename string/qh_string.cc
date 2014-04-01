#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO ��������дʵ�ִ���

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        if(s)
        {
            len_=strlen(s)+1;
            data_=new char[len_];
            strcpy(data_,s);
        }
        else
        {
            data_=NULL;
            len_=0;
        }
    }

    string::string( const char* s, size_t len )
    {
        len_=len+1;
        data_=new char[len_];
        strcpy(data_,s);
    }

    string::string( const string& rhs )
    {
        len_=rhs.len_;
        data_=new char[len_];
        strcpy(data_,rhs.data_);
    }

    string& string::operator=( const string& rhs )
    {
        if(this!=&rhs)
        {
            delete[] data_;
            if(!rhs.data_)
                data_=NULL;
            else
            {
                data_=new char[strlen(rhs.data_)+1];
                strcpy(data_,rhs.data_);
            }
        }
        return *this;
    }

    string::~string()
    {
       delete[] data_;
       len_=0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char* string::operator[]( size_t index )
    {   
        assert(index<len_);
        return data_+index;
    }
}
