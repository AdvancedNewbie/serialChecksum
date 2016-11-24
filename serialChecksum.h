#ifndef serialChecksum_h
#define serialChecksum_h

#include "Arduino.h"


class serialChecksum {
  
  private:
    String msg;
    int csum;
    int xor_sum();
    
  public:
    String inputString = "";
    int getCommaPosition();
    boolean isGood();
    int recv_checksum();
    String message();
    char charMessage();
    int checksum();
    
};


#endif
