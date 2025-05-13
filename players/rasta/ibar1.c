inherit "room/room";

object ob;
  int i;
 
reset(arg) 
{
  ::reset(arg);
  if (!arg) {
  set_light( 1);

 dest_dir = ({"players/rasta/room/path11","east" });

  short_desc = "The Ital Drinks Bar";
  long_desc = 
   "The atmosphere is filled with smoke from ganja\n "
       +"spliffs. You find it hard to breathe.\n"
       +"Ital drinks are sold here.\n"
       +"*******************************************************\n"
	+ "*    Ital special           1000 coins                * \n"
	+ "*    Herbsman's drink        600 coins                * \n"
	+ "*    Coconut milk            400 coins                * \n"
	+ "*    Pineapple juice         250 coins                * \n"
	+ "*    Water                    10 coins                * \n"
	+ "*******************************************************\n";
  }
}
init() 
{
  ::init();
  add_action("order"); add_verb ("order");
  add_action("order"); add_verb ("buy");
}

order(str)
{
   string name, short_desc,art, mess;
   int value, cost, strength, heal;
 
 if (!str) 
 {
  write("Huh ? order what?\n");
  return 1;
 }
  if (str == "juice" || str == "pineapple juice") 
  {
    mess = "The pineapple juice makes you tingle with delight";
    heal = 20;
    value = 250;
    strength = 4;
    art ="soft";
  }
  else if (str == "milk") 
  {
    mess = "The coconut milk makes you feel good";
    heal= 50;
    value = 400;
    strength = 10;
    art ="soft";
  }
  else if (str == "special" || str=="ital special") 
  {
    mess = "Irie Ites ! Natural mystics flow through your body";
    heal= 100;
    value = 1000;
    strength = 25; /* Strength 14 is far too low */
    art = "alko";
  }
  else if (str == "water" ) 
  {
    mess = "You drink some ital water";
    heal = 6;
    value = 10;
    strength = 1;
    art = "soft";
  }
  else if (str == "drink" || str=="herbsman drink") 
  {
    mess = "The African herbsman's drink makes you feel IRIE";
    heal = 70;
    value = 600;
    strength = 20; /* Strength 1 is ridiculous */
    art = "alko";
  }
  else 
  {
    write("We don't sell that here !\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) 
  {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }

  if (art=="alko") 
  {
    if (!call_other(this_player(), "drink_alcohol", strength)) 
    {
       write("The vendor says: I think you've had enough.\n");
       say(call_other(this_player(), "query_name", 0) + " asks for a " +
	str + " but the vendor refuses.\n");
       return 1;
     }
  }
  else if (art=="soft") 
  {
    if (!call_other(this_player(),"drink_soft",strength))
    {
     write("The vendor says: You better stop now. \n");
     say(this_player()->query_name()+" asks for a "+str+" but the vendor \n"+
     "refuses.\n");
     return 1;
    }
  }

  write("You pay " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " enjoys a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;

}
