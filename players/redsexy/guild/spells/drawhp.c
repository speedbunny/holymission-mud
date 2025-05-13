drawhp(arg) {
  int power, diff;
  diff = TP->MAXHP - TP->HP;
  if(diff == 0) {
    write("You are already at full hit points.\n");
    return 1;
  }
  if(arg == "max") {
    if(diff <= broochpower) command("drawhp " + diff, TP);
    else command("drawhp " + broochpower, TP);
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
    TP->ADDHP(power);
    broochpower -= power;
    write("You draw " + power + " hit points from your Brooch.\n");
    say(TP->SNAME + " draws power from " + TP->POS + " Brooch.\n");
    return 1;
  }
  write("Syntax: drawhp <number>\n");
  return 1;
}
