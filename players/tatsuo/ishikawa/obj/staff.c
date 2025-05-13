/*coded by tatsuo for the samurai guild*/


inherit "/obj/weapon";

 reset(arg) {
 if (arg) return;

     set_name("Holy Staff");
     set_id("Holy Staff");
     set_short("A Holy Staff");
     set_alt_name("staff");
     set_long("This is the holy staff of Hachiman's high priest. With it one\n"+
              "can call down the wrath of Hachiman upon his victims head.\n"+
              "Be warned though Hachiman only honors those who use this weapon\n"+
              "for good!\n");
     set_value(5000);
     set_weight(4);
     set_type(3);
     set_class(15);
     set_hit_func(this_object());
 }

 weapon_hit(attacker) {
 write("You feel the wrath of Hachiman being called down upon\n"+
       ""+attacker->query_name()+"'s head!!!!\n");
 return 10+random(15);

 }
