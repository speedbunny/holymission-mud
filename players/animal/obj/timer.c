inherit "obj/treasure";
 
#define LOBBY "players/animal/closed/lobby"
int room_no;
 
set_room_no(value){room_no=value;}
 
get()
{
  write("I dont think so!\n");
  return 0;
}
 
short()
{
  int time;
 
  time=LOBBY->query_ttimer(room_no);
  if(time<1)
    return "A small timer that is on 0";
  else
    return "A timer that is showing "+time+" minutes left";
}
 
reset(arg)
{
  set_id("timer");
  set_alias("watch");
  set_long("This is a timer! What do ya expect to see here?\n");
}
 
 

