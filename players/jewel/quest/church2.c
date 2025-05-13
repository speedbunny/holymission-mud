inherit "room/room";
int vamp,coff;

reset(arg) {
    if(!present("vampire",this_object())) vamp=1;
    if (arg) return;

    short_desc="A room with a coffin.";
    long_desc=
        "You are in the cellar of the church, in front of you there is a\n"+
        "large black coffin\n";
    items=({ "coffin","The graveyard masters bed, made of solid wood" });
dest_dir = ({ "/players/jewel/quest/church1","up"});
}

init() {
    ::init();
    if(vamp && (!present("vampire",environment(this_player())))) {
        vamp=0;
        coff=1;
        call_out("vamp1",5);
    }
    add_action("enter","enter");
}
 
vamp1() {
    tell_room("/players/jewel/quest/church2", "CREEEEEEEEEEEEEEEEEK .......\n");
    call_out("vamp2",5);
}

vamp2() {
    tell_room("/players/jewel/quest/church2",
        "You notice the lid of the coffin slowly opens.\n");
    call_out("vamp3",5);
}

vamp3() {
    object vam,cl;

    tell_room("/players/jewel/quest/church2",
        "A friendly looking old man steps out of the coffin.\n");
    move_object(vam=clone_object("/players/jewel/quest/vampire1"),this_object());
    vam->add_money(1000+random(2000));
    cl=clone_object("/obj/armour");
    cl->set_id("cloak");
    cl->set_short("A black cloak");
    cl->set_long("A vampirers long, black cloak.\n");
    cl->set_value(500);
    cl->set_weight(1);
    cl->set_ac(1);
    cl->set_alias("black cloak");
    cl->set_type("cloak");
    cl->set_arm_light(1);
    move_object(cl,vam);
    coff=0;
}

enter(arg) {
    if(arg=="coffin") {
        if(vamp || coff || present("vampire")) {
            write("You can't do that now.\n");
            return 1;
        }
        write("As you enter the coffin, a hidden trapdoor opens,"+
              " and throughs\nyou in a strange magical field.\n");
        say(this_player()->query_name()+
              " steps into the coffin and disappears.\n");
        move_object(this_player(),"players/jewel/quest/darkl1");
        return 1;
    } else {
        notify_fail("Enter what ?\n");
    }
}
