inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("Sabre-tooth");
   set_id("Sabre-tooth");
   set_short("A Sabre-tooth");
   set_alt_name("tooth");
   set_long("A mystical Sabre-tooth. You are sure it must be a VERY powerful weapon!\n");
   set_value(5000);
   set_weight(8);
   set_type(3);
   set_hit_func(this_object());
}

weapon_hit(attacker) {
   write("*******************************************************************\n\n"
        +"You hear the roar of 1000 tigers as the Sabre-tooth dives deep into\n"
        +""+attacker->query_name()+"'s flesh!\n"
        +"*******************************************************************\n\n");
   say("You hear the roar of 1000 tigers as the Sabre-tooth dives into\n"             +""+attacker->query_name()+"'s flesh!\n");
   return 15+random(10);
}
