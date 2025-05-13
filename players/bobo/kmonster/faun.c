inherit "obj/monster";

object stick;

reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_name("faun");
    set_race("faun");
    set_level(10);
    set_size(3);
    set_hp(120);
    set_wc(5);
    set_ac(3);
    set_al(100);
    set_short("A faun");
    set_long("A faun from the village.\n");
    set_male();
    set_move_at_reset();

    if(!stick) {
        stick=clone_object("/obj/treasure");
        stick->set_id("stick");
        stick->set_short("A stick");
        stick->set_long("Just a wooden stick.\n");
        stick->set_value(1000);
        stick->set_weight(1);
        move_object(stick,this_object());
    }
}

