inherit "room/store";

init() {
  if(!interactive(this_player()) || this_player()->query_level()<50
	&& this_player()->query_real_name()!="moonchild")
	transfer(this_player(),"players/moonchild/gnome/shop");
}

reset(arg) {
  object o;
  int i;
/* Frisbees have been removed from HM - Airborne 
  if(!present("frisbee"))
    for(i=0;i<3;i++)
      move_object(clone_object("players/moonchild/gnome/shop/frisbee"),
	this_object());
 */
  if(!present("scroll")) {
    move_object(o=clone_object("obj/treasure"),this_object());
    o->set_id("scroll");
    o->set_alias("ash scroll");
    o->set_short("A crumbling ash scroll");
    o->set_long("A crumbling ash scroll with something written on it.\n");
    o->set_read("The scroll reads:\n\nThey are turquoise, green, pink, red and blue,\n"
	+ "And in the place where they come true,\n"
	+ "For verily the five crystals are the key,\n"
	+ "Within the temple - it's plain to see.\n");
    o->set_value(150);
  }
  if(!present("blue scroll"))
    move_object(clone_object("players/moonchild/gnome/shop/tit_scroll"),
	this_object());
  if(!present("can"))
    move_object(clone_object("players/moonchild/gnome/shop/can"),
	this_object());
  if(!present("torch")) {
    move_object(o=clone_object("obj/torch"),this_object());
    o->set_name("torch");
    o->set_fuel(2000);
    o->set_weight(1);
  }
  if(!present("lantern")) {
    move_object(o=clone_object("obj/torch"),this_object());
    o->set_name("lantern");
    o->set_fuel(4000);
    o->set_weight(2);
  }
  if(!present("seeds"))
	move_object(clone_object("players/moonchild/gnome/shop/seeds"),
	this_object());
  if(!present("crystal")) {
    move_object(o=clone_object("players/moonchild/gnome/crystal"),
	this_object());
    o->set_type(1);
  }
/* 141097: Sauron: Removed the globe from the game - it's a shout.
  if(!present("globe"))
	move_object(clone_object("players/moonchild/gnome/shop/globe"),
	this_object());
*/
  if(!present("shortsword")) {
    move_object(o=clone_object("obj/weapon"),this_object());
    o->set_name("shortsword");
    o->set_alias("sword");
    o->set_short("A shortsword");
    o->set_long("An ordinary shortsword.\n");
    o->set_class(12);
    o->set_weight(5);
    o->set_value(550);
  }
  if(!present("longsword")) {
    move_object(o=clone_object("obj/weapon"),this_object());
    o->set_name("longsword");
    o->set_alias("sword");
    o->set_short("A beautifully carved longsword");
    o->set_long("This is a superbly crafted blade.\n");
    o->set_class(18);
    o->set_weight(4);
    o->set_value(2000);
  }
  if(!present("armour")) {
    move_object(o=clone_object("obj/armour"),this_object());
    o->set_name("chainmail");
    o->set_type("armour");
    o->set_short("A suit of chainmail");
    o->set_long("A large protective suit of chainmail.\n");
    o->set_ac(4);
    o->set_weight(4);
    o->set_value(750);
  }
  if(!present("helmet")) {
    move_object(o=clone_object("obj/armour"),this_object());
    o->set_name("helmet");
    o->set_type("helm");
    o->set_short("A metal helmet");
    o->set_long("A sturdy metal helmet.\n");
    o->set_ac(1);
    o->set_weight(2);
    o->set_value(125);
  }
  if(!present("shield")) {
    move_object(o=clone_object("obj/armour"),this_object());
    o->set_name("shield");
    o->set_type("shield");
    o->set_short("A superb crystal shield");
    o->set_long("A very fine piece of armour indeed!\n");
    o->set_ac(1);
    o->set_weight(3);
    o->set_value(600);
  }
}
