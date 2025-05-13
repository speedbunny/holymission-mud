inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("guard");
  set_short("City Guard");
  set_long("He is big, burly and he doesn't look too smart but you somehow get the\nimpression that he takes his job very seriously.\n");
  set_level(14);
  set_al(200);
  set_hp(600);
  set_ep(222222);
  set_wc(15);
  set_ac(3);
  set_aggressive(0);
move_object(clone_object("players/silas/obj/kaxe"),
this_object());
init_command("wield axe");
move_object(clone_object("players/silas/obj/karmor"),
this_object());
init_command("wear armor");
  return 1;
}

query_moncreator() { return "silas"; }

query_monmaker() { return 1; }
