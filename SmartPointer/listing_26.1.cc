template<typename T>
class smart_pointer{

    private:
        T* m_pRawPointer;
    public:
        smart_pointer(T* pData) : m_pRawPointer(pData){} // c'tor
//        ~smart_pointer(){}
        ~smart_pointer() {delete m_pRawPointer;}

        //copy ctor
        smart_pointer(const smart_pointer& anotherSP);
        // copy assignment operator
        smart_pointer& operator= (const smart_pointer& anotherSP);

        T& operator* () const{
            return *(m_pRawPointer);
        }

        T* operator-> () const{
            return m_pRawPointer;
        }
        
};
