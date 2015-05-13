#include <sstream>
#include <iostream>
#include <string>

int main(){

    for(int ipt=0; ipt<1; ++ipt){
        for(int ieta=0; ieta<1; ++ieta){
            for(int icent=0; icent<3; ++icent){

                std::stringstream hname;
                hname << "hPosGen" << "_pt" << ipt <<
                    "_eta" << ieta <<
                    "_cent" << icent;
                    std::cout << hname.str().c_str() << std::endl;
                    hname.str(std::string());
                hname << "hNegGen" << "_pt" << ipt <<
                    "_eta" << ieta <<
                    "_cent" << icent;
                    std::cout << hname.str().c_str() << std::endl;
            }
         }
      }
}
