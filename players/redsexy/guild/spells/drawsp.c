drawsp(arg) {
  int power, diff;
  diff = TP->MAXSP - TP->SP;
  if(diff == 0) {
    write("You are already at full spell points.\n");
    return 1;
  }
  if(arg == "max") {
    if(diff <= broochpower) command("drawsp " + diff, TP);
    else command("drawsp " + broochpower, TP);
    return 1;
  }
  if(arg && sscanf(arg, "%d", power)) {
    if(power <= 0) {
      write("You may only draw a positive amount from your Brooch.\n");
      return 1;
    }
    if(power > broochpower) {
      write("Your Brooch does not have that much power stored.\n");
      return 1;
    }
    if(power > diff) power = diff;
    CHECK_GHOST();
    TP->ADDSP(power);
    broochpower -= power;
    write("You draw " + power + " spell points from your Brooch.\n");
    say(TP->SNAME + " draws power from " + TP->POS + " Brooch.\n");
    return 1;
  }
  write("Syntax: drawsp <number>\n");
  return 1;
}
