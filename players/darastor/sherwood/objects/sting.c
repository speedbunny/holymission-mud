inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("Sting");
 set_alias("sting");
 set_class(5);
 set_short("A sting");
 set_long("A brown wasp or bee sting.\n");
 set_value(200);
 set_weight(1);
}
