inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("trout");
set_race("fish");
set_short("A trout");
set_long("A river trout.\n");
set_level(9);
set_wc(10);
set_ac(5);
set_size(2);
set_al(-50);
move_object(clone_object("players/goldsun/7-islands/sapphire/obj/trout_bone"),
             this_object());
}

