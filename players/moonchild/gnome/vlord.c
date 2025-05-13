inherit "room/room";

reset(arg) {
  if(!present("vampire lord")) {
    object b,o;
    move_object(b=clone_object("obj/monster"),this_object());
    b->set_name("vampire lord");
    b->set_alias("lord");
    b->set_race("vampire");
    b->set_short("Vampire lord");
    b->set_long("This huge undead vampire lord has enormous teeth!\n");
    b->set_level(80);
    b->set_hp(8000);
    b->set_chance(20);
    b->set_spell_dam(85);
    b->set_spell_mess1("Vampire lord stares at its enemy.");
    b->set_spell_mess2("Vampire lord drains your life-force.");
    b->set_al(-2500);
    b->set_wc(32);
    b->set_ac(25);
    b->set_aggressive(1);
    move_object(o=clone_object("obj/armour"),b);
    o->set_type("cloak");
    o->set_short("Vampire cloak");
    o->set_long("A long dark vampire's cloak.\n");
    o->set_weight(2);
    o->set_ac(1);
    o->set_max_strength(90);
    o->set_value(400);
    move_object(o=clone_object("players/moonchild/gnome/crystal"),b);
    o->set_type(3);
    move_object(o=clone_object("obj/armour"),b);
    o->set_type("ring");
    o->set_short("Ring of Protection");
    o->set_long("A ring which offers magical protection.\n");
    o->set_weight(1);
    o->set_ac(1);
    o->set_max_strength(45);
    o->set_value(250);
    move_object(o=clone_object("obj/armour"),b);
    o->set_type("amulet");
    o->set_short("Amulet of Blood");
    o->set_long("This amulet was magically fashioned from human blood!\n");
    o->set_weight(1);
    o->set_ac(1);
    o->set_max_strength(45);
    o->set_value(250);
    move_object(o=clone_object("obj/treasure"),b);
    o->set_id("statuette");
    o->set_short("A small amber statuette");
    o->set_long("This amber statuette depicts a very strange scene. A man stands in a cavern,\n"
	+ "with six stones hanging in the air. He is depicted touching one of the stones.\n");
    o->set_weight(2);
    o->set_value(200);
    b->add_money(250+random(1251));
  }
  if(arg) return;
  set_light(1);
  short_desc="Vampire Lord's tower";
  long_desc="This is the main hall of the Vampire Lord's tower.\n"
	+ "The exit is to the north; doors lead east, south and\n"
	+ "west, and a crystal staircase leads up to a landing.\n";
  dest_dir=({ "players/moonchild/gnome/ghouls", "north",
        "players/emerald/forest/tower_2", "east",
        "players/emerald/forest/tower_2", "south",
        "players/emerald/forest/tower_2", "west",
        "players/emerald/forest/tower_2", "up",
        });
  items=({ "doors", "Beautiful carved oaken doors",
	"staircase", "An amazing crystal staircase" });
  property=({ "no_teleport", "no_sneak" });
}

move(str) {
  if(query_verb()=="north") return ::move(str);
  if(present("vampire lord")) write("Vampire lord bars your way!\n");
  else {
    write("You feel a magical force, and go far from where you thought you were going.\n");
  return ::move(str);
  }
  return 1;
}
