inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sword");
 set_class(14);
 set_type(3);
 set_short("A steel Longsword");
 set_long("A steel Longsword with the Nottingham coat of arms engraved on its blade.\n");
 set_value(3000);
 set_weight(4);
}
