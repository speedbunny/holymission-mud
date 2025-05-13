inherit "room/room";
	
void reset(int arg)
  {if(!arg)
    {set_light(1);
    short_desc= "George's Grub";
    long_desc=
    "You have entered a small establishment know as George's Grub.  "+
    "Around the room are tables and chairs, although are all empty at "+
    "the moment.  The air is thick with the odor of dwarven food, "+
    "which, to your stomach, isn't the most appetizing.\n"+
    "A menu hangs from the ceiling.\n";
    items=({
    "menu","A small iron sign with something written on it",
    "table","A brown wooden table",
    "tables","Brown wooden tables",
    "chair","A small wooden chair",
    "room","You are standing in it",
    "ceiling","It is a small thatch roof",
    "roof","It covers the building",
    "building","You are standing in it",
    "thatch","It is made of some tall grass or something",
    "chairs","Some small wooden chairs" });
    smell="The pungent odor of dwarven cooking turns your stomach..";
    dest_dir=({"/players/kawai/areas/dwarves/village8","north"});
    property=({"no_fight"});}
  ::reset(arg);}

 
void init()
  {::init();
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read");}


status read(string str)
  {if (str=="menu" || str=="drink" || str=="drinks"||str=="sign")
    {write(
     "#######################################################\n"+
     "                    George's Grub                       \n"+
     "#######################################################\n"+
     "We offer:\n"+
     "A.) Food and drinks for the direct consume:\n"+
     "1-  Water                             5 coins \n"+
     "2-  Ale                               10 coins \n"+
     "3-  Dwarven Punch                     250 coins \n"+
     "4-  Mole Jerky                       100 coins \n"+
     "5-  Troll Steak                       600 coins \n\n"+
     "B.) Food and drinks to take away:\n"+
     "6-  Fish (roasted)                    100 coins \n"+
     "7-  Ale (bottled)                     70 coins \n"+
     "You can consume also in numbers....<buy 1> for the Water.\n");
     return 1;}
  return 0;}


status order(string str)
  {string name, short_desc,art, mess;
  int value, cost, strength, heal, scream;
  object dummy;
  if(!str) 
    {notify_fail("Order what?\n");
    return 0;}
  if (str == "water" || str == "1")
    {mess = "The water refreshes you.... AHHHH";
    heal = 5;
    value = 5;
    strength = 1;
    art ="soft";}
  else if (str == "ale" || str == "2")
    {mess = "The Ale makes you feel much better.... AHHHH";
    heal= 10;
    value = 10;
    strength = 2;
    art ="alko";}
  else if (str == "punch" ||str=="dwarven punch"|| str=="3")
    {mess = "WOAH!!!!!";
    heal= 60;
    value = 250;
    strength = 7;
    art = "alko";}
  else if (str == "jerky" ||str=="mole jerky"|| str=="4")
    {mess = "MMM....best jerky you've ever had!";
    heal = 20;
    value = 100;
    strength = 3;
    art = "food";}
  else if (str=="steak"||str=="troll"||str=="troll steak" || str=="5")
    {mess = "<gulp>....different....certainly different...";
    heal = 100;
    value = 600;
    strength = 13;
    art = "food";}
  else if (str == "fish" || str == "6")
    {if (this_player()->query_money() < 100) 
      {notify_fail("The dwarf says: Sorry, but you don't have enough money.\n");
      return 0;}
    write("The dwarf gives you a roasted fish.\n");
    dummy=clone_object("players/kawai/obj/rfish");
    if (transfer(dummy,this_player()))
      {move_object(dummy,environment(this_player()));}
    this_player()->add_money(-100);
    return 1;}
  else if (str == "Ale" || str == "7") {
    if (this_player()->query_money() < 70) 
      {notify_fail("The dwarf says: Sorry, but you don't have enough money.\n");
      return 0;}
    write("The dwarf gives you some Ale.\n");
    dummy=clone_object("players/kawai/obj/ale");
    if (transfer(dummy,this_player()))
      {move_object(dummy,environment(this_player()));}
    this_player()->add_money(-70);
    return 1;}
  else 
    {notify_fail("George stares at you, saying: We don't have that.\n");
    return 0;}
  if(this_player()->query_money(0)<value) 
    {notify_fail("That costs " + value + " gold coins, which you don't have.\n");
    return 0;}
  if(art=="alko")
    {if (!this_player()->drink_alcohol(strength))
      {write("George says: I think you've had enough.\n");
      return 1;}}
  else if (art=="soft")
    {if (!this_player()->drink_soft(strength))
      {write("George says: Sorry, I don't think you have a cow stomach.\n");
      return 1;}}
  else if (art=="food")
    {if (!this_player()->eat_food(strength))
      {write("George says: I think you've had enough.\n");
      return 1;}}
  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;}
