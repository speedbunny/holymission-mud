inherit "/room/room";
 
#include "/players/kryll/test/bin/adverbs.h"
#include "/sys/defs.h"
 
// prototypes
nomask string find_adverb(string str);
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  short_desc = "Adverb room";
  long_desc =
    "This room is for adverbs. Type <dump> to get a list of all "+
    "of the available adverbs.\n";
}
 
void init() {
  ::init();
  add_action("list_adverbs","dump");
}
 
status list_adverbs() {
  string str;
  int    i, j, sz, sz1;
 
  str = "Adverb List\n";
  str += "-----------\n";
  for(i=0, sz1=sizeof(ALPHABET); i<sz1; i++) {
    if(!(sz = sizeof(ADVERB_LIST[i])))
      continue;
    for(j=0; j<sz; j++) {
      str += sprintf("%19s", ADVERB_LIST[i][j]);
      if((j+1)%4 == 0 && j != sz-1)
        str += "\n";
    }
    str += "\n\n";
  }
  str += "\n";
  TP->more_string(str);
  return 1;
}
 
nomask string find_adverb(string str) {
  string adverb;
  int    len, idx, where;
 
  len = strlen(str);
  switch(len) {
    case 3 :
        idx = member_array(str[0], ALPHABET);
        if((where = member_array(str, SHORT_ADV_LIST[idx])) == -1)
          return 0;
        adverb = ADVERB_LIST[idx][where];
        break;
    case 4 :
        idx = member_array(str[0], ALPHABET);
        if((where = member_array(str, LONG_ADV_LIST[idx])) == -1)
          return 0;
        adverb = ADVERB_LIST[idx][where];
        break;
    default : adverb = 0;
  }
  return adverb;
}
