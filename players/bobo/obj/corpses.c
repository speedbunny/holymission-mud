inherit "/obj/treasure";
reset (arg){
::reset(arg);
if(!arg) {
set_name("corpses");
set_short("corpses");
set_long("Many dismembered corpses lie scattered about.\n");
set_value(0);
set_weight(150);
}
}
