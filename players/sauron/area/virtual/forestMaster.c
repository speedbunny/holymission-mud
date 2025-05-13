inherit "/players/sauron/inherit/virtualMaster";

void reset(int iArg) {
    if(!iArg) {
        setAreaSize(30,30,1);
        setMap(0,"/players/sauron/area/virtual/forestMap");
        setBorderRoom(({ 15, 29, 0}),"south",
                      "/players/sauron/area/virtual/testMaster,11,0,0");
    }
// Important! This must come last.
    ::reset(iArg);
}
