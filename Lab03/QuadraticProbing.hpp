
template <typename T>
QuadraticProbing<T>::QuadraticProbing(int m, int k)//constructor
{
	m_m = m;
    m_k = k;
    numOfEle = 0;
    m_hashtable = new Bucket<T> [m_m];
}
template <typename T>
QuadraticProbing<T>::QuadraticProbing()//constructor
{
	m_m = 53;
    m_k = 10;
    numOfEle = 0;
    m_hashtable = new Bucket<T> [m_m];
}

template <typename T>
QuadraticProbing<T>::~QuadraticProbing()//distructor
{
    delete[] m_hashtable;//delete hash table
}

template <typename T>
bool QuadraticProbing<T>::Insert(T value)//insert value to hash table
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
bool QuadraticProbing<T>::Remove(T value)//delete value from hash table
{
    for(int i=0;i<=m_k-1;i++)
    {    
        int hx = (value % m_m + i*i) % m_m;
        if(m_hashtable[hx].AlwaysEmpty())
        {
            return false;
        }
        else if(m_hashtable[hx].getItem() == value)
        {
            numOfEle--;
            m_hashtable[hx].desetItem();
            return true;
        }
    }
    return false;
}

template <typename T>
void QuadraticProbing<T>::Print()// print all value in the hash table
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
int QuadraticProbing<T>::Hash(T value)//return the index for key value
{
    for(int i=0;i<=m_k-1;i++)
    {    
        int hx = (value % m_m + i*i) % m_m;
        if(m_hashtable[hx].isEmpty())
        {
            return hx;
        }
    }
    return -1;
}

template <typename T>
bool QuadraticProbing<T>::Find(T value)//return true if the key value is in the hashtable and false otherwise
{
    for(int i=0;i<=m_k-1;i++)
    {    
        int hx = (value % m_m + i*i) % m_m;
        if(m_hashtable[hx].AlwaysEmpty())
        {
            return false;
        }
        else if(m_hashtable[hx].getItem() == value)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
float QuadraticProbing<T>::loadFactor()
{
    //std::cout<<"Num of Ele: "<<numOfEle<<"/"<<m_m<<std::endl;
    return((float)numOfEle/m_m);
}




