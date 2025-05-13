/* Gully next to Fissure Joint */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Gully next to fissure joint";
    long_desc = "This area is full of useless debris. A small ridge of\n"+
                "brown crystal rises to the east of this gully. The\n"+
                "fissure joint is more pronounced to the west and totally\n"+
                "unclimbable. A large splintered upheaval lies to the north\n"+
                "almost blocking the path. South, the world seems to end.\n"+
                " ";
    dest_dir = ({"players/kbl/chaos/cho5","north",
                 "players/kbl/chaos/cho3","south",
                 "players/kbl/chaos/cho41","up"});
    property = "no_steal";
    smell = "Strong nasty sulphuric odor coming from the north";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
}



look_it(str)
{
  if(!str)
   return;
  if(str == "at gully" || str == "gully")
  {
    say(this_player()->query_name()+" scans the gully.\n");
    write("Gully has a natural slope down to the north where it ends in a\n");
    write("splintered upheavel of brownish and dark crystal. The west side\n");
    write("of the gully is unclimbable because of its steepness. Nothing of\n");
   write("read value catches your attention here.\n");
    return 1;
  }
  if(str == "at upheaval" || str == "upheaval")
  {
    say(this_player()->query_name()+" looks at upheaval.\n");
    write("These many crystal shards are all fragmented and worthless. The\n");
    write("amount of pressure that it took to create this pile has taken\n");
    write("its toll on the lattice structures of the crystals. You see a\n");
    write("faint glow coming from beyond the upheavel.\n");
    return 1;
  }
  if(str == "at debris" || str == "debris")
  {
    say(this_player()->query_name()+" looks at the debris laying around.\n");
    write("Most of the debris is broken crystal of both dark and brownish\n");
    write("origin. Its scatterd around as if someone tossed it there.\n");
    return 1;
  }
  if(str == "at ridge" || str == "ridge")
  {
    say(this_player()->query_name()+" looks east a ridge.\n");
    write("The pressure ridge of brownish crystal is very climbable. The\n");
    write("chunks of brownish crystal lay in stair step patterns going up\n");
    write("the ridge.\n");
    return 1;
  }
}
