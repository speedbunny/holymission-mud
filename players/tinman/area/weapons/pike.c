inherit"obj/weapon";

reset(arg){
::reset(arg);
if (arg) return;
set_name("pike");
set_alt_name("spear");
set_short("Long pike");
set_long("Long spears made for attacks from horseback. It has some red fur"+
" attached to the spearend\n");
set_class(12);
set_two_handed();
set_weight(3);
set_value(1000);
}
