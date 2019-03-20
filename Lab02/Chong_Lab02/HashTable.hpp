
template <typename T>
HashTable<T>::HashTable(int size)//constructor
{
	m_size = size;
    m_hashtable = new LinkedList<T> [size];
}
// template <typename T>
// HashTable<T>::HashTable()//constructor
// {
// 	m_size = 0;
//     m_hashtable = new LinkedList<T> [0];
// }

template <typename T>
HashTable<T>::~HashTable()//distructor
{
    for(int i=0;i<m_size;i++)
    {
        m_hashtable[i].RemoveAll();//remove all nodes from the list
    }
    delete[] m_hashtable;//delete hash table
}

template <typename T>
bool HashTable<T>::Insert(T value)//insert value to hash table
{
    return (m_hashtable[Hash(value)].addFront(value));
}

template <typename T>
bool HashTable<T>::Delete(T value)//delete value from hash table
{
    return (m_hashtable[Hash(value)].remove(value));
}

template <typename T>
void HashTable<T>::Print()// print all value in the hash table
{
    for(int i=0;i<m_size;i++)
    {
        std::cout<<i<<": ";
        m_hashtable[i].print();
    }
}

template <typename T>
int HashTable<T>::Hash(T value)//return the index for key value
{
    return(value % m_size);
}

template <typename T>
bool HashTable<T>::Find(T value)//return true if the key value is in the hashtable and false otherwise
{
    return (m_hashtable[Hash(value)].isExist(value));
}

// template <typename T>
// void HashTable<T>::setSize(int size)
// {
//     m_size = size;
// }




