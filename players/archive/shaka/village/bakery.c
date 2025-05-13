inherit "room/room";
object keeper;

reset(arg){
  if( !keeper  || !living(keeper) )
   { keeper=clone_object("players/shaka/monsters/keeper");
     transfer(keeper,this_object()); }
  if(arg) return;
  set_light(1);
  short_desc="Village Bakery";
  long_desc="You're in the village bakery.\n"+
            "A small plate on the wall says:\n"+
            "1: A bread              : 10gc\n"+
            "2: A seed cake          : 50gc\n"+
           "3: Mushroom pie         : 100gc\n"+
            "Just order <nr> or order <name>.\n\n"+
            "West is door leading out of the bakery.\n"+
            "Behind the counter is a small door.\n";
   items=({"bakery","the village bakery",
           "plate","a small plate, made of wood",
           "wall","A ordinary wall",
           "door","a normal door, there's two of them in this room",
           "counter","a counter"});
   no_obvious_msg="";
}

init() {
  ::init();
  add_action("order","order");
  add_action("order","buy");
  add_action("west","west");
  add_action("enter","enter");
}

west()
{
  this_player()->move_player("west#players/shaka/village/vil2");
  return 1;
}
enter(arg)
{
  if(!arg)
   { write("enter what?\n");
     return 1;
   }
  if (arg=="door")
   {
    if (keeper)
     { write("Keeper tells you: You have no business over there!\n");
       return 1;
     }
    this_player()->move_player("behind the counter#players/bug/village/counter");
    return 1;
   }
  return 0;
}

order(arg)
{
object food;
string naam,alias,desc,msg,other_msg;
int value,weight,heal;

  if(!arg)
   { write("Please order something!\n");
     return 1;
   }
  if(!keeper)
   { write("But there's nobody to serve you!\n");
     return 1;
   }
  if (arg=="bread" || arg=="1")
   {
     naam = "bread";
     alias = naam;
     desc="A Bread";
     msg="You eat a simple bread.\n";
     other_msg=" eats a simple bread.\n";
     heal=10;
     weight=1;
     value=10;
   }
  else if (arg=="cake" || arg=="2")
   {
     naam="cake";
     alias="seed cake";
     desc="A seed cake";
     msg="You eat a fresh seed cake.\n";
     other_msg=" eats a sweet seed cake.\n";
     heal=50;
     weight=1;
     value=50;
   }
  else if (arg=="pie" || arg=="3")
   {
     naam="pie";
     alias="mushroom pie";
     desc="A mushroom pie";
     msg="You eat a delicious mushroom pie. mmmmmmm\n";
     other_msg=" eats a delicious mushroom pie. Yummy!\n";
     heal=100;
     weight=1;
     value=100;
   }
  else
   {
     write("Rosamunda tells you: We don't sell such things!\n");
     return 1;
   }
  if(this_player()->query_money() <value)
   {
    write("Rosamunda tells you: I'm afraid you don't have enough coins.\n");
    say(this_player()->query_name()+" cant afford the order.\n");
    return 1;
   }
  food = clone_object("obj/food");
   if (!this_player()->add_weight(food->query_weight()))
    {
     write("You can't carry any more.\n");
     destruct(food);
     return 1;
    }
   food->set_name(naam);
   food->set_alias(alias);
   food->set_short(desc);
   food->set_value(value);
   food->set_weight(weight);
   food->set_strength(heal);
   food->set_eater_mess(msg);
   food->set_eating_mess(other_msg);
   transfer(food,this_player());
   this_player()->add_money(-value);
   write("You lay "+value+" gold coins on the counter.\n");
   write("Rosamunda puts the money safely away.\n");
   say(this_player()->query_name() + " orders a "+naam+".\n");
   return 1;
}



