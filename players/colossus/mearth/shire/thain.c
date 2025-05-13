inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("thain");
    set_race("hobbit");
    set_level(10);
    set_short("The thain of the shire");
    set_long("This is the thain of the shire. His job is to keep peace and order\n"+
      "in the Shire. He is a hobbit who's a veteran of many battles.\n");
    set_al(250);
    set_wc(15);
    set_ac(5);
    add_money(650);
    move_object(clone_object("/players/colossus/mearth/shire/girth"), this_object());
init_command("wear belt");
}
