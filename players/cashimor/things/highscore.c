inherit "obj/thing";
#include "/obj/lw.h"
#define LIST_LENGTH 50

string names;
int points;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("list");
    set_alias("player list");
    set_short("A player list");
    set_long(lw("This is a list of players who logged in today, sorted "
              + "according to the amount of quests they completed. It is "
              + "updated everytime it is read.\n"));
    set_can_get(1);
    set_weight(1);
    set_value(10);
    names=allocate(LIST_LENGTH);
    points=allocate(LIST_LENGTH);
  }
  recalc_list();
}

read(str) {
int i;
string tmp;

  if((!str)||(str!="list")) {
    notify_fail("Read what?\n");
    return 0;
  }
  recalc_list();
  write("These are the players who still fight in the Holy Mission.\n");
  tmp="";
  for(i=0;i<LIST_LENGTH;i++) {
    if(names[i]) tmp=tmp+sprintf("%d) %s\n",i+1,capitalize(names[i]));
  }
  printf("%-*#s\n",SCREEN_WIDTH,tmp);
  return 1;
}

recalc_list() {
int i,j,where,point;
object who;
string name;

  who=users();
  for(i=0;i<sizeof(who);i++) {
    if((!who[i]->query_immortal())&&(!who[i]->query_testchar())) {
      name=who[i]->query_real_name();
      point=who[i]->query_quest_points();
      where=member_array(name,names);
      if(where==-1) {
        add_person(name,point);
      }
      else {
        if(point!=points[where]) {
          for(j=where+1;j<LIST_LENGTH;j++) {
            points[j-1]=points[j];
            names[j-1]=names[j];
          }
          points[LIST_LENGTH-1]=0;
          names[LIST_LENGTH-1]=0;
          add_person(name,point);
        }
      }
    }
  }
}

add_person(name,point) {
int i,ok;

  ok=-1;
  for(i=0;i<LIST_LENGTH;i++) {
    if(points[i]<point) {
      ok=i;
      break;
    }
  }
  if(ok==-1) return;
  for(i=LIST_LENGTH-1;i>ok;i--) {
    points[i]=points[i-1];
    names[i]=names[i-1];
  }
  points[ok]=point;
  names[ok]=name;
}
    



