
#define NAME this_player()->query_name() 
#define RNAME this_player()->query_real_name()
#define LVL this_player()->query_level() 
#define PPRON environment(this_object())->query_pronoun()
#define POSS this_player()->query_possessive() 
#define RACE this_player()->query_race()
#define OBJ this_player()->query_objective()
#define ACTION "/players/bobo/clan/actions/actions.c"
#define TO this_object() 
#define PRON this_player()->query_pronoun() 
#define WHO environment(this_object())->query_real_name()
#define TP this_player()
#define CP(arg) capitalize(arg)
#define SERVER "/players/bobo/clan/server.c"

#define MEMBERS ([ "bobo":"soke", "tetsuhara":"renshi", "turbo":"renshi", \
  "rhaile":"renshi", "monkie":"monkey", "jewel":"kyoshi", "saryon":"renshi", \
  "khufu":"renshi", "wilbie":"hanshi", "mercy":"renshi", \
  "thumper":"renshi" ])






