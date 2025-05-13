inherit "room/room";
#include "/obj/lw.h"
#define MAXNEWS 7
#define LIST_LENGTH 45

string names;
int points;
int news;

reset(arg) {
  if(!arg) {
    short_desc="Cashimor's Workroom";
    long_desc="This is an empty room.\n";
    set_light(1);
    smell="It is very airy here.";
    names=allocate(LIST_LENGTH);
    points=allocate(LIST_LENGTH);
  }
}

query_newspaper() {
  if(!news) news=random(MAXNEWS)+1;
  return news;
}
  
query_list() {
int i;
string tmp;

  recalc_list();
  tmp="";
  for(i=0;i<LIST_LENGTH;i++) {
    if(names[i]) tmp=tmp+sprintf("%d) %s\n",i+1,capitalize(names[i]));
  }
  return sprintf("%-*#s\n",SCREEN_WIDTH,tmp);
}

query_names() {
  recalc_list();
  return names;
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







