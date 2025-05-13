inherit "/room/room";
 
#define ALPHABET ({"a","b","c","d","e","f","g","h","i","j","k","l","m",\
                   "n","o","p","q","r","s","t","u","v","w","x","y","z"})
 
void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  short_desc = "The finger cleaning room";
  long_desc = "This room lets you update the finger information. "+
    "Just type <finger_clean> to make it work.\n";
 
  ::reset(arg);
}
 
void init() {
  ::init();
  add_action("clean_finger", "finger_clean");
}
 
status clean_finger(string str) {
  string *ppl, pth, tmp;
  int    i, j, sz;
 
  if(!this_player()->query_archwiz())
    return 0;
  for(i=0; i<26; i++) {
    ppl = get_dir("/players/moonchild/misc/fingerdata/" + 
                  ALPHABET[i] + "*.o");
    for(i=0, sz=sizeof(ppl); i<sz; j++) {
      sscanf(ppl[j], "%s.o", tmp);
      pth = sprintf("p/%c/%s", tmp[0], tmp);
      if(!restore_object(pth)) {
        write(tmp + "\n");
        rm("/players/moonchild/misc/fingerdata/" + ppl[j]);
      }
    }
  }
  return 1;
}
