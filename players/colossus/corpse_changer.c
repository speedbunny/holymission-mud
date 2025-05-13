/* 
 * A corpse changer
 * by Justice
 */
 
string name;
 
id(str) { return str=="corpse changer"; }
 
init() {
   if (interactive(this_player()))
      return;
   if (!name)
      name = this_player()->query_name();
   set_heart_beat(1);
}
 
heart_beat() {
   string temp;
   if (!environment(environment()))
      destruct(this_object());
   if (sscanf(environment()->short(), "Corpse of %s", temp) && temp != name) {
      tell_room(environment(environment()), temp + "'s corpse suddenly reverts to the corpse of " + name + "!\n");
      environment()->set_name(name);
      destruct(this_object());
   }
}
 
