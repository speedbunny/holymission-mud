get() { return 1; }

reset() {
  call_out("destroy",2);
}

destroy() {
  destruct(this_object());
}

