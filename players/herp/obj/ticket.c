/* 920416 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* A ticket to my workroom */

id(str) { return str=="ticket" || str=="ticket to herp"; }

get() { return 1; }

short() { return "A ticket to the workroom of Herp"; }

query_value() { return 10; }

long() { write("This is a ticket to the workroom of Herp.\n" +
	       "Use with 'goto herp'.\n" +
	       "Feel free to use any exit you like in my workroom," +
	       "there aren't much, anyway.\n" +
	       "If you are stuck in an exit, call the wizards to pick you up.\n" +
	       "if you were stuck, send me a bug report please (via mail, or post it\n" +
	       "on the thieves board)\n" +
	       "\nGreetinx, Herp.\n");
  return 1;
}

init() { add_action("goto","goto"); }

goto(str) {
  if (str=="herp") {
     if (environment(this_player())->has_drink(this_player())) {
	write("You are not allowed to bring drinks to Herp's workroom.\n"
	    + "Herp doesn't drink anymore.\n");
	return 1;
     }
     this_player()->move_player("to Herp's workroom#players/herp/workroom");
     return 1;
  }
}
