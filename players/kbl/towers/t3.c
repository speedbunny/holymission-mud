/* Southeast tower of KBL's castle */

inherit "room/room";
object leaf,elf;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "South wall tower of KBL's castle";
    long_desc = "You enter the southeast tower of KBL's castle.\n"+
                "The louvered firing slits in the south wall allow enough\n"+
                "light in here to see. Stone stands under the firing slits\n"+
                "show how the guards must have held off the armies of\n"+
                "nomad warriors. The stands are so blood stained, they look\n"+
                "purple. This place is otherwise so clean you could eat off\n"+
                "the floor. Looking up you see the stonework inside this\n"+
                "tower. Nothing of real interest here.\n";
    dest_dir = ({"players/kbl/towers/mid","out"});
    smell = "The air is odorless right now";
    elf = clone_object("players/kbl/objs/elf");
    transfer(elf,this_object());
    leaf = clone_object("players/kbl/objs/short_sword");
    transfer(leaf,elf);
    command("wield sword",elf);
    items = ({"slits","The are facing looking out over the pathway coming\n"+
                      "up from the valley. Looking out the slits you see\n"+
                      "the pathway is a easy shot from here in a still wind", 
              "wall","Made of field stone laid tightly together",
              "stands","They are just blocks of stone carved for the guards",
              "stonework","Extremely well placed stones create patterns in\n"+
                          "familiar ways",
              "patterns","Looks like clover leaf patterns",
              "stones","Field stones"});
  }
}

init()
{
  ::init();
  add_action("search","search");
  add_action("yes","yes");
  wind();
}

wind()
{
  if(call_other("/players/kbl/grounds/gro1","query_wind_set"))
   smell = call_other("/players/kbl/grounds/gro1","query_wind_smell");
  else
   smell = "The air is odorless right now";
}

search(str)
{
  if(!str)
   return;
  if(str == "tower" || str == "walls" || str == "room")
  {
   say(this_player()->query_name()+" searchs the "+str+" and finds nothing.\n");
   write("You find nothing.\n");
   return 1;
  }
  if(str == "floor")
  {
    say(this_player()->query_name()+" searchs the floor in vain.\n");
    write("You find nothing on the floor except clover patterns.\n");
    return 1;
  }
  if(str == "stand" || str == "stands")
  {
    say(this_player()->query_name()+" searchs the stands.\n");
    write("You search the "+str+" but find nothing.\n");
    return 1;
  }
}

yes()
{
  if(!living(elf))
  {
    if(this_player()->query_int() > 15)
    {
      write("Gray elf tells you: KBL's library is surrounded by Drow!\n"+
            "Its hard to get into without letting go.\n");
      return 1;
    }
    write("Gray elf snickers at you and says: Go find out stuff yourself!\n");
    return 1;
  }
}
