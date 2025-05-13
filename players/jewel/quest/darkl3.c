inherit "room/room";

reset(arg) {
    if(!present("priest")) {
        move_object(clone_object("players/jewel/quest/priest"),this_object());
    }

    if (arg) return;

    set_light(1);
    short_desc="The dark vally";
    long_desc=
        ("A dark valley in the dark mountains, there is no way to climb them\n"+
         "You notice an old but strangly clean altar.\n");
    items=({
        "mountain","A very steep and nasty looking mountain, too high"+
                   " for you\nto climb",
        "vally","The dark vally it dose not look like a nice"+
                " camping place here",
        "altar","A strangly clean, small shrine, used to direct bids to the "+
                "good gods",
          });
    dest_dir=({ "/players/jewel/quest/darkl2","south" });
}

init() {
    ::init();
    add_action("sacr","sacrifice");
}

sacr(arg) {
int cn,cost;
object o;

    notify_fail("How much coins ?\n");
    if(!arg) return 0;
    if(!intp(arg)) {
        if(sscanf(arg,"%d coins",cn)!=1) return 0;
    } else cn=arg;
    if(this_player()->query_money()<cn) {
        write("You have not that much money.\n");
        return 1;
    }

    cost=-(this_player()->query_alignment()-1000)*10;
    if(cost<1) cost=1;
    this_player()->add_money(-cn);
    if(cn<cost) {
        write("The good gods are not satisfied.\n");
    } else {
        write("As you sacrifice the money, an item appears on the altar.\n");
        say("As "+this_player()->query_name()+" sacrifice some money,\n"+
            " an item appears.\n");
        move_object(o=clone_object("obj/thing"),this_object());
        o->set_name("holy water");
        o->set_alias("bottle");
        o->set_alt_name("water");
        o->set_short("a bottle of holy water");
        o->set_long("A little bottle containing some holy water.\n");
        o->set_weight(1);
        o->set_value(500);
    }
    return 1;
}
