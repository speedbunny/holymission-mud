reset(arg) { call_out("h_dest",600); }
h_dest() {
object h;	/* destruct helenette ... she's a source of quarrels */

  h=find_player("helenette");
  if (h) {
    destruct(h);
    destruct(this_object());
  }
  else call_out("h_dest",600);
}
