#include "/include/defs.h"

/********* 
**********/

int main(string str) {
  object brooch;
  brooch = present("brooch", TP);

  if(!str) {
  TP->guild_line();
  return 1;
}

//  if(brooch){
//  CD->do_chat(9,"[>>>"+CAP(TP->RNAME)+"<<<] "+(str)+"\n");
//  return 1;
//}
  write("You need a brooch to communicate with.\n");
  return 1; 
}
