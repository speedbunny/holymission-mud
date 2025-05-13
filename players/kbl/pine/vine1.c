inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Hanging from a vine";
    long_desc = "The vines stretch down below you towards the ground and\n"+
                "high above you into some solid growths of crimson pine\n"+
                "needles.\n";
    dest_dir = ({
                 "/players/kbl/pine/base1","down",
                 "/players/kbl/pine/vine2","up",
                });
    items = ({
              "pine needles","Think pine needles, deep crimson colour",
              "pine needles","Thick pine needles, deep crimson colour",
              "needles","Thick pine needles, deep crimson colour",
              "vines","Thick, very durable and used very often",
              "solid growths","Pine needles",
             });
    property = "no_hide","no_steal";
    smell = "Intense pine scent fills the air";
  }
}

init()
{
  ::init();
}
