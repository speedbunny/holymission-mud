/* North/south trail, one square south of Ole man */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "High Cliff trail south of climb down spot";
    long_desc = "You are behind a part of the cliff that obsures your view\n"+
                "to the west. The path doesn't look that well traveled\n"+
                "here. Scanning east to north you see an endless plane\n"+
                "with black tipped triangle sticking out of the plane\n"+
                "to the northeast. South are some rugged mountains. Their\n"+
                "rugged peaks show in the light as if they were covered\n"+
                "with snow but they are really covered with a white\n"+
                "quartz crystal carpet\n";
    dest_dir = ({"players/kbl/clifftop","north",
                 "players/kbl/southcliff2","south"});
    items = ({"plane","Empty plane with short brownish grass. To the\n"+
                      "northeast you see a black triangular tip",
              "cliff","Its not level to the edge of the cliff here, it\n"+
                      "rises up here about 10 meters, enough to block your\n"+
                      "view westward",
              "path","Small narrow path being over grown by the brown grass",
              "brown grass","Short dry looking grass growing on the plane",
              "grass","Only short dry looking plant growing on the plane",
              "black tipped triangle","Not much to see really",
              "triangle","Not much to see really",
              "mountains","They are tall and young mountains. Their peaks\n"+
                          "rise sharply above the plane going east to west.\n"+
                          "Their is alot of white quartz crystal covering\n"+
                          "the slopes, almost looks like snow",
              "white quartz crystal","Too far away on the mountains",
              "quartz crystal","Too far away on the mountains",
              "crystal","Too far away on the mountains"});
    smell = "Fresh air ... Ahhhh!";
    property = "no_hide","no_sneak";
  }
}

init()
{
  ::init();
}
