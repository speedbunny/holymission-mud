inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("palanthea");
  set_alias("amazon");
  set_short("Palanthea, the Amazon Warrior");
  set_long("She is one of the most revered of the tribe of the Amazons, well known for her\nability to judge fairly in disputes. She has mediated not only for the good of\nher own tribe but for other parties as well. It looks as if she has fought\nmany battles and lost only a few of them.\n");
  set_race("human");
  set_level(20);
  set_al(250);
  set_hp(1500);
  set_ep(1000000);
  set_wc(18);
  set_ac(5);
  set_aggressive(0);
  add_money(2000+random(500));
  move_object(clone_object("players/silas/armor/warsuit"),
  this_object());
  init_command("wear warsuit");
  move_object(clone_object("players/silas/armor/headband"),
  this_object());
  init_command("wear headband");
  return 1;
}

query_moncreator() { return "silas"; }

query_monmaker() { return 1; }
