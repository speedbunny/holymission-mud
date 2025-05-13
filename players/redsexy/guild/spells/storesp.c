storesp(arg) {
  int power, diff, sp;
  diff = MAXBP - broochpower;
  sp = TP->SP;
  if(diff == 0) {
    write("Your Brooch is already full.\n");
    return 1;
  }
  if(arg == "max") {
    if(diff < sp) command("storesp " + diff, TP);
    else command("storesp " + sp, TP);
    return 1;
  }
  if(arg && sscanf(arg, "%d", power)) {
    if(power <= 0) {
      write("You may only store a positive amount in your Brooch.\n");
      return 1;
    }
    if(power > sp) {
      write("You do not have that many spell points.\n");
      return 1;
    }
    if(power > diff) power = diff;
    CHECK_ATTACK();
    CHECK_GHOST();
    TP->ADDSP(- power);
    broochpower += power;
    write("You store " + power + " spell points in your Brooch.\n");
    say(TP->SNAME + " stores power in " + TP->POS + " Brooch.\n");
    return 1;
  }
  write("Syntax: storesp <number>\n");
  return 1;
}
