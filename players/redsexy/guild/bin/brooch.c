#include "/include/defs.h"

/********* 
**********/

int main(string str) {
  object brooch;
  brooch = present("brooch", TP);
  if(brooch)  CD->do_chat(9,"[>>>"+CAP(TP->RNAME)+"<<<] "+(str)+"\n");
  else write("You need a brooch to communicate with.\n");
  return 1; 
}
