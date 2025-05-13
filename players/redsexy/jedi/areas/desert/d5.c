inherit "room/room";

void reset(int arg) {     
    if(!arg) {
        set_light(1);     

        short_desc = "Mos Eisley Desert";     
        long_desc = "\
You have arrived at a busy commuter port in the lands of Mos Eisley. A few \
creatures busy themselves preparing the few crafts docked here for \
passage, and they look at you suspiciously as you explore this area. \
The waves from the sea are vicious, lashing at the dock and occaisionally \
splashing at your feet. A nagging thought at the back of your mind keeps \
telling you to be careful on your travels through this land.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/desert/d4",  "west",
            "/players/redsexy/jedi/areas/desert/d16", "southeast",
        });

        items = ({
            "port", "This seems to be a kind of dock for crafts making \
passage to this land",            
            "waves", "These waves powerful and dangerous.", 
            "crafts", "A few battered rafts and boats which look like \
they will sink at any second",
            "dock", "This old wooden dock is covered in wet sand.",
            "wind", "Harsh and cold, the wind howls across the sea.",
            "sea", "The sea leaves you spellbound. Never before has nature \
been so powerful",
            "dune sea", "The sea leaves you spellbound. Never before has \
nature been so powerful",
            "spray", "The spray tastes salty against your lips, and \
dampens your hair slightly",
            "craft", "A few old boats, most of which are in a state of \
disrepair",
            "creatures", "They have a look of fear in their eyes",
            "sand", "The sand here is wet",
            "feet", "From the wise Haplo and Sarge: They're your feet! \
Know them! Use them!",
            "desert", "Miles of sand make this island look the same all \
over",
        });

        clone_list = ({
            1, 1, "jawa", "/players/redsexy/jedi/monsters/jawa", 0,
            2, 3, "weequay", "/players/redsexy/jedi/monsters/weequay", 0,
        });
    }
    ::reset(arg);
    replace_program("room/room");
}
