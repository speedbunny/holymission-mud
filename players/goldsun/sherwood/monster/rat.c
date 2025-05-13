inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("rat");
set_race("animal");
set_short("A Brown rat");
set_long("A brown small rat.\n");
set_wc(12);
set_no_steal();
set_ac(3);
set_hp(100);
set_al(-10);
set_aggressive(0);
set_level(3);
set_size(1);
move_object(clone_object("/players/goldsun/sherwood/obj/rat_fur"),
        this_object());
move_object(clone_object("/players/goldsun/sherwood/quest/silver_tooth"),
        this_object());
command("wear fur");
}

int query_property(string str){
 return str=="no_steal";
}
