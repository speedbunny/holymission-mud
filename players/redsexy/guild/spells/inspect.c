inspect(arg) {
  object item;
  if(arg) {
    item = present(arg, TP);
    if(item) {
      if(item->query_armour() || item->query_weapon()) {
	if((item->query_armour() &&
	    (item->WEAR || item->armour_class() <= 0)) ||
	   (item->query_weapon() && item->WIELD)) {
	  write("You can safely use " + item->SHORT + ".\n");
	  return 1;
	}
	write(item->SHORT + " would interfere with your " +
	      "Summoner abilities.\n");
	return 1;
      }
      write("That is not an armour or weapon.\n");
      return 1;
    }
    write("You are not carrying that.\n");
    return 1;
  }
  write("Syntax: inspect <item>\n");
  return 1;
}
