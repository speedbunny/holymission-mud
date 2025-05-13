broff(arg) {
  if(arg) return;
  if(linestatus == "OFF") {
    write("Your mind is not attuned to the Brooch.\n");
    return 1;
  }
  write("You detach your mind from the Brooch.\n");
  linestatus = "OFF";
  tell_others("guild_notify", TP->NAME + " detaches " + TP->POS +
	      " mind from yours.\n");
  return 1;
}
