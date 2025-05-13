inherit "/obj/monster";

void reset(int arg) {


    ::reset(arg);

   if (arg) return;
    set_name("guard");
    set_race("human");
    set_short("A sleeping guard");
    set_long("A guard. He sleeps.\n");
    set_level(1);
    set_al(590);
    set_gender(1);
    set_hp(1);
    set_aggressive(0);
    set_wc(50);
    if (random(3)<1){
     move_object(clone_object("/players/goldsun/nottingham/obj/cell_key2"),
       this_object());
    }

}

int query_property(string str){
 return str=="no_steal";
}
