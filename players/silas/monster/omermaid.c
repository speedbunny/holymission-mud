inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mermaid");
  set_short("old mermaid");
  set_long("She must have been quite a beauty forty years ago, now she is nothing but an\nold hag with a fish tail. The sight of her alone makes you gag, but you notice\nthat there is something uncanny about her...\n");
  set_level(8);
  set_al(0);
  set_hp(300);
  set_wc(10);
  set_ac(4);
  set_aggressive(0);
  set_whimpy();
  set_frog();
  move_object(clone_object("players/silas/obj/mscale"),
  this_object());
  return 1;
}

