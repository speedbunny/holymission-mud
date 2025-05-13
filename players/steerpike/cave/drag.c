inherit "room/room";

reset(arg) {
  if(!present("dragon")) {
    object d,c,o;
    int i;
    move_object(d=clone_object("obj/monster"),this_object());
    d->set_name("dragon");
    d->set_short("A large red dragon");
    d->set_long("This is a massive red dragon, with jaws ten times your own\n"
	+ "size, and lungs of awesome power. You feel afraid of it.\n");
    d->set_level(60);
    d->set_hp(2500);
    d->set_wc(30);
    d->set_ac(20);
    d->set_chance(30);
    d->set_spell_dam(100);
    d->set_spell_mess1("Dragon lets off a blast of flame!");
    d->set_spell_mess2("Dragon blows fire at you. You are horribly burnt!");
    d->set_al(-500);
    move_object(c=clone_object("obj/container"),d);
    c->set_name("chest");
    c->set_alias("treasure chest");
    c->set_short("A treasure chest");
    c->set_long("A beautifully made carved wooden treasure chest.\n");
    c->set_weight(4);
    c->set_max_weight(12);
    c->set_value(500);
    for(i=0;i<12;i++) {
      switch(random(3)) {
	string type;
	case 0:
	  move_object(o=clone_object("obj/money"),c);
	  o->set_money(50+random(201));
	  break;
	default:
	  o=clone_object("players/moonchild/cave/treasure");
	  o->set_weight(1);
	  o->set_value(100+random(301));
	  type=({ "emerald", "ruby", "diamond", "sapphire" })[random(4)];
	  o->set_id(type);
	  o->set_short((type=="emerald") ? "An " + type : "A " + type);
	  o->set_long("A beautiful " + type + ". It must be quite valuable.\n");
	  transfer(o,c);
	  break;
      }
    }
  }
  if(arg) return;
  short_desc="A rock tunnel";
  long_desc="A rock tunnel leads off east from here. Above, you could just\n"
	+ "possibly climb back into the cavern from which you entered.\n";
  dest_dir=({ "players/moonchild/cave/tunnel", "east",
	"players/moonchild/cave/c21", "up" });
  items=({ "tunnel", "It looks dark, and rocky" });
}

init() {
  ::init();
  add_action("east", "east");
}

east() {
  if(!present("dragon")) return;
  write("You can't possibly get past the dragon!\n");
  return 1;
}
