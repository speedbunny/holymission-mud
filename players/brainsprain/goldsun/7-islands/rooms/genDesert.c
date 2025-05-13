inherit "/room/room";
#define OPN this_player()->query_name()
#define TR(x) tell_room(this_object(),x)

string type;
int  is_storm, chance, time, maxTime;

int my_test_player()
{
object all;
 all=first_inventory(this_object());
 while(all)
 {
 if (living(all) && !all->query_npc()) return 0;
 all=next_inventory(all);
 }
 return 1;
}

void set_type(string s){ type=s; } /* sandy, rocky, mix */
                                   /* standard is mix   */

void set_name(string n){ short_desc=n; }  /* name of desert  */

void set_storm(int i, int b)  /* chance , maxTime */
{ 
  chance=i;
  maxTime=b;
}

query_long(){
 if (is_storm) return "You cannot see anything. You have sand in your eyes.\n";
 switch(type){
  case "sandy" : return( "You are in "+short_desc+" desert. The hot sand and"+
                 " blazing sun are unbearable. In all directions you can see"+
                 " sandy dunes.  They are amazingly formed.\n"
			 );
		
 case "rocky" : return ("You are in "+short_desc+" desert.  Hunks of slate "+
"and shale radiate heat from the sun high overhead.  This desert is +"
"known for its wicked sandstorms, which appear quickly.\n");

  default      : return ( "You are in "+short_desc+" desert. The hot sand and"+
                 " blazing sun are unbearable. In all directions you can see"+
                 " sandy dunes.  They are amazingly formed.\n"
                         );

 }
}

void reset(int arg){
if (!arg){
 is_storm=0;
 set_light(1);
 long_desc="@@query_long@@";

 /* possibillity to code extra items in your room */

 if (sizeof(items)) items+=({"desert","@@query_long@@"});
  else items=({"desert","@@query_long@@"});

 switch(type){
  case "sandy": items+=({"sand","yellow sand"});
                break;
  case "rocky": items+=({"rock","dark rock"});
	        break;
  default     : items+=({"sand","yellow sand",
			"rock","dark rock"}); 
                break;
 }
 smell="You smell hot dusty and dry air.";
}
 ::reset(arg);

}

heart_beat()
{
 if (my_test_player() ) set_heart_beat(0);
 if (is_storm)
 {
   switch(random(6))
   {
     case 0: TR("Sand swirls in the air.\n");
	     break;
     case 1: TR("You breath sand and dust.\n");
	     break;
     case 2: TR("Sand rubs in your mouth.\n");
	     break;
     case 3: TR("Sand rubs in your eyes.\n");
	     break;
     case 4: TR("Sand rubs in your ears.\n");
	     break;
     case 5: TR("Strong wind blows the sand to you.\n");
	     break;
   }
   time++;
 }
 if (!is_storm && chance > random(100))
 {
  TR("A huge cloud of sand appears in the horizon.\n"+
     "A wave of wind precedes it, blowing stronger and stronger.\n"+
     "The sand starts to swirl.\n");
  is_storm=1;
  time=0;
 }
 if (time > maxTime ){
   TR("The wind blows slower and slower.\n");
   TP("The storm ends.\n");
   is_storm=0;
   time=0;
 }
 return;
}


init()
{
  ::init();
  if (chance) set_heart_beat(1);
  add_action("do_get","get");
}

int  do_get(string str)
{
  if (str=="sand")
  {
   write("The sand slips through your fingers.\n");
   say(OPN + "tries to take the sand.\n");
   return 1;
  }
}

