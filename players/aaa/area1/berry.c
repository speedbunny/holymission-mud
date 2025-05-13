/* Completed 14.01.1995 */

inherit "/obj/food";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("blackberry");
    set_alias("berry");
    set_short("a blackberry");
    set_long("A blackberry, usual in forests (at least, a smaller version "+
             "of this).\nLooks delicious!\n");
    set_value(5);
    set_heal_amount(5);
    set_eater_mess("Yum-yum-yum... that was good!\n");
    set_eating_mess(" devours a blackberry.\n");
    set_strength(3);
    set_weight(0);
}
