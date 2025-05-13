inherit "/obj/thing";

reset(arg) {
    if (arg) return 1;
    set_name("A black hole");
    set_alias("hole");
    set_short("A black hole");
    set_long("A black hole in the ground.\n");
    set_value(0);
    set_weight(20000);
    return 1;
}

query_objmaker() { return 1; }
init(){
    add_action("enter_hole","enter");
}
enter_hole(str){
    if(!str){
	notify_fail("Enter what ?\n");
	return 0;
    }
    if((str=="hole")||(str=="black hole")){
 if(!this_player()->query_frog()){
 write("You are too big to enter this hole.\n");
	    return 1;
	}
	  write("You enter the hole, and find that it is bigger than you thought.\n");
	  this_player()->move_player("through a black hole#players/dice/quest/q6");
	  return 1;
      }
    }
