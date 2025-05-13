#include "/include/defs.h"

int main(string arg) {

  int spz, power, diff, broochpower, maxbp;
  object br;

  br = present("guildbrooch", TP);
  broochpower =(br->query_bp());
  maxbp=(br->query_max_bp());
  spz=(TP->SP-1);

  if(!br){
    notify_fail("You need a brooch to store power in.\n");
    return 0;
  }
 
  diff = maxbp - broochpower;

  if(diff == 0) {
    notify_fail("Your brooch is already full.\n");
    return 0;
  }

  if(arg == "max") {
    if(diff < spz) {
      br->add_bp(diff);
      TP->ADDSP(-diff);
      write("You store " + diff + " spell points in your Brooch.\n");
    }
    else {
      TP->ADDSP(-spz);
      br->add_bp(spz);
      write("You store " + spz + " spell points in your Brooch.\n");
    }
    return 1;
  }

  if(arg && sscanf(arg, "%d", power)) {
    if(power <= 0) {
      notify_fail("You may only store a positive amount in your Brooch.\n");
      return 0;    
    }
  }
  else {
    notify_fail("Syntax: storesp <number>\n");
    return 0;
  }
 
  if(power != -1) {
    if(power > spz) {
      write("You do not have that many spell points.\n");
      return 1;
    }
  
    if(power > diff) {
      write("You can only store " + diff + " spell points.\n");
      power = diff;
    }

    TP->ADDHP(-power);
    br->add_bp(power);
    write("You store " + power + " spell point in your Brooch.\n");
    say(TP->SNAME + " stores power in " + TP->POS + " Brooch.\n");
    return 1;
  }
  
  notify_fail("Syntax: storesp <number>\n");
  return 0;
}
