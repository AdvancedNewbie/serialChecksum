#include "Arduino.h"
#include "serialChecksum.h"

boolean serialChecksum::isGood(){
  if(xor_sum() == recv_checksum()){
    return true;
  } else {
    return false;
  }
}
int serialChecksum::recv_checksum(){
  String recv_checkSum = inputString.substring(getCommaPosition()+1,inputString.length());
  return recv_checkSum.toInt();
  
}

int serialChecksum::checksum(){
  return xor_sum();  
}

String serialChecksum::message(){
  return inputString.substring(0,getCommaPosition());
}

char serialChecksum::charMessage(){
  char buf[getCommaPosition()];
  inputString.toCharArray(buf, getCommaPosition());
  return buf;
}

int serialChecksum::getCommaPosition(){
  char buf[inputString.length()];
  inputString.toCharArray(buf, inputString.length());

  int i = inputString.length();

  while(i > 0){
    if (buf[i] == ',') {
      break;
    }
    i--;
  }

  return i--;
}

int serialChecksum::xor_sum(){
  int csum = 0;
  char buf[inputString.length()];
  inputString.toCharArray(buf, inputString.length());
  
  for(int i=0; i < getCommaPosition(); i++){
    csum ^= buf[i];
  }
  return csum;
}
