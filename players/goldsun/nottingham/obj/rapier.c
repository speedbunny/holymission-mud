inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sword");
 set_type(3);
 set_class(20);
 set_short("A steel rapier");
 set_long("A steel rapier with the Nottingham coat of arms engraved on its blade.\n");
 set_value(580);
 set_hit_func(this_object());
 set_weight(2);
}

weapon_hit(attacker){
 return 24+random(15);
}

drop(){
 destruct(this_object());
 write("Sword disappears in the fog.\n");
 return 1;
}
