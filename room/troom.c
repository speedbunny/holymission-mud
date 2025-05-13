inherit "room/room";

reset(int arg) {
    ::reset(arg);
    if (arg) return;
    short_desc="Transit room";
    long_desc="Land rushes by as you travel along.\n";
    set_light(1);
}

int no_clean_up() {
  return 1;
}
