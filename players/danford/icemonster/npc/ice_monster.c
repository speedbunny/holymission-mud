/* The Ice Monster for the Quest ... */

inherit "obj/monster";

reset(arg) {
::reset(arg);
  if(!arg) {
  	
     set_name("ice monster");
     set_alias("ice monster");
     set_alt_name("monster");
     set_level(5);
     set_hp(100);
     set_al(300);
     set_short("Ice Monster");
     set_long
("The Ice Monster is a nice, plushy creature with a funny smile on its face.\n");
     set_wc(3);
     set_ac(15);
     set_aggressive(0);
     load_chat(20, ({
     	              this_object()->query_name() + " says: I'm sooooo hungry!\n",
     	              this_object()->query_name() + " says: Do you have Ice Cream?\n",
     	              this_object()->query_name() + " says: Give me Ice Cream and I'll be happy!\n",
     	              this_object()->query_name() + " says: There must be Ice Cream in my fridge.\n",
     	              this_object()->query_name() + " says: Give me Ice from my fridge!\n",
     	              this_object()->query_name() + " says: Find my fridge, but not in this cave!\n"
     	              
     }));
  }
}

init() {
	::init();
        add_action("get_ice", "give");
}

get_ice(str) {
	if(!str == "Ice Cream") write("wrong!");
}

