inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("club");
 set_class(20);
 set_short("A steel long club");
 set_long("A steel long club.\n");
 set_value(4000);
 set_weight(6);
}
