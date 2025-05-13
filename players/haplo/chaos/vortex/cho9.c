/* Storage room in the basement of Stronghold */

inherit "room/room";
int frac_f,boxes,box_m;
object mon;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(0);
  short_desc = "Basement storage room";
  long_desc = "There are many boxes piled high here and most have about\n"+
              "a inch of dark crystal dust on them. The walls glow with\n"+
              "a faint hint of green. The room is filled to capacity and\n"+
              "only narrow pathways allow you movement between boxes.\n"+
              "All are filled with provisions to supply the DOC for years.\n";
  dest_dir = ({"players/kbl/chaos/cho8","up"});
  smell = "the air is filled with the odor of dried meat";
  property = "no_steal";
  if(!mon)
  {
   mon = clone_object("obj/money");
    mon->set_money(random(500)+4415);
    transfer(mon,this_object());
  }
  boxes = 5;
 }
}


init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("move_it","move");
  add_action("search","search");
  add_action("south","south");
  add_action("north","north");
  add_action("west","west");
  add_action("east","east");
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at basement" || str == "basement")
  {
    say(this_player()->query_name()+" looks around the basement.\n");
    write("Many boxes scattered around. This room feels warmest near the\n");
    write("southeast corner of the room. The walls seem solid in every\n");
    write("direction except the northeast corner staircase going up.\n");
    return 1;
  }
  if(str == "at boxes" || str == "boxes" || str == "at box" || str == "box")
  {
    say(this_player()->query_name()+" looks at the boxes in the room.\n");
    write("Looking closer, some of the boxes are a slight bit different.\n"); 
    write("Some boxes are empty, some are full of raw metals of unknown\n");
    write("types. Most of the stuff in the boxes is for DOC to live on.\n");
    return 1;
  }
  if(str == "at walls" || str == "walls" || str == "at wall" || str == "wall")
  {
    say(this_player()->query_name()+" looks around at the walls.\n");
    if(frac_f)
    {
      write("You notice a fracture in the southeast corner of the room.\n");
      if(box_m)
       write("Looks like the boxes have been moved in the southeast corner.\n");
      else
       write("Boxes seem to hide the fracture in the southeast corner.\n");
      return 1;
    }
    write("You see nothing special about the walls, very plain.\n");
    return 1;
  }
}

search(str)
{
  if(!str)
   return;
  if(str == "south wall" || str == "walls")
  {
    if(!frac_f)
    {
      say(this_player()->query_name()+" found a large crack in southeast corner.\n");
      write("You find a large crack in the southeast corner, but many\n");
      write("boxes are stacked in front of it.\n");
      frac_f = 1;
      return 1;
    }
    say(this_player()->query_name()+" searchs "+str+".\n");
    write("You search and see the fracture in the southeast wall.\n");
    if(!box_m)
     write("Some boxes block most of your view of the fracture.\n");
    else
     write("Also, you can see a secret door in the south wall.\n");
    return 1;
  }
}

move_it(str)
{
  if(!str)
   return;
  if(str == "box from south wall" || str == "box from southeast")
  {
    if(!box_m)
    {
      if(boxes > 0)
      {
        write("You move a box away from south wall.\n");
        say(this_player()->query_name()+" moves a box away from south wall.\n");
        boxes -=1;
      }
      if(boxes == 0)
      {
       if(frac_f)
       {
        write("You just moved the last box, exposing a secret door here.\n");
        say(this_player()->query_name()+" just exposed a secret door in south wall.\n");
        box_m = 1;
       }
      else
      {
        write("You expose the south wall.\n");
        say(this_player()->query_name()+" exposes the south wall.\n");
      }
      }
      return 1;
   }
   write("All boxes have been moved already!\n");
   return 1;
  }
}


south()
{
  if(frac_f && box_m)
  {
    write("You leave through secret door to...\n");
    this_player()->move_player("through secret door south#players/kbl/chaos/cho10");
    return 1;
  }
  if(frac_f && !box_m)
  {
    write("Some boxes still block your way south.\n");
    say("Some boxes still block "+this_player()->query_name()+"'s way south.\n");
    return 1;
  }
  if(!frac_f && box_m)
  {
    write("The south wall is here. You can't go through walls!\n");
    return 1;
  }
}

north()
{
  write("You just can't go north.\n");
  return 1;
}

east()
{
  write("You just can't go east.\n");
  return 1;
}

west()
{
  write("You can't just go west.\n");
  return 1;
}
