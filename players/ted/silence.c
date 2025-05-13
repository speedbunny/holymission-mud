#include "security.h"

#define all		0;
#define race		1;

#define monk		2;
#define fighter		3;
#define adventurer	4;
#define bard		5;
#define mage		6;
#define thief		7;
#define priest		8;
#define druid		9;

#define elf		10;
#define half_elf	11;
#define half_orc	12;
#define dwarf		13;
#define faerie		14;
#define human		15;


int	*silenced;                 /* silences race and guild tells */


silence(str) {
  int i;
  if(!silenced) silenced = allocate(15);
  if(!str)
    for(i=0; i<sizeof(silenced); i++)
      if(silenced[i]) write(silenced[i]+"\n");
/*
  silenced[str];
*/
  if(str == "all" || str == "race" || str == "thief"
    || str == "mage" || str == "adventurer" || str == "bard"
    || str == "fighter" || str == "monk" || str == "priest"
    || str == "druid" || str == "elf" || str == "half_elf"
    || str == "half_orc" || str == "dwarf" || str == "faerie"
    || str == "human") {
    if(silenced[str]) {
      silenced[str] = 0;
	write(str+" now active\n");
    } else {
      silenced[str] = 1;
	write(str+" now silenced.\n");
    }
  }
  write("Ok.\n");
  return 1;
}

query_silenced(str) { return silenced[str]; }

race_tell(msg) {
  string per_name, per_race;
  int i, max;
  object list;

  list = users();
  i = 0;
  if(!msg) {
    write("Send what message?\n");
    return 1;
  }
  per_name = this_player()->query_name();
  per_race = this_player()->query_race();
  max = sizeof(list);
  while(i < max) {
 if((per_race==list[i]->query_race()||(list[i]->query_level() >= APPRENTICE))
    && (!list[i]->query_silenced(per_race)) && (!in_editor(list[i])))
   tell_object(list[i],
   format("|-"+capitalize(per_name)+" the "+capitalize(per_race)+"-| "+msg+"\n",78));
    i++;
  }
  return 1;
}

guild_tell(str) {
  string per_name, tmp, msg, guild_name;
  int i, max;
  object list;

  list = users();
  i = 0;
  if(!str) {
    write("Send what message?\n");
    return 1;
  }
  sscanf(str, "%s %s", tmp, msg);
  if((tmp=="thief" || tmp=="fighter" || tmp=="mage" || tmp=="bard" ||
      tmp=="priest" || tmp=="druid" || tmp=="monk")
      && (this_player()->query_level() >= APPRENTICE)) {
    guild_name = tmp;
  } else {
    guild_name = this_player()->query_class_name();
    msg = str;
  }
  per_name = this_player()->query_name();
  max = sizeof(list);
  while(i < max) {
    if((guild_name == list[i]->query_class_name()||(list[i]->query_level() >= APPRENTICE))
       && (!list[i]->query_silenced(guild_name)) && (!in_editor(list[i]))) 
    tell_object(list[i],
    format("[*"+capitalize(guild_name)+" "+capitalize(per_name)+"*] "+msg+"\n",78));
    i++;
  }
  return 1;
}
