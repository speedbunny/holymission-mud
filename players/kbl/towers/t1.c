/* Southwest tower on KBL's castle */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Southwest tower of KBL's castle";
   long_desc = "You have entered the southwest tower of KBL's castle.\n"+
                "The louvered firing slits in the south wall allow enough\n"+
                "light in here to see. Stone stands under the firing slits\n"+
                "show how the guards must have held off the armies of\n"+
                "nomad warriors. The stands are so blood stained, they look\n"+
                "purple. This place is otherwise so clean you could eat off\n"+
                "the floor. Looking up you see the stonework inside this\n"+
                "tower. Nothing of real interest here.\n";
    dest_dir = ({"players/kbl/towers/mid","out"});
    smell = "The air is odorless right now";
    transfer(clone_object("players/kbl/objs/chest"),this_object());
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
  if(str == "floor")
  {
    say(this_player()->query_name()+" search the floor and finds nothing.\n");
    write("You search the floor and find nothing.\n");
    return 1;
  }
  if(str == "tower" || str == "room" || str == "walls")
  {
    say(this_player()->query_name()+" searchs everywhere but the floor.\n");
    write("You search everywhere in the tower, save the floor.\n");
    return 1;
  }
}
