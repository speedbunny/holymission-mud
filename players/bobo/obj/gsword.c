inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(!arg){
set_name("sword");
set_short("Gladiator sword");
set_long("A sharp looking gladiator sword with a golden handle.\n");
set_class(4);
set_weight(2);
set_value(150);
}
}
