/* Two squares south of climb down spot on High Cliff */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Edge of chasm";
    long_desc = "A deep chasm in the quartz cliff runs parallel with the\n"+
                "east/west mountain range. The chasm must be 800 meters\n"+
                "deep and has a dry jagged looking bottom. Once upon a\n"+
                "time there was a way to cross by foot bridge, but that\n"+
                "has been destroyed due to time. Scanning east to north\n"+
                "you see a endless plane and west you can see the mountains\n"+
                "going towards a sparkling sea in the distance.\n";
    dest_dir = ({"players/kbl/southcliff1","north"});
    smell = "Air is dry with a tinge of dead grass";
    property = "no_hide","no_sneak";
    items = ({"chasm","Too deep to see anything clearly on the bottom, but\n"+
                      "on the other side you see the remains of two posts\n"+
                      "that at one time held a foot bridge in place. Part\n"+
                      "of the bridge still is connected to the posts, but\n"+
                      "hangs down only part way into the chasm. No way to\n"+
                      "cross and there's no post on the side you are on",
              "quartz cliff","The edge is to your west about 50 meters",
              "cliff","The edge is to your west about 50 meters",
              "mountain range","Runs east/west parallel to the chasm. The\n"+
                               "mountains are tall and rugged",
              "mountains","White crystal covers the tops of these rugged\n"+
                          "mountains. The lower slopes are devoid of the\n"+
                          "crystal but large rocks and other debris can be\n"+
                          "seen on the lower slopes",
              "lower slopes","Scattered rocks and debris dominate the view",
              "slopes","Scattered rocks and debris dominate the view",
              "debris","Your a little to far away for detail",
              "rocks","Your a little to far away for detail",
              "large rocks","They have whiteish streaks in them",
              "foot bridge","The only remains are on the opposite side\n"+
                            "of the chasm",
              "bottom","Jagged looking and dry, thats all the detail you\n"+
                       "can see from here",
              "plane","Endless plane stretching from the base of the\n"+
                      "mountains to the horizon north. Only thing you see\n"+
                      "on the plane is brown grass",
              "grass","Looks dry but still lives",
              "brown grass","Looks dry but still lives",
              "sparkling sea","So far in the distance that only the suns\n"+
                              "sparkling off the water can be seen",
              "sea","No detail can be seen from here"});
  }
}

init()
{
  ::init();
}
