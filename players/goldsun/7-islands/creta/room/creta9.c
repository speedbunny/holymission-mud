inherit "/room/room";
#define PATH "players/goldsun/7-islands/creta/room/"
#define MAXTREE 45   /*maximum of trees you can climb here, make it*/
#define TP this_player()            /* more than 2                  */
#define OPN TP->query_name()
#define TREE ({"up tree","tree"})

object *trees;

void reset(int arg){
if (!arg){
 trees=allocate(MAXTREE);
 set_light(1);
 short_desc=("Dense forest");
 long_desc=
  ("You are in the dense forest between Madaros and Idhe. Many trees of\n"+
   "undefined kinds grows up to sky. They have to been here for thousands\n"+
   "of years. The ground is covered by grass and moss. A steam in the branches\n"+ 
   "above and sunbeams make fantastic figures.\n"
  );

 smell="You smell strong wooden smell.";

 dest_dir=({ PATH+"creta8", "north",
	     PATH+"creta5", "northwest",
	     PATH+"creta10","south"
	   });

 items=({"forest",long_desc,
	 "island",long_desc,
         "tree","It is large tree with wide branches like "+
		 MAXTREE+" other trees. Maybe you could climb them",
         "madaros","Madaros to the west. It is very high mountain",
         "idhe","Idhe to the east. It is very high mountain",
	 "mountain","Madaros to the west. It is very high",
         "mountains","Madaros to the west and Idhe to the east",
        });
 }
 ::reset(arg);
}

init(){
 ::init();
add_action("climb","climb");
}   

int climb(string str)
{
string what;
int num;

 notify_fail("Climb what?\n");
 if (!str) return 0;
 if (str=="madaros" || str=="idhe" || str=="mountain" ||
     str=="mountains")
 {
     write("You cannot climb "+str+". Idhe and Madaros are too steep.\n");
     say(OPN+" tries to climb up "+str+".\n");
     return 1;
 }
 if (member_array(str,TREE)!=-1)
  {
    num=1;
    what=str;
  }
  else 
  if (sscanf(str,"%s %d",what,num)==2)
  {
    if (num>MAXTREE || num<1)
    {
      write("There are only "+MAXTREE+" that you could climb up.\n");
      return 1;
    }
  } //
    if (member_array(what,TREE)!=-1)  /* now we climb up it */
    {
      if (!trees[num-1])
      {
	   trees[num-1]=clone_object("/players/goldsun/gen/room/genTree");
    	   trees[num-1]->set_dest(file_name(this_object()));
      }
      write("You start to climb up the tree.\n");
      write("Uf.\nUffff.\nYou stand on the wide branch.\n");
      say(OPN+"Climbs up a tree.\n");
      transfer(TP,trees[num-1]);
      return 1;
    }
  //
}
