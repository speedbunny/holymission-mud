inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sword");
 set_class(8);
 set_short("A steel long sword");
 set_long("A steel long sword with the Nottingham coat of arms engraved on its blade.\n");
 set_value(580);
 set_weight(2);
}
