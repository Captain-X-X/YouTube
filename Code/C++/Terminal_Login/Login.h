#include "includeHeader.h"
//
namespace Lin{
    // Start
    namespace Var{
        // CHAR
        char UserName[300];
        char Password[300];
        // STD::STRING
        std::string UN = "CaptainXX";
        std::string PW = "ZeroDay";
        std::string Answer;
        // INT
        int StatCode;
    }
    namespace Deets{
        // File Used To Save UserInfo AKA Username N Password
        std::fstream UFile("UserName.bin",std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        std::fstream PFile("Password.bin",std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        // Load INFO
        void load(){
            // Get Account Info
            UFile.read(Var::UserName, sizeof(Var::UserName));
            PFile.read(Var::Password, sizeof(Var::Password));
            PFile, UFile.close();
            // File(s) Loaded
            std::cout << "File's Loaded!" << std::endl;
        }
        // Save INFO
        void save(){
            UFile.write((char *)Var::UserName, sizeof(Var::UserName));
            PFile.write((char *)Var::Password, sizeof(Var::Password));
            PFile, UFile.close();
            // File(s) Saved!
            std::cout << "File Made" << std::endl;
            // When Saved
            std::cout << "Account Made! : )" << std::endl;
        }
    }
    // Main Login
    void Login(){
        // Clear Screen!
        system("clear");
        // Login Header
        std::cout << "\n" << "- - - - - Account Loggin - - - - -" << std::endl;
        // Start Login
        std::cout << "User Name:";
        std::cin >> Var::UserName;
        // Get Password
        std::cout << "Password:";
        std::cin >> Var::Password;
        // Just Some LOGIC : )
        if (Var::UserName == Var::UN){
            if (Var::Password == Var::PW){
                // Do Something
                std::cout << "Logged in!" << std::endl;
                Array::MakeArray();
                // return;
            }
            else{
                // Wrong PASSWORD
                std::cout << "Wrong Password!" << std::endl;
                return;
            }
        }
        else{
            // Wrong USERNAME
            std::cout << "Wrong UserName!" << std::endl;
            return;
        }

    }
}