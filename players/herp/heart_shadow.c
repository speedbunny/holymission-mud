/* my very special heart_beat */

object owner;

start_shadow(ob) {
  owner=ob;
  shadow(ob,1);
}

heart_beat() {
    tell_object(environment(owner),"Du-dunk.\n");
}
