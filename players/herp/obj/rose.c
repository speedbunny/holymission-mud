inherit "obj/thing";

init() {
  ::init();
  if (random(3)==0) {
    write("Suddenly the rose turns out as an illusion and with a *BOP* it is gone.\n");
    destruct(this_object());
  }
}
