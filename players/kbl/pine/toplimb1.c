/* Next to the tree trunk of the giant pine */

inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc = "Top level of giant pinetree";
    long_desc = "The view of the internal structure of this tree is\n"+
                "awesome! So large and spacious. Carved into the trunk is a\n"+
                "entranceway into the tree. Going down to the left is a\n"+
                "spiral stairway.\n";
    dest_dir = ({"/players/kbl/pine/inpine3","west",
                 "/players/kbl/pine/toplimb2","east",
                 "/players/kbl/pine/stairway3","down",
                });
    smell = "Intense pine odor";
  }
}

init()
{
  ::init();
}
