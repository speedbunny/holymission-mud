inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("wolf");
set_race("animal");
set_short("A black wolf");
set_long("You see very hungry black wolf.\n");
set_wc(12);
set_ac(1);
set_hp(200);
set_aggressive(0);
set_level(3);
set_size(2);
move_object(clone_object("/players/goldsun/sherwood/obj/wolf_fur"),
             this_object());
command("wear fur");
}
