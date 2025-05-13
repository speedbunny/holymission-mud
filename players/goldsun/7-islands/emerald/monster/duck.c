inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("mother duck");
set_alias("duck");
set_race("animal");
set_short("A Mother duck");
set_long("A small mother of duckling.\nShe is looking for her small duckling.\n");
set_level(3);
set_gender(2);
set_wc(9);
set_ac(1);
set_size(2); 
set_aggressive(1);         
move_object(clone_object("players/goldsun/7-islands/emerald/obj/feathers"),
   this_object());
}

