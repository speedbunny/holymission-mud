inherit "/obj/std_shop";

int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the castle shop";
  long_desc = (
  "You have entered a small dusty room. The walls are made of red\n"+
  "bricks and the floor is made of spruce wooden lathes. This is the\n"+
  "place where Eponine , who is standing behind a desk, trades\n"+
  "with stuff. There is a sign saying: 'type list' behind\n"+
  "her desk.\n");
   set_light(1);
   store = "/players/goldsun/guild/room/other_store";
   keeper = "Eponine";
   maxlist=40;
   
  items = ({"walls","The walls are made of red bricks",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
	    "stairs","The stairs leads up",
            "Eponine","She is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/guild/room/hall","west",
	        "/players/goldsun/guild/room/arm_shop","up" });
    move_object(clone_object("/obj/torch"),query_store());
    move_object(clone_object("/players/galadriel/fire/matchbox"),query_store());

  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}

query_property(arg) 
{
   return arg=="no_fight";
 }

int sell_fcn(object sob,object player,int i)
 {
  if (sob->query_armour() || sob->query_weapon())
   {
    if (i) tell_object(player,keeper+" tells you: I don't buy this item.\n");
   }
   else check_transfer(sob,player);
  return 1;
 }


int buy_object(string arg)
{
   if (!present("matchbox",query_store()) || 
        !present("torch",query_store()) )
    {
        write(keeper+" tells you: Wait a second I get one from the store.\n");
      if (!present("matchbox",query_store()))
      {
        move_object(clone_object("/players/galadriel/fire/matchbox"),
                    query_store());
      }
      else
       move_object(clone_object("/obj/torch"),query_store());
    }
   return ::buy_object(arg);
}

int get_list(string arg)
{
    if (::get_list(arg))
    {
       write(
       "Even if not in my list, I can get you a matchbox or torch from the store.\n");
       return 1;
    }
   return 0;
}

