inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("mother");
    set_race("human");
    set_level(30);
    set_wc(1);
    set_ac(10);
    set_al(1000);
    add_money(1000);
    set_short("A small child");
    set_long(
       "A tall beautful woman with long flowing hair and a huge heart.\n" +
    "She loves her children with all her heart, and will defend them to\n" +
    "her last dying breath.\n"
    );
}
