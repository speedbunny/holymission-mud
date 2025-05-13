inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
        set_name("mould");
        set_race("ooze");
        set_short("This mould is formed from the pollution in the water");
        set_long("The mould smells like dry rot, and clings on to your body.\n");
        set_alias("mould");
        set_level(1);
        set_al(2000);
        set_ac(1);
        set_wc(1);
        set_aggressive(0);

    }
}
