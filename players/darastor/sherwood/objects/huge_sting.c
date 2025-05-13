inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("huge sting");
 set_alias("sting");
 set_short("A huge sting");
 set_long("This is the huge sting from the killer wasp.\n");
 set_value(1000);
 set_weight(2);
 set_hit_func(this_object());
}
weapon_hit(attacker){
   return 4+random(10);
}
