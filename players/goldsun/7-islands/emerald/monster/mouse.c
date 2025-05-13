inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("mouse");
set_race("animal");
set_short("A white mouse");
set_long("A small white mouse.\n");
set_level(2);
set_gender(2);
set_wc(5);
set_ac(1);
set_size(2); 
move_object(clone_object("players/goldsun/7-islands/emerald/obj/tooth"),
   this_object());
}

