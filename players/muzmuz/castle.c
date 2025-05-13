

/* castle */

#define DEST "/players/muzmuz/workroom.c"
#define BOAT "/players/muzmuz/island/commuter"
#define QUEST1 "/players/muzmuz/quest/quest_obj"
#define QUEST2 "/players/muzmuz/island/quest_obj"
#define START "/players/uglymouth/vikings/shallow"
#define ISL "/players/muzmuz/island/rooms/landing"
#define EZOBOAT "/players/muzmuz/island/ezocommuter"
#define EZOSTART "/players/patience/ezo/coast/rf10"
#define EZOISL "/players/muzmuz/island/rooms/jetty"



object quest1, quest2 ;

int id(string str) 
{ 
       return str == "castle"; 
}

string short() 
{
    return "The castle of Muzmuz";
}

void long() 
{
    write("This is the ancient castle of Muzmuz. A magic barrier\n"+
          "prevents people to enter it.\n");
}

void init()
{
   add_action("fcn_enter","enter");
}

int fcn_enter(string arg)
{
    if (!id(arg))
         return 0;
    write("As you try to enter the castle of Muzmuz you are stopped\n"+
          "by a magic barrier.\n");
    return 1;
}

void make_quest()
{
   quest1 = clone_object(QUEST1);
   quest1->add_quest();
   quest2 = clone_object(QUEST2);
   quest2->add_quest();
}


void reset(int flag) 
{
  /* loading the rooms for the boats */
      catch(call_other(START,"???"));
      catch(call_other(EZOSTART,"???"));
      catch(call_other(ISL,"???"));
      catch(call_other(EZOISL,"???"));

  /* loading master_objects checked in the reset */ 
  if (!find_object(BOAT))
      catch(call_other(BOAT,"???"));
  if (!find_object(EZOBOAT))
      catch(call_other(EZOBOAT,"???"));
   
   if (!find_object("/players/muzmuz/workroom"))
   {
      catch(call_other(DEST,"???"));
     move_object(this_object(),DEST);
   }

  /*  the creation */
  if (flag == 0)
  {
      /* moving the master_object */
      move_object(this_object(), DEST);
   }
}

no_clean_up()
  {
     return 1;
  }

