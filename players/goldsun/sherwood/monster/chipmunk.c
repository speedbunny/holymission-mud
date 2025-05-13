inherit "/obj/monster";
 reset(arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("chipmunk");
set_race("animal");
set_short("A Red Chipmunk");
set_long("A Red Chipmunk.");
set_wc(2);
set_ac(2);
set_aggressive(0);
set_al(70);
set_level(3);
set_size(1);
move_object(clone_object("/players/goldsun/sherwood/obj/hnut"),
             this_object());
move_object(clone_object("/players/goldsun/sherwood/obj/chfur"),
             this_object());
command("wear fur");
}
