inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
        set_name("mould");
        set_race("ooze");
        set_short("Mould");
        set_long("This mould is formed from the pollution in the water.\n" +
                 "The mould smells like dry rot, and clings on to your body.\n");
        set_alias("mould");
        set_level(13);
        set_al(-23);
        set_ac(8);
        set_wc(10);
        add_money(100);
        set_aggressive(1);

    }
}
