inherit "obj/monster";

object tooth,disease;

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name ("guineapig");
  set_alias ("guineapig");
  set_race ("rodant");
  set_short ("A nice guineapig");
  set_long ("A really nice guineapig which wants to be cuddled.\n");
  set_level(4);
  set_hp(100);
  tooth = clone_object("players/muzmuz/obj/tooth");
  move_object(tooth, this_object());
  init_command("wield tooth");
/*  disease = clone_object("players/whisky/obj/disease");
  move_object(disease,this_object()); */
 return 1; }
