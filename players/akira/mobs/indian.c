inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("indian");
set_short("Indian Warrior");
set_alias("indian");
set_long("This is an idian brave. He has colored his skin with\n"+
         "war paints. There is a fire in his eyes, and rage in\n"+
         "his actions.\n");
set_level(10);
set_ac(5);
set_wc(7);
set_aggressive(1);
}
