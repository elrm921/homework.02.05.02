#include <iostream>

struct Row {

};

template<typename T>
class table {
    int m_i;
    int m_j;
    T** m_array;
public:
    table(int i, int j) : m_i(i), m_j(j) {
        m_array = new T*[m_i];
        for (int k = 0; k < m_i; ++k) {
            m_array[k] = new T[j];
        }
    }
    ~table() {
        for (int k = 0; k < m_i; ++k) {
            delete[] m_array[k];
        }
        delete[] m_array;
    }
    int Size() const {
        return m_i * m_j;
    }
    T* &operator [](int i) const {
        return m_array[i];
    }
    T* &operator [](int i) {
        return m_array[i];
    }
};

int main() {
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    return 0;
}