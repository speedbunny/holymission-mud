inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Outside a cave";
    long_desc = "A large cave entrance is to the north, under a large\n"+
                "boulder.  There seems to be no plant life growing around\n"+
                "the cave entrance. There's a crack leading down also. Cool\n"+
                "damp air rises from the crack.\n";
    dest_dir = ({
                  "/players/kbl/expa/exp4","north",
                  "/players/kbl/expa/exp2","east",
                  "/players/kbl/expa/for2","west",
                  "/players/kbl/dungeon/dun20","down",
                 });
    items = ({
              "crack","A crack in the forest floor. Obvious stair step\n"+
                      "rocks make for easy way down into the darkness..",
              "boulder","Large boulder with a cave entrance under it",
              "cave entrance","A dark forboding cave",
              "cave","A dark forboding cave",
              "entrance","A dark forboding cave entrance",
             });
    property = "no_hide";
    smell = "Heavy musty odor coming from the cave";
  }
}

init()
{
  ::init();
}
