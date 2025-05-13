inherit "/room/room";
#include "/players/goldsun/stand.h"
#define MAXCOUNT 2000
#define SAY(x) tell_room(this_object(),x)
#define RM "race/master"
 
string *foot;
int count;
object pl;

string query_ft()
{
 if (sizeof(foot)==0) return "A white snow. There are no footprints in it";
 return "A white snow with footprint(s) in it. Maybe you could study it";
}         

void reset_foot(){ foot= ({ }); }

void add_foot(string str)
{
 if (member_array(str,foot)==-1) foot+=({str});
}

void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("In the inland");
 long_desc="You are walking through the cold valley. A breeze blows "+
  "the snow flakes into your face. You can see high peaks covered by snow. "+
  "Many of them rises very steeply from the deep valleys to the clouds. "+
  "Nice spruce trees grow up from small platforms in the peak walls. "+
  "Whole island is covered by white snow.\n";

 smell="You smell fresh, cold air.";
 reset_foot();
 count=0;
 items=({"valley",long_desc,
	 "island",long_desc,
 	 "ground","The ground consists of rocks",
	 "snow","@@query_ft@@",
         "tree","A small spruce tree. It is snowed",
	 "peak","Very high peak with several trees. It's coverd by snow too"
         });
}
 ::reset(arg);

}


void init(){
  ::init();

  if (interactive(this_player()))
  {
      pl = this_player();
      SAY("You see small snow flakes falling down.\n");
      set_heart_beat(1);
  }
  add_action("climb","climb");
  add_action("study","study");
}   

void heart_beat()
{
  if (present(pl,this_object()) && interactive(pl))
  {
    if (!random(4)){
     SAY("Small snow flakes are falling down.\n");
     count++;
    }
    if (count>MAXCOUNT)
    {
     reset_foot();
     count=0;
    }
   }

  else 
     set_heart_beat(0);
}

int climb(string str){
 notify_fail("Climb what?\n");
 if (str=="peak"){
  write("You try to climb up, but it is too steep.\nYou fall back.\n");
  return 1;
 }
}


int study(string str)
{
  int i;
 notify_fail("Study what?\n");
 if (str=="footprint" || str=="footprints" || str=="snow"){
   say(OPN+" studies snow carefuly.\n");
   if (sizeof(foot)==0)
   {
     write("You study snow carefuly, but there are no footprints in it.\n");
     return 1;
   }
   write("You can see in the snow :\n");
   for(i=0;i<sizeof(foot);i++)
   {
     write(foot[i]+"\n");
   }
   return 1;
 }
}


catch_tell(str){
  string who,where;

  if (sscanf(str,"%s leaves %s",who,where)==2)
  {
    if (sizeof(foot)>200) reset_foot();  /* to fix possible bug */
    if (TP->query_immortal())
    {
         add_foot(capitalize("obj/armour"->query_size_name(TP->query_size()))+
		  " footprints lead to nowhere.");
         return 1;
    }
    add_foot(capitalize("obj/armour"->query_size_name(TP->query_size()))+
                " footprints lead to the "+where);
    return 1;
  }
}			

