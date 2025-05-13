inherit "/obj/weapon";

#define nonplayers;

int charges;

void reset(int flag){

    if (flag) return;

    charges =(5 + random(20));
    set_name("earthquake mace");
    set_alias("mace");
    set_type(1);
    set_class(9);
    set_short("a shit");
    set_long(
             "The earthquake mace is a weapon made out of a wooden handle\n "+
             "and a glowing steel ball on the end. The power can be felt\n "+
             "flowing through the handle. With 'use mace' you can sometimes\n "+
             "cast earthquakes with it.\n");
    set_value(300);
    set_weight(2);
    set_value(500);

}

int init() {
    add_action("_use", "use");
    ::init();
}


int _use(string str) {

    string target;
    object player, room;

    if (!str || (sscanf(str, "mace on %s",target) != 1))
        return 0;
    if (!query_wielded()) {
        notify_fail("You have to wield the mace before you can use it.\n");
        return 0;
    }
    if (!charges) {
        notify_fail("Your mace seems powerless, you have to wait a while.\n");
        return 0;
    }

    player = find_living(target);
    room = environment(this_player());

    if (!player || (environment(player) != room)) {
        notify_fail("Nothing by that name here.\n");
        return 0;
    }


    say("The earth trembles and shivers !\n",this_player());
    write("The earth trembles and shivers !\n");
    charges--;
    write(player->query_name()+" falls down on "+
          player->query_possessive()+" butt !\n");
    tell_object(player,"You get your ass kicked!\n");
    player->attack_object(this_player());
    player->hit_player( 20 + random(30),5);
    return 1;
}
