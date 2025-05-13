brooch(arg) {
  int i;
  object *valid, otherbro;
  if(!arg) {
    valid = filter_array(users(), "guild_list", TO, TP);
    write("Summoners Currently Playing:\n");
    for(i = 0; i < sizeof(valid); i++) {
      otherbro = present("guildbrooch", valid[i]);
      printf("  %-35s %s\n",
	     otherbro->query_line() + " - " +
	     valid[i]->SNAME + ", " +
	     valid[i]->query_gender_string() + " " +
	     valid[i]->query_race(),
	     "(Level " + valid[i]->LEVEL + ")");
    }
    return 1;
  }
  if(linestatus == "OFF") {
    write("Your mind is not attuned to the Brooch.\n");
    return 1;
  }
  tell_others("guild_comm", lw("[->*" + TP->SNAME + "*<-] " + arg + "\n"));
  return 1;
}
