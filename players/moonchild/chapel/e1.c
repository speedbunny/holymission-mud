inherit "room/room";

void reset(int arg) {
  if(!present("monk")) {
    int i;
    for(i=random(3);i<6;i++) {
      object m,o;
      m=clone_object("obj/monster");
      m->set_level(12);
      m->set_name("black monk");
      m->set_alias("monk");
      m->set_short("A Black Monk");
      m->set_long("This is one of the many Black Monks who work in the chapel.\n");
      m->set_al(-100);
      m->add_money(100+random(401));
      o=clone_object("obj/armour");
      o->set_ac(1);
      o->set_value(300);
      o->set_name("monk's robe");
      o->set_alias("monks robe");
      o->set_type("robe");
      o->set_weight(1);
      o->set_long("A long and light monk's robe.\n");
      move_object(o,m);
      move_object(m,this_object());
      command("wear robe", m);
    }
  }
  set_light(1);
  short_desc="In the chapel";
  long_desc="This is the eastern end of the chapel of the Black Monks.\n"
	+ "The main corridor of the chapel extends to the east and west.\n"
	+ "A shimmering field to the west prevents any exit in that direction.\n";
  dest_dir=({ "players/moonchild/chapel/e2", "east", });
  items = ({
            "corridor", "It's rather bare and spartan in its looks",
            "field", "Mystical field preventing passage",
          });
}
