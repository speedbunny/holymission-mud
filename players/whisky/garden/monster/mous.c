inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("mouse");
     set_short("A rabiate Mouse");
     set_long("It is looking very angry at you, it dont like desturbing guests.\n");
     set_level(4);
     set_size(1);
     set_al(-10);
     set_aggressive(1);
     move_object(clone_object("players/whisky/garden/obj/boots"),this_object());
  }
}  

