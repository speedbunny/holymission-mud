inherit "obj/weapon";
reset(arg) {
if (arg) return;
   set_name("Szabolcs's Excalibur");
   set_id("sword");
   set_short("excalibur");
   set_alt_name("sword");
   set_alias("excalibur");
   set_long("Very famous ancient sword.\n"
          +"It is SZABOLCS's personal weapon.\n");
   set_light(2);
   set_value(4000);
   set_weight(1);
   set_type(3);
   set_hit_func(this_object());
}
weapon_hit(attacker)
{
   write("You hit " +attacker->query_name()+ "with its blade.\n"
        +"The Excalibur Crushes your enemy.\n");
   return 50000;
}
