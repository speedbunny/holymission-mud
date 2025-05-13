inherit "room/room";

#define TO this_object()
#define TP this_player()

void reset(int arg)
  {if(!arg)
    {clone_list=({1,2,"guard","/players/kawai/monst/dguard",0});
    set_light(1);
    short_desc = "Outer Chambers";
    long_desc = "You have entered the lavishly decorated Outer Chambers "+
    "of the palace.  Large tapestries hang from along the walls "+
    "and gold and silver trimmings line everything in sight.\n";
    smell = "The air fresh";
    dest_dir = ({"players/kawai/areas/dwarves/palace/swalk","west",
    "players/kawai/areas/dwarves/palace/anteroom","northeast"});
    items = ({"tapestries","Large, woven designs hang from the ceiling",
    "tapestry","This one looks depicts an ancient battle",
    "gold","The gold glimmers in the light",
    "silver","The silver glimmers in the light",
    "chamber","The chamber is one of the entrance rooms of the castle",
    "wall","The wall is decorated and glimmers in the light",
    "walls","The walls glimmer in the light",
    "castle","It's the king's palace.  Not very large, but nicely\n"+
    "decorated, though",
    "trimmings","Gold and silver linings are everywhere!",
    "trimming","Its a beautiful touch",
    "palace","It's the king's palace.  Not very large, but nicely\n"+
    "decorated, though"});}
  ::reset(arg);}

void init()
  {::init();
  add_action("est","northeast");}

status est()
  {int i,weap;
  mixed inv;
  if(!present("guard",TO)) 
    {return 0;}
  inv=all_inventory(TP);
  i=0;
  weap=0;
  while((i<sizeof(inv))&&(!weap))
    {if((inv[i]->query_weapon())&&(!inv[i]->id("kq1-sword")))
      {weap=1;}
    i++;}
  if(weap)
    {write("Guard says: Sorry, but you'll have leave your weapons outside.\n");
    return 1;}
  write("Guard says: You're clean....you may pass.\n");
  return 0;}
 
 