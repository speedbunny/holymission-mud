
inherit "obj/container";  

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Bag of Holding");
  set_alt_name("bag of holding");
  set_alias("bag");
  set_short("A Bag of Holding");
  set_long("This is a small bag, but it holds a lot!\n");
  set_value(100);
  set_weight(2);
  set_max_weight(21);

  move_object((clone_object("players/whisky/obj/haste_potion")), 
	this_object());
  move_object((clone_object("players/sherman/hills/bracers")),
	this_object());
  move_object((clone_object("players/whisky/obj/jeweled_earrings")),
	this_object());
  move_object((clone_object("players/padrone/obj/wizardshat")),
	this_object());
  move_object((clone_object("players/whisky/obj/ruby_bracelet")),
	this_object());

}
