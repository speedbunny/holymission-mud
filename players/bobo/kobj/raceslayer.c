inherit "obj/weapon";
 
string race;
 
reset(arg) {
 race="orc";
 set_name("slayer");
 set_alias(race+"slayer");
 set_class(2);
 set_weight(3);
 set_value(1000);
 set_short("An "+capitalize(race)+"-slayer");
 set_long("This is an truely lethal blade for all "+race+"s.\n");
 set_hit_func(this_object());
}
 
init() {
::init();
  if(this_player()->query_wizard())
    add_action("setrace","setrace");
}
 
weapon_hit(attacker)   {
 if (attacker->query_race()==race) {
   return 50;
 }
 write("The blade doesn't work on "+attacker->query_race()+"s.\n");
 return 0;
}
 
setrace(str) {
  race=str;
  set_short("An "+capitalize(race)+"-slayer");
  set_long("This is an truely lethal blade for all "+race+"s.\n");
  set_alias(race+"slayer");
  write("Race now on :"+str+"\n");
  return 1;
}
 
