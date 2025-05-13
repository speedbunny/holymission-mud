inherit "obj/monster";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {

    set_name("bunny");
    set_alias("baby bunny");
    set_short("A cute little baby bunny");
    set_long("It looks at you with it's big brown eyes.\n");
    set_level(1);
    set_size(2);
    set_al(100);
    set_aggressive(0);
    set_whimpy();
    set_dead_ob(this_object());
    
move_object(clone_object("players/misticalla/garden/obj/claws2"),this_object());
  }
}
monster_died(ob) {
  say("Suddenly, father rabbit arrives angrily.\n");
  move_object(clone_object("players/misticalla/garden/monster/f_bunny"),
              environment(this_object()));
  return 0;
   }
