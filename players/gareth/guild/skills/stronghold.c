#define TP	this_player()
stronghold(str) {
  if(TP->query_ghost()) {
    write("Your home is situated in the hell. Don't go there if you don't wanna " +
          "stay there, forever!\n");
	return 1;
  }

  if(TP->query_level() < 10) { 
        write("You do not possess this power yet.\n"); return 1; }
  if(TP->query_spell_points() < 40) {
	write("You attempt to stronghold but you cannot muster up the mental"+
		" energy.\n"); return 1;}
  if(environment(TP)->query_property("no_teleport")) {
    write("As you try to leave this place you bang your head on an "+
          "invisible wall of force.\n");
    return 1;
  }
  write("You use all you mental and physical powers to return to your " +
  "guild.\n\n");
  TP->move_player("home#players/gareth/guild/rooms/restroom.c");
  TP->restore_spell_points(-35);
  return 1;
}
