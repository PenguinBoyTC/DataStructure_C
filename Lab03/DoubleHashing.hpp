
template <typename T>
DoubleHashing<T>::DoubleHashing(int m, int k, int p)//constructor
{
	m_m = m;
    m_k = k;
    m_p = p;
    numOfEle = 0;
    m_hashtable = new Bucket<T> [m_m];
}
template <typename T>
DoubleHashing<T>::DoubleHashing()//constructor
{
	m_m = 53;
    m_k = 10;
    m_p = 13;
    numOfEle = 0;
    m_hashtable = new Bucket<T> [m_m];
}

template <typename T>
DoubleHashing<T>::~DoubleHashing()//distructor
{
    delete[] m_hashtable;//delete hash table
}

template <typename T>
bool DoubleHashing<T>::Insert(T value)//insert value to hash table
{
    if(Hash(value)!=-1)
    {
        m_hashtable[Hash(value)].setItem(value);
        numOfEle++;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool DoubleHashing<T>::Remove(T value)//delete value from hash table
{
    int hx = value % m_m;
    int hxx = m_p - (value % m_p);
    for(int i=0;i<=m_k-1;i++)
    {    
        int hn = (hx + i * hxx) % m_m;
        if(m_hashtable[hn].AlwaysEmpty())
        {
            return false;
        }
        else if(m_hashtable[hn].getItem() == value)
        {
            m_hashtable[hn].desetItem();
            numOfEle--;
            return true;
        }
    }
    return false;
}

template <typename T>
void DoubleHashing<T>::Print()// print all value in the hash table
{
    for(int i=0; i<m_m; i++)
    {
        if(!m_hashtable[i].isEmpty())
        {
            std::cout<<i<<": "<<m_hashtable[i].getItem()<<std::endl;
        }
    }    
}

template <typename T>
int DoubleHashing<T>::Hash(T value)//return the index for key value
{
    int hx = value % m_m;
    int hxx = m_p - (value % m_p);
    for(int i=0;i<=m_k-1;i++)
    {    
        int hn = (hx + i * hxx) % m_m;
        if(m_hashtable[hn].isEmpty())
        {
            return hn;
        }
    }
    return -1;
}

template <typename T>
bool DoubleHashing<T>::Find(T value)//return true if the key value is in the hashtable and false otherwise
{
    int hx = value % m_m;
    int hxx = m_p - (value % m_p);
    for(int i=0;i<=m_k-1;i++)
    {    
        int hn = (hx + i * hxx) % m_m;
        if(m_hashtable[hn].AlwaysEmpty())
        {
            return false;
        }
        else if(m_hashtable[hn].getItem() == value)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
float DoubleHashing<T>::loadFactor()
{
    //std::cout<<"Num of Ele: "<<numOfEle<<"/"<<m_m<<std::endl;
    return((float)numOfEle/m_m);
}




