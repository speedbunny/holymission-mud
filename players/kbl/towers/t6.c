/* Northeast tower of KBL's castle */

inherit "room/room";
int found_sec;
object leaf,elf;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    found_sec = 0;
    short_desc = "Northeast tower of KBL's castle";
    long_desc = "You enter the northeast tower of KBL's castle.\n"+
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
    transfer(clone_object("players/kbl/objs/cooshee"),this_object());
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
  add_action("yes","yes");
  add_action("search","search");
  add_action("enter_it","enter");
  add_action("look_it","look");
  add_action("look_it","scan");
  wind();
}

wind()
{
  if(call_other("/players/kbl/grounds/gro1","query_wind_set"))
   smell = call_other("/players/kbl/grounds/gro1","query_wind_smell");
  else
   smell = "The air is odorless right now";
}

yes()
{
int i;
  if(living(elf))
  {
    i = random(5);
    switch(i)
    {
     case 1:
     case 2:
      say("Elf says: The Ole man elf can think to you! Ask him sometime.\n");
      write("Elf says: The Ole man elf can think to you! Ask him sometime.\n");
      break;
     case 3:
     case 4:
      say("Gray elf says: Drow elf Enchantress has a blackheart!\n");
      write("Gray elf says: Drow elf Enchantress has a blackheart!\n");
      break;
    default:
      say("Gray elf says: Well then go west from the big hall!\n");
      write("Gray elf says: Well then go west from the big hall!\n");
      break;
   }
    return 1;
  }
}

search(str)
{
  if(!str)
   return;
  if(str == "stand" || str == "stands")
  {
    say(this_player()->query_name()+" search the solid granite stands\n"+
        "but finds nothing.\n");
    write("You find nothing but three solid granite stands closely laid\n"+
          "together here on the floor.\n");
    return 1;
  }
  if(str == "tower" || str == "walls" || str == "room")
  {
    say(this_player()->query_name()+" search around the tower.\n");
    write("You find nothing of interest on the walls or near the\n"+
          "louvered firing slits.\n");
    return 1;
  }
  if(str == "floor")
  {
    say(this_player()->query_name()+" finds a secret door in the floor.\n");
    write("You find a secret door in the floor of the tower.\n");
    found_sec = 1;
    return 1;
  }
}

enter_it(str)
{
  if(!str)
   return;
   if(found_sec == 0)
   {
     write("Enter what??\n");
     return 1;
   }
  if(str == "secret door")
  {
    say(this_player()->query_name()+" enters the secret door.\n");
    write("You enter the secret door in the tower floor.\n");
     write("You get sucked into the secret door and start sliding\n"+
           "down a chute at high speed... It spirals downward...\n"+
           "then you see a green glow coming up fast!\n");
     write("You flip end over end... spinning... tumbling... then...\n");
    this_player()->move_player("into secret door#players/kbl/dungeon/dun2");
    found_sec = 0;
    say("Secret door closes with a thud!\n");
    return 1;
  }
}

look_it(str)
{
  if(!str)
   return;
  if((str == "at secret door" || str == "secret door") && found_sec == 1)
  {
    say(this_player()->query_name()+" looks at the secret door on the\n"+
        "floor of the tower.\n");
    write("You see a well concealed secret door in the floor. Its shape\n"+
          "matches part of the clover leaf design stonework.\n");
    return 1;
  }
}
