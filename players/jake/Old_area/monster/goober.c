inherit "/obj/monster";

string chat_str;
object point;
reset(arg) {
  ::reset(arg);
chat_str=({"Goober says: Go check out Jake's newbie area ->\n"});
  if (arg) return 1;
  set_name("goober");
  set_short("Goober");
 set_long("This is goober.  Jake thinks he is a mental patient\nwho has escaped.\n");
  set_race("human");
  set_level(10);
add_money(431);
load_chat(10,chat_str);
  set_al(242);
  set_aggressive(0);
  point=clone_object("players/jake/Old_area/stuff/pointer");
move_object(point,this_object());
  return 1;
}

