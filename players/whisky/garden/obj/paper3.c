#define TP this_player()
#define TPN TP->query_name()
inherit "obj/treasure";
 
reset(arg) {
  if (!arg) {
     set_id("paper");
     set_short("A dirty sheet of toilet-paper");
     set_long("A pink pleasant but dirty sheet of toilet-paper.\n");
     set_value(1);
  }
}
        


