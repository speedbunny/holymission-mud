bremote(arg) {
  if(arg) {
    if(linestatus == "OFF") {
      write("Your mind is not attuned to the Brooch.\n");
      return 1;
    }
    tell_others("guild_comm", lw("[->**<-] " + TP->SNAME +
				 " " + arg + "\n"));
    return 1;
  }
  write("Syntax: bremote <emote>\n");
  return 1;
}
