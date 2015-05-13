template <typename T>
class deepcopy_smart_pointer{

    private:
        T* m_pObject;
    public:
        // copy ctor
        deepcopy_smart_pointer(const deepcopy_smart_pointer& source){
            // ensure deep copy of derived class object (Clone() is virtual)
            m_pObject = source->Clone();
        }

        deepcopy_smart_pointer& operator= (const deepcopy_smart_pointer& source){
            if(m_pObject) delete m_pObject;
            m_pObject = source->Clone();
        }
};
