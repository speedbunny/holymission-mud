inherit "obj/monster";

object bunnyclaw;

reset (arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name ("bunny");
  set_alias ("bunny");
  set_race ("rodant");
  set_short ("A fluffy bunny");
  set_long ("A white fluffy bunny, it looks nice and not harmful at all.\n");
  set_level(5);
  set_hp(130);
  bunnyclaw = clone_object("players/muzmuz/obj/bunnyclaw");
  move_object(bunnyclaw,this_object());
  init_command("wield bunnyclaw");
 command ("wield claw");

return 1;

}
