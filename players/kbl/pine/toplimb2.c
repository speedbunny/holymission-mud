/* On the top most, largest branch of a 2500' pine */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "On a giant limb on a crimson pine tree";
    long_desc = "Pine needles grow thick all around but you can see the\n"+
                "grows east to west. West you see the limb continues to\n"+
                "the main trunk of the tree and east the limb ends at a\n"+
                "white wall of somekind. Down you see the inner branch\n"+
                "growth of this pine. Fantastic array of limbs some larger\n"+
                "and smaller growing from the main trunk of the pine. Up\n"+
                "you see the branches form dark spaces that you cannot see\n"+
                "into.\n";
    dest_dir = ({"players/kbl/pine/toplimb3","east",
                 "players/kbl/pine/toplimb1","west"});
    smell = "Intense pine odor, WOW!";
  }
}

init()
{
  ::init();
}
