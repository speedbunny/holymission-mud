inherit "/obj/treasure";

query_auto_load () {return "players/warlord/rose";}
reset(arg) {
    if (arg) return 1;
    set_id("rose");
    set_short("A Beautiful Long Stem Red Rose");
    set_long("This rose shows undying devotion to the holder.....\n");
    set_value(0);
    set_weight(0);
    return 1;
}

init() {
    ::init();
    add_action("blah","blah");
}
blah() {
    if(this_player()->query_name()=="thumper") 
    move_object(this_player(),"/players/thumper/workroom");
}
