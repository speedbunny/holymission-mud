inherit "obj/weapon";

reset(arg){
if(arg) return;

  set_name("Unicorn-horn");
  set_id("Unicorn-Horn");
  set_short("Unicorn-Horn");
  set_alt_name("horn");
  set_long("The powerful horn of the mystical Unicorn.  It exudes power!\n");
  set_value(5000);
   set_type(3);
   set_weight(8);
   set_hit_func(this_object());
}
weapon_hit(attacker){
  write("************************************************************\n\n"
      +"You hear shrieks of agony as "+attacker->query_name()+" is gored!\n"
      +"************************************************************\n\n");
  say("You hear shrieks of agony as\n"
     +""+attacker->query_name()+" is gored!\n");
   return 35;
}
