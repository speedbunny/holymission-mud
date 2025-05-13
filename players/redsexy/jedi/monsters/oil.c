inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
        set_name("oil");
        set_race("ooze");
        set_short("Greasy Oil");
        set_long("The oil is greasy and covers you with dirt.\n");
        set_alias("oil");
        set_level(20);
        set_al(-23);
        set_ac(10);
        set_wc(16);
        add_money(100);
        set_aggressive(1);

    }
}
