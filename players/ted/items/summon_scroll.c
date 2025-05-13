
id(str) {
 return (str == "scroll" || str == "ash scroll" || str == "scroll of summoning" 
         || str == "ash colored scroll");
}

short() {
  return "An Ash Colored Scroll";
}

long(str) {
	write("This is a scroll of summoning.\n");
	write("Type 'summon <monster/player>'\n");
	return 1;
}

init() {
	if(environment() != this_player()) return 1;
	add_action("summon"); add_verb("summon");
}

drop() { return 0; }
get() { return 1; }
query_name() { return "Scroll of Summoning"; }
query_value() { return 300; }
query_info() {
	write("This is a scroll of summoning, type 'summon <monster>'\n");
	return 1;
}

summon(arg) {
 object ob;
 if(!find_living(arg)) {
	write("Nothing happens.\n");
	write("The scroll turns to ash and blows away.\n");
	destruct(this_object());
	this_player()->recalc_carry();
	return 1;
  }
 ob = find_living(arg);
 if(ob->query_level() >= 30) {
   write("No summoning of wizards!\n");
   return 1;
 }
 write("You summon "+arg+"!\n");
 tell_object(ob, "You are summond!\n");
 say(call_other(this_player(),"query_name")+" reads an ash colored scroll and "+
      arg+" appears!\n");
 write("The scroll turns to ash and blows away.\n");
 move_object(ob, environment(this_player()));
 if(ob->query_npc()) {
   ob->set_aggressive(0);
   write(arg+" is angry at being summoned!\n");
   ob->attack_object(this_player());
 }
 destruct(this_object());
 this_player()->recalc_carry();
 return 1;
}
