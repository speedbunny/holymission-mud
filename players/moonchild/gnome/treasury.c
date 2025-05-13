inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Gnomes' Treasury";
  long_desc="This is the Gnomes' Treasury, it's normally full of valuable items.\n"
	+ "In the centre of the floor there is a pit - this is the only exit!\n";
  dest_dir=({ "players/moonchild/gnome/maze4", "down" });
  items=({ "pit", "It looks not too deep" });
  property=({ "no_teleport" });
}

move(str) {
  write("You wriggle down the pit.\n");
  return ::move(str);
}

make_treasure(arg) {
  object *allinv;
  int i;
  allinv=all_inventory(this_object());
  for(i=0;i<sizeof(allinv);i++) if(!living(allinv[i])) destruct(allinv[i]);
  for(i=0;i<arg;i++) {
    switch(random(4)) {
	case 0:
	  make_money(); break;
	case 1:
	  make_weapon(); break;
	case 2:
	  make_armour(); break;
	case 3:
	  make_jewel(); break;
    }
  }
}

make_money() {
  object m;
  move_object(m=clone_object("obj/money"),this_object());
  m->set_money(100+random(401));
}

make_weapon() {
  object o;
  move_object(o=clone_object("obj/weapon"),this_object());
  if(random(2)) {
    o->set_name("shortsword");
    o->set_alias("sword");
    o->set_short("A shortsword");
    o->set_long("An ordinary shortsword.\n");
    o->set_class(12);
    o->set_weight(5);
    o->set_value(550);
  } else {
    o->set_name("longsword");
    o->set_alias("sword");
    o->set_short("A beautifully carved longsword");
    o->set_long("This is a superbly crafted blade.\n");
    o->set_class(19);
    o->set_weight(4);
    o->set_value(3000);
  }
}

make_armour() {
  object o;
  move_object(o=clone_object("obj/armour"),this_object());
  switch(random(3)) {
    case 0:
	o->set_name("chainmail");
	o->set_type("armour");
	o->set_short("A suit of chainmail");
	o->set_long("A large protective suit of chainmail.\n");
	o->set_ac(4);
	o->set_weight(4);
 	o->set_value(750);
	break;
    case 1:
	o->set_name("helmet");
        o->set_type("helmet");
	o->set_short("A metal helmet");
	o->set_long("A sturdy metal helmet.\n");
	o->set_ac(1);
	o->set_weight(2);
	o->set_value(125);
	break;
    case 2:
	o->set_name("shield");
	o->set_type("shield");
	o->set_short("A superb crystal shield");
	o->set_long("A very fine piece of armour indeed!\n");
	o->set_ac(1);
	o->set_weight(4);
	o->set_value(600);
	break;
  }
}

make_jewel() {
  object o;
  string type;
  move_object(o=clone_object("players/moonchild/cave/treasure"),this_object());
  o->set_weight(1);
  o->set_value(100+random(301));
  type=({ "emerald", "ruby", "diamond", "sapphire" })[random(4)];
  o->set_id(type);
  o->set_short((type=="emerald") ? "An " + type : "A " + type);
  o->set_long("A beautiful " + type + ". It must be quite valuable.\n");
}
