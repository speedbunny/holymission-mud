inherit "/obj/monster";
object wine;
reset (arg) {
   ::reset (arg) ;
  if (arg) return;
       set_name("goblin");
       set_short("drunken goblin");
       set_long("He looks real intoxicated.\nHe stares at you through glassy yellow eyes.\n");
       set_level(11);
       set_al(100);
       set_aggressive(0);
       set_race("goblin"); 
       set_size(3);
    wine=move_object(clone_object("players/jake/goblin/castle/obj/wine"),this_object());
      return 1;
}
