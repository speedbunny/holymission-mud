inherit "/obj/thing";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("tester");
  set_short("A tester for feelings");
}
 
void init() {
  ::init();
  add_action("_filter", "", 1);
}
 
int _filter(string str) {
  string verb;
 
  verb = (string)query_verb();
  if(verb[0..0]=="'" || member(verb,'.')!=-1)
    return 0;
 
  if(verb=="quit")
    return 0;
 
  if(file_size("/players/kryll/test/bin/feelings/"+verb+".c") > 0)
    if(("/players/kryll/test/bin/feelings/"+verb)->main(str)) {
      write("The test version.\n");
      return 1;
    }
  return 0;
}
