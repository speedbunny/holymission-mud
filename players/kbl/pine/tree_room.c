inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Tree holder room";
    long_desc = "This room looks unique. There are several different vines\n"+
                "growing here that have strange symbols carved into them.\n";
    dest_dir = ({
                 "/players/kbl/expa/for4","forest",
                 "/room/church","church",
                });
    items = ({
              "room","Very large looking room",
              "vines","They hang from the ceiling and look alien in nature",
              "symbols","Vine commands:\n"+
                        "    pull vine <type>\n"+
                        "    climb vine <type>\n"+
                        "Vine types:\n"+
                        "    cherry, dogwood and cedar",
             });
  }
}

