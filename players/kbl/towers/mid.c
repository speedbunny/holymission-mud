/* Very middle of KBL's castle */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Six tower view";
    long_desc = "You are standing in the exact middle of the castles top\n"+
                "level. The area is sloped towards the east so it can drain\n"+
                "the water from itself. Above you is a covering that\n"+
                "protects this opening when the driving rains come. The\n"+
                "six towers can be accessed from this point.\n";
    dest_dir = ({"players/kbl/towers/t6","t6",
                 "players/kbl/towers/t5","t5",
                 "players/kbl/towers/t4","t4",
                 "players/kbl/towers/t3","t3",
                 "players/kbl/towers/t2","t2",
                 "players/kbl/towers/t1","t1",
                 "players/kbl/kblroom","down"});
    items = ({"towers","They all have a very smooth looking finish to\n"+
                       "their exteriors. Each has a opening leading into\n"+
                       "it. It looks dark inside the towers",
              "covering","A oak covering that is louvered. As the wind\n"+
                         "blows, the louvers move into positions that\n"+
                         "route the winds around the stairwell.",
              "louvers","Metal louvers with liquid weights attached",
              "liquid weights","Blueish liquid in a clear glass teardrop\n"+
                               "shaped container. Maybe 2cm in diameter",
              "stairwell","Stairs leading down to the entrance hall"});
    smell = "Fresh air, sweet to the nose but a little cool";
    property = "no_hide";
  }
}

init()
{
  ::init();
  wind();
}

wind()
{
  if(call_other("/players/kbl/grounds/gro1","query_wind_set"))
   smell = call_other("/players/kbl/grounds/gro1","query_wind_smell");
  else
    smell = "Fresh air, sweet to the nose but a little cool";
}
