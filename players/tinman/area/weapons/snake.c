inherit"obj/weapon";

reset(arg){
::reset(arg);
if (arg) return;
set_name("snake spear");
set_alt_name("spear");
set_short("Snake Spear of Zhang Fei");
set_long("This is the Snake spear of Zhang Fei. It's a long spear with a\n"+
"swigglly metal blade. the blade looks like the tongue of a snake indeed.\n");
set_class(19);
set_two_handed();
set_type(3);
set_weight(4);
set_value(10000);
}
