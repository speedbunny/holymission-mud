/* Coded by Tegerl, 25.3.1995 */
/* rooms/town/door */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
#define TP this_player()
#define TPN TP->query_name()
#define TPOBJ TP->query_objective()
#define TPPOS TP->query_possessive()
object key;
void reset(int arg) 
{
::reset(arg);
if (arg) return;

set_light(1);
short_desc="In front of a huge door.";

long_desc=
    "You are in front of a huge door. " +
    "It seems that this door hasn't been opened for quite a long time. " +
    "The whole area around that door makes you believe that not many people have been here lately.\n";

dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/yard","south"
  });  

items=({
    "castle","It is a big old castle, but it is in a very bad condition",   
    "door","It is a huge wooden door, and it seems that it hasn't been opened for a long time",
    "ground","Your footprints are the only ones around here",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

/* void init() {
 ::init();
add_action("unlock","unlock");
add_action("do_open","open");
add_action("close","close");
add_action("north","north");
add_action("knock","cast 'knock door'");
add_action("pl","picklock");
}

pl(str) {
  if (str=="door" && present("picklock",TP)) {
  write("You can't open that door by using a picklock.\n");
  say(TPN+" tries to use "+TPPOS+" picklock on the door.\n" +
  capitalize(TPOBJ)+" fails completely.\n");
  return 1;
}
}

north(){
 write("You bang your head against the closed door.\n");
 say(TPN+" runs into the closed door.\n");
 return 1;
}

knock(str) {

if (str=="door") {
write("You fail to open the door.\n");
say(TPN+" fails to open the door.\n");
return 1;
}
}
do_open (str) {
if (str=="door") {
write("You can't open the locked door.\n");
say(TPN+" tries to open the locked door and failes.\n");
return 1;
}
}
unlock(str) {
 if (present("jajaja",TP)) {
    write("The door opens and you go north.\n");
    say("The door opens and "+TPN+" goes north.\n");
    TP->move_player("#/players/tegerl/jabberwocky/rooms/castle/knight");
   return 1;
}
write("You fail to open the door.\n");
say(TPN+" fails to open the door.\n");
return 1;
} */

