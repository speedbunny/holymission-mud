id(str) {
        return str =="note" || str == "ND";
}
 
short() {  return "READ this note!";  }
 
long() { write("I said read.\n");  return 1; }
 
init() {
     add_action("nope2", "i_trans");
     add_action("nope2", "trans");
     add_action("nope", "destruct");
     add_action("nope", "zap");
     add_action("nope", "destr");
     add_action("nope", "nuke");
     add_action("nope", "bomb");
     add_action("nope2", "clean");
     add_action("nope2", "i_clean");
     add_action("nope", "unmake");
     add_action("read", "read");
     add_action("nope2", "Trans");
     add_action("nope", "Dest");
}
 
read(str) {
     if(!id(str)) return 0;
     cat("/players/animal/note");
     return 1;
}
 
get() { return 0; }
 
nope(str) {
     if(!id(str)) return 0;
     write("The note smirks: Animal has been notified of this.\n");
     log_file("animal", this_player()->query_real_name()+" messed with note\n");
     return 0;
}
 
nope2() {
     write("The note smirks: Animal has been notified of this.\n");
  log_file("animal", this_player()->query_real_name()+" screwed with the note\n");
     return 0;
}
 
