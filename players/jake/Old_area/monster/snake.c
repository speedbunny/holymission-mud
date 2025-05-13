inherit "/obj/monster";

object fangs;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("snake");
  set_alias("rattle");
  set_short("Rattle snake");
set_long("This is a desert rattesnake.\nIt appears to be very poisonous.\n");
  set_level(6);
  set_al(-400);
  set_ep(1000);
  set_ac(2);
  set_aggressive(0);
  add_money(200);
fangs=clone_object("players/jake/Old_area/weapons/sfangs");
  move_object(fangs,this_object());
  init_command("wield snake fangs");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
