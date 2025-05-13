inherit "/players/sauron/inherit/virtualMaster";

void reset(int iArg) {
    if(!iArg) {
        setAreaSize(20,20,1);
        setMap(0,"/players/sauron/area/virtual/map");
        setBorderRoom(({ 0, 0,0}),"up",
                      "/players/sauron/area/virtual/entrance");
        setBorderRoom(({19, 0,0}),"up",
                      "/players/tuppence/workroom");
        setBorderRoom(({19,10,0}),"up",
                      "/players/nae/workroom");
        setBorderRoom(({11, 0,0}),"north",
                      "/players/sauron/area/virtual/forestMaster,15,29,0");
        setBorderRoom(({17,19,0}),"south",
                      "/players/sauron/area/virtual/testMaster2,0,0,0");
    }
// Important! This must come last.
    ::reset(iArg);
}
