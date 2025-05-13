inherit "/room/room";
#define TP this_player()
#define TPN TP->query_name()

int is_cotton, is_moven, is_lock, is_open, is_bed, drawer_open, is_key,
    drawer_lock, is_key2;

int is_ladder()
{
object po;
  po=first_inventory(this_object());
  while(po)
  {
   if ( po->id("ladder") && (po->query_tied_to_ob()==this_object())) return 1; 
   po=next_inventory(po);  
  }
  return 0;
}

void reset(int arg){

  is_lock = 1;
  is_open = 0;
  is_moven= 0;
  is_cotton=1;
  is_bed=0;
  drawer_open=0;
  drawer_lock=1;
  is_key=1;
  is_key2=1;

if (!arg){
  set_light(1);
  short_desc=("Goldsun cottage");
  long_desc="You are in the Goldsun cottage. This is his resting cottage. "+
            "He is very often here. The floor and ceiling are made of wood. "+
       "There are chairs with a wooden table and bed. You have a nice view "+
       "through the small windows.\n";
   
  smell="You smell nice wooden smell";

  hidden_dir=({ "/players/goldsun/nottingham/room/road10","east"});

  property=({"no_teleport"});
  items=({ "floor","A wooden floor is made of oak",
	   "table","@@query_table@@",
	   "bed","@@query_bed@@",
	   "cottage",long_desc,
	   "chair","@@query_chair@@",
	   "ceiling","It's made of oak. You can see two rings fixed to it",
           "rings","@@query_rings@@",
	   "trapdoor","@@query_trapdoor@@",
	   "cotton","@@query_cotton@@",
	   "drawer","@@query_drawer@@",
	   "window","A small window with a view to the town",
	   "windows","The windows are small. You can see a road through them",
	   "view","You can see town road"
	  });
  }
 ::reset(arg);
}


string query_table()
{
 if (is_moven) return "An old wooden table with small drawer. It stands by the wall";
 return "An old wooden table with small drawer. It stands in the middle of the room";
}
  
string query_bed()
{
 if (is_bed) 
 {
   if (is_cotton) return "A wooden bed. There is a heap of cotton on it.\n"+
                "Goldsun likes soft beds. It stands few feet from the "+
 	        "wall";  
   return "A wooden bed. It stands few feet from the wall";  
 }

   if (is_cotton) return "A wooden bed. There is a heap of cotton on it.\n"+
                "Goldsun likes soft beds. It stands near the wall";
   return "A wooden bed. It stands near the wall";  
}

string query_chair()
{
  if (is_key) return "An old leather chair. There is a key on it";
  return "An old leather chair";
}

string query_rings()
{
 if (is_ladder()) return "You can see the iron rings fixed to the ceiling. There is "+
        "a ladder tied to them";
 return "You can see the iron rings fixed to the ceiling";
}

string query_trapdoor()
{
 if (is_bed)
 {
   if (is_open) return "A wooden trapdoor. It leads down. It's opened";
   return "A wooden trapdoor. It leads down. It's closed";
 }  
 return "There is no trapdoor here";
}

string query_cotton()
{
  if (is_cotton) return "A heap of white cotton. It's white. It is possible "+
    "to make\nsomething from it";
  return "There is no cotton here";

}

string query_drawer()
{
 if (drawer_open) return "A wooden table drawer. It's open";
 return "A wooden table drawer. It's closed";
}


init(){
 ::init();
 add_action("m_get","get");
 add_action("my_move","move");
 add_action("_open","open");
 add_action("_unlock","unlock");
 add_action("_close","close");
 add_action("_lock","lock");
 add_action("_climb","climb");
 add_action("_search","search");
 add_action("_enter","enter"); 
}

int _enter(string str)
{
 if (str=="trapdoor" && is_bed)
 { 
   if (is_open)
   {
     this_player()->move_player("down#players/goldsun/nottingham/room/my_cell");
     return 1; 
   }
   write("The trapdoor is closed.\n");
   return 1;
 }
}

int _search(string str)
{
object ob;

  if (str=="drawer")
  {
    if (drawer_open)
    {
       if (is_key2)
       {
  	  write("You search the drawer.\n");
          ob=clone_object("players/goldsun/nottingham/obj/iron_key");
          if (transfer(ob,this_player()))
	  {
	     write("You can't carry that much.\n");
	     return 1;
           }
	   write("You find a key.\n");
 	   is_key2=0;
           return 1;
        }
        write("Someone was faster than you.\n");
        return 1; 
     } else {
        write("The drawer is closed.\n");
        return 1;
     }
    }
 }
        
int _climb(string str)
{
 if ((str=="rope ladder" || str=="ladder") && is_ladder())
 {
   write("You climb up.\n");
   this_player()->move_player("up#players/goldsun/nottingham/room/cott2");
   return 1;
 }
}

int m_get(string str)
{
object ob;

 if (str=="key from chair")
 {
   if (!is_key) return 0;
   ob=clone_object("players/goldsun/nottingham/obj/d_key");
   if (transfer(ob,this_player()))
   {
	write("You can't carry that much.\n");
	return 1;
   }
   write("Ok.\n");
   is_key=0;
   return 1;
 }
 if (str=="cotton")
 {  
    if (!is_cotton)
    {
	 write("That is not here.\n");
	 return 0;
    }
    ob=clone_object("/players/goldsun/nottingham/obj/cotton");
    if (transfer(ob,this_player()))
    {
	write("You can't carry that much.\n");
	return 1;
    }
    is_cotton=0;
    write("Ok.\n");
    return 1;
  }
}

int _unlock(string str)
{
   if ((str=="trapdoor" || str=="trapdoor with key" ||
        str=="trapdoor with orion key") && is_bed)
   {
      if (!is_lock)
      {
	 write("But it's already unlocked.\n");
         return 1;
      }	
      if (present("special_tr_key_001",TP))
      {
         write("You unlock the trapdoor.\n");
         say(TPN+" unlocks a trapdoor.\n");		
         is_lock=0;
         return 1;
      }
      write("You haven't proper key.\n");
      return 1;	
   }
   if (str=="drawer" || str=="drawer with key" || 
	str=="drawer with gnosbol key")
   {
      if (!drawer_lock)
      {
	 write("But it's already unlocked.\n");
         return 1;
      }	
      if (present("special_tr_key_002",TP))
      {
         write("You unlock the drawer.\n");
         say(TPN+" unlocks a drawer.\n");		
         drawer_lock=0;
         return 1;
      }
      write("You haven't proper key.\n");
      return 1;	
   }
}

int _open(string str)
{
   if (str=="trapdoor" && is_bed)
   {
      if (is_lock)
      {
	 write("But it's locked.\n");
	 say(TPN+"tries to open a trapdoor.\n");
         return 1;
      }	
      if (is_open)
      {
	write("It's already opened.\n");
	return 1;
      }
      write("You open the trapdoor.\n");
      say(TPN+" opens a trapdoor.\n");		
      is_open=1;
      return 1;
   }
  if (str=="drawer" || str=="table drawer")
  {
      if (drawer_open)
      {
      	write("It's already opened.\n");
	return 1;
      }
      if (drawer_lock)
      {
	 write("But it's locked.\n");
	 say(TPN+"tries to open a drawer.\n");
         return 1;
      }	
      write("You open the drawer.\n");
      say(TPN+" opens a drawer.\n");		
      drawer_open=1;
      return 1;
  }
}

int _close(string str)
{
   if (str=="trapdoor" && is_bed)
   {
      if (!is_open)
      {
	write("It's already closed.\n");
	return 1;
      }
      write("You close the trapdoor.\n");
      say(TPN+" closes a trapdoor.\n");		
      is_open=0;
      return 1;
   }
  if (str=="drawer" || str=="table drawer")
  {
      if (!drawer_open)
      {
      	write("It's already closed.\n");
	return 1;
      }
      write("You close the drawer.\n");
      say(TPN+" closes a drawer.\n");		
      drawer_open=0;
      return 1;
  }
}

int _lock(string str)
{
   if ((str=="trapdoor" || str=="trapdoor with key" ||
        str=="trapdoor with orion key") && is_bed)
   {
      if (is_lock)
      {
	 write("But it's already locked.\n");
         return 1;
      }	
      if (present("special_tr_key_001",TP))
      {
	 if (is_open)
 	 {
	    write("You close the trapdoor.\n");
	    say(TPN+" closes a trapdoor.\n");
	    is_open=0;
         }
         write("You lock the trapdoor.\n");
         say(TPN+" locks a trapdoor.\n");		
         is_lock=1;
         return 1;
      }
      write("You haven't proper key.\n");
      return 1;	
   }
   if (str=="drawer" || str=="drawer with key" || 
	str=="drawer with gnosbol key")
   {
      if (drawer_lock)
      {
	 write("But it's already locked.\n");
         return 1;
      }	
      if (present("special_tr_key_002",TP))
      {
	 if (drawer_open)
 	 {
	    write("You close the drawer.\n");
	    say(TPN+" closes a drawer.\n");
	    drawer_open=0;
         }
         write("You lock the drawer.\n");
         say(TPN+" locks a drawer.\n");		
         drawer_lock=1;
         return 1;
      }
      write("You haven't proper key.\n");
      return 1;	
   }
}

int tie(string str)   /* function called by rope.c */
{
 if (str=="rings" || str=="ring") write("It is not proper to tie rope there.\n");
 return 0;
}

int ladder_tie(string str)  /* function called by rope_ladder.c   */
{
 object ob;
 notify_fail("Tie what?\n");
 if (str == "rings" || str=="ring" )
 { 
        if (is_ladder())
        {
	  write("But there is already such ladder here.\n");
 	  return 0;
        }
	return 1;
 }
}  


int my_move(string str)
{
   notify_fail("Move what?\n");
   if (str=="table")
   {
     if (!is_moven)
     {
	 is_moven=1;
	 write("You move the table to the wall.\n");
	 say(TPN+" moves a table.\n");
	 return 1;
     }
     write("You move table to the middle of the room.\n");
     say(TPN+" moves a table.\n");
     is_moven=0;
     return 1;
   }
   if (str=="bed")
   {
    
     if (is_cotton)
     {
        write("You try to move the bed.\n  But it is a bit heavy for you.\n");
        say(TPN+" tries to move a bed.\n");
        return 1;
     }
     if (!is_bed)
     {
        write("You move the bed from the wall.\nYou find a trapdoor.\n");
        say(TPN+" moves a bed.\n");
        is_bed=1;
        return 1;
     } 
     write("You move the bed to the wall.\n");
     say(TPN+" moves a bed.\n");
     is_bed=0;
     return 1;
   }
}

