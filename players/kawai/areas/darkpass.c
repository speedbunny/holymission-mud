inherit "room/room";

void reset(int arg) 
  {if(!arg) 
    {short_desc = "Underground passage";
    long_desc = "You are in a dark underground passage.  The air is damp, and a slight breeze "+ 
    "flows by.  You can hear the sound of water far to the northwest.   You feel a "+
    "strange wind to the east, and a small tunnel leads to the south."+
    "@@chk_orb@@";
    smell = "The air is damp.";
    dest_dir = ({"players/kawai/areas/coins","east",
    "players/kawai/areas/dwarves/entrance","south",
    "players/kawai/areas/epass","northwest"});
    items = ({"cave","It is cold and damp",
    "tunnel","The cave narrows as it heads south",
    "passage","It is cold and damp"});}
    ::reset(arg);}

string chk_orb() 
  {if( !present("kq1-orb",this_player())) 
    {return "\nYour lights flicker in the wind.\n";}
  return("\n");}

