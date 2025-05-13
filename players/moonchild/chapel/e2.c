inherit "room/room";

void reset(int arg) {
  if(!present("blackrobed monk")) {
    object m,o;
    m=clone_object("obj/monster");
    m->set_level(35);
    m->set_name("blackrobed monk");
    m->set_alias("monk");
    m->set_long("This black-robed monk is a senior monk in the Order of the Black Monks."
	"He is a tall figure wearing a cloak and carrying an upside-down cross.");
    m->set_al(-300);
    m->set_hp(2000);
    m->set_whimpy(-1);
    o=clone_object("obj/armour");
    o->set_name("cloak");
    o->set_alias("black cloak");
    o->set_type("robe");
    o->set_ac(1);
    o->set_weight(1);
    o->set_value(500);
    o->set_short("A black cloak");
    o->set_long("A long flowing black cloak. It seems to drape about you.\n");
    move_object(o,m);
    o=clone_object("obj/armour");
    o->set_name("upside-down cross");
    o->set_type("other");
    o->set_short("Upside-down cross");
    o->set_long("This cross signifies the worship of Satan.\n");
    o->set_arm_light(2);
    o->set_value(200);
    move_object(o,m);
    command("wear cloak", m);
    command("wear cross", m);
    m->add_money(500+random(2001));
    move_object(m, this_object());
  }
  set_light(1);
  short_desc="In the Chapel";
  long_desc="This is the eastern end of the chapel of the Black Monks.\n"
	"The main corridor of the chapel extends off to the west.\n";
  dest_dir=({ "players/moonchild/chapel/link", "east",
	"players/moonchild/chapel/e1", "west" });
  items=({ "corridor", "It's rather bare and spartan in its looks" });
}

int move(string str) {
  if(present("monk") && query_verb()=="west"
	&& (int)this_player()->query_alignment()>-40) {
    tell_room(this_object(), "Monk says: You are too good to come in here.\n");     return 1;
  }
  return ::move(str);
}
