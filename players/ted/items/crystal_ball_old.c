int charges;

id(str) {
 return (str == "ball" || str == "cystal" || str == "crystal ball");
}

long(str) {
	write("This is a round crystal ball. It is slightly cloudy.\n");
	return 1;
}

short() {
	return "A Crystal Ball";
}

init() {
  charges = 14;
 add_action("view"); add_verb("peer");
 add_action("view"); add_verb("find");
}

drop() { return 0; }
get() { return 1; }
query_name() { return "Crystal Ball"; }
query_value() { return 325; }
query_weight() { return 2; }
query_info() {
	write("This is a crystal ball, used to locate people.\n");
	write("type 'peer <monster/person>' or type 'find <monster/person>'\n");
	return 1;
}

view(arg) {
 object back, ob;
 back = environment(this_player());
 if(!arg) {
	write("What are you looking for?\n");
	return 1;
  }
   if (charges == 0) {
  write("The ball goes dull and dies crumbling to little crystalline pieces\n");
 destruct(this_object());
  return 1;
 }
 if(!(ob=find_living(arg)) || ob->query_wizard() && ob->query_invis() || 
      ob->query_linkdeath()) {
	write("The crystal ball becomes cloudy, but you see nothing.\n");
	return 1;
  }
 write("You peer into the crystal ball, trying to find "+arg+"\n");
 write("You see:\n\n");
 if (ob->query_wizard()) {
    write("You can't stand looking at the power surrounding "+ob->query_name()+".\n");
    write("You lose your consciousness ...\n");
    return 1;
 }
 move_object(this_player(), environment(ob));
 command("look", this_player());
  charges -= 1;
 move_object(this_player(), back);
 write("\n\n");
 return 1;
}
