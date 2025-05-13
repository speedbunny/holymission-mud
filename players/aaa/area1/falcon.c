/* Completed 15.01.1995 */

inherit "/obj/monster";

void reset(int arg) {
    string str;
    string str2;
    ::reset(arg);
    if(arg) return;
    str="Falcon says: whee... whee... whee...\n";
    str2="Falcon says: I will protect my egg, you killer!\n";
    set_name("falcon");
    set_short("A falcon");
    set_long("A giant falcon, protecting her nest.\n");
    set_gender(2);
    load_chat(15,({str,str}));   
    load_a_chat(30,({str2,str2}));        
    set_al(-50);
    set_level(8);
    set_race("bird");
    set_aggressive(0);
    set_dead_ob(this_object());
}

int monster_died(object ob) {
    object ob2;
    ob2=clone_object("/players/aaa/area1/egg.c");
    move_object(ob2,environment(this_object()));   
    return 0;
}     
