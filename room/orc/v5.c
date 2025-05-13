inherit "room/room";

#include "/room/orc/orc.h"

string w_name, alt_name;
int i, class, value, weight, type;
object orc, wp;

reset(arg) {

  if (!present("orc"))
     for (i=0;i<5;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("huge orc");
	orc->set_race("orc");
        orc->set_long("This is a fowl smelling orc with blood"+
                      "dripping off his fangs.  His is breathing "+
                      "in harsh grunts.\n");
	orc->set_level(random(15)+1);
	orc->set_al(-360);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	switch (random(4)) {
	case 0 : w_name="battleaxe"; class=12; value=100; weight=3; type=1;alt_name="axe"; break;
	case 1 : w_name="waraxe";    class=14; value=200; weight=4; type=1;alt_name="axe"; break;
	case 2 : w_name="axe";class=9; value=25; weight=1; type=1;break;
	case 3 : w_name="small morningstar";class=12;value=150; weight=5; type=1;alt_name="morningstar"; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_weight(weight);
	wp->set_alt_name(alt_name);
        wp->set_type(type);
        if(w_name=="spear") wp->set_two_handed();

	move_object(orc,this_object());
	move_object(wp,orc);
	command("wield "+w_name,orc);
     }

  if(arg) return;
  short_desc="The orc valley";
  long_desc=
            "You are in Orc Valley.  There are limbs thrown about all " +
            "around you.  Broken bones from past victims are scattered on " +
            "the ground.  The ground has been stained red from the blood " +
            "that has been spilled here.  There are signs of orcs everywhere.  " +
            "Faint growls and grunts can be heard somewhere in the distance.\n";
  set_light(1);
  items=({
            "valley","The Orc Valley",
            "red", "Blood red",
            "somewhere", "Somewhere in the distance",
            "distance", "Somewhere far",
            "signs", "Signs of orcs",
            "everywhere", "All around you",
            "limbs","Limbs of past victims",
            "bones","Bones of past victims",
            "blood", "Blood of past victims",
            "ground", "Covered in blood",
            "grunts", "You cannot see a sound",
            "growls", "You cannot see a sound",
            "sounds", "You cannot see a sound",

  });
  smell="You smell blood and guts.\n";
  dest_dir=({
             ORC+"v4","east",
             ORC+"v6","west",
  });
  ::reset();
}
