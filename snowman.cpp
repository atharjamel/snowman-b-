#include <stdexcept>
#include"snowman.hpp"
#include<array>
#include <string>
#include<stddef.h>
using namespace std;


namespace ariel { 
const int hat=0;
const int nose=1;  
const int lefe_eye=2;  
const int right_eye=3; 
const int left_arm =4; 
const int right_arm=5; 
const int torso=6;
const int base=7;

const int min_number=1;
const int max_number=4; 
const int length =8,ten=10;

string hat_func(int num){
        if (num==1){
          return "_===_";
    }
    if (num==2){
       return " ___\n .....";
    }
    if (num==3){
        return "  _\n  /_\\";
    }
    return " ___\n (_*_)";
    
}
   
string nose_func(int num){
   if (num==1){
       return ",";
   }
   if (num==2){
       return ".";
   }
   if (num==3){
       return "_";
   }
   
       return " ";
}
string eye_func (int num){
if (num==1){
    return ".";
}
if (num==2){
    return "o";
}
if (num==3){
    return "O";
}
     return "-";
}

string torso_func(int num){
    if (num==1){
        return " : ";
    }
    if (num==2){
      return "] [";
    }
    if (num==3){
        return "> <" ;
    }
        return "   ";
}

string base_func(int num){
    if (num==1){
        return " : ";
    }
     if (num==2){
         return "\" \""; 
     }
     if (num==3){
         return "___";
     }
         return "   "; 
       
}
// part of X(LNR)Y
    string makerightarm(int x){
         string s ;
        if ( x==1){
            s=s+">";
        }
        if (x==2){
            s=s+"/";
        }
        if (x==3){
            s=s+"\\";
        }
        if (x==4){
            s=s+" ";
        }
        return s;
    }

    string makeleftarm(int x){
         string s ;
        if ( x==1){
            s=s+"<";
        }
        if (x==2){
            s=s+"\\";
        }
        if (x==3){
            s=s+"/";
        }
        if (x==4){
            s=s+" ";
        }
        return s;
    }
    // part of X(TTT)Y

     string snowman (int num){
         array<int,length>arr={};
          int count=0,digit=0;
          int c_of_number=0;
         string snowman;
        
         for (count=length-1;num>0&& count>0;count--){
             digit=num%ten;
             if (digit<min_number || digit>max_number){
                 throw out_of_range{"wrong number!!"};
             }
             arr.at(count)=digit;  
             num =num / ten;
             c_of_number++;   
         }
         if (c_of_number!=base){   
              throw out_of_range{" number is not 8 digits!!"};
         }
            
         snowman=hat_func(arr.at(hat))+'\n';
         if(arr.at(left_arm)==2&&arr.at(right_arm)!=2){
             snowman+=makeleftarm(arr.at(left_arm))+"("+eye_func(arr.at(lefe_eye))+nose_func(arr.at(nose))+eye_func(arr.at(right_eye))+")"+'\n';
             snowman+="("+torso_func(arr.at(torso))+")"+makerightarm(arr.at(right_arm))+'\n';
         }
         else if(arr.at(left_arm)!=2&&arr.at(right_arm)==2){
             snowman+="("+eye_func(arr.at(lefe_eye))+nose_func(arr.at(nose))+eye_func(arr.at(right_eye))+")"+makerightarm(arr.at(right_arm))+'\n';
             snowman+=makeleftarm(arr.at(left_arm))+"("+torso_func(arr.at(torso))+")"+'\n';
         }
         else if(arr.at(left_arm)==2&&arr.at(right_arm)==2){
             snowman+=makeleftarm(arr.at(left_arm))+"("+eye_func(arr.at(lefe_eye))+nose_func(arr.at(nose))+eye_func(arr.at(right_eye))+")"+makerightarm(arr.at(right_arm))+'\n';
             snowman+="("+torso_func(arr.at(torso))+")"+'\n';
         }
         else {
             snowman+="("+eye_func(arr.at(lefe_eye))+nose_func(arr.at(nose))+eye_func(arr.at(right_eye))+")"+'\n';
             snowman+=makeleftarm(arr.at(left_arm))+"("+torso_func(arr.at(torso))+")"+makerightarm(arr.at(right_arm))+'\n';
         }
         snowman+="("+base_func(arr.at(base))+")";
         return snowman;
    }                                                   
 }            