inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("child");
    set_race("human");
    set_level(15);
    set_wc(1);
    set_ac(1);
    set_al(1000);
    add_money(1000);
    set_ep(8000);
    set_short("A small child");
    set_long(
       "A small cute helpless child. He has big innocent eyes and the\n"
    "cutest face you have ever seen!\n"
    );
}
