inherit "room/room";
#define PATH "/players/goldsun/nottingham/"

int is_chest;

void reset(int arg) 
{
 is_chest=1;
if (!arg)
{
 set_light(1);
 short_desc="On the rope ladder";
 long_desc="You are hanging on the rope ladder. Near you head you can see "+
	   "sturdy wooden ceiling.";

 dest_dir=({  PATH+"room/my_cott","down"   });

 items=({
	  "ceiling","A wooden ceiling with small crack in it",
	  "crack","A dark small crack"
  });

 smell = "You smell strong wooden smell.";
}  
}

void init(){
 ::init();
 add_action("s_search","search");
}

int s_search(string str)
{
object ob;

 if (str=="crack")
 {
    if (is_chest)
    {
       ob=clone_object(PATH+"/obj/my_chest");
       write("You find a chest.\n");
       if (transfer(ob,this_player()))
       {
 	 write("You can't carry that much.\n");
         transfer(ob,this_object());
       }
     }	else  write("Someone was faster than you.\n");
     is_chest=0;
     return 1;
  }
}
 
     
