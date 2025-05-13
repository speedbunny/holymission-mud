/*
 *
 *****************************************************************************
 * 
 * D R A G O N A I R L I N E    (WARLORD (c))
 * 
****************************************************************************
 */

// Last Edit: Whisky, moved call_out to heart_beat and changed some
//            functions. Hope it works now.

#define TO  this_object()
#define TP  this_player()
#define TPN TP->query_name()
#define TPR TP->query_real_name()
#define TPP TP->query_possessive()
#define E   environment
#define DEST1 "players/warlord/trans/port1"
#define DEST2 "players/warlord/trans/port2"
#define DEST3 "players/warlord/trans/port3"
#define DEST4 "players/warlord/trans/port4"
#define DEST5 "players/warlord/trans/port5"
#define DEST6 "players/warlord/trans/port6"

inherit "obj/monster";

object          me;
int             fly, mounted, count;
string          where;

void reset(int flag)
{
    ::reset(flag);
    set_light(1);
    if (!flag) 
    {

	    set_name("dragon");
	    set_alias("green dragon");
	    set_short("green dragon");
	    set_long(
       "You see a mighty 80 feet high, green Dragon. She is one of\n"   +
	    "the transporters of the famous Dragon Airline. If you like\n"   +
       "to mount her and you are over level five, you have to pay \n"   +
       "200 coins for a ticket. Once mounted, you can travel around\n"  +
       "as long as you like. With dismount you can leave the dragon.\n" +
       "If you are in a hurry, type kick and she will fly immediatly.\n");
	    set_gender(2);
	    set_level(80);
	    me = TO;		/* just to get sure */
	    add_property("no_teleport",1);
       count = 15;
       set_heart_beat(1);
   }
}

/* 010195 Colossus: Some queries for the dragon */

int query_flight()
{
    return fly;
}

int query_mounted()
{
    return mounted;
}

void long()
{
   string sho;

    if (present(TP, E(me))) 
	     ::long(); 
    else if (fly) 
    {
	     write("You see the back of the green Dragon and below you\n" +
	     "can see the tops of buildings and tiny figures\n" +
	     "scurring about. They look like ants.\n");
    } 
    else 
    {
	     write("You see the back of the friendly green Dragon.\n");
        if (sho = E(me)->short()) 
            write("You recognize that she is now in: "+sho+"\n"); 
    }
}

void init()
{
    add_action("do_mount", "mount");
    add_action("fly_out", "dismount");
    add_action("do_kick", "kick");
    if (!where)
        where = file_name(E(this_object()));
    ::init();
}

varargs mixed hit_player(int dam,int kind,mixed elem)
{

    if (mounted) 
	     return 0;
    return ::hit_player(dam, kind, elem);
}

/* *** mount   ***  */

int do_mount(string arg)
{
   string file;

    if (!arg || !id(arg))
    {
        notify_fail("Mount what ?\n");
        return 0;
    }
    else if (E(TP) == me)
    {
         write("You are already on the Dragon.\n");
         return 1;
    }
    else if (TP->query_money() < 200 && TP->query_level()>5) 
    { 
	     write("You have to pay 200 coins for the Dragon Airlines.\n");
	     return 1;
    }
    write("You mount the Dragon.\n");
    file = "mounting the dragon#"+file_name(this_object());
	 TP->move_player(file);
	 mounted = 1;
    if (TP->query_level() > 5)
	     TP->add_money(-200);
  return 1;
}

/* *** kick ***   */

int do_kick(string arg)
{

    if (!arg || !id(arg))
	     return 0;
    if (fly && count)
    {
        write("You kick the poor Dragon.\n");
        return 1;
    }
    fly = 1;
    where=file_name(E(me)); 
    move_object(me, "players/warlord/nowhere"); 
    tell_room(me, "The Dragon rises high into the air.\n");
    tell_room(E(me), "The Dragon takes off for its' next port.\n"); 
    count = 0;
  return 1;
}


/* *** heart_beat *** */

void heart_beat()
{

    count ++;
    switch(count)
    {
       case 3:
         tell_room(me, "You see the birds pass below.\n");
       break;
       case 5:
         tell_room(me, 
         "Suddenly, the Dragon does a loop in midair and you almost fall off.\n");
       break;
       case 7:
          tell_room(me,"The Dragon slightly swoops down the land.\n");
       break;
       case 9:
          tell_room(me,"The Dragon prepares for the landing.\n");
       break;
       case 11:
          tell_room(me,"The Dragon lands ");
          fly = 0;
          switch (where)
          {
             case DEST1:
                move_object(me,DEST2);
                tell_room(me,"in Rasta City.\n");
                break;
             case DEST2:
                move_object(me,DEST3);
                tell_room(me,"at a Bridge.\n");
                break;
             case DEST3:
                move_object(me,DEST4);
                tell_room(me,"next to the Sea.\n");
                break;
             case DEST4:
                move_object(me,DEST5);
                tell_room(me,"in Mariawichteldorf.\n");
                break;
             case DEST5:
                move_object(me,DEST6);
                tell_room(me,"in Ezo.\n");
                break;
             default:
                move_object(me,DEST1);
                tell_room(me,"near Warlord's Castle.\n");
                break;
          }
         tell_room(E(me), 
         "The Dragon suddenly swoops down to land in front of you.\n");
         break;
         default:
           if (count > 11  && count < 25) 
           {
              fly = 0;
           }
           if (count == 23)
           {
               tell_room(E(me), "The Dragon spreads its large wings.\n");
               tell_room(me, "The Dragon spreads its large wings.\n");
           }
           if (count == 25)
           {
               count = 2;
               fly = 1;
               tell_room(me,   "The Dragon raises off into the air.\n");
               tell_room(E(me),"The Dragon takes off for its' next port.\n"); 
               where = file_name(E(this_object()));
               move_object(this_object(),"/players/warlord/nowhere");
           }
     }
}



int fly_out()
{

    object          inv;
    int             i;

    if(fly && count && count <= 9) 
    { 
	    write("You can't dismount while the Dragon is flying !\n"+
             " You would fall to your death!\n");
	    return 1;
    }
    TP->move_player(", dismounting the Dragon", E(me)); 
    fly = 0;
    mounted = 0; 
    return 1;
}

int no_clean_up()
{
    return 1;
}
