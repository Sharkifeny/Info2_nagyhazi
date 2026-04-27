#include <iostream>
#include "Zene.h"
#include "tarolo.h"
#include "Musorlista.h"

int main()
{
    try {
        //A mûsorlista létrehozása
        Musorlista musorlista;

        bool aktiv = true;
        while (aktiv)
        { 
            std::string szam;
            int i = 0;
            while (true)
            {
            std::cout << std::endl << "----------------------------------------------------" << std::endl;
            std::cout << "Mit szeretnel csinalni?" << std::endl;
            std::cout << "0. Kilepek" << std::endl;
            std::cout << "1. Zenet veszek fel a lejatszasi listara" << std::endl;
            std::cout << "2. Zenet torlok a lejatszasi listarol" << std::endl;
            std::cout << "3. Megszeretnem nezni a lejatszasi listat" << std::endl;
            std::cout << "4. Eloadora keresek" << std::endl;
            std::cout << "5. Zenere keresek cim szerint" << std::endl;
            std::cout << "6. Zenere keresek mufaj szerint" << std::endl;
            std::cout << "----------------------------------------------------" << std::endl << std::endl;

                try {
                    std::getline(std::cin, szam);
                        i = std::stoi(szam); //exceptiont dob, ha nem számot kapott
                        if (i < 0 || i>7)
                            throw std::invalid_argument("");
                        break;
                       
                }
                catch (std::invalid_argument&) { std::cerr << "0 es 6 kozotti szamot adjon meg!"; }
            }

            switch (i)
            {
            case 0:
                aktiv = 0;
                break;

            case 1:
            {
                Zene felvesz;
                std::cin >> felvesz;
                try {
                    musorlista.addMusic(felvesz);
                }
                catch (std::out_of_range& e) { std::cerr << e.what() << std::endl; };
            }
            break;

            case 2:
            {
                try {
                    musorlista.deleteMusic();
                }
                catch (std::out_of_range& e) { std::cerr << e.what() << std::endl; }
            }
            break;

            case 3:
            {
          
                try {
                    std::cout << musorlista;
                }
                catch (std::runtime_error& e) { std::cerr << e.what() << std::endl; }
                
            }
            break;
            case 4:
            {
                try {
                    musorlista.eloadoKeres();
                }
                catch (std::runtime_error& e) { std::cerr << e.what() << std::endl; }
            }
            break;
            case 5:
            {
                try {
                    musorlista.cimKeres();
                }
                catch (std::runtime_error& e) { std::cerr << e.what() << std::endl; }
            }
            break;
            case 6:
            {
                try {
                    musorlista.mufajKeres();
                }
                catch (std::runtime_error& e) { std::cerr << e.what() << std::endl;}
                
                 
            }
            break;
            }

        }
    }
    catch (std::bad_alloc&) { std::cerr << "memoriafutasi hiba" << std::endl; }

    std::cout << "__________________________________" << std::endl;
    std::cout << "Viszont latasra" << std::endl;

    return 0;
}