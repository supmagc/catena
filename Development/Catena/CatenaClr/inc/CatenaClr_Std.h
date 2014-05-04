#ifndef _H_CATENACLR_STD
#define _H_CATENACLR_STD

#include "Rock.h"
#include "Diamond.h"
#include "Chalk.h"
#include "Chalk_D3d9.h"

/*
template<typename T>
ref struct NativeValuePtr {
    NativeValuePtr() : m_ptr(0) {
    }

    NativeValuePtr(T* ptr) : m_ptr(ptr)  {
    }

    NativeValuePtr(NativeValuePtr<T>% right) : m_ptr(right.Release()) {
    }

    ~NativeValuePtr() {
        if (0 != m_ptr) {
            delete m_ptr;
            m_ptr = 0;
        }
    }

    T& operator*()  {
        return *m_ptr;
    }

    T* operator->()  {
        return m_ptr;
    }

    T* Get() {
        return m_ptr;
    }

    T* Release() {
        T* released = m_ptr;
        m_ptr = 0;
        return released;
    }

    void Reset() {
        Reset(0);
    }

    void Reset(T* ptr) {
        if (0 != m_ptr) {
            delete m_ptr;
        }
        m_ptr = ptr;
    }
private:
    T* m_ptr;
};
*/

#endif // _H_CATENACLR_STD