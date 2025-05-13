inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="In the Deep forest, next to a small path";

    long_desc=
              "You are standing in the deep forest. Dark trees surround "+
              "you and you get the bad feeling as they are watching you. "+
              "But to the south the forest opens into a small light path "+
              "leading to a big, picturesque 'castle' on the top of a hill.\n";

    items = ({
              "forest","The dark forest surrounds you, better you take the\n"+
                       "path to the south",
              "path","A small, light path leading out of the dark forest",
              "castle","A big, picturesque castle, with strong stone walls\n"+
                       "and two watchtowers",    
              "hill","You see a big grassy hill, the path is winding itself\n"+
                     "in circles up the hill to a big castle",
            }); 
    dest_dir= ({
                "/room/forest4", "west",
                "/players/padrone/outside/path1","south",
              });

    ::reset(arg);
    replace_program("room/room");
}
