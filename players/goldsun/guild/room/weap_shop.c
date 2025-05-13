inherit "players/whisky/genesis/std/shop";


int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the weaponery";
  long_desc = (
  "You have entered a dusty room in the tower. The walls are made\n"+
  "of shiny stone and the floor is made of spruce wooden lathes.\n"+ 
  "Near the wall there are stairs leading down. This is the\n"+
  "place where Tyr the master of weapons, who is standing behind a desk,\n"+
  "trades with all kinds of weapons. There is a sign saying: 'type list'\n"+
  "behind his desk.\n");
   set_light(1);
   store = "/players/goldsun/guild/room/weap_store";
   type = "smithy";
   keeper = "Tyr";
   maxlist=40;
   
  items = ({"walls","The walls are made of shiny stone",
	    "wall","Near the wall there are stairs leading down",
	    "stairs","The stairs leads down",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
	    "weapons","There are so many weapons, that you better should"
			+" look at sign",
	    "weapon","There are so many weapons, that you better should"
			+" look at sign",
            "tyr","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/guild/room/arm_shop","down"});
  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}

query_property(arg) 
{
   return arg=="no_fight";
 }

int get_list(string arg)
 {
  if (::get_list(arg))
   {
    write("\nTyr said: If there is nothing in my list, You can \n"
         +"wait for a moment. New weapons can being brought.\n");
    return 1;
   }
  return 0;
 }

