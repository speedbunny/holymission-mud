inherit "room/room";

#include "/room/orc/orc.h"

string w_name, alt_name;
int i, class, value, weight, type;
object orc, wp;

reset(arg) {
  if (!present("orc"))
     for (i=0;i<2;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("huge orc");
	orc->set_race("orc");
        orc->set_long("This is a fowl smelling orc with blood"+
                      "dripping off his fangs.  His is breathing "+
                      "in harsh grunts.\n");
	orc->set_level(random(20)+16);
	orc->set_al(-1000);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	switch (random(5)) {
            case 1: w_name="morningstar"; class=15; value=500; weight=6; alt_name="morningstar";type=1; break;
            case 2: w_name="heavy morningstar"; class=18; value=2000; weight=8; alt_name="morningstar";type=1; break;
            case 3: w_name="huge pike"; class=18; value=2000; weight=6; alt_name="pike";type=2;    break;
            case 4: w_name="falchion"; class=18; value=2000; weight=6; alt_name="pike";type=0; break;
            case 5: w_name="heavy wooden club"; class=19; value=2000; weight=10; alt_name="club";type=1;   break;
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
             ORC+"v5","east",
             "/players/moonchild/pot/orc1","west",
  });
  ::reset();
}
