inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sword");
 set_class(20);
 set_type(3);
 set_short("A steel Black Longsword");
 set_long("A steel Black Longsword with the Nottingham coat of arms engraved on its blade.\n");
 set_value(7980);
 set_weight(5);
}
