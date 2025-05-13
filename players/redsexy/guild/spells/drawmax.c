draw(arg) {
  int power, diff1, diff2;

  diff1 = TP->MAXHP - TP->HP;
  if(diff1 == 0) {
    write("You are already at full hit points.\n");
    return 1;
  }

  diff2 = TP->MAXSP - TP->SP;
  if(diff2 == 0) {
    write("You are already at full spell points.\n");
    return 1;
  }

  if(arg == "max") {
    if(diff1 <= broochpower) command("draw " + diff1, TP);
    if(diff2 <= broochpower) command("draw " + diff2, TP);
    return 1;
  }

    if(power > broochpower) {
      write("Your Brooch does not have that much power stored.\n");
      return 1;
    }

    if(power > diff1)&&(power > diff2) power = diff1 + diff2;

    CHECK_GHOST();
    TP->ADDHP(power-diff2);
    TP->ADDSP(power-diff1);
    broochpower -= power;
    write("You draw " + power + " of healing points from your Brooch.\n");
    say(TP->SNAME + " draws power from " + TP->POS + " Brooch.\n");
    return 1;
  }
  write("Syntax: draw max\n");
  return 1;
}
