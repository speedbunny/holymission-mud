#define RWHERE	"/players/sauron/sys/rwhere/rwhere"

int main(string str) {
  return (int)RWHERE->main(str);
}

string help() {
  return "\
Command:        rwhere <player>\n\
Arguments:      none, or a visible, online player.\n\
See also:       who"+
((this_player()->query_immortal() || this_player()->query_testchar())?
   ", ip, people":
   "")+"\n\
\n\
This command displays a list of all the users online who are visible to \
you, along with their location in the real world. You can specify the \
name of a player who is online and visible to you to just see their \
location.\n";
}
