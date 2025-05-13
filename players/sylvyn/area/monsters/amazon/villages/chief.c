inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("guard");
    set_race("human");
    set_level(50);
    set_wc(15);
    set_ac(25);
    set_al(-500);
    add_money(2000);
    set_short("A guard.");
    set_long(
       "A tall well built guard. He towers over you and eyes you\n" +
    "carefully, then tightens the grip on his spear.\n" +
    );
}
