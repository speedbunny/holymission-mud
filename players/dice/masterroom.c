inherit "room/room";

int tick;
static string text;
reset(arg) {
    if(arg) return;
    property="no_fight";
    set_light(1);
    short_desc="Dice's workroom";
    long_desc="            \n"+
    "This is the workroom of The amazing Mastermind.\n"+
    "He pretends to be here a lot, but that's only an illusion.\n"+
    "Actually, he's mostly drinking with his mentor:\n"+
    "The coffee-addicted Dice\n(Mastermind buys, Dice drinks).\n"+
    "Feel free to enter.\nIt's quite a mess, but he is learning.\n";
    dest_dir=({"room/church","chu",
      "room/adv_guild", "advg",
      "players/dice/workroom","dice",
      "room/post", "post", });
}

init(){::init();
    say(capitalize(this_player()->query_real_name())+" has entered Masterminds workroom.\n");
}
