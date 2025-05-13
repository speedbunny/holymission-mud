#include "../garden.h"

id(str) { return str=="cembalo"; }
short() { return "A black cembalo"; }
long() {
  write("It looks really old, dust lays on its keys.\n" +
	"It seems that noone has played on it for a very long time.\n");
}

init() { add_action("play","play"); }

play(str) {
  if (str=="cembalo") {
     write("As you play the piano you hear the beautiful sound\n"
	+ "of J.S.Bach's Toccata e fuga in d-minor.\n" +
           "But suddenly the cembalo crumbles to tiny pieces of wood, it was too old.\n" +
	   "Now you see that the piano had hidden an iron door to the west ...\n");
     say(this_player()->query_name()+ " plays a beautiful toccata from Bach.\n" +
         "Suddenly the cembalo crumbles to tiny pieces of wood.\n");      
     self_destruct();
     return 1;
  }
}

self_destruct() {
object env;
int i,max;
 tell_room(environment(),
	  "You hear a funny sound, as the strings of the cembalo lose their "
	+ "tension.\n");
  max=random(4)+1;
  env=environment(this_object());
  for (i=0;i<max;i++)
      move_object(clone_object(OBJ+"/cembpiece"),env);
  destruct(this_object());
}


query_property()
{
  return "no_clean_up";
}
