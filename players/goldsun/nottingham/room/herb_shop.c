inherit "players/whisky/genesis/std/shop";


int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the herb shop";
  long_desc ="You are in the herb shop. The walls are made of brick.\n"+
	     "The wooden roof makes this shop very cosy. This is the\n"+
            "place where Leila, who is standing behind a desk, trades\n"+
        "with strange things. There is a sign saying: 'type list' behind\n"+
        "his desk.\n";
   
   set_light(1);
   store = "/players/goldsun/nottingham/room/herb_store"; 
   type = "trader";
   keeper = "Leila";
   maxlist=20;
   
  items = ({"walls","The walls are made of shiny stone",
	    "wall","Near the wall there are stairs leading up and down",
	    "stairs","The stairs leading up and down",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "leila","She is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/nottingham/room/road12","south"});

    move_object(clone_object("/players/goldsun/sherwood/obj/bottle"),query_store());
    move_object(clone_object("/players/goldsun/sherwood/obj/bottle"),query_store());
    move_object(clone_object("/players/whisky/obj/pois_potion"),query_store());
    move_object(clone_object("/players/whisky/obj/pois_scroll"),query_store());
/*  Mangla: removed these items since they do not exist.
    move_object(clone_object("/players/goldsun/guild/obj/fbwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/crwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/mrwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/lwand"),query_store());
*/
}

init(){
 ::init();
add_action("d_sell","sell");
 }

query_property(arg) 
{
   return arg=="no_fight";
 }

int get_list(string arg)
 {
  if (::get_list(arg))
   {
    write("\nLeila says: Do you want to buy something ?\n");
    return 1;
   }
  return 0;
 }

int d_sell(){
 write("Leila says: I don't buy anything from you.\n");
 return 1;
}
