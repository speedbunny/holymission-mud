inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("esmeralda");
  set_alias("gnome");
  set_short("Esmeralda");
 set_long("You see a nice pretty woman who is looking at you.\n"+
"She is sleek of body enough to lure any mans heart.\n");
  set_race("gnome");
  set_level(40);
  set_al(-500);
  set_hp(1200);
  set_wc(19);
  set_ac(10);
  set_aggressive(0);
  set_whimpy();
  set_move_at_reset();
  add_money(2000+random(300));
  load_chat(20,({
    "Esmeralda says: Don't you like me, you fool!!!\n",
    "Esmeralda looks at you and laughs.\n",
    "Esmeralda whispers to you: Hey, I wanna tell you a secret.\n",
    "Esmeralda whispers to you: I'm the princess of Pavi castle.\n",
}));
  return 1;
}

