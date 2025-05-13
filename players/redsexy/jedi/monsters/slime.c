inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
        set_name("slime");
        set_race("ooze");
        set_short("Festering green slime");
        set_long("This green slime oozes all over you...\n");
        set_alias("slime");
        set_level(18);
        set_al(-23);
        set_ac(8);
        set_wc(19);
        add_money(500);
        set_aggressive(1);

    }
}
