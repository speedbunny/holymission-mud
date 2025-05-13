object g1,g2,g3;

void make()
  {if(!g1) 
    move_object(g1=clone_object("players/kawai/areas/dwarves/mole"),
    "players/kawai/areas/dwarves/field2");
  if(!g2)
    move_object(g2=clone_object("players/kawai/areas/dwarves/mole"),
    "players/kawai/areas/dwarves/field5");
  if(!g3)
    move_object(g3=clone_object("players/kawai/areas/dwarves/mole"),
    "players/kawai/areas/dwarves/field10");}

void init() 
  {call_out("make", 15, 0);}

int id(string str)
  {return str=="disp";}



