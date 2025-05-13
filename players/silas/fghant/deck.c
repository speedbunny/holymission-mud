

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Sightseeing Deck";
    no_castle_flag = 0;
    long_desc = 
        "You are standing on a deck which protrudes from the mountain. The bottom of\n"
        + "the chasm lies 500 meters below you, but a guard railing makes you feel safe.\n"
        + "Mountains tower above you to all sides and you have a strange feeling of peace\n"
        + "here. The reddish stone of both sides of the chasm launch themselves skywards\n"
        + "while the verdant bottom of the canyon is illuminated by the sun above. This\n"
        + "place is truly one of the most beautiful that you have ever seen.\n";
    items = ({
         "chasm","The bottom lies far below you and you can see a forest there",
         "mountains","You can make out a circle of rectangular pillars on one of them",
         "circle","The distance between you and the circle prevents you from making out any details",
         "pillars","The distance between you and the pillars prevents you from making out any details",
         "railing","It keeps people from committing suicide",
            });
    dest_dir = 
        ({
        "/players/silas/fghant/square", "south",
        });
    smell = "The fragrant smells of the forest below enter your nose.\n";
}
