inherit "players/animal/closed/cabin";
 
#define ROOM_NO 6
 
init() 
{
::init();
}
 
reset(arg) 
{
::reset(arg);
  if(arg) return;
    
  short_desc = "Cabin #"+ROOM_NO+" of Cabin Village";
  long_desc =
    "Cabin #"+ROOM_NO+"\n\n"+
    "\tThis is cabin #"+ROOM_NO+". Its fully furnished with all\n"+
    "\tthe latest gadjets, and of course, is a perfect place for\n"+
    "\ttalking, storing goods, and who knows what else!\n\n";
  room_no=ROOM_NO;
  thisplace = this_object();
}

