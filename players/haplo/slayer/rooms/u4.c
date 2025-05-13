inherit "room/room";

#include "/room/orc/orc.h"

string w_name, alt_name;
int i, class, value, weight, type;
object ogre, wp;

reset(arg) {

  if (!present("ogre"))
     for (i=0;i<3;i++) {
	ogre=clone_object("obj/monster");
	ogre->set_name("ogre");
	ogre->set_race("ogre");
        ogre->set_long("This is a fowl smelling ogre with blood"+
                      "dripping off his fangs.  His is breathing "+
                     "in harsh grunts.\n");
	ogre->set_level(random(15)+1);
	ogre->set_al(-500);
	ogre->set_aggressive(1);
	ogre->set_move_at_reset(1);
	switch (random(3)) {
	case 0 : w_name="club"; class=10; value=50; weight=3; type=1; break;
	case 1 : w_name="small morningstar"; class=12; value=100; weight=4; type=1; alt_name="morningstar"; break;
        case 2 : w_name="wooden club";class=9; value=50; weight=3; type=1; alt_name="club"; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_weight(weight);
	wp->set_alt_name(alt_name);
        wp->set_type(type);
        if(w_name=="spear") wp->set_two_handed();

	move_object(ogre,this_object());
	move_object(wp,ogre);
	command("wield "+w_name,ogre);
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
             ORC+"v4","south",
             ORC+"u3","east",
  });
  ::reset();
}
