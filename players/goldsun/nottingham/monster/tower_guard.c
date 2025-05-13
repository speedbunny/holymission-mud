inherit "/obj/monster";

void reset(int arg) {


    ::reset(arg);

   if (arg) return;
    set_name("guard");
    set_race("human");
    set_short("A drunk guard");
    set_long("A guard. He is very drunk.\n");
    set_level(5);
    set_al(390);
    if (random(3)<1){
     move_object(clone_object("/players/goldsun/nottingham/obj/cell_key2"),
       this_object());
    }
    set_gender(1);
    set_aggressive(0);
    set_wc(10);
    set_ac(5);
}

int query_property(string str){
 return str=="no_steal";
}
