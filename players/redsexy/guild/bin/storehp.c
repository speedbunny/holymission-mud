#include "/include/defs.h"

int main(string arg) {

  int hpz, power, diff, broochpower, maxbp;
  object br;

  br = present("guildbrooch", TP);
  broochpower =(br->query_bp());
  maxbp=(br->query_max_bp());
  hpz=(TP->HP-1);

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
    if(diff < hpz) {
      br->add_bp(diff);
      TP->ADDHP(-diff);
      write("You store " + diff + " hit points in your Brooch.\n");
    }
    else {
      TP->ADDHP(-hpz);
      br->add_bp(hpz);
      write("You store " + hpz + " hit points in your Brooch.\n");
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
    notify_fail("Syntax: storehp <number>\n");
    return 0;
  }
 
  if(power != -1) {
    if(power > hpz) {
      write("You do not have that many hit points.\n");
      return 1;
    }
  
    if(power > diff) {
      write("You can only store " + diff + " hit points.\n");
      power = diff;
    }

    TP->ADDHP(-power);
    br->add_bp(power);
    write("You store " + power + " hit point in your Brooch.\n");
    say(TP->SNAME + " stores power in " + TP->POS + " Brooch.\n");
    return 1;
  }
  
  notify_fail("Syntax: storehp <number>\n");
  return 0;
}
