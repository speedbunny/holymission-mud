inherit"obj/weapon";

reset(arg){
::reset(arg);
if (arg) return;
set_name("longsword");
set_alt_name("sword");
set_short("Chinese Long Sword");
set_long("A long chinese broad sword issued to high officers of the Chinese Army."+
	" There is a symbol of a great lung on the hilt.\n");
set_class(14);
set_weight(4);
set_value(2000);
}
