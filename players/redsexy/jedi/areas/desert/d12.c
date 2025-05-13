inherit "room/room";

void reset(int arg) {     
    if(!arg) {
set_light(1);

        short_desc = "Venturing over a vast landscape of desertland";     
        long_desc = "\
You are walking through what seems to be miles and miles of desert \
wasteland, the sun beating down your neck and your sense of direction \
blurred by the sameness of the area you travel.  This area spreads on \
for many miles in every direction and you think you may well be lost.  \
You cannot imagine how you ended up in such a godforsaken place, and \
long to find a refuge of some kind.\n\n";

  items = ({
            "sand", "The sand spreads on for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",
            "sun", "Two suns emit heat so powerful you are surprised you \
haven't melted",
            "refuge", "You doubt you will ever find refuge in this hellhole"
 });

  clone_list = ({1, 15, "sandperson", "/players/redsexy/jedi/monsters/sandpersonmv", 0,});
  
  dest_dir = ({
            "/players/redsexy/jedi/areas/desert/d1",  "northwest",
            "/players/redsexy/jedi/areas/desert/d2",  "north",
            "/players/redsexy/jedi/areas/desert/d3",  "northeast",
            "/players/redsexy/jedi/areas/desert/d11", "west",
            "/players/redsexy/jedi/areas/desert/d13", "east",
            "/players/redsexy/jedi/areas/desert/d22", "south",
            "/players/redsexy/jedi/areas/desert/d21", "southwest",
            "/players/redsexy/jedi/areas/desert/d23", "southeast",

        });

    }
    ::reset(arg);
    replace_program("room/room");
}


