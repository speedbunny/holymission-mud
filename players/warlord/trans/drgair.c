inherit"obj/monster";
reset(arg) {
 if (arg) return;
 set_name("dragonair");
set_alias("airdragon");
 set_light(1);
 set_heart_beat(1);
 set_short("Dragon Airway");
 set_long("This is the Dragon Airway. Type board to enter it.\n"+
 "It only costs 500 coins.\n");
 return 1;
 }
/*
query_ghost() { return 1;}
is_player() {return 1;}
*/
init() {
add_action("board_it","board");
}
board_it() {
if (this_player()->query_money() < 500 ) {
  write("You don't have enough money to board.\n");
  return 1;
  }
move_object(this_player(), "players/warlord/trans/ondrag");
write("You board the Dragon. Have a safe journey.\n");
return 1;
}
