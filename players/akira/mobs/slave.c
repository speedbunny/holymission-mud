inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Test Subject");
    set_level(5);
    set_al(-300);
    set_ac(12);
    set_aggressive(0);
    set_wc(10);
    set_race("human");
    set_short("Test Subject");
    set_long("This is a test subject used by the students at the Tower.\n"+
             "He looks to be in very good physical shape, but his face\n"+
             "tells you a differnt tail. His eys are that of a crushed\n"+
             "man. For some reason he can still talk, unlike the others.\n");
    load_chat(15,({
        "Test Subject crys: God Help Me!\n",
        "Test Subject screems: Get them out of my mind!\n",
        "Test Subject says: If you can't free me, kill me!\n",
        "The Test Subject grabs the sides of his head and screems!\n",
        "Test Subject screems: They are rippimg my mind appart!\n"
                 }));
    load_a_chat(15,({
        "Test Subject crys: Make them stop!\n",
        "Test Subject crys: KILL ME!\n",
        "The Test Subject begins to cry.\n"
                 }));
}
