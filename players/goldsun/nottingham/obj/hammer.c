inherit "obj/weapon";
reset(arg){
 ::reset(arg);

 if (arg) return;
 set_name("hammer");
 set_class(18);
 set_short("A steel heavy smith hammer");
 set_long("A steel heavy smith hammer. It looks very old.\n");
 set_value(17800);
 set_weight(5);
}
