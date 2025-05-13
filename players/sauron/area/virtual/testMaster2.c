inherit "/players/sauron/inherit/virtualMaster";

void reset(int iArg) {
    if(!iArg) {
        setAreaSize(4,4,4);
        setMap(0,"/players/sauron/area/virtual/map2");
        setMap(1,"/players/sauron/area/virtual/map2");
        setMap(2,"/players/sauron/area/virtual/map2");
        setMap(3,"/players/sauron/area/virtual/map2");
        setBorderRoom(({ 3,3,0}),"south",
                      "/players/sauron/area/virtual/testMaster,0,0,0");
      }
// Important! This must come last.
      ::reset(iArg);
}
