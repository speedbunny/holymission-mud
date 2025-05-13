/*coded for ishikawa by gandalf*/
inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("Serpent Claw");
   set_id("Serpent Claw");
   set_short("A Serpent Claw");
   set_alt_name("claw");
    set_long("The ancient Claw of the Serpent King of Shou-Ti.\n"+
            "This seems to be the most vicious weapon you have\n"+
            "ever seen. You feel that this weapon could do\n"+
            "massive amounts of damage.\n");
   set_value(5000);
   set_weight(8);
   set_type(3);
   set_class(20);
   set_hit_func(this_object());
}

weapon_hit(attacker) {
   write("*******************************************************************\n\n"
        +"You feel the fire of the Serpent King as the Dragon claw burns\n"
        +""+attacker->query_name()+"'s flesh!\n"
        +"*******************************************************************\n\n");
   say("You feel the fire of the Serpent King as the Dragon claw burns the\n"
       +""+attacker->query_name()+"'s flesh!\n");
   return 20+random(30);
}
