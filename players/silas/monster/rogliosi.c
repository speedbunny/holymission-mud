inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("rogliosi");
  set_alias("mountaineer");
  set_short("Rogliosi, the Mountaineer");
  set_long("This is an image of Rogliosi, the famed warrior who retaliated with guerilla\nwarfare tactics against the rule of the evil tyrant lord Archak. A long beard\ncovers the face of this hardy warrior and the abundance of scars on his face\ntell you that he knows how to do battle.\n");
  set_race("human");
  set_level(18);
  set_al(200);
  set_hp(1500);
  set_ep(500000);
  set_wc(18);
  set_ac(4);
  set_aggressive(0);
  add_money(1500+random(500));
  move_object(clone_object("players/silas/weapon/rclub"),
  this_object());
  init_command("wield club");
  move_object(clone_object("players/silas/armor/rring"),
  this_object());
  init_command("wear ring");
  return 1;
}

query_moncreator() { return "silas"; }

query_monmaker() { return 1; }
