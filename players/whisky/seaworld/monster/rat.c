
inherit "obj/monster";

void reset(int arg) 
{
  ::reset();
   
   if (arg) return; 
      set_name("rat");
      set_short("A big rat");
      set_long("...it looks dangerous.\n");
      set_level(3);
      set_aggressive(1);
      move_object(clone_object(
      "players/whisky/seaworld/obj/cheese"),this_object());
 }
