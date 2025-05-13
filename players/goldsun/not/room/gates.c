/*  coded by: Goldsun 191095    	 */

inherit "/room/room.c";
#include "room.h"

#define GATES2 "/domains/prime_plane/zones/nottingham/rooms/outside_gates"
#define GATESW "/domains/rpime_plane/zones/nottingham/rooms/gates_w"

// first and second time of Nottingham feast
#define FIRST_TIME 2
#define SECOND_TIME 17
#define MAX_ADV 18
#define houses ({"house1"})
#define NUM_HOUSES 13
static private status is_feast;
static private status is_open;
static private object *adv_list;

int query_feast()
{ 
  return (is_feast==FIRST_TIME || is_feast==SECOND_TIME);
}

void add_adventurer(object ob)
{
 if (member_array(ob,adv_list)) return;
 adv_list+=({ob});
}

void start_feast()
{ 

int i;
object ob;

 // is_feast=1; 
  for(i=1;i++;i<MAX_ADV)
  {
    ob=clone_object(_PATH+"monsters/mix");
    transfer(ob,PATH+"road"+random(18)+1);
    add_adventurer(ob);
    ob=clone_object(_PATH+"monsters/mix");
    transfer(ob,PATH+"room/wall"+random(23)+1);
    add_adventurer(ob);
  }

  // clone_monsters=> special for nott.
 /*
  for(i=1;i++;i<NUM_HOUSES)
  {
    transfer(clone_object(PATH+"monster/owner"),PATH+"room/house"+i);
    transfer(clone_object(PATH+"monster/visitor"),PATH+"room/house"+i);
    (PATH+"room/house"+i)->start_unlock();
  }
   */
}

void end_feast()
{
 int i;

  for(i=1;i++;i<NUM_HOUSES)
  {
    (PATH+"room/house"+i)->start_unlock();
  }
  for(i=0;i++;i<sizeof(adv_list)-1)
  {
    if (objectp(adv_list[i])) destruct(adv_list[i]);
  }
}

void reset(int arg)
{
  if (query_feast()) end_feast();
  is_feast++;
  if (query_feast()) start_feast();
  if (is_feast>35) is_feast=1;

  ::reset(arg);
  if (arg) return;
  adv_list=({});
  set_light(1);
  is_open=0;  //closed
  property=({"no_clean_up"});
  short_desc=("Town gates");
  long_desc=("You are at the town gate in the Nottingham. The east gate "+
            "is made of oak wood. The town lies to the west.\n");
//  smell="The air is damp and dusty."; 
  dest_dir=({ PATH+"room/wall1","north",
 	      PATH+"room/road1","west",
	      PATH+"room/wall23","south"});
  items=({"gates","@@query_gates_desc@@",
          "road","Stony town road"

}

void init()
{
 ::init();
 add_action("enter","enter");
 add_action("open","open");
 add_action("close","close");
}

int open(string str)
{
 if (str=="gates")
 {
   if (is_open)
   {
     write("The gates are already open.\n");
     return 1;                                                    /***********/
   }
   write("You open the gates.\n");
   say(this_player()->query_name()+" opens the gates.\n");
   tell_room(GATES2,"Someone opens the gates.\n");
   is_open=1; 
   return 1;
 }
 notify_fail("Open what ?\n");
 return 0;
}

int close(string str)
{
 if (str=="gates")
 {
   if (!is_open)
   {
     write("The gates are already closed.\n");
     return 1;                                                    /***********/
   }
   write("You close the gates.\n");
   say(this_player()->query_name()+" closes the gates.\n");
   tell_room(GATES2,"Someone closes the gates.\n");
   is_open=0; 
   return 1;
 }
 notify_fail("Close what ?\n");
 return 0;
}
 
int enter(string str)
{
 if (str=="gates")
 {
  if (is_open) this_player()->move_player("east#players/goldsun/nottingham/room/outside_gates.c");
  else write("The gates are closed.\n");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}


