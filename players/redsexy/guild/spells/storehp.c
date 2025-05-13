storehp(arg) {
  int power, diff, hp;
  diff = MAXBP - broochpower;
  hp = (TP->HP - 1);
  if(diff == 0) {
    write("Your Brooch is already full.\n");
    return 1;
  }
  if(arg == "max") {
    if(diff < hp) command("storehp " + diff, TP);
    else command("storehp " + hp, TP);
    return 1;
  }
  if(arg && sscanf(arg, "%d", power)) {
    if(power <= 0) {
      write("You may only store a positive amount in your Brooch.\n");
      return 1;
    }
    if(power > hp) {
      write("You do not have that many hit points.\n");
      return 1;
    }
    if(power > diff) power = diff;
    CHECK_ATTACK();
    CHECK_GHOST();
    TP->ADDHP(- power);
    broochpower += power;
    write("You store " + power + " hit points in your Brooch.\n");
    say(TP->SNAME + " stores power in " + TP->POS + " Brooch.\n");
    return 1;
  }
  write("Syntax: storehp <number>\n");
  return 1;
}
