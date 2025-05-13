inherit "room/room";

void reset(int arg) {
  if(!present("raourort")) {
    object m,o;
    m=clone_object("obj/monster");
    m->set_level(25);
    m->set_gender(1);
    m->set_name("raourort, King of Gnomes");
    m->set_alias("raourort");
    m->set_race("gnome"); 
    m->set_long("Raourort is the King of Gnomes, and is a pretty nasty sort of person\n"
	+ "to trifle with. He's certainly the toughest-looking gnome you've ever seen.\n");
    m->set_al(-300);
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
    o=clone_object("obj/weapon");
    o->set_name("sword");
    o->set_short("Longsword");
    o->set_long("This is a very powerful longsword.\n");
    o->set_class(20);
    o->set_value(3500);
    move_object(o,m);
    command("wear cloak", m);
    command("wield sword", m);
    m->add_money(2000+random(5001));
    move_object(m, this_object());
  }
  set_light(1);
  short_desc="Prayer Rooms";
  long_desc="These are the sparsely decorated prayer rooms of the Chapel of the Black.\n"
	+ "Monks. The Black Monks come here to pray, particularly if they've come into\n"
	+ "contact with the perils of the good beings of this world.\n";
  dest_dir=({ "players/moonchild/chapel/s1", "north" });
}

void init() {
  ::init();
  add_action("remove_ghost", "pray");
}

#define RELIGION "Satanist"

int remove_ghost(string str) {
  string belief;
  belief=(string)this_player()->query_religion();
  if(belief!=RELIGION) {
    if((string)this_player()->query_alignment()>-1000) {
      notify_fail("You are too good to become a " + RELIGION + "!\n");
      return 0;
    }
    write("You are now a devout " + RELIGION + ".\n");
    this_player()->set_religion(RELIGION);
    this_player()->set_smell("You smell the odour of evil.");
    return 1;
  }
  if(!this_player()->remove_ghost()) return 0;
  this_player()->set_smell("You smell the odour of evil.");
  return 1;
}
