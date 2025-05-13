inherit "room/room";

#define TO this_object()
#define TP this_player()

void reset(int arg)
  {if(!arg)
    {clone_list=({1,2,"guard","/players/kawai/monst/dguard",0});
    set_light(1);
    short_desc = "Southern Gate";
    long_desc = "You stand ready to enter a bright and cheery castle. "+
    "Before you is a massive gate, to which the east opens up "+
    "into a courtyard, and west to the town.\n";
    smell = "The air fresh";
    dest_dir = ({"players/kawai/areas/dwarves/village26","west",
    "players/kawai/areas/dwarves/palace/swalk","east"});
    items = ({"cave","It is large and illuminated by a strange source",
    "town","You are at the edge of the village, and only see a few of the buildings",
    "village","You are at the edge of the village, and only see a few of the buildings",
    "building","It looks like somebody's home.  You'd better not go near it!",
    "buildings","They are all very similar and indistinctive",
    "castle","It's the king's palace.  Not very large, but nicely\n"+
    "decorated, though",
    "gate","It is a large, guarded gate leading to the courtyard",
    "courtyard","It is beautifully decorated.  In the center is a large statue",
    "statue","It is a large statue of the king....obviously not life-sized",
    "palace","It's the king's palace.  Not very large, but nicely\n"+
    "decorated, though"});}
  ::reset(arg);}

void init()
  {::init();
  add_action("est","east");}

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


