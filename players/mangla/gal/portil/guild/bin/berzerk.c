berzerk(int is_berzerk,object bloarm) { 
  object tp;
  tp=this_player();
  if(tp->query_ghost()) {
    write("You suddenly realize that this was a great mistake.\n" +
          "The whole room is spinning around you.\n" +
          "You decide to run as far as you can to leave this place.\n");
    tp->run_away();
    tp->run_away();
    write("As you feel your mind clearing you decide to rest for a moment.\n");
    return 1;
  }
	
  if (!tp->query_attack()) {
      write("You are not fighting anyone.\n");
      return 1;
  }
  if (is_berzerk) {
     write("You are as berzerk as anyone can be.\n");
     return 1;
  }
  if(bloarm) {
	write("You cannot berzerk whilst you are blocking.\n");
	return 1;
	}

  write("You turn into a rampaging frenzy.\n");
  tp->set_berzerk(1);
  return 2; //Two will indicate that berzerk started
}
