/*Monster description corrected by Silas*/
inherit "/obj/monster";

object bar;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("beth");
  set_short("Beth");
  set_long("This is Beth.  She eats everything in sight.\nWhat a pig!  She is tremendously fat, with pimples all over her face.\nHer teeth are rotting out of her skull.\n");
  set_level(15);
  set_al(1000);
  set_aggressive(0);
bar=clone_object("players/jake/stuff/ba");
move_object(bar,this_object());
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
