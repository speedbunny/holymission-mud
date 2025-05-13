/* a viking's shade. holds some info */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("ghost of viking");
      set_alias("shade");
      set_alt_name("ghost");
      set_short("The shade of a long dead viking");
      set_level(4);
      set_race("ghost");
      set_gender(1);
      set_dead_ob(this_object());

      }
   }

monster_died() {
   tell_room(environment(this_object()),"With a loud scream of agony the shade shrinks\n"
      + "becomes more solid and finally transforms into a piece of leather.\n");
   move_object(clone_object("players/uglymouth/vikings/items/scroll"),environment(this_object()));
   return 0;
   }
