//#include "tarolo.h"
//
//template <class T>
//Tarolo<T>::Tarolo()
//{
//    db = 0;
//    pData = nullptr;
//}
//template <class T>
//Tarolo<T>::Tarolo(const Tarolo<T>& p)
//{
//    if (db != 0)
//    {
//        db = p.db;
//        T* seged = new T[db];
//        
//        for (int i = 0; i < db; i++)
//            seged.pData[i] = p.pData[i];
//
//        delete[]pData;
//        pData = seged.pData;
//    }
//}
//
//template <class T>
////Sor végére teszi az adatot
//void Tarolo<T>::pushData(const T& p)
//{
//
//    T* seged = new T[db+1];
//    int i = 0;
//    for (i=0; i < db; i++)
//        seged[i] = pData[i];
//    seged[i] = p;
//    
//    db++;
//
//    delete[]pData;
//    pData = seged;
//}
//
//template <class T>
////adott indexû elemet töröl
//void Tarolo<T>::deleteData(unsigned index)
//{
//    if (index >= db)
//        std::cout << "Ilyen inddexû elem nem  létezik." << std::endl;
//    T* seged = new T[db - 1];
//    int i = 0; 
//    int j = 0;
//    for (i = 0, j = 0; i < db; i++)
//    {
//        if (i != index)
//        {
//            seged[j] = pData[i];
//                j++;
//        }
//            
//    }
//    delete[] pData;
//    pData = seged;
//}
//
//template <class T>
////az indexelés mûködéséhez
//T& Tarolo<T>::operator[](unsigned index)
//{
//    if(index<db)
//    return pData[index];
//    std::cout << "Ilyen idnexû elem nem létezik." << std::endl;
//}
//
//template <class T>
//unsigned Tarolo<T>::size() const
//{
//    return db;
//}
//
//template< class T>
//
//bool Tarolo<T>::ures() const
//{
//    if (db == 0)
//        return true;
//    return false;
//}

