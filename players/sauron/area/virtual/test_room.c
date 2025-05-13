inherit "/players/sauron/inherit/virtual_room";

#include "/players/sauron/include/virtual.h"

string variable_long() {
  string ret,msg,*dirs;
  int *coords,tmp,i,j,d;

  dirs=m_indices(query_virtual_exits());
  tmp=(sizeof(query_dest_dir())/2)-sizeof(dirs);
  switch(sizeof(dirs)) {
    case 0:
      msg="\
You appear to be trapped in here as there are no virtual exits leading \
from this room!"
+(tmp?
  " It's a good job that there "
  +(tmp==1?
    "is 1 exit":
    "are "+tmp+" exits")
  +" to the real world here...":
  "");
      break;
    case 1:
      msg="\
You have reached a dead end in the virtual area you are exploring."
+(tmp?
  " However, there "
  +(tmp==1?
    "is 1 exit":
    "are "+tmp+" exits")
  +" to the real world here...":
  "");
      break;
    case 2:
      i=dir_name(dirs[0]);
      j=dir_name(dirs[1]);
      d=j-i;
      if(d<0)
        d=-d;
      msg="\
You are walking down a passageway in the virtual area you are exploring. \
The passageway "
+(d==4?
  "runs "+dirs[0]+"-"+dirs[1]+".":
  (d==3 || d==5?
   "curves slightly.":
   (d==2 || d==6?
    "bends at right angles.":
    (d==1 || d==7?
     "almost doubles back on itself.":
     "doubles back on itself? That can't be right!"))))
+(tmp?
  " There "
  +(tmp==1?
    "is 1 exit":
    "are "+tmp+" exits")
  +" to the real world here...":
  "");
      break;
    default:
      msg="\
You have arrived at a "
+sizeof(dirs)+"-way junction in the virtual area you are exploring."
+(tmp?
  " There "
  +(tmp==1?
    "is also 1 exit":
    "are also "+tmp+" exits")
  +" to the real world here...":
  "");
      break;
  }
  coords=query_virtual_coords();
  return "This is a virtual room at coordinates "+encode_coords(coords)
+".\n"+msg+"\nThere isn't much here right now... sorry. :)\n";
}

void reset(int arg) {
  if(!arg) {
    set_light(1);
    short_desc="A virtual room.";
    long_desc="@@variable_long@@";
  }
  ::reset(arg);
}
