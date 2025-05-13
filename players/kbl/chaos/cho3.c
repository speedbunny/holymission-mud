/* Fissure Joint in Chaos */

inherit "room/room";
int num_c;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    num_c = 1;
    set_light(1);
    short_desc = "Fissure joint view of vortex";
     long_desc = "Two great rifts of dark and brownish crystal merge\n"+
                 "together here. The joint is exactly where you are\n"+
                 "standing. From this distance the vortex has more\n"+
                 "definition. Way down to the left you can see a ledge\n"+
                 "of dark crystal sticking out over the vortex. Here you\n"+
                 "feel alot of power just virbrating through underfoot.\n"+
                 "Its feels as if this place is breaking apart slowly.\n";
    property = "no_hide";
    smell = "A strong sulfur odor is in the air";
    items = ({"rifts","Two wedges of material come together here. The\n"+
                      "crystal on top of the rifts looks very sharp making\n"+
                      "the rifts unclimbable.",
              "brownish crystal","All pieces are splintered and broken",
              "chunks","Still to far away for any detail",
              "light pulse","to far away to see any detail in this beam",
              "underfoot","The ground underfoot is very fractured and\n"+
                          "virbrates almost continuously."});
    dest_dir = ({"players/kbl/chaos/cho2","west",
                 "players/kbl/chaos/cho4","north"});
  }
}

init()
{
  ::init();
  add_action("down","down");
  add_action("search","search");
  add_action("look_it","look");
  add_action("look_it","scan");
}



down()
{
  write("You climb down a section of the fissure joint.\n");
  this_player()->move_player("climbing down#players/kbl/chaos/cho31");
  return 1;
}

search(str)
{
  object tal;

  if(!str)
   return;
  if(str == "fissure" || str == "joint")
  {
   if(num_c == 1)
   {
   write("You pick up a dark crystal.\n");
   say(this_player()->query_name()+" picks up a dark crystal.\n");
   tal = clone_object("players/kbl/objs/ridge_cr");
   tal->set_tim(5);
   transfer(tal,this_player());
   num_c+=1;
   return 1;
   }
   else
   {
     write("There's no more fractured crystal here at the moment.\n");
     return 1;
   }
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at vortex" || str == "vortex")
  {
    say(this_player()->query_name()+" looks down and left at vortex.\n");
    write("Looking closer at vortex you see chunks of matter disappearing\n");
    write("into it causing a emission of RGB light pulse. The pulse travels\n");
    write("upward and beyond your mear sight. There is a constant pulsing\n");
    write("of this light and way down below you can see it fans out, out\n");
    write("of sight.\n");
    return 1;
  }
  if (str == "at joint" || str == "joint")
  {
    say(this_player()->query_name()+" scans fissure joint for loose crystal.\n");
    write("Look at the fissure joint you see its made of brown\n");
    write("crystaline material merged with dark crystal. The dark crystal\n");
    write("looks more crumbly here and none seems to look good enough\n");
    write("to keep.\n");
    return 1;
  }
  if (str == "at beam" || str == "beam")
  {
    say(this_player()->query_name()+" looks out at the distant light beam.\n");
    write("Not much detail to see from here.\n");
    return 1;
  }
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks at ledge down below.\n");
    write("You look at the ledge that is sticking out down below here.\n");
    write("Not much detail to see, just that it seems to be sticking\n");
    write("out over the vortex.\n");
    return 1;
  }
}
