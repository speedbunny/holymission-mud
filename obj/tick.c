/*-------------------------------------------------------------------------*/
/* FILE : tick.c                                                           */
/*                                                                         */
/* Description : This file calls the shutdown for the mud. It is called    */
/*               every 24 hours. Only an arch can call this otherwise.     */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Sometime     HERP         Since we changed a lot to increase performance,
                          we try to reboot only 2 days.
Sometime     HERP         Set reboot to 20 days temporarily: let's see what
                          the machine can stand.
Sometime     HERP         Back to 1 day, cleanup is screwed and thus disabled
Mar 25 1997  Kryll        Cleaned up this file. Fixed so only for arches.
 
*/
 
#include "/obj/obj_defs.h"
#include "/obj/lw.h"

//#define DAY 345600
#define DAY   86400
 
#define MAXTIMER 90
#define DAY_CNT                43200
#define HOUR_CNT               1800
#define MIN_CNT                30

int timer;

/* PROTOTYPES */
status qry_timer();
 
void reset(int arg) {
  if(arg) return;
  call_out("do_shut", DAY);
}
 
void init() {
  set_light(1);
  add_action("set_timer","timer");
  add_action("qry_timer","query"); 
  add_action("church","church");
  add_action("south","south");
  add_action("south","s");
}
 
int do_shut() {
  timer = MAXTIMER+1;
  set_heart_beat(1);
  return 1;
}
 
void heart_beat() {
  timer--;
  switch(timer) {
#if 1
    case 0:
      shout("Death reaches out a bony hand straight into your chest.\n");
      shout("The prophet screams in agony.\n");
      "/obj/shut"->shut(10);
      set_heart_beat(0);
      break;
 
    case 45:
      shout("The prophet screams: It is a human's number, and its number is 666 !\n");
      shout("The prophet screams: Do penance ! The Lord will punish you, weary pilgrims !\n");
      shout("The prophet screams: The end of the world is near ... BEHOLD !\n");
      break;
 
    case 90:
      shout("You feel the ground moving below your feet !\n");
      shout("A crack appears beneath your feet. Take care !\n");
      shout("You are caught in a shower of blood and frogs !\n");
      shout("The four apocalyptic riders appear on the sky.\n");
      shout("The sky darkens, the earth quakes, the blind prophet rises from his grave...\n");
      shout("The prophet shouts: Fear the antichrist ! Fear the antichrist !\n");
      shout("The prophet shouts: The Lord will judge us ! Cower in fear, ye Mortals ...\n");
      break;
  }
#else
    case 0:
      shout("Make haste. Time is short.\n");
      shout("Death reaches out a bony hand straight into your chest.\n");
      "/obj/shut"->shut(10);
      set_heart_beat(0);
      break;

    case 60:
      shout("You feel the ground moving below your feet !\n");
      shout("A crack appears beneath your feet. Take care !\n");
      shout("Beware, for the end of the world is upon you !\n");
      break;
  }
#endif
  return;
}
 
status set_timer(string str) {
  int i, j;
 
  if(!TP->query_archwiz()) return 0;
 
  if(!str || !sscanf(str, "%d", i))
    return qry_timer();
 
  set_heart_beat(0);             /* falls gerade ein shutdown da */
  j = remove_call_out("do_shut");
  call_out("do_shut", i);
  write("Removed reboot time has been "+j+" seconds.\n");
  write("New world recreation time is "+i+" seconds.\n");
  return 1;
}
 
status qry_timer() {
  string delay;
  int i;
 
  i = find_call_out("do_shut");
  if(i <= 0) {
    write("The world is fading, behold !\n");
    if(timer > 0) 
        write("Armageddon will punish this world's citizens for their sins in "+timer+" seconds.\n");
     if(timer == 0)
       write("Armageddon is here to destroy the world !\n");
     return 1;
  }
  delay = "";
 
  if(i > 3599) {
     delay = " "+i/3600+" hours";
     i = i%3600;
  }
  if(i > 59) {
     delay += " "+i/60+" minutes";
     i = i%60;
  }
  if(i > 0)
     delay += " "+i+" seconds"; 
  write("Game reboot will be in"+delay+".\n");
  return 1;
}
 
int qry_timer_value() {
  return find_call_out("do_shut");
}
 
status church() {
  TP->MOVEP("X#room/church");
  return 1;
}

status south() {
  TP->MOVEP("south#players/"+TP->RNAME+"/workroom");
  return 1;
}
 
string short() { 
  return "This room echoes the sound of millions of clocks ticking ...";
}

void long() {
  write(short()+"\n\n");
  writelw("Wizard, you here can query how much time is left till the world "+
    "will be renewed. Use 'query'.\n");
  write("\nExits are: church and south.\n"); 
  if(!TP->query_archwiz()) return;
  writelw("\nYou also can set the time the world shall be recreated. "+
    "Use 'timer <seconds>'\n");
  return;
}

