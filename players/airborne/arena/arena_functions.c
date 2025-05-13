/* ************************************************************************
   This is a file in the arena. Do not make changes without commenting both
   at the top of this file and in the /players/airborne/arena/CHANGES.made
   file. This code is very intricate, and we need to know what is going on
   if we are to maintain it.  - Airborne and Blade
   ************************************************************************ */

/* ************************************************************************
   Changes:

   ************************************************************************ */

string perimeter_desc=0;

void reset(arg){
  if(arg) return;
  ::reset(arg);

  master_obj = find_object(AMASTER);

  set_light(0 + random(3));
  short_desc = "In the arena";
  long_desc = long();
  items = ({
    "wall", query_walldesc,
    "walls", query_walldesc,
    "floor", query_floordesc,
  });

  return;
}

query_general_walldesc(){
string shit;

  shit = find_object(AMASTER)->query_inner_wall();
  return "The wall is made of "+ shit +".\n";
}

query_floor_desc(){
string shit;

  shit = find_object(AMASTER)->query_type();
  return "The floor is made of solid "+shit+".\n";
}


set_perimeter(int low, int high){
  string desc;
  int north=FALSE, south=FALSE, west=FALSE, east=FALSE;

  if(X==low) west=TRUE;
  if(X==high) east=TRUE;
  if(Y==low) south=TRUE;
  if(Y==high) north=TRUE;
  desc = "You are at the ";
  if(north) desc += "north";
  if(south) desc += "south";
  if(east) desc += "east";
  if(west) desc += "west";
  if(west+east+north+south ==2){
    desc += " corner";
  }
  desc += " wall of the arena.\n";
  set_perimeter_desc(desc);
  return 1;
}

void set_perimeter_desc(string desc){
  perimeter_desc = desc;
  return;
}

string query_perimeter_desc(){
  return perimeter_desc;
}

int query_perimeter(){
  if(perimeter_desc)return 1;
  return 0;
}






