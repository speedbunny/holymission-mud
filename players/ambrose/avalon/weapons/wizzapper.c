inherit "obj/weapon";

reset(arg){
if(arg) return;

   set_name("Wand of Power");
   set_alt_name("wand");
   set_short("wand");
   set_long("The Wand of Power purely pulses with magic gone wild.\n");
   set_type(3);
   set_value(15000);
   set_weight(10);
   set_hit_func(this_object());
}
weapon_hit(attacker){
  write("************************************************************\n\n"
      +"Fire from the wand burns into "+attacker->query_name()+"s flesh!\n"
      +"************************************************************\n\n");
  say("You hear flesh sizzle as the wand burns into\n"
     +""+attacker->query_name()+"s skin!\n");
   return 200;
}
