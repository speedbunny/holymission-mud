inherit "obj/weapon";
reset(arg){
::reset(arg);
if(arg) return;
set_name("axe");
set_short("A evil battleaxe");
set_alias("battleaxe");
set_class(17);
set_weight(2);
set_value(300);
set_long("A evil battleaxe usualy wielded by a great demon\n");
}
