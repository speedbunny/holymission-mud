inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("bear");
set_race("animal");
set_short("A Brown bear");
set_long("A brown medium bear.\n");
set_wc(23);
set_ac(3);
set_aggressive(0);
set_level(16);
set_size(3);
set_al(-100);
move_object(clone_object("/players/goldsun/sherwood/obj/bear_fur"),
             this_object());
command("wear fur");
}
