inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    long_desc="You're in a long and dark tunnel. You have the "
           + "feeling as if someone is watching you.\n";
    short_desc="Tunnel";
    set_light(0);
    smell="The smell of earth lingers against your nose.";
  }
}
