/* Zesranotae Chamber in Stronghold */

inherit "room/room";
object zes,suit;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(0);
  short_desc = "Zesranotae's Stronghold chamber";
  long_desc = "The Arch DOC Zesranotae commands the Parallel Plane of Chaos\n"+
              "from here. The walls are made of woven dark crystal with\n"+
              "tapestries scattered about the walls in a whimsical manner.\n"+
              "You see no furnishings in this room.\n";
  dest_dir = ({"players/kbl/chaos/cho7","out"});
  property = "no_hide";
  smell = "Intense pine odor";
  if(!zes || !living(zes))
  {
    zes = clone_object("players/kbl/objs/zesronatae");
    suit = clone_object("players/kbl/objs/litesuit");
    transfer(suit,zes);
    transfer(zes,this_object());
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("south","south");
}

ownw()
{
  return "Zesranotae";
}



south()
{
  object temp;

  temp = this_player();
  if(temp->query_name() == ownw())
  {
    this_player()->move_player("south behind battle tapestry#players/kbl/chaos/private");
    command("drink potion",this_player());
   command("drink potion",this_player());
   this_player()->set_whimpy(0);
    return 1;
  }
  write("You leave south behind tapestry to...\n");
  this_player()->move_player("south behind battle tapestry#players/kbl/chaos/cvoid");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at walls" || str == "walls")
  {
    say(this_player()->query_name()+" looks at the walls.\n");
    write("Many tapestries line the walls. All are crooked and have\n");
    write("no order to them. The walls are tightly woven dark crystal\n");
    write("that look as if they could stand any bombardment.\n");
    return 1;
  }
  if(str == "at tapestries" || str == "tapestries")
  {
    say(this_player()->query_name()+" looks at the tapestries.\n");
    write("These tapestries, even tho they are out of order, show the\n");
    write("pattern of how the DOC are going to take over the Parallel\n");
    write("Plane of Light. A glowing suit seems to be the key to their\n");
    write("planes, but no one understands its functions here yet.\n");
    return 1;
  }
  if(str == "at ceiling" || str == "ceiling")
  {
    say(this_player()->query_name()+" looks up at doomed ceiling.\n");
    write("You see a symbol up there, carved into the very top of the\n");
    write("doomed part of the ceiling. Its looks like this:\n");
    write("          -----------------------------------------\n");
    write("    -----------------------------------------\n");
    write("----------------------------------------\n");
    write("<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>\n");
    write("----------------------------------------\n");
    write("    -----------------------------------------\n");
    write("          -----------------------------------------\n");
    return 1;
  }
}

