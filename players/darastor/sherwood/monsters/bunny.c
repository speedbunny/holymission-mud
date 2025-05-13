inherit "/obj/monster";
reset(arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("bunny");
set_race("animal");
set_short("A little bunny");
set_long("A little bunny.\n"
         +"It jumps around you.\n");
set_wc(2);
set_ac(1);
set_aggressive(0);
set_al(100);
set_level(2);
set_size(1);
move_object(clone_object("/players/goldsun/sherwood/obj/bunny_fur"),
             this_object());
command("wear fur");
}

query_plural(){
 return "bunnies";
}

