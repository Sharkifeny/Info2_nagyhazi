#include "Musorlista.h"



Musorlista::Musorlista() : playList() {

    
    //fájl megnyitása
    std::ifstream load("musorlista.txt");
    if (!load.is_open())
    {
        std::cerr << "hiba a fajl megnyitasakor" << std::endl;
        return;
    }
    //A fájl ürességének vizsgálata
    load.seekg(0, load.end); //A fájl végére megy
    if (static_cast<int>(load.tellg())== 0) //Ha a fájl üres, tehát 0 byte
        return;                             //akkor visszatér, nincs aktuális mûsorlista
    load.seekg(0, load.beg);                //egyébként visszamegy a fájl elejére, és kezdõdhet a beolvasás
    
    
    unsigned size;
    load >> size; //a fájl elsõ sorában a mûsorlista zenéinek száma szerepel
    Zene buffer;
    char ch;
    load.get(ch); //a size után marad egy új sor karakter
    for (int i = 0; i < size; i++)
    {
        //zene beolvasása a fájlból
        buffer.beolvas(load);
        try {
            addMusic(buffer); //hozzáadása a mûsorlistához
        }
        catch (std::out_of_range) { std::cerr << "a musorlista betoltese soran volt azonos cimu zene, a duplikacio miatt az egyiket toroltuk"; }
    }
    load.close();
    
    
    


};


bool Musorlista::empty() const {
    return playList.ures();
}

std::ostream& operator<<(std::ostream& os, Musorlista& m) 
{
    if (m.empty())
        throw std::runtime_error("a musorlista ures");
    else
    {
        std::cout << "Eloado|Nyelv|Cim|Mufaj|Megjelenes eve|Hossz (perc:mp)|Kedvenc" << std::endl << std::endl;
        for (unsigned i = 0; i < m.getSize(); i++)
        {
            //zene kiírása
            m[i].kiIr(os);
        }
    }
    return os;
}


std::istream& operator>>(std::istream& is, Zene& z)
{
    std::string writerName;
    std::string writerNationality;
    std::string name;
    unsigned recorded = 0;
    std::string genre;
    bool liked = false;
    unsigned idoSecond = 0;
    unsigned idoMinute = 0;
    std::string buffer;
    char c;
    bool rossz = true;
    bool rossz1 = true;

    std::cout << "A zene cime: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "A zene mufaja: " << std::endl;
    std::getline(std::cin, genre);

    std::cout << "Szereted ezt a zenet (igen/nem): " << std::endl;
    //ciklus a hibakezeléshez
    while (rossz)
    {
        try {
            std::getline(std::cin, buffer);
            if (buffer == "nem" || buffer == "Nem")
            {
                liked = false;
                rossz = false;
            }
            else
                if (buffer == "igen" || buffer == "Igen")
                {
                    liked = true;
                    rossz = false;
                }
                else throw std::invalid_argument("probald ujra"); //ha helytelen bemenet érkezett, akkor hibád dob, és újra kell próbálni
        }
        catch (std::invalid_argument& e) { std::cout << e.what() << std::endl; }
    }

    std::cout << "Kiadas eve: " << std::endl;
    // ciklus a helyesség ellenõrzéséhez
    while (true) {
        try {
            std::getline(std::cin, buffer);
            //2024-nél nagyobb számokat ne adjunk meg
            recorded = std::stoi(buffer); //stoi: invalid_argument exceptiont dob, ha nem számot kap
            if (recorded < 0 || recorded>2024)
                throw std::invalid_argument("");
            break; // kilép a ciklusból, ha jó adat érkezett
        }
        catch (std::invalid_argument&) { std::cout << "probald ujra" << std::endl; }

    }

    std::cout << "Az eloado neve: " << std::endl;
    std::getline(std::cin, writerName);

    std::cout << "Nemzetisege: " << std::endl;
    std::getline(std::cin, writerNationality);
    
    std::cout << "A zene hossza:  " << std::endl;
    //ciklus a hibakezeléséhez ellõszõr a perchez, aztán a másodperchez
    while (rossz1) {
        try {
            std::cout << "perc: ";
            std::getline(std::cin, buffer);
            //A stoi is invalidot dob, ha nem szám jön
            idoMinute = std::stoi(buffer);
            
            //59-nél nagyobb számokat ne adjunk meg
            if (idoMinute<60 && idoMinute>=0)
            {
                rossz1=false;
            }
            else throw std::invalid_argument("");
        }
        catch (std::invalid_argument&) { std::cout << "probald ujra" << std::endl; }

    }

    rossz1 = true;
    while (rossz1) {
        try {
            std::cout << "masodperc: ";

            std::getline(std::cin, buffer);
            //A stoi is invalidot dob, ha nem szém jön
            idoSecond = std::stoi(buffer);
           
            //59-nél nagyobb számokat ne adjunk meg
            if (idoSecond<60 && idoSecond>=0)
                rossz1 = false;
            else throw std::invalid_argument("");
        }
        catch (std::invalid_argument&) { std::cout << "probald ujra" << std::endl; }

    }

    //Zene példányosítása az adatokkal
    Zene m(name, genre, idoMinute, idoSecond, liked, writerName, writerNationality, recorded);
    
    // A kapott zenébe átmásoljuk a létrehozott zenét
    z=m;
   
    return is;
}

Zene& Musorlista::operator[](unsigned index) const
{
    return playList[index];
}


unsigned Musorlista::getSize() const
{
    return playList.size();
}



void Musorlista::addMusic(const Zene& param)
{
    //Ha a mûsorlistán van már ugyan olyan címû zene, akkor hibát dob
    for (unsigned i = 0; i < playList.size(); i++) {
        if (playList[i].getName() == param.getName())
        {
            throw std::out_of_range("mar van ilyen cimu zene");
        }
    }
    //ha nincs egyezés, akkor hozzáadja a mûsorlistához
    playList.pushData(param);
}


void Musorlista::deleteMusic()
{
    std::string zeneCim;
    std::cout << "Irja le a torolni kivant zene cimet: " << std::endl;
    std::getline(std::cin, zeneCim);

    for (unsigned i = 0; i < playList.size(); i++) {
        if (playList[i].getName() == zeneCim) //ha megtalálta a zenét
        {
            playList.deleteData(i); //akkor törli
            std::cout << "sikerult torolni" << std::endl;
            return;
        }
    }
    throw std::out_of_range("nem sikerult torolni");
}

void Musorlista::mufajKeres() const
{

    std::cout << std::endl << "Irja le annak a zenenek a mufajat, amelyre kivancsi: " << std::endl;
    std::string mufaj;
    std::getline(std::cin, mufaj);

    bool talalt = false;
    for (unsigned i = 0; i < playList.size(); i++) {
        if (playList[i].getGenre() == mufaj) //ha a mûfaj egyezik
        {
            talalt = true;
            std::cout << playList[i]; //akkor azt a zenét kiírja
        }
    }
    if (!talalt)
        throw std::runtime_error("nem talalhato ilyen mufaju zene");
}

//hasonló elven mûködik, mint a mufajKeres()
void Musorlista::cimKeres() const
{
    std::cout << std::endl << "Irja le annak a zenenek a cimet, amelyre kivancsi: " << std::endl;
    std::string cim;
    std::getline(std::cin, cim);

    bool talalt = false;
    for (unsigned i = 0; i < playList.size(); i++) {
        if (playList[i].getName() == cim)
        {
            talalt = true;
            std::cout << playList[i];
        }
    }
    if (!talalt)
        throw std::runtime_error("nem talalhato ilyen cimu zene");
}

//Hasonló elv, mint a mûfajKeres()
void Musorlista::eloadoKeres() const
{
    std::cout << std::endl << "Irja le az eloado nevet, akire kivancsi: " << std::endl;
    std::string eloadoNev;
    std::getline(std::cin, eloadoNev);

    bool talalt = false;
    for (unsigned i = 0; i < playList.size(); i++) {
        if (playList[i] == eloadoNev) //használjuk a zene operator== túlterhelést
        {
            talalt = true;
            std::cout << playList[i];
        }
    }
    if (!talalt)
        throw std::runtime_error("nem talalhato ilyen nevu eloado");
}




//itt a destruktorban menti az adatokat
Musorlista::~Musorlista()
{
    std::ofstream save("musorlista.txt");
    
    if (!save.is_open())
    {
        std::cerr << "a mentes sikertelen volt" << std::endl;
        return;
    }

    

    save << playList.size() << std::endl; //A fájl elejére írja a mûsorlista hosszát
    for (unsigned i = 0; i < playList.size(); i++)
        playList[i].kiIr(save); //kimenti a fájlba
        
    
}