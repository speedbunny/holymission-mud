/* #######################################################################

                  T H E  A V E N G E R  (c) Whisky

   weapon class will be:(2+4+6+8+10+12+14+16+18+50)/11+9=21,7273 = ok 
   ####################################################################### */

#define T this_player()->query_name()
inherit "/obj/weapon";

reset(arg) {
if (arg) return;

  set_name("avenger");
  set_alias("bloodstained avenger");
  set_short("The bloodstained Avenger");
  set_long("A sharp softly glowing sword, with some strange magical power.\n");
  set_class(8);
  set_weight(3);
  set_value(8000);
  set_hit_func(this_object());
 }

weapon_hit(attacker) {

int i;
i = random(11);

 if (i==0) {
  write("You strike "+attacker->query_name()+" like a novice.\n");
 say(T+" strikes "+attacker->query_name()+" like a novice.\n");
  return 0; }

 if(i==1) {
  write("You slash "+attacker->query_name()+" like a maverick.\n");
  say(T+" slashes "+attacker->query_name()+" like a maverick.\n");
  return 2; }

 if (i==2) {
  write("You shave "+attacker->query_name()+" to julienne fries.\n");
  say(T+" shaves "+attacker->query_name()+" to julienne fries.\n");
  return 4; }

  if (i==3) {
  write("You chop "+attacker->query_name()+" into tiny pieces.\n");
  say(T+" chops "+attacker->query_name()+" into tiny pieces.\n");
  return 6; }

 if (i==4) {
  write("You cut big pieces of bloody flesh from "+attacker->query_name()+"'s corpse.\n");
  say(T+" cuts big pieces of bloody flesh from "+attacker->query_name()+"'s corpse.\n");
 return 8; }

  if (i==5) {
  write("You granulate "+attacker->query_name()+" to bloody jam.\n");
  say(T+" granulates "+attacker->query_name()+" to bloody jam.\n");
  return 10; }

  if (i==6) {
    write("You grind "+attacker->query_name()+" to hash.\n");
    say(T+" grinds "+attacker->query_name()+" to hash.\n");
   return 12; }

  if (i==7) {
  write("You atomize "+attacker->query_name()+" into small fragments.\n");
  say(T+" atomizes "+attacker->query_name()+" into small fragments.\n");
  return 14; }

   if (i==8) {
    write("You do an awful damage to "+attacker->query_name()+".\n");
  say(T+" does an awful damage to "+attacker->query_name()+".\n");
   return 16; }
   if (i==9) {
  write("You grate "+attacker->query_name()+" to death.\n");
  say(T+" grates "+attacker->query_name()+" to death.\n");
   return 18; }

  if (i==10) {
   write("A red magic beam flashes out from your sword\nand pulverizes "+attacker->query_name()+" to ashes.\n");
   say("A red magic beam flashes out from "+T+" sword\nand pulverizes "+attacker->query_name()+" to ashes.\n");
    return 20; }
 return 1;

}

