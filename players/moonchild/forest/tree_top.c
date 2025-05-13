inherit "room/room";

string type;
object m,down;

void reset(int arg) {
  if(type && !m) {
    object o;
    move_object(m=clone_object("obj/monster"),this_object());
    switch(type) {
      case "oak":
	m->set_level(3);
	m->set_name("owl");
	m->set_long("A wise-looking owl. ");
	m->set_al(100);
	break;
      case "ash":
	m->set_level(10);
	m->set_name("tree elf");
	m->set_race("elf");
	m->set_al(100);
	m->set_long("A busy-looking tree elf. ");
	m->add_money(100+random(201));
	o=clone_object("obj/weapon");
	o->set_name("oak staff");
	o->set_alias("staff");
	o->set_long("An oaken staff.\n");
	o->set_class(13);
	o->set_value(300);
	move_object(o,m);
	command("wield staff", m);
	break;
      case "cedar":
	m->set_level(5);
	m->set_name("magpie");
	m->set_long("A small magpie. ");
	o=clone_object("obj/treasure");
	o->set_id("bauble");
	o->set_short("A glossy bauble");
	o->set_long("A glossy bauble, ripped from some expensive dress.\n");
	o->set_value(50+random(51));
	o->set_weight(1);
	move_object(o,m);
	break;
      case "alder":
	m->set_level(2);
	m->set_name("blackbird");
	m->set_long("A beautiful little blackbird, gripping an apple in its beak.\n");
	o=clone_object("obj/food");
	o->set_strength(4);
	o->set_value(15);
	o->set_weight(1);
	o->set_name("apple");
	o->set_short("An apple");
	o->set_long("A small apple.\n");
	o->set_eater_mess("A very nice apple.\n");
	o->set_eating_mess(" eats an apple.\n");
	move_object(o,m);
	break;
    }
  }
  if(arg)
    return;
  set_light(1);
  short_desc="Treetop";
  smell="You smell the clean, fresh air";
  items=({ "tree", "It's a rather tall tree",
	"branches", "The branches aren't very sturdy higher up, so you couldn't climb further",
	"forest", "It extends a long way in all directions" });
}

void init() {
  add_action("down", "down");
}

int down() {
  this_player()->move_player("down", down);
  return 1;
}

void set_type(string str) {
  down=environment(previous_object());
  type=str;
  long_desc="You are standing high up in the branches of "
	+ (type=="cedar" ? "a " : "an ") + type + " tree.\n"
	+ "The air is fresh and clean, and you can see all around the forest.\n"
	+ "    The only obvious exit is down.\n";
  no_obvious_msg="";
  reset(0);
}
