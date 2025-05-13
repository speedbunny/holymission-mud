/* Completed 14.01.1995 */

inherit "/obj/poison";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("mushroom");
    set_short("a mushroom");
    set_long("A strange-looking mushroom. Why, it is totally blue, dark blue. "+
             "Looks delicious!\n");
    set_value(5);
    set_strength(30);
    set_eater_mess("Yum-yum-yum... that was good!\n\n\nOh, yuyuyuy...!\n"+
                   "You got a terrible stomach-ache !\n");
    set_eating_mess(" devours a mushroom.\n");
    set_weight(0);
}
