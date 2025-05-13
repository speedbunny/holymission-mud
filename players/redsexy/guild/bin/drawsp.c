#include "/include/defs.h"

int main(string arg) {

  int power, diff, broochpower;
  object br;

  br = present("guildbrooch", TP);
  broochpower =(br->query_bp());

  if(!br){
    notify_fail("You need a brooch to draw power from.\n");
    return 0;
  }

  diff = TP->MAXSP - TP->SP;

  if(diff == 0) {
    notify_fail("You are already at full spell points.\n");
    return 0;
  }


  if(arg == "max") {
   if (broochpower == 0) {
      notify_fail("Your brooch is out of power.\n");
      return 0;
    }
    if(diff <= broochpower) {
      TP->ADDSP(diff);
      br->add_bp(-diff);
      write("You draw " + diff + " spell points from your Brooch.\n");
    }
    else {
      TP->ADDSP(broochpower);
      br->add_bp(-broochpower);
      write("You draw " + broochpower + " spell points from your Brooch.\n");
    }
    return 1;
  }

  if(arg && sscanf(arg, "%d", power)) {
    if(power <= 0) {
      notify_fail("You may only draw a positive amount from your Brooch.\n");
      return 0;    
    }
  }
  else {
    notify_fail("Syntax: drawsp <number>\n");
    return 0;
  }

  if(power != -1) {
    if(power > broochpower) {
      write("Your Brooch does not have that much power stored.\n");
      return 1;
    }
  
    if(power > diff) {
      write("You can only hold " + diff + " more spell points.\n");
      power = diff;
    }

    TP->ADDSP(power);
    br->add_bp(-power);
    write("You draw " + power + " spell points from your Brooch.\n");
    say(TP->SNAME + " draws power from " + TP->POS + " Brooch.\n");
    return 1;
  }
  
  notify_fail("Syntax: drawsp <number>\n");
  return 0;
}
