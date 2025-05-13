
/* wardrobe.c */

inherit "/room/room";

object skeleton;

void reset(int flag) 
{
    if (!skeleton || !living(skeleton)) {
	skeleton = clone_object("obj/monster");
	skeleton->set_name("skeleton");
	skeleton->set_level(8);
	skeleton->set_hp(70);
	skeleton->set_wc(7);
	skeleton->set_al(-200);
	skeleton->set_short("A skeleton");
	skeleton->set_aggressive(1);
	move_object(skeleton, this_object());
    }
    if (flag == 0)
    {
      set_light(1);
      dest_dir = ({ "players/padrone/tower/bedroom", "west",});
      short_desc = "In a Wardrobe";
      long_desc =
	 "You are inside a small, cluttered wardrobe,\n" +
	 "full of the Wizard's clothes.\n";
     }
}
