/* This is a new weapon in special for too hard monsters */
int timer, counter;

short() { return "A red Striker"; }
long() { write("room/hump"->linewrap
  ("This is a new kind of weapon. You can use it along with your "+
   "standard weapon. When you are attacked by a monster type "+
   "<strike> a few times during the fight. "+
   "This weapon is of limited use.\n",78));}
init() { add_action("do_kill","strike"); }
id(str) { return str == "striker"; }
reset(arg) {
  if (arg) return;
  counter = 0;
}


do_kill(str) {
  object victim;
  string player_name, victim_name;
  int how_hard;
  victim = this_player()->query_attack();
  if (!victim) { write("You are not hunted by anyone.\n"); return 1; }
  if (timer) { write("You can't be that fast.\n"); return 1; }
  if (this_player() != environment(this_object())) return 0;
  player_name= this_player()->query_name();
  say(player_name + " strikes "+victim->query_name()+" to hash.\n");
  write("You are striking "+victim->query_name()+" extremely hard.\n");
  call_other(victim,"hit_player",15);
  counter = counter+1;
  if (counter >= 20) {
    write("Suddenly your striker gets hot and turns to ashes.\n");
    destruct(this_object());
    return 1;
  }
  timer++;
  call_out("strike_again",1);
  return 1;
}

strike_again() {
 timer=0;
 return 1;
 }
query_weight() { return 1; }
get() { return 1; }
query_value() { return 200; }
