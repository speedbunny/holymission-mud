bron(arg) {
  if(arg) return;
  if(linestatus == " ON") {
    write("Your mind is already attuned to the Brooch.\n");
    return 1;
  }
  write("You attune your mind to the Brooch.\n");
  linestatus = " ON";
  tell_others("guild_notify", TP->NAME + " joins " + TP->POS +
	      " mind to yours.\n");
  return 1;
}
