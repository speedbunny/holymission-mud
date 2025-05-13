inherit "/room/std_bank";

void reset(int flag) {

    ::reset(flag);
    if(flag) return;

    set_light(1);
    short_desc="Monk Guild Bank";
    long_desc=
        "You enter a room that has a long counter and some "+
        "notices on the walls. There is an old monk sitting "+
        "behind the counter on a stool. He appears to be reading "+
        "ancient texts of some sort. You see a safe on the "+
        "far wall and read the sign above the counter. It "+
        "will tell you what to do here. The monk peers at you "+
        "and welcomes you to the monk's bank.\n";

    dest_dir= ({
         "/players/misticalla/guild/rooms/courtyard3","south",
              });
    items = ({
              "sign","There is something written on it",
              "counter","Behind the counter Goldfinger counts the coins",
              "walls","They are plain and made of mahogany",
              "goldfinger","He is grinning at you, rubbing his hands",
            });
    clerk = "Goldfinger";
    taxes = 0;
    save_file = "/players/misticalla/guild/rooms/newbank";
    load_info();

// If you wanted taxes in your bank then add the following line.
//  ::daily_taxes();

}

