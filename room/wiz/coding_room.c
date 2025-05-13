inherit "/room/room";

#define TP this_player()

int read(string sStr) {
    switch(sStr) {
        case "sign":
            write("\
You see a big sign with a lot information.\n\
The sign gives you information about following topics:\n\
\n\
1.) editor       2.) monsters            3.) armour\n\
4.) weapons      5.) food                6.) drinks\n\
7.) rooms        8.) containers          9.) examples\n\
\n\
Just type 'read <number>' to get the information.\n");
            break;
        case "1":
            write("General information about the editor.\n\n");
            TP->more("/doc/build/ed1");
            break;
        case "2":
            write("General information about monsters.\n\n");
            TP->more("/doc/build/monster");
            break;
        case "3":
            write("General information about armour.\n\n");
            TP->more("/doc/build/armour"); 
            break;
        case "4":
            write("General information about weapons.\n\n");
            TP->more("/doc/build/weapon"); 
            break;
        case "5":
            write("General information about food.\n\n");
            TP->more("/doc/build/food"); 
            break;
        case "6":
            write("General information about drinks.\n\n");
            TP->more("/doc/build/drinks"); 
            break;
        case "7":
            write("General information about rooms.\n\n");
            TP->more("/doc/build/rooms"); 
            break;
        case "8":
            write("General information about containers.\n\n");
            TP->more("/doc/build/container"); 
            break;
        case "9":
            write("\
You can read these examples:\n\
\n\
a) basic room     b) room with monster    c) room with well-equipped monster\n\
d) room with monster with special weapon  e) room with food and drink etc\n\
f) more complex room (search command!)    g) room with a door and key\n\
h) simple bar     i) simple shop          j) clone_list/replace_program xmp\n");
            break;
        case "a":
            TP->more("/doc/examples/exa1.c");
            break;
        case "b":
            TP->more("/doc/examples/exa2.c");
            break;
        case "c":
            TP->more("/doc/examples/exa3.c");
            break;
        case "d":
            TP->more("/doc/examples/exa4.c");
            break;
        case "e":
            TP->more("/doc/examples/exa5.c");
            break;
        case "f":
            TP->more("/doc/examples/exa6.c");
            break;
        case "g":
            TP->more("/doc/examples/exa7.c");
            break;
        case "h":
            TP->more("/doc/examples/exa8.c");
            break;
        case "i":
            TP->more("/doc/examples/exa9.c");
            break;
        case "j":
            TP->more("/doc/examples/exa10.c");
            break;
        default:
            write("Sorry, that didn't work. Try reading the sign for \
more information.\n");
            break;
    }
    return 1;
}
   
void reset(int iArg) {
    ::reset(iArg);
    if(!iArg) {
        set_light(1);

        short_desc = "The coding room";
        long_desc = "This is the coding room of Holy Mission. It's a room \
where not so experienced wizards can study how to make items, rooms and \
livings. There is an information sign hanging on the wall. There is a \
room to discuss guild problems to the north.\n";

        dest_dir = ({
            "/room/wiz/general",              "down",
            "/room/wiz/illegal",              "up",
            "/room/wiz/guild",                "north",
            "/players/uglymouth/guilds/hall", "east",
        }); 

        items = ({
            "wall",  "You see a wooden wall",
             "sign", "You see a big sign, just read it to get more \
information"
        });

        property = ({
            "no_fight",
            "no_sneak",   
            "no_steal",   
            "no_teleport",
        });
    }
}

void init() {
    if(!this_player()->query_immortal() || !interactive(this_player())) {
        write("You feel dizzy and fall down the stairs!\n");
        this_player()->move_player("down#/room/wiz/general");
        return;
    }
    else {
        ::init();
        add_action("read","read");
    }
}
