/* Northwest tower of KBL's castle */

inherit "room/room";
object leaf,elf;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Northwest tower of KBL's castle";
    long_desc = "You enter the northwest tower of KBL's castle.\n"+
                "The louvered firing slits in the north wall allow enough\n"+
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
    leaf = clone_object("players/kbl/objs/leaf");
    leaf->set_heal_points(random(50)+15);
    transfer(leaf,elf);
    items = ({"slits","They are facing looking out at the mountains to\n"+
                      "the north. You see the wind swept mountain sides\n"+
                      "looking cold an forbidden",
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
   say(this_player()->query_name()+" searchs the "+str+" in vain.\n");
   write("You search the "+str+" in vain.\n");
   return 1;
  }
  if(str == "floor")
  {
    say(this_player()->query_name()+" searchs floor with vigor but nothing\n"+
        "is to be found.\n");
    write("You find nothing, not even dust on the floor.\n");
    return 1;
  }
}
