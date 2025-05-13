#define SAY(x) tell_room(environment(),x)
inherit "obj/monster";

reset(a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("abbot Kliment");
    set_alias("abbot");
    set_alt_name("kliment");
    set_short("Abbot Kliment");
    set_long("Abbot Kliment. He is private abbot of Sheriff.\n"+
	     "He is very fat, but looks in good condition.\n");
    set_gender(1);
    set_race("monk");
    set_size(3);
    set_level(20);
    set_ac(10);
    set_wc(23);	
    add_money(100+random(500));
    move_object(clone_object("/players/goldsun/nottingham/obj/crystal_key"),this_object());
    move_object(clone_object("/players/goldsun/nottingham/obj/cloak"),this_object());
    init_command("wear cloak");
}

init(){
 ::init();
add_action("search","search");
}

int search(){
 SAY("Abbot Kliment says: Hey you! Don't search here!\n");
 return 1;
}
 
run_away(){
 write("He is very fat.\You cannot fear him.\n");
 return 1;
}

int query_property(string str){
 return str=="no_steal";
}
