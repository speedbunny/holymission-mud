/* Dump room for matrix expulsions! (bounces) */ 

inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc = "Matrix bounce/disposal room";
    long_desc = "This is a retangular room with many exits. All the surfaces\n"+
                "here are gray, except for the exits which are shimmering\n"+
                "blue-white against the gray.\n";
    dest_dir = ({"/room/church","church",
                 "/room/pub2","pub",
                });
    items = ({"exits","Shimmering blue-white portals",
              "portals","Shimmering blue-white energy fields",
              "fields","Shimmering blue-white energies",
              "energies","Shimmering blue-white portals",
             });
    smell = "Fresh air";
  }
}

init()
{
  ::init();
}
