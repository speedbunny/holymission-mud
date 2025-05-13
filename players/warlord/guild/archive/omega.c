inherit "/obj/monster";


object cloak,sword;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("omega");
  set_short("Omega");
  set_long("This is The Almighty Omega..Take Extreme caution HE'S DEADLY!!!!\n");
  set_al(100);
  set_aggressive(0);
  set_whimpy();
  add_money(5000);
  set_level(19);
  set_hp(10000);
  set_move_at_reset();
  cloak=clone_object("players/warlord/cloak1");
  sword=clone_object("players/warlord/sun_sword");
  transfer(cloak, this_object());
  transfer(sword, this_object());
  init_command("wear cloak");
  init_command("wield sword");
  return 1;
  }
