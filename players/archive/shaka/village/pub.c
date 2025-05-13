inherit "room/room";
object bartender;

reset(arg) {
   if( (!bartender) || (!living(bartender)) )
    { bartender = clone_object("players/shaka/monsters/ferny");
      transfer(bartender,this_object());
    }
   if(arg) return;
   set_light(1);
   short_desc="The prancing pony";
   long_desc="You're in the prancing pony, the village's pub .\n"+
             "A small sign reads:\n"+
             " 1: A Mug of beer          : 15 gold coins.\n"+
             " 2: A Malibu               : 60 gold coins.\n"+
             " 3: Mushroom extract       : 120 gold coins.\n"+
             "just type order <name> or order <nr>.\n\n"+
              "A door to the east leads back on the road.\n\n";
  items=({"pub","the village's pub",
          "sign","a small sign",
          "door","a door, even big enough for bigfolk",
          "road","the road outside"});
  no_obvious_msg="";
  smell="The strong smell of beer";
}

init() {
  ::init();
  add_action("east","east");
  add_action("order","order");
  add_action("order","buy");
}

east() {
  if ( has_drink(this_player()) && bartender )
   {
    write("Ferny tells you: You are not allowed to leave with drinks!\n");
    say(this_player()->query_name()+" tried to leave with a drink!\n");
    return 1;
   }
  this_player()->move_player("east#players/shaka/village/vil3");
  return 1;
}
order(arg)
{
object drink;
string naam,desc,msg;
int val,str,heal;

  if(!arg)
   {
    write("Order something!\n");
    return 1;
   }
  if( (!bartender) || (!living(bartender)) )
   {
    write("But ferny isn't here to fix the drinks!\n");
    return 1;
   }
  if (arg == "beer" || arg == "1")
   {
     naam = "beer";
     desc = "A mug of beer";
     msg = "You drink a fine mug of hobbits' beer";
     heal = 1;
     val=15;
     str= 2;
   }
  else if (arg =="malibu" || arg=="2" )
   {
    naam= "malibu";
    desc="A malibu drink";
    msg="You feel the taste of coconut on your tongue";
    heal=12;
    val=60;
    str=8;
   }
  else if (arg == "extract" || arg == "3" )
   {
    naam="extract";
    desc="A mushroom extract";
    msg="You think your brains are going to explode";
    heal=20;
    val=120;
    str=10;
   }
  else
   {
    write("Ferny tells you: I don't serve such a drink!\n");
    say(this_player()->query_name()+" orders something stupid.\n");
    return 1;
   }
  if(this_player()->query_money() < val)
   {
    write("Ferny tells you : You don't have "+val+" gold coins.\n");
    say(this_player()->query_name()+" can't afford the order.\n");
    return 1;
   }
  drink = clone_object("obj/drink");
  if (!this_player()->add_weight(drink->query_weight()))
   {
    write("You can't carry any more.\n");
    destruct (drink);
    return 1;
   }
  if (!call_other(drink, "set_value", naam + "#" + desc + "#" + msg +
	"#" + heal + "#" + val + "#" + str ))
   {
     write("Error in creating drink.\n");
     destruct(drink);
     return 1;
   }
  drink->set_pub();
  transfer(drink,this_player());
  this_player()->add_money(-val);
  write("You pay ferny "+val+" gold coins for a "+naam+".\n");
  write("Ferny puts the money safely away.\n");
  say(this_player()->query_name() + " orders a "+naam+".\n");
  return 1;
}

has_drink(obj)
{
status drink;
object obie;

  obie=first_inventory(obj);
  while(obie) {
     if (obie->id("drk2")) drink =1;
     if (obie->can_put_and_get())
      {
       if (has_drink(obie))  drink =1;
      }
     obie = next_inventory(obie);
  }
  return drink;
}
