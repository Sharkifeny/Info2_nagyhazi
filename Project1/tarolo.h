#pragma once
#include <iostream>

/// Template Tároló létrehozása dinamikus adattárolásra
/// Használati feltétel: a típusnak létezzen default konstruktora, másoló konstruktora, operator=-je
template <class T>
class Tarolo
{
    unsigned db;
    T* pData;

public:
    
    /// Üres tároló inicializálása
    Tarolo()
    {
        db = 0;
        pData = nullptr;
    }
    

    ///Sor végére teszi a kapott adatot
    void pushData(const T& p)
    {

        T* seged = new T[db + 1];
        
        for (int i = 0; i < db; i++)
            seged[i] = pData[i];
        
        seged[db] = p;

        delete[]pData;
        pData = seged;
        db++;
    }

    /// Kapott indexû elemet töröl
    void deleteData(unsigned index)
    {
        if (index >= db)
            throw std::out_of_range("Tul indexeles"); //Hibakezelés
        T* seged = new T[db - 1];
        int i = 0;
        int j = 0;
        //Új tömb létrehozása, a törölni kívánt elem nélkül
        for (i = 0, j = 0; i < db; i++)
        {
            if (i != index)
            {
                seged[j] = pData[i];
                j++;
            }

        }
        
        delete[] pData;
        pData = seged;
        db--;
    }


    /// Visszaadja az indexedik elemet
    T& operator[](unsigned index) const
    {
        if (index < db)
        {
            return pData[index];
        }
        throw std::out_of_range("Ilyen indexu elem nem letezik.");
    }

   
  
    unsigned size() const
    {
        return db;
    }

   
    bool ures() const
    {
        if (db == 0)
            return true;
        return false;
    }


   ~Tarolo()
   {
        delete[] pData;
   }

};

