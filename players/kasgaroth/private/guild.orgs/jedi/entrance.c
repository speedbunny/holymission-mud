#define GUILD	"jedi"
#define	GM	"guild/master"

string room;
int gd;

short() { return "A shimmering entrance to the east"; }

long() { write("You get the feeling of Power floating through your mind.\n"); }

id(str) { return str=="entrance"; }

reset(arg) {
  if (arg) return;
  gd=GM->query_number(GUILD);
  room=GM->query_room(gd);
  move_object(this_object(),"room/crop");
}

init() { add_action("move","east"); }

move(str) {
  if (!str && query_verb()=="east" || str=="east") {
     this_player()->move_player("east#"+room);
     return 1;
  }
}
