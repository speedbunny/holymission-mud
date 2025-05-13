/* Completed 26.02.1995 */

inherit "/obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("turtle");
    set_alias("aaa-turtle");
    set_short("A giant turtle");
    set_long("Except its size, this turtle looks usual. But, to say the "+
             "truth, the magic that gave him this size, alse provided him "+
             "with remarkable constitution and\nstrengthened his armour.\n"); 
    set_gender(1);   
    set_al(0);
    set_level(5);
    set_race("turtle");
    set_aggressive(1);
    set_ac(3);
    set_wc(0);
    set_hp(1000);
}     
