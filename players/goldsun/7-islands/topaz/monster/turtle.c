inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("turtle");
set_race("animal");
set_short("A sea turtle");
set_long("A sea turtle. She is medium size with gray turtle shell.\n");
set_level(20);
set_wc(18);
set_ac(13);
set_size(3);
set_gender(2);
set_al(-10);
move_object(clone_object("players/goldsun/7-islands/topaz/obj/shell"),
              this_object());     
}

