inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_short("Some Special Anti-Flu Herbs");
    set_long("Very Special Anti-Flu Herbs. \n");
	set_id("herbs");
  set_value(700);
  set_weight(1);
}
init() {
 ::init();
 add_action("eat","eat");
}

eat(str) {
	object ob;
  if (str!="herbs")  return; 
   write("Mjammmie  that was Iterly Ital, you feel Most Irie\n");
  say(this_player()->query_name()
			+" eats some Ital Herbs, and feels better visably.\n");
	ob=present("flu_q174",this_player());
	if (ob) {
  	write("Now your flu should soon be over.\n");
		ob->set_immune();
	}
 return 1;
}

