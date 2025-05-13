/*		 gen Tree in forest   */
/* 		 Goldsun 020295       */

inherit "/room/room";
#include "tear.h"
#include "light.h"
#include "listen.h"

string tree_type;

void set_dest(string dest)
{
 dest_dir=allocate(2);
 dest_dir[0]=dest;
 dest_dir[1]="down";
 return;
}

void make_monster(int i){
object ob;
 switch(i){
  case 0:
   if (present("ant",this_object())) break;
   ob=clone_object("obj/monster");
   ob->set_name("wood ant");
   ob->set_alias("ant");
   ob->set_short("A wood ant");
   ob->set_long("A small wood ant.\n");
   ob->set_level(1);
   ob->set_ac(1);
   ob->set_wc(1);
   move_object(ob,this_object());
   break;
                            
  case 1:           
   if (present("bear",this_object())) break;                
   ob=clone_object("obj/monster");
   ob->set_name("small bear");
   ob->set_alias("bear");
   ob->set_short("A small bear");
   ob->set_long("A small brown bear.\n");
   ob->set_level(8);
   ob->set_ac(8);
   ob->set_wc(3);
   move_object(ob,this_object());
   break;

  case 2:
   if (present("snake",this_object())) break;                
   ob=clone_object("obj/monster");
   ob->load_chat(19,({"Sssssssssssss\n"}));
   ob->set_name("snake");
   ob->set_short("A snake");
   ob->set_long("A long huge snake.\n");
   ob->set_level(23);
   ob->set_ac(4);
   ob->set_wc(23);
   move_object(ob,this_object());
   break;
 }
 return;
}

void reset(int arg){
  ::reset(arg);
 make_monster(random(3));
 if (arg) return;
 set_light(1);
 short_desc="On the tree";
 switch(random(4)){
   case 0: long_desc="On the oak tree. Large branches with a lot of leaves\n"+
		     "are everywhere around you.\n";
	   tree_type="oak";
           break;
   case 1: long_desc="This is a huge pine tree. Far above your head you can see \n"+
                     "thousands of fragrant pine needles. The tree must have been\n"+
                     "for thousands of years because your arms can't even encircle\n"+
		     "it.\n";
	   tree_type="pine";
           items=({"needles","Green pine needles"});
	   break;
   case 2: long_desc="You are on the maple tree. A tangle of branches are everywhere\n"+
		     "around you. Green maple leaves are waving in the wind.\n";
	   tree_type="maple";    /* javor */
           items=({"leaves","Maple leaves are waving in the wind"});
	   break;
   case 3: long_desc="You are on the branch of beech tree. This tree is high\n"+
                     "and wide. It must have been here for many years.\n";
	   tree_type="beech";  /* buk */
           items=({"leaves","Thousands of leaves are waving in the wing"});
 	   break;
 }
  items=({ "tree",long_desc,
           "trunk","Old dark "+tree_type+" trunk with many scars",
	   "branch","You are standing on this "+tree_type+" branch"
    });


}


init(){
 ::init();
add_action("tear","tear");
add_action("shake","shake");
add_action("light","light");
add_action("listen","listen");
add_action("climb","climb");
}

shake(str){
 if (str=="tree" || str==tree_type){
  write("You shake this tree but nothing happend.\n");
  say(OPN+" shakes the tree but nothing happend.\n");
  return 1;
  }
}

climb(str){
 if (str=="tree" || str=="oak" || str=="oak tree"){
  write("You don't think you could climb up this tree.\n");
  say(OPN+" tries to climb up this tree.\n");
  return 1;
 }
}
