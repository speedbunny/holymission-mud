inherit "room/room";

void reset(int arg) {
  if(!present("gnome")) {
    int i;
    for(i=random(3);i<8;i++) {
      object m,o;
      m=clone_object("obj/monster");
      m->set_level(14);
      m->set_name("gnome guard");
      m->set_alias("guard");
      m->set_race("gnome");
      m->set_short("A gnome guard");
      m->set_long("This is one of the many guards of the Gnome King Raourort\n");
      m->set_al(-100);
      m->set_whimpy(-1);
      m->add_money(100+random(401));
      m->set_aggressive(1);
      o=clone_object("obj/weapon");
      o->set_class(15);
      o->set_value(750);
      o->set_name("sharp sword");
      o->set_alias("sword");
      o->set_weight(3);
      o->set_long("A sharp-bladed sword of gnomish manufacture.\n");
      move_object(o,m);
      move_object(m,this_object());
      command("wield sword", m);
    }
  }
  set_light(1);
  short_desc="Corridor";
  long_desc="This is the corridor leading north to the centre of the chapel\n"
	+ "and south towards the main prayer rooms.\n";
  dest_dir=({ "players/moonchild/chapel/cent", "north",
	"players/moonchild/chapel/s2", "south" });
  items=({ "corridor", "It's rather bare and spartan in its looks" });
}

int move(string str) {
  if(query_verb()=="south" && present("gnome")) {
    write("The gnome bars your way!\n");
    return 1;
  }
  return ::move(str);
}
